#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations

int main() {
    double A[N][N] = {{10, -1, 2}, {1, 5, -2}, {3, 1, 6}};
    double b[N] = {27, 7, 29};
    double x[N] = {0, 0, 0};
    double x_old[N] = {0, 0, 0};
    double tol = 1e-10;
    int max_iter = 1000;

    // Check for diagonal dominance
    int i, j;
    double D[N], S[N];
    for (i = 0; i < N; i++) {
        D[i] = fabs(A[i][i]);
        S[i] = 0;
        for (j = 0; j < N; j++) {
            if (j != i) {
                S[i] += fabs(A[i][j]);
            }
        }
        if (D[i] <= S[i]) {
            printf("The matrix is not diagonally dominant.\n");
            return 1;
        }
    }
    printf("The matrix is diagonally dominant.\n");

    // Implement the Gauss-Seidel method
    int k;
    for (k = 0; k < max_iter; k++) {
        for (i = 0; i < N; i++) {
            x_old[i] = x[i];
            double sum1 = 0, sum2 = 0;
            for (j = 0; j < i; j++) {
                sum1 += A[i][j] * x[j];
            }
            for (j = i+1; j < N; j++) {
                sum2 += A[i][j] * x_old[j];
            }
            x[i] = (b[i] - sum1 - sum2) / A[i][i];
        }
        double error = 0;
        for (i = 0; i < N; i++) {
            error = fmax(error, fabs(x[i] - x_old[i]));
        }
        if (error < tol) {
            break;
        }
    }

    // Print the solution
    printf("The solution is:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %f\n", i+1, x[i]);
    }

    return 0;
}
