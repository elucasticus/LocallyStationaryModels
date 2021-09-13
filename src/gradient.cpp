#include "gradient.hpp"
#include <math.h>
#include <iostream>

using namespace cd;
using namespace LBFGSpp;

cd::scalar compute_h(const cd::scalar &lambda1, const cd::scalar &lambda2, const cd::scalar &phi, const cd::scalar &x, const cd::scalar &y)
{
    scalar xx = x * x;
    scalar yy = y * y;
    scalar xy = x * y;

    return sqrt((lambda2 * lambda2 * xx * cos(phi) * cos(phi) + lambda1 * lambda1 * yy * cos(phi) * cos(phi)
    + lambda1 * lambda1 * xx * sin(phi) * sin(phi) + lambda2 * lambda2 * yy * sin(phi) * sin(phi)
    + lambda1 * lambda1 * xy * sin(2 * phi) - lambda2 * lambda2 * xy * sin(2 * phi)) / (lambda1 * lambda1 * lambda2 * lambda2));
}


cd::scalar exponential(const cd::vector &params, const cd::scalar &x, const cd::scalar &y)
{
    double lambda1 = params[0];
    double lambda2 = params[1];
    double phi = params[2];
    double sigma = params[3];

    scalar h = compute_h(lambda1, lambda2, phi, x, y);
    return sigma * sigma * (1 - exp(-h));
}

cd::variogramfunction make_variogramiso(const std::string &id)
{
    return exponential;
}




///--------------------------------------------------------------------------




cd::scalar funzionedaottimizzare::operator() (const cd::vector &params)
{
    vector w = squaredweights->row(x0);
    vector truegamma(empiricvariogram->rows());

    #pragma omp parallel for
    for (unsigned int h = 0; h < truegamma.size(); ++h)
    {
        truegamma[h] = gammaiso(params, x->operator[](h), y->operator[](h));
    }
    vector empiricgamma = empiricvariogram->col(x0);
    return w.transpose() * (truegamma - empiricgamma).cwiseProduct(truegamma - empiricgamma);
}

cd::scalar funzionedaottimizzare::operator() (const cd::vector &params, vector &grad)
{
    vector w = squaredweights->row(x0);
    vector truegamma(empiricvariogram->rows());

    #pragma omp parallel for
    for (unsigned int h = 0; h < truegamma.size(); ++h)
    {
        truegamma[h] = gammaiso(params, x->operator[](h), y->operator[](h));
    }
    for (unsigned int i=0; i<params.size(); ++i)
    {
        vector paramsdeltaplus(params);
        vector paramsdeltaminus(params);

        double increment = 1e-6;

        paramsdeltaplus[i] += increment;
        paramsdeltaminus[i] -= increment;

        grad[i] = (funzionedaottimizzare::operator()(paramsdeltaplus) - funzionedaottimizzare::operator()(paramsdeltaminus))/(2*increment);
    }
    vector empiricgamma = empiricvariogram->col(x0);
    return w.transpose() * (truegamma - empiricgamma).cwiseProduct(truegamma - empiricgamma);
}


funzionedaottimizzare::funzionedaottimizzare(const cd::matrixptr empiricvariogram_, const cd::matrixptr squaredweights_, const cd::vectorptr x_, const cd::vectorptr y_, unsigned int x0_, 
    const std::string &id): empiricvariogram(empiricvariogram_), squaredweights(squaredweights_), x(x_), y(y_), x0(x0_), gammaiso(make_variogramiso(id)) {};




///--------------------------------------------------------------------------



opt::opt(const cd::matrixptr empiricvariogram_, const cd::matrixptr squaredweights_, const cd::vectorptr x_, const cd::vectorptr y_, const std::string &id_): 
    empiricvariogram(empiricvariogram_), squaredweights(squaredweights_), x(x_), y(y_), id(id_) 
{
    solutions = std::make_shared<matrix>(matrix::Zero(empiricvariogram->cols(),4));
};


vector opt::findonesolution(const unsigned int pos) const
{
    funzionedaottimizzare fun(empiricvariogram, squaredweights, x,  y, pos, id);

    // Set up parameters
    LBFGSBParam<double> param;
    param.epsilon = 1e-6;
    param.max_iterations = 1000000;

    // Create solver and function object
    LBFGSBSolver<double> solver(param);

    // Bounds
    Eigen::VectorXd lb(4);
    lb << 1e-08,1e-08,1e-08,1e-08;
    Eigen::VectorXd ub(4);
    auto inf = std::numeric_limits<double>::infinity();
    ub << inf,inf,M_PI_2,inf;

    // Initial guess
    vector x(4);
    x << 200,200,0.01,100;
    // x will be overwritten to be the best point found
    double fx;
    /*int niter = */solver.minimize(fun, x, fx, lb, ub);

    return x;
}


void opt::findsomesolutions(const vectorind &pos)
{    
    for (unsigned int i = 0; i < pos.size(); ++i)
    {
        vector sol = findonesolution(pos[i]);
        for (unsigned int j = 0; j < 4; ++j)
        {
            solutions->operator()(pos[i], j) = sol[j];
        }
    }
}

void opt::findallsolutions()
{
    #pragma omp parallel for
    for (unsigned int i=0; i<empiricvariogram->cols(); ++i)
    {
        vector sol = findonesolution(i);
        for (unsigned int j = 0; j < 4; ++j)
        {
            solutions->operator()(i, j) = sol[j];
        }
    }
}

cd::matrixptr opt::get_solutions() const
{
    return solutions;
}