
#include<stdio.h>

int main(){
    float tinggi, berat, BMI;
    char perempuan, laki_laki;
    int menu;

    printf("Menu\n");
    printf("1. Perempuan\n");
    printf("2. Laki-laki\n");
    printf("Pilih menu : ");
    scanf("%d", &menu); 

    if (menu==1){
        printf("Masukkan tinggi (cm): ");
        scanf("%f", &tinggi);
        printf("Masukkan berat : ");
        scanf("%f", &berat);

        tinggi=tinggi/100;
        BMI=berat/(tinggi*tinggi);
        printf("BMI : %.1f \n",BMI);
        if (BMI>=18 && BMI<25){
            printf("Berat badan anda ideal");
        }
        else{
            printf("Berat badan anda tidak ideal");
        }
    }
    else if (menu==2){
        printf("Masukkan tinggi (cm): ");
        scanf("%f", &tinggi);
        printf("Masukkan berat : ");
        scanf("%f", &berat);

        tinggi=tinggi/100;
        BMI=berat/(tinggi*tinggi);
        printf("BMI : %.1f \n",BMI);
        if (BMI>=18 && BMI<25){
            printf("Berat badan anda ideal");
        }
        else{
            printf("Berat badan anda tidak ideal");
        }
    }
    else {
        printf("Inputan salah!");
    }
    return 0;

}
