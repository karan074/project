#include <stdio.h>

float f(float x, float y) {
    return x * y * y; // The derivative function f(x, y) = xy^2
}
int main() {
    float x0 = 0, y0 = 1, h = 0.1; // Initial conditions and step size
    int n, i;
    float x, y;
    // Prompt for number of steps
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    x = x0;
    y = y0;

    printf("\nStep\t x\t\t y\n");
    printf("-----------------------------\n");
    printf("0\t %.8f\t %.8f\n", x, y);

    // Euler's method iteration
    for (i = 1; i <= n; i++) {
        y = y + h * f(x, y); // Update y using Euler's method
        x = x + h;           // Increment x by step size

        printf("%d\t %.8f\t %.8f\n", i, x, y);
    }
    return 0;
}