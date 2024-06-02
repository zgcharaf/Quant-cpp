#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <numeric>
#include <fstream>

// Function to generate Wiener increments
std::vector<double> generateWienerIncrements(int N, double dt) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, std::sqrt(dt));

    std::vector<double> dW(N);
    for (int i = 0; i < N; ++i) {
        dW[i] = d(gen);
    }
    return dW;
}

// Function to compute the cumulative sum of a vector
std::vector<double> cumulativeSum(const std::vector<double>& vec) {
    std::vector<double> result(vec.size());
    std::partial_sum(vec.begin(), vec.end(), result.begin());
    return result;
}

// Main function to simulate the Volterra process
int main() {
    double T = 1.0;   // Total time
    int N = 1000;     // Number of time steps
    double dt = T / N;  // Time step size

    std::vector<double> t(N);
    for (int i = 0; i < N; ++i) {
        t[i] = i * dt;
    }

    // Generate Wiener process increments
    std::vector<double> dW = generateWienerIncrements(N, dt);

    // Compute Wiener process
    std::vector<double> W = cumulativeSum(dW);

    // Compute Volterra process
    std::vector<double> X(N, 0.0);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            X[i] += std::sqrt(t[i] - t[j]) * dW[j];
        }
    }

    // Write results to a file for plotting
    std::ofstream outFile("volterra_process.csv");
    outFile << "time,Wiener,Volterra\n";
    for (int i = 0; i < N; ++i) {
        outFile << t[i] << "," << W[i] << "," << X[i] << "\n";
    }
    outFile.close();

    std::cout << "Simulation complete. Data saved to volterra_process.csv" << std::endl;

    return 0;
}
