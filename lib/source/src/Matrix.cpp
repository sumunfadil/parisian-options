/**
 * @file Matrix.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Matrix.hpp"
#include <cmath>

Vector operator* (const Matrix& C, const Vector& V)
{
    int d = C.size();
    Vector W(d);

    for (int j=0; j<d; j++)
    {
        W[j] = 0.0;

        for (int l=0; l<d; l++)
        {
            W[j] = W[j] + C[j][l] * V[l];
        }
    }

    return W;
}

Vector operator* (const double& a, const Vector& V)
{
    int d = V.size();
    Vector W(d);

    for (int j=0; j<d; j++)
    {
        W[j] = 0.0;

        W[j] += a*V[j];
    }
    
    return W;
} 

Vector operator+ (const double& a, const Vector& V)
{
    int d = V.size();
    Vector W(d);

    for (int j=0; j<d; j++)
    {
        W[j] = a;

        W[j] += V[j];
    }
    
    return W;
} 

Vector operator+ (const Vector& V, const Vector& W)
{
    int d = V.size();
    Vector Z(d);

    for (int j=0; j<d; j++)
    {
        Z[j] = 0.0;

        Z[j] += V[j] + W[j];
    }
    
    return Z;
} 

// Unsure of implementation
Vector operator* (const Vector& V, const Vector& W)
{
    int d = V.size();
    Vector Z(d);

    for (int j=0; j<d; j++)
    {
        Z[j] = 0.0;

        Z[j] += V[j] * W[j];
    }
    
    return Z;
} 

// Unsure of implementation
Vector exp(const Vector& V)
{
    int d = V.size();
    Vector Z(d);

    for (int j=0; j<d; j++)
    {
        Z[j] = 0.0;

        Z[j] += exp(V[j]);
    }
    
    return Z;
} 

// Dot product
double operator^ (const Vector& V, const Vector& W)
{
    double sum = 0.0;
    int d = V.size();

    for (int j=0; j<d; j++) 
    {
        sum += V[j]*W[j];
    }

    return sum;
}