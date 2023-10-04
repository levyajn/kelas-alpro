#include <stdio.h>
int main(){
    int n1,n2;
    printf("\n Masukkan  Angka:\n");
    scanf("%d\n%d",&n1,&n2);
    while (n1!=n2)
    {
         if(n1 > n2)
    {
         n1=n1-n2;

    }
         else
    {
         n2=n2-n1;
    }


    }
    printf("\n GCD: %d" , n1, n2);
    return 0;
}
