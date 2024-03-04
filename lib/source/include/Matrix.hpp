/**
 * @file Matrix.hpp
 * @author Sumun, M. Fadil
 * @brief Matrix operations
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

/**
 * @brief Matrix multiplication with a vector
 * 
 * @param C Matrix
 * @param V Vector
 * @return Vector 
 */
Vector operator* (const Matrix& C, const Vector& V);

/**
 * @brief Multiply a matrix with a constant
 * 
 * @param a constant
 * @param V Vector
 * @return Vector 
 */
Vector operator* (const double& a, const Vector& V);

/**
 * @brief Add a constant to each element of a vector
 * 
 * @param a 
 * @param V 
 * @return Vector 
 */
Vector operator+ (const double& a, const Vector& V);

/**
 * @brief Elementwise addition of two vectors
 * 
 * @param V 
 * @param W 
 * @return Vector 
 */
Vector operator+ (const Vector& V, const Vector& W);

/**
 * @brief Elementwise product of two vectors
 * 
 * @param V 
 * @param W 
 * @return Vector 
 */
Vector operator* (const Vector& V, const Vector& W);

/**
 * @brief Exponentiating each element of a vector
 * 
 * @param V 
 * @return Vector 
 */
Vector exp(const Vector& V);

/**
 * @brief Dot product of two vectors
 * 
 * @param V 
 * @param W 
 * @return double 
 */
double operator^ (const Vector& V, const Vector& W);

#endif /* MATRIX_HPP */
