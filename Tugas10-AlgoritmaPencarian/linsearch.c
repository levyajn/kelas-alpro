#include<stdio.h>
#define SIZE 1000
#include<time.h>

size_t linearSearch(const int array[], int key, size_t size);

int main(void){
    int a[SIZE];


    for (size_t x = 0; x < SIZE; ++x){
        a[x] = 2 * x + 1;
    }

    printf("Enter integer search key: ");
    int searchKEy;
    scanf("%d", &searchKEy);

    

    clock_t begin = clock();
    size_t index = linearSearch(a, searchKEy, SIZE);
    clock_t end = clock();

    if (index != -1){
        printf("Found value at index %ld\n", index);
    }
    else{
        puts("Value not found");
    }

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Waktu yang didapat adalah %f detik\n\n", time_spent);
}

    size_t linearSearch(const int array[], int key, size_t size){
        for (size_t n = 0; n < size; ++n){
            if (array[n] == key){
                return n;
            }
        }
        return -1;
    }