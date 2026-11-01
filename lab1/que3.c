//linear regression
#include <stdio.h>
#include <math.h>

int main() {
    // Training data
    double X[5][2] = {
        {1000, 2},
        {1500, 3},
        {2000, 4},
        {2500, 4},
        {3000, 5}
    };
    double y[5] = {200, 300, 400, 500, 600};
    int m = 5; // number of training examples

    // Parameters
    double w1 = 0.0, w2 = 0.0, b = 0.0;

    // Hyperparameters
    double alpha = 0.0000001; // learning rate
    int iterations = 10000;

    for (int iter = 0; iter < iterations; iter++) {
        double y_pred[5], error[5];
        double cost = 0.0;

        // Prediction and error
        for (int i = 0; i < m; i++) {
            y_pred[i] = b + w1 * X[i][0] + w2 * X[i][1];
            error[i] = y_pred[i] - y[i];
            cost += error[i] * error[i];
        }
        cost = cost / (2 * m);

        // Gradients
        double dw1 = 0.0, dw2 = 0.0, db = 0.0;
        for (int i = 0; i < m; i++) {
            dw1 += error[i] * X[i][0];
            dw2 += error[i] * X[i][1];
            db  += error[i];
        }
        dw1 /= m;
        dw2 /= m;
        db  /= m;

        // Update parameters
        w1 -= alpha * dw1;
        w2 -= alpha * dw2;
        b  -= alpha * db;

        // Display cost every 1000 iterations
        if (iter % 1000 == 0) {
            printf("Iteration %d, Cost = %f\n", iter, cost);
        }
    }

    // Final parameters
    printf("\nFinal Parameters:\n");
    printf("w1 = %f\n", w1);
    printf("w2 = %f\n", w2);
    printf("b  = %f\n", b);

    // Prediction example
    double size = 2200, bedrooms = 4;
    double predicted_price = b + w1 * size + w2 * bedrooms;
    printf("Predicted price for house (2200 sqft, 4 bedrooms): %.2f\n", predicted_price);

    return 0;
}
