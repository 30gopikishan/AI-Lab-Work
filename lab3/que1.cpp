//Lab 3: To implement Logistic Regression using Gradient Descent for binary classification.
#include <bits/stdc++.h>
using namespace std;

// Sigmoid function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Logistic Regression using Gradient Descent
int main() {
    // Training data (X1, X2 -> features, y -> label)
    // Example: simple dataset for binary classification
    vector<vector<double>> X = {
        {0, 1}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}
    };
    vector<int> y = {0, 0, 0, 1, 1, 1}; // labels

    int m = X.size();      // number of samples
    int n = X[0].size();   // number of features

    // Parameters (weights + bias)
    vector<double> w(n, 0.0);
    double b = 0.0;

    // Hyperparameters
    double alpha = 0.1;       // learning rate
    int iterations = 1000;    // number of iterations

    // Gradient Descent
    for(int iter = 0; iter < iterations; iter++) {
        vector<double> dw(n, 0.0);
        double db = 0.0;

        // Compute gradients
        for(int i = 0; i < m; i++) {
            double z = b;
            for(int j = 0; j < n; j++) {
                z += w[j] * X[i][j];
            }
            double y_pred = sigmoid(z);
            double error = y_pred - y[i];

            for(int j = 0; j < n; j++) {
                dw[j] += error * X[i][j];
            }
            db += error;
        }

        // Average gradients
        for(int j = 0; j < n; j++) {
            dw[j] /= m;
        }
        db /= m;

        // Update parameters
        for(int j = 0; j < n; j++) {
            w[j] -= alpha * dw[j];
        }
        b -= alpha * db;

        // Print cost every 100 iterations
        if(iter % 100 == 0) {
            double cost = 0.0;
            for(int i = 0; i < m; i++) {
                double z = b;
                for(int j = 0; j < n; j++) {
                    z += w[j] * X[i][j];
                }
                double y_pred = sigmoid(z);
                cost += -y[i]*log(y_pred) - (1-y[i])*log(1-y_pred);
            }
            cost /= m;
            cout << "Iteration " << iter << " Cost: " << cost << endl;
        }
    }

    // Final parameters
    cout << "\nFinal Weights and Bias:\n";
    for(int j = 0; j < n; j++) {
        cout << "w[" << j << "] = " << w[j] << endl;
    }
    cout << "b = " << b << endl;

    // Prediction example
    vector<double> test = {2.5, 2.5};
    double z = b;
    for(int j = 0; j < n; j++) {
        z += w[j] * test[j];
    }
    double prob = sigmoid(z);
    cout << "\nPrediction for (2.5, 2.5): Probability = " << prob
         << " -> Class = " << (prob >= 0.5 ? 1 : 0) << endl;

    return 0;
}
