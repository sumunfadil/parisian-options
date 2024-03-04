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

Vector operator* (const Matrix& C, const Vector& V);
Vector operator* (const double& a, const Vector& V);
Vector operator+ (const double& a, const Vector& V);
Vector operator+ (const Vector& V, const Vector& W);
Vector operator* (const Vector& V, const Vector& W);
Vector exp(const Vector& V);
double operator^ (const Vector& V, const Vector& W);

#endif /* MATRIX_HPP */
