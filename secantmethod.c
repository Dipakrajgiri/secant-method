#include <stdio.h>
#include <math.h>

// The function for which we want to find the root
double function(double x) 
{
    return x * x - 4;  // Example function: f(x) = x^2 - 4
}

// Secant method to find the root of a function
double secantMethod(double x0, double x1, double tolerance) 
{
    double x2, f0, f1, f2;
    int iteration = 0;
    
    do {
        f0 = function(x0);
        f1 = function(x1);
        
        if (f1 - f0 == 0.0) {
            printf("Division by zero, secant method failed.\n");
            return NAN;
        }
        
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = function(x2);
        
        x0 = x1;
        x1 = x2;
        
        iteration++;
        
        printf("Iteration %d: Root = %lf, f(root) = %lf\n", iteration, x2, f2);
        
    } 
	while (fabs(f2) > tolerance && iteration < 1000);  // Limit iterations to prevent infinite loop
    
    return x2;
}

int main() {
    double x0, x1, tolerance, root;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter second guess x1: ");
    scanf("%lf", &x1);

    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);

    root = secantMethod(x0, x1, tolerance);

    if (!isnan(root)) {
        printf("\nApproximate root: %lf\n", root);
    }

    return 0;
}
