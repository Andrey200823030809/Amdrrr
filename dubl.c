#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE *f, *g;
    double a[1000], x;
    int n = 0, i, povtor;

    f = fopen("input.txt", "r");
    g = fopen("output.txt", "w");

    while (fscanf(f, "%lf", &x) == 1) {
        povtor = 0;
        for (i = 0; i < n; i++)
            if (fabs(a[i] - x) < 1e-9)
                povtor = 1;
        if (povtor == 0) {
            a[n] = x;
            n++;
            fprintf(g, "%lf ", x);
        }
    }

    fclose(f);
    fclose(g);
    return 0;
}
