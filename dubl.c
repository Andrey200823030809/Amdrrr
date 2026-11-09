#include <stdio.h>
#include <math.h>

#define MAXN 10000
#define EPS 1e-12

/* Возвращает 1, если x уже есть среди первых n элементов массива a */
int est_li(double *a, int n, double x)
{
    int i;
    for (i = 0; i < n; i++)
        if (fabs(a[i] - x) < EPS)
            return 1;
    return 0;
}

int main(void)
{
    FILE *fin, *fout;
    double a[MAXN];
    double x;
    int n = 0, i;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Ne mogu otkryt input.txt\n");
        return 1;
    }

    /* читаем числа; дубликаты сразу не добавляем */
    while (fscanf(fin, "%lf", &x) == 1) {
        if (!est_li(a, n, x)) {
            if (n >= MAXN) {
                printf("Slishkom mnogo chisel\n");
                fclose(fin);
                return 2;
            }
            a[n] = x;
            n++;
        }
    }
    if (!feof(fin)) {
        printf("V fajle ne chislo\n");
        fclose(fin);
        return 3;
    }
    fclose(fin);

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Ne mogu otkryt output.txt\n");
        return 4;
    }
    for (i = 0; i < n; i++)
        fprintf(fout, "%lf ", a[i]);
    fprintf(fout, "\n");
    fclose(fout);

    printf("Gotovo, ostalos %d chisel\n", n);
    return 0;
}
