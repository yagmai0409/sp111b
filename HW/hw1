#include <stdio.h>

double integrate(double (*f)(double), double a, double b) {
    int n = 1000000;
    double h = (b - a) / n;  
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h; 
        sum += f(x) * h;  
    }
    return sum;
}
double square(double x) {
    return x * x;
}

int main() {
    printf("integrate(square, 0.0, 2.0) = %f\n", integrate(square, 0.0, 2.0));
    return 0;
}
