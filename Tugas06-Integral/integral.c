
#include <stdio.h>
#include <math.h>

// Fungsi yang akan diintegralkan (fungsi kelompok kami (x+2)^2)
double fungsi(double x) {
    return (x+2)*(x+2);
}

// Metode trapesium untuk menghitung integral
double trapesium(double alas_a, double alas_b, int n) {
    double h = (alas_b - alas_a) / n;
    double integral = (fungsi(alas_a) + fungsi(alas_b)) / 4.0;

    for (int i = 1; i < n; i++) {
        double x = alas_a + i * h;
        integral += fungsi(x);
    }

    return integral * h;
}

int main() {
    double batas_bawah = 0; // Batas bawah
    double batas_atas = 4;  // Batas atas
    int N;

    printf("Masukkan jumlah sub-interval: ");
    scanf("%d", &N);

    double hasilNumerik = trapesium(batas_bawah, batas_atas, N);

    // Perhitungan integral secara analitik 
    double hasilAnalitik = (batas_atas * batas_atas * batas_atas / 3) - (batas_bawah * batas_bawah * batas_bawah / 3);

    printf("Hasil integral metode trapezoid: %lf\n", hasilNumerik);
    printf("Hasil integral analitik : %lf\n", hasilAnalitik);

    return 0;
}
