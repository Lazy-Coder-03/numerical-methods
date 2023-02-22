#include <stdio.h>
#include <math.h>

int main()
{
    int n = 3; // number of equations
    double A[3][4] = {{27, 6, -1, 85},
                      {6, 15, 2, 72},
                      {1, 1, 54, 110}}; // augmented matrix

    // check if Gauss-Jacobi method can be applied
    int flag = 0;
    for (int i = 0; i < n; i++) {
        double diag = fabs(A[i][i]);
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum += fabs(A[i][j]);
            }
        }
        if (diag <= sum) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Gauss-Jacobi cannot be applied to the input matrix\n");
        printf("Matrix does not satisfy the diagonal dominance condition\n");
        return 0;
    }

    // apply Gauss-Jacobi method
    int max_iter = 100; // maximum number of iterations
    double eps = 1e-5; // tolerance
    double x[n]; // initial guess
    double x_new[n];
    int iter = 0;
    x[0]=0;
    while (iter < max_iter) {
        for (int i = 0; i < n; i++) {
            x_new[i] = A[i][n];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
        }
        int is_converged = 1;
        for (int i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > eps) {
                is_converged = 0;
                break;
            }
        }
        if (is_converged) {
            break;
        }
        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
        iter++;
    }

    // print the solution
    if (iter == max_iter) {
        printf("Gauss-Jacobi method did not converge within the maximum number of iterations\n");
    } else {
        printf("Solution found in %d iterations:\n", iter);
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %.5f\n", i, x_new[i]);
        }
    }

    return 0;
}
