#include <stdio.h>

//(fungsi kelompok kami (x+2)^2)
double fungsi(double x) {
    return (x+2)*(x+2);
}


double trapesium(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (fungsi(a) + fungsi(b)) / 4;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += fungsi(x);
    }

    return integral * h;
}

int main() {
    double batas_bawah = 0; 
    double batas_atas = 4;  
    int N;

    printf("Masukkan nilai intervalnya: ");
    scanf("%d", &N);

    double hasil = trapesium(batas_bawah, batas_atas, N);


    printf("Hasil integral: %lf\n", hasil);

    return 0;
}
