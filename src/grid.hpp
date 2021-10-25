#ifndef GRID
#define GRID

#include "traits.hpp"

/**
 * \brief               this function builds a 2D-grid using a "a fette di pizza" (slices-of-pizza like) algorithm to partition the domain
 * \param d             a shared pointer to the matrix of the coordinates
 * \param n_angles      number of slices of the pizza
 * \param n_intervals   number of the pieces for each slice of the pizza
 * \param epsilon       the same epsilon regulating the kernel
*/
cd::matrixIptr Pizza(const cd::matrixptr &d, const unsigned int &n_angles, const unsigned int &n_intervals, const double &epsilon);


/**
 * \brief       allow to select between the preferred method to build the grid
 * \param id	name of the function of choice
*/
cd::gridfunction make_grid(const std::string &id);


/**
 * \brief   two-dimensional version of the grid class
*/
class grid
{
private:
    cd::gridfunction f;
    cd::matrixIptr g = std::make_shared<cd::matrixI>(0,0);
    cd::vectorptr normh = std::make_shared<cd::vector>(0);
    cd::vectorptr x = std::make_shared<cd::vector>(0);
    cd::vectorptr y = std::make_shared<cd::vector>(0);
    double epsilon;

    /**
     * \brief           a "helper" function to build the vector containing the position of the centers of the cells of the grid
     * \param data      a shared pointer to the matrix of the coordinates
    */
    void build_normh(const cd::matrixptr &data);

public:
    /**
	 * \brief           constructor
	 * \param id 	    name of the grid function
     * \param epsilon   the same epsilon regulating the kernel
	*/
	grid(const std::string &id, const double epsilon_);

    /**
     * \brief   use the Pizza style by default
    */
    grid();

    /**
     * \brief               build the grid
     * \param d             a shared pointer to the matrix of the coordinates
     * \param n_angles      number of slices of the pizza
     * \param n_intervals   number of the pieces for each slice of the pizza
    */
    void build_grid(const cd::matrixptr &d, const unsigned int &n_angles, const unsigned int &n_intervals);

    const cd::matrixIptr get_grid() const;
    const cd::vectorptr get_normh() const;
    const cd::vectorptr get_x() const;
    const cd::vectorptr get_y() const;
};






#endif // GRID