#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x)+2*x;
}

double regula_falsi(double a, double b, double tol) {
    double fa = f(a);
    double fb = f(b);
    
    if (fa * fb >= 0) { // check if solution exists in bounds
        printf("Error: solution does not exist in the specified interval.\n");
        return NAN;
    }
    
    double c = (a*fb-b*fa)/(fb-fa);//a - fa * (b - a) / (fb - fa); // initial approximation using linear interpolation
    int iter = 0; // iteration counter
    
    printf("Iteration %d:\n", iter);
    printf("Interval: [%lf, %lf]\n", a, b);
    printf("Approximation: %lf\n", c);
    printf("Function value at approximation: %lf\n", f(c));
    
    while (fabs(f(c)) > tol) { // loop until solution found within tolerance
        iter++; // increment iteration counter
        double fc = f(c);
        if (fa * fc < 0) { // root in [a, c]
            b = c;
            fb = fc;
        } else { // root in [c, b]
            a = c;
            fa = fc;
        }
        c = (a*fb-b*fa)/(fb-fa);//a - fa * (b - a) / (fb - fa); // update approximation
        
        printf("\nIteration %d:\n", iter);
        printf("Interval: [%lf, %lf]\n", a, b);
        printf("Approximation: %lf\n", c);
        printf("Function value at approximation: %lf\n", f(c));
    }
    
    return c; // return approximation of root
}

int main() {
    double a = 0.3; // left endpoint of interval
    double b = 1; // right endpoint of interval
    double tol = 1e-6; // tolerance for convergence
    double root = regula_falsi(a, b, tol);
    
    if (!isnan(root)) { // check if root is not NaN
        printf("\nApproximate root: %lf\n", root);
        printf("f(%lf) = %lf\n", root, f(root));
    }
    
    return 0;
}
