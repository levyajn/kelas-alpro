#include<stdio.h>
 int main (){
    int nilai1,nilai2,i;

    printf("Masukkan angka : ");
    scanf("%d %d", &nilai1, &nilai2);

    if (nilai1>0 && nilai2>0){
        for (i=nilai1;i>0;i--){
            if(nilai1%i==0 && nilai2%i==0){
                printf("GCD : %d", i);
                break;
                }

            
            }
    }
    else{
    printf("Nilai input salah");
    }
        return 0;
    }
