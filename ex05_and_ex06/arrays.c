#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /* 5. Массивы и «каша памяти» */
    char chars[304];
    int integers[25];
    double reals[25];

    for (int i = 0; i < 304; i++) 
        chars[i] = 'A' + (i % 26);

    for (int i = 0; i < 25; i++) 
    {
        integers[i] = i + 10;       
        reals[i] = i * 1.5;
    }
    
    /*Вывод*/
    printf("\nChars (first 30):\n");
    for (int i = 0; i < 30; i++) { 
        printf("%c ", chars[i]);
        if ((i + 1) % 10 == 0) 
            printf("\n");
    }

    printf("sizeof(chars) = %zu\n", sizeof(chars));
    printf("sizeof(chars[0]) = %zu\n", sizeof(chars[0]));
    printf("Count = %zu\n", sizeof(chars) / sizeof(chars[0]));

    printf("Integers (first 5):\n");
    for (int i = 0; i < 5; i++) 
        printf("%d\n", integers[i]);
        
    printf("sizeof(integers) = %zu\n", sizeof(integers));
    printf("sizeof(integers[0]) = %zu\n", sizeof(integers[0]));
    printf("Count = %zu\n", sizeof(integers) / sizeof(integers[0]));

    printf("\nReals (first 5):\n");
    for (int i = 0; i < 5; i++) 
        printf("%.1f\n", reals[i]);

    printf("sizeof(reals) = %zu\n", sizeof(reals));
    printf("sizeof(reals[0]) = %zu\n", sizeof(reals[0]));
    printf("Count = %zu\n", sizeof(reals) / sizeof(reals[0]));


    /*6. Одинаковые символы в разных целочисленных типах */
    char a[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    short b[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    int c[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    unsigned long long d[] = {'M', 'A', 'I', '3', '0', '4', '\0'};

    /* Вывод %c */
    printf("Print with %%c\n");
    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("%c", (char)a[i]);
    }
    printf("\nsizeof(a) = %zu\n", sizeof(a));

    for (size_t i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        printf("%c", (char)b[i]);
    }
    printf("\nsizeof(b) = %zu\n", sizeof(b));

    for (size_t i = 0; i < sizeof(c) / sizeof(c[0]); ++i) {
        printf("%c", (char)c[i]);
    }
    printf("\nsizeof(c) = %zu\n", sizeof(c));

    for (size_t i = 0; i < sizeof(d) / sizeof(d[0]); ++i) {
        printf("%c", (char)d[i]);
    }
    printf("\nsizeof(d) = %zu\n", sizeof(d));


    /* Вывод %s */
    printf("\nPrint with %%s\n");
    
    printf("a: %s\n", a);
    printf("b: %s\n", (char*)b);
    printf("c: %s\n", (char*)c);
    printf("d: %s\n", (char*)d);
    return 0;
}