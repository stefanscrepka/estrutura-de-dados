#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");
    printf("Exercício 8: Aritmética de Ponteiros\n\n");
 
    int array[5];
    int *ptr = array;  

    printf("1. Digite 5 números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("   array[%d]: ", i);
        scanf("%d", (ptr + i));  
    }
    printf("\n");

    printf("2. Dobro de cada valor (usando *(ptr + i)):\n");
    for (int i = 0; i < 5; i++) {
        printf("   *(ptr+%d) = %d  =>  dobro = %d\n",
               i, *(ptr + i), *(ptr + i) * 2);
    }

    system("pause");
    return 0;
}
