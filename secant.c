#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x)+2*x;
}

double secant(double a, double b, double tol){
    double fa = f(a);
    double fb = f(b);
    double c = (a*fb-b*fa)/(fb-fa);
    int iter = 0;
    printf("Iteration %d:\n", iter);
    printf("Interval: [%lf, %lf]\n", a, b);
    printf("Approximation: %lf\n", c);
    printf("Function value at approximation: %lf\n", f(c));

    while (fabs(c-b) > tol && iter<100) { // loop until solution found within tolerance
        //iter++; // increment iteration counter
        double fc = f(c);
        fa = fb;
        fb = fc;
        a=b;
        b=c;
        c = (a*fb-b*fa)/(fb-fa);//a - fa * (b - a) / (fb - fa); // update approximation
        
        printf("\nIteration %d:\n", iter+1);
        printf("Interval: [%lf, %lf]\n", a, b);
        printf("Approximation: %lf\n", c);
        printf("Function value at approximation: %lf\n", f(c));
        iter++;
    }
    return c;
}


int main() {
    double a = 0.3; // left endpoint of interval
    double b = 1; // right endpoint of interval
    double tol = 1e-6; // tolerance for convergence
    double root = secant(a, b, tol);
    
    if (!isnan(root)) { // check if root is not NaN
        printf("\nApproximate root: %lf\n", root);
        printf("f(%lf) = %lf\n", root, f(root));
    }
    
    return 0;
}