#include <stdio.h>

#define MAX_N 20 // Maximum number of data points

int main() {
    int n;
    double x[MAX_N], y[MAX_N]; // Arrays for data points
    double xi, yi = 0;
    int i, j;

    // Get the number of data points and the data points
    printf("Enter the number of data points (maximum %d): ", MAX_N);
    scanf("%d", &n);
    printf("Enter the data points in the format 'x y':\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the point to interpolate: ");
    scanf("%lf", &xi);

    // Compute the Lagrange polynomial
    for (i = 0; i < n; i++) {
        double L = 1;
        for (j = 0; j < n; j++) {
            if (j != i) {
                L *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        yi += y[i] * L;
    }

    // Print the interpolated value
    printf("The interpolated value at %f is %f\n", xi, yi);

    return 0;
}
