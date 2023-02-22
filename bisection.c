#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x)+2*x;
}

double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) { // check if solution exists in bounds
        printf("Error: solution does not exist in the specified interval.\n");
        return NAN;
    }

    double c = (a + b) / 2.0; // midpoint of interval [a, b]
    int iter = 0; // iteration counter
    
    printf("Iteration %d:\n", iter);
    printf("Interval: [%lf, %lf]\n", a, b);
    printf("Midpoint: %lf\n", c);
    printf("Function value at midpoint: %lf\n", f(c));
    
    while (iter<100&&fabs(f(c)) > tol) { // loop until solution found within tolerance
        iter++; // increment iteration counter
        if (f(a) * f(c) < 0) { // root in [a, c]
            b = c;
        } else { // root in [c, b]
            a = c;
        }
        c = (a + b) / 2.0; // update midpoint
        
        printf("\nIteration %d:\n", iter);
        printf("Interval: [%lf, %lf]\n", a, b);
        printf("Midpoint: %lf\n", c);
        printf("Function value at midpoint: %lf\n", f(c));
    }
    
    return c; // return approximation of root
}

int main() {
    double a = 0.3; // left endpoint of interval
    double b = 1; // right endpoint of interval
    double tol = 1e-6; // tolerance for convergence
    double root = bisection(a, b, tol);
    
    if (!isnan(root)) { // check if root is not NaN
        printf("\nApproximate root: %lf\n", root);
        printf("f(%lf) = %lf\n", root, f(root));
    }
    
    return 0;
}
