#include "BlackScholesModel.hpp"
#include "Option.hpp"
#include "BlackScholesEquation.hpp"
#include "ExplicitMethod.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    double S0 = 100.0, r = 0.05, sigma = 0.2;
    BSModel Model(S0, r, sigma);

    int num_K = 100, num_T = 100;
    double K_min = 90.0, K_max = 110.0, T_min = 1.0 / 12.0, T_max = 1.0;

    // Create and open a CSV file for writing
    ofstream outputFile("option_prices.csv");
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file." << endl;
        return 1;
    }

    // Write header to the CSV file
    outputFile << "K,T,Price" << endl;

    for (int i = 0; i < num_K; ++i) {
        for (int j = 0; j < num_T; ++j) {
            double K = K_min + (K_max - K_min) * i / (num_K - 1);
            double T = T_min + (T_max - T_min) * j / (num_T - 1);

            // Create EuropeanPut option for each (K, T) pair
            Put EuropeanPut(K, T, 0.0, 2.0 * S0);
            BSEq BSPDE(&Model, &EuropeanPut);
            int imax = 3000, jmax = 1000;
            ExplicitMethod ExplicitMethod(&BSPDE, imax, jmax);

            // Solve PDE and write results to the CSV file
            double price = ExplicitMethod.v(0.0, S0);
            outputFile << K << "," << T << "," << price << endl;
        }
    }

    // Close the CSV file
    outputFile.close();

    cout << "Option prices saved to option_prices.csv." << endl;

    return 0;
}


