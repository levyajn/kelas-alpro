#include <stdio.h>
#include <string.h>


int calcnilai(int tugas, int quiz, int UTS, int UAS) {
    return (0.1 * tugas) + (0.2 * quiz) + (0.3 * UTS) + (0.4 * UAS);
}

void displaynilaiakhir(char *nama, char *nim, int nilaiakhir) {
    char *hurufmutu;
    char *keterangan;

    if (nilaiakhir > 90) {
        strcpy (hurufmutu, "A");
        keterangan = "Lulus";
    } else if (81 <= nilaiakhir && nilaiakhir <= 90) {
        strcpy (hurufmutu, "AB");
        keterangan = "Lulus";
    } else if (71 <= nilaiakhir && nilaiakhir <= 80) {
        strcpy (hurufmutu, "B");
        keterangan = "Lulus";
    } else if (61 <= nilaiakhir && nilaiakhir <= 70) {
        strcpy (hurufmutu, "BC");
        keterangan = "Lulus";
    } else if (51 <= nilaiakhir && nilaiakhir <= 60) {
        strcpy (hurufmutu, "C");
        keterangan = "Lulus";
    } else if (45 <= nilaiakhir && nilaiakhir <= 50) {
        strcpy (hurufmutu, "D");
        keterangan = "Tidak Lulus";
    } else if (nilaiakhir < 45) {
        strcpy (hurufmutu, "E");
        keterangan = "Tidak Lulus";
    }

    printf("Nama Mahasiswa : %s\n", nama);
    printf("NIM : %s\n", nim);
    printf("Nilai Akhir : %d\n", nilaiakhir);
    printf("Huruf Mutu : %s\n", hurufmutu);
    printf("Keterangan : %s\n", keterangan);
}

int main() {
    char nama[50];
    char nim[20];
    int tugas, quiz, UTS, UAS;

   
    printf("Nama Mahasiswa : "); scanf("%s", &nama);
    printf("NIM : "); scanf("%s", &nim);
    printf("Nilai Tugas : "); scanf("%d", &tugas);
    printf("Nilai Quiz : "); scanf("%d", &quiz);
    printf("Nilai UTS : "); scanf("%d", &UTS);
    printf("Nilai UAS  : "); scanf("%d", &UAS);
    printf("\n");

   
    int nilaiakhir = calcnilai(tugas, quiz, UTS, UAS);

    displaynilaiakhir(nama, nim, nilaiakhir);

    return 0;
}