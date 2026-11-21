#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num = 304;
    printf("--- 7.1 ---\n");
    printf("dec=%d, oct=%o, hex=%x\n", num, num, num);
    printf("address: %p\n", (void*)&num);


    printf("\n--- 7.2 ---\n");
    printf("AAA\tBBB\n");
    printf("first\rSECOND\n");
    printf("one\0two\n");
    printf("quote: \"C\" and slash: \\\n");

    printf("--- 7.3 ---\n");
    int number;
    printf("Enter a number: ");
    // Проверяем, что ввели именно число
    if (scanf("%d", &number) != 1) 
        printf("Invalid input!\n");
    else 
        printf("You entered: %d\n\n", number);
        
    return 0;
}