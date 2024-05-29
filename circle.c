#include <stdio.h>
#include <math.h>

#define RADIUS 5

int main(void) {
    int r = 10;

    for (int y = -r; y <= r; y++) {
        for (int x = -r; x <= r; x++) {
            double d = sqrt(pow(x - 0, 2) + pow(y - 0, 2));
            if (d <= r + 0.5 && d >= r - 0.5) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}