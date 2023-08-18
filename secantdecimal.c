#include <stdio.h>
#include <math.h>

double function(double x) 
{
    return x * x - 4;  
}

double secantMethod(double x0, double x1) 
{
    double x2,a1,b1, f0, f1, f2,prev;
    int a,b, iteration = 0;
    prev=x1;
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
        a=x2*1000;
        b=prev*1000;
        prev=x2;
        
    } 
	while (!(a==b));  
    return x2;
}

int main() {
    double x0, x1, root;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter second guess x1: ");
    scanf("%lf", &x1);

    

    root = secantMethod(x0, x1);

    if (!isnan(root)) {
        printf("\nApproximate root: %lf\n", root);
    }

    return 0;
}
