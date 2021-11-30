/// Copyright (C) Luca Crippa <luca7.crippa@mail.polimi.it>
/// Copyright (C) Giacomo De Carlo <giacomo.decarlo@mail.polimi.it>
/// Under MIT license

#ifndef LOCALLY_STATIONARY_MODELS_SAMPLEVAR
#define LOCALLY_STATIONARY_MODELS_SAMPLEVAR

#include "traits.hpp"
#include "kernel.hpp"
#include "grid.hpp"

namespace LocallyStationaryModels
{
/**
 * \brief a class to build and store the empiric variogram in all the anchor points
*/
class samplevar
{
private:
    cd::matrixptr variogram = nullptr; /// sample variogram matrix
    cd::matrixptr denominators = nullptr; /// a matrix with the denominators necessary to compute the squared weights
    cd::matrixptr squaredweights = nullptr; /// matrix with the squared weights
    kernel kernel_; /// kernel
    grid grid_; /// grid
    unsigned int n_angles; /// number of angles of the grid
    unsigned int n_intervals; /// number of intervals per angle of the grid

    /**
     * \brief a "helper" function which built the squared weights for the wls problem needed by the optimizer
    */
    void build_squaredweights();
    
public:
    /**
	 * \brief               constructor
	 * \param kernel_id     the name of the function you want to use for the kernel
     * \param n_angles      the number of angles to be passed to the grid
     * \param n_intervals   the number of inervals to be passed to the grid
     * \param epsilon       the bandwidth parameter regulating the kernel
	*/
    samplevar(const std::string &kernel_id, const unsigned int &n_angles_, const unsigned int &n_intervals_, const cd::scalar &epsilon);
    
    /**
     * \brief a default constructor for the class which calls the default constructors for both the kernel and the grid
    */
    samplevar();

    /**
     * \brief                   build the matrix of the empiric variogram
     * \param dptr              a shared pointer to the matrix of the coordinates of the original dataset
     * \param anchorpointsptr   a shared pointer to the matrix of the coordinates of the anchor poitns 
     * \param zptr              a shared pointer to the vector of the value of Z
    */
    void build_samplevar(const cd::matrixptr &dptr, const cd::matrixptr &anchorpointsptr, const cd::vectorptr &zptr);

    /**
     * \brief   return a shared pointer to the sample variogram
    */
    const cd::matrixptr get_variogram() const;
    /**
     * \brief   return a shared pointer to the matrix of the denominators
    */
    const cd::matrixptr get_denominators() const;
    /**
     * \brief   return a shared pointers to the squaredweigths required to evaluate the function to be optimized
    */
    const cd::matrixptr get_squaredweights() const;
    /**
     * \brief   return grid_.mean_x
    */
    const cd::vectorptr get_x() const;
    /**
     * \brief   return grid_.mean_y
    */
    const cd::vectorptr get_y() const;
    /**
     * \brief   return kernel_.k
    */
    const cd::matrixptr get_kernel() const;
    /**
     * \brief   return grid_.g
    */
    const cd::matrixIptr get_grid() const;
    /**
     * \brief   return grid_.normh
    */
    const cd::vectorptr get_normh() const;
}; // class samplevar
}; // namespace LocallyStationaryModels

#endif // LOCALLY_STATIONARY_MODELS_SAMPLEVAR
