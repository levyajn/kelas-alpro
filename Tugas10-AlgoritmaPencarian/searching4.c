#include <stdio.h>

#define SIZE 100
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
int main(){
    int a[SIZE];
    int LOW=0;
    int HIGH=100;
    for (size_t x = 0; x < SIZE; ++x)
    {
        a[x] = x;
    }
    printf("Enter integer search key: ");
    int searchKey;
    scanf("%d", &searchKey);

    size_t index = binarySearch(a, searchKey, LOW, HIGH);
    if (index != -1)
    {
        printf("Found value at index %d\n", index);
    }
    else
    {
        puts("Value not found");
    }
}

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high){
    while (low <= high)
    {
        size_t middle = (low+high)/2;
        if (searchKey == b[middle])
        {
            return middle;
        }else if(searchKey<b[middle]){
            high = middle - 1;
        }else{
            low = middle + 1;
        }
    }
    return -1;
}