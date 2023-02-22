#include <stdio.h>
#include <math.h>
#define EPSILON 0.001 
double f(double x) {
    return (pow(x,3))-(2*x);
}

double fd(double x){
    return (3*pow(x,2))-2;
}


double newton_rapson(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) { // check if solution exists in bounds
        printf("Error: solution does not exist in the specified interval.\n");
        return NAN;
    }
    int i;
    double c,x,h;
    if(fabs(f(a))<=fabs(f(b))){
        c=a;
    }else{
        a=b;
    }
    //c=(a+b)/2;
    printf("c=%lf\n",c);
    for(i=0;i<10;i++){
        h=(f(c)/fd(c));
        x=c-h;
        if(fabs(h)<tol){
            printf("c = %lf x = %lf final iteration = %d\nf(%lf)=%lf\n\n",c,x,i,c,f(c));
            return x;
        }
        printf("c = %lf x = %lf iteration = %d\nf(%lf)=%lf\n\n",c,x,i,c,f(c));
        c=x;
    }
    //printf("Root = %lf final iteration = %d\n f(%lf)=%lf ",x,i,c,x);
    return x;

}

int main() {
    double a = 1; // left endpoint of interval
    double b = 2; // right endpoint of interval
    double tol = 1e-6; // tolerance for convergence
    double root = newton_rapson(a, b, tol);
    printf("\n%lf %lf\n",f(a),fd(a));
    if (!isnan(root)) { // check if root is not NaN
        printf("\nApproximate root: %lf\n", root);
        printf("f(%lf) = %lf\n", root, f(root));
    }
    
    return 0;
}
