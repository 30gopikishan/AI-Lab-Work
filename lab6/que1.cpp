//LAB 06: Implement a Single-Layer Neural Network(Perceptron) for Classification.
#include <bits/stdc++.h>
using namespace std;

// Sigmoid activation function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Derivative of sigmoid
double sigmoidDerivative(double z) {
    return sigmoid(z) * (1 - sigmoid(z));
}

class Perceptron {
    vector<double> weights;
    double bias;
    double lr; // learning rate

public:
    Perceptron(int n, double lr=0.1) {
        weights.resize(n, 0.0);
        bias = 0.0;
        this->lr = lr;
    }

    // Predict probability
    double predictProb(vector<double> x) {
        double z = bias;
        for(int i=0;i<weights.size();i++) {
            z += weights[i] * x[i];
        }
        return sigmoid(z);
    }

    // Predict class (0 or 1)
    int predict(vector<double> x) {
        return predictProb(x) >= 0.5 ? 1 : 0;
    }

    // Train using gradient descent
    void train(vector<vector<double>> X, vector<int> y, int epochs) {
        int m = X.size();
        for(int epoch=0; epoch<epochs; epoch++) {
            double cost = 0.0;
            for(int i=0;i<m;i++) {
                double z = bias;
                for(int j=0;j<weights.size();j++) {
                    z += weights[j] * X[i][j];
                }
                double y_pred = sigmoid(z);
                double error = y_pred - y[i];

                // Update weights and bias
                for(int j=0;j<weights.size();j++) {
                    weights[j] -= lr * error * X[i][j];
                }
                bias -= lr * error;

                // Cost (log loss)
                cost += -y[i]*log(y_pred) - (1-y[i])*log(1-y_pred);
            }
            cost /= m;
            if(epoch % 100 == 0)
                cout << "Epoch " << epoch << " Cost: " << cost << endl;
        }
    }

    void printParameters() {
        cout << "\nFinal Weights:\n";
        for(int i=0;i<weights.size();i++) {
            cout << "w[" << i << "] = " << weights[i] << endl;
        }
        cout << "Bias = " << bias << endl;
    }
};

int main() {
    // Example dataset: OR function
    vector<vector<double>> X = {
        {0,0}, {0,1}, {1,0}, {1,1}
    };
    vector<int> y = {0,1,1,1}; // OR truth table

    Perceptron p(2, 0.1);
    p.train(X, y, 1000);
    p.printParameters();

    cout << "\nPredictions:\n";
    for(int i=0;i<X.size();i++) {
        cout << "(" << X[i][0] << "," << X[i][1] << ") -> "
             << p.predict(X[i]) << endl;
    }

    return 0;
}

