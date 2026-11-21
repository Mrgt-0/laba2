#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    // 4.1. sizeof и диапазоны
    printf("=== sizeof ===\n");
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(signed char) = %zu\n", sizeof(signed char));
    printf("sizeof(unsigned char) = %zu\n", sizeof(unsigned char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(unsigned short) = %zu\n", sizeof(unsigned short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(unsigned int) = %zu\n", sizeof(unsigned int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(unsigned long) = %zu\n", sizeof(unsigned long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));
    printf("sizeof(unsigned long long)= %zu\n", sizeof(unsigned long long));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(long double) = %zu\n", sizeof(long double));
    printf("sizeof(void *) = %zu\n", sizeof(void *));
    printf("sizeof(uint8_t) = %zu\n", sizeof(uint8_t));
    printf("sizeof(uint16_t) = %zu\n", sizeof(uint16_t));
    printf("sizeof(uint32_t) = %zu\n", sizeof(uint32_t));
    printf("sizeof(uint64_t) = %zu\n", sizeof(uint64_t));

    printf("\n=== limits.h ===\n");
    printf("CHAR_MIN = %d, CHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX);
    printf("SHRT_MIN = %d, SHRT_MAX = %d\n", SHRT_MIN, SHRT_MAX);
    printf("INT_MIN  = %d, INT_MAX  = %d\n", INT_MIN, INT_MAX);
    printf("LONG_MIN = %ld, LONG_MAX = %ld\n", LONG_MIN, LONG_MAX);
    printf("LLONG_MIN = %lld, LLONG_MAX = %lld\n", LLONG_MIN, LLONG_MAX);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

    printf("\n=== stdint.h ===\n");
    printf("INT8_MAX = %d\n", INT8_MAX);
    printf("INT16_MAX = %d\n", INT16_MAX);
    printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT64_MAX = %lld\n", (long long)INT64_MAX);
    
    printf("UINT8_MAX  = %u\n", UINT8_MAX);
    printf("UINT16_MAX = %u\n", UINT16_MAX);
    printf("UINT32_MAX = %u\n", UINT32_MAX);
    printf("UINT64_MAX = %llu\n", (unsigned long long)UINT64_MAX);
    

    printf("C standart: %ld\n", __STDC_VERSION__);
    /*4.2. Одно число - несколько записей */ 
    int a = 304;      /* decimal  */
    int b = 0460;     /* octal    */
    int c = 0x130;    /* hex      */
    int d = 0b100110000;


    /* проверка равенства */ 
    printf("a == b ? %s\n", (a == b) ? "yes" : "no");
    printf("a == c ? %s\n", (a == c) ? "yes" : "no");
    printf("a == d ? %s\n", (a == d) ? "yes" : "no");

    /* вывод каждого через разные форматы */ 
    printf("a: dec=%d oct=%o hex=%X\n", a, a, a);
    printf("b: dec=%d oct=%o hex=%X\n", b, b, b);
    printf("c: dec=%d oct=%o hex=%X\n", c, c, c);
    printf("d: dec=%d oct=%o hex=%X\n", d, d, d);

    printf("=== Power 2 ===\n");
    int p = 1;
    for (int n = 0; n <= 20; n++) {
        printf("2^%d = %d\n", n, p);
        p *= 2;
    }

    unsigned long long p32 = 1;
    for (int i = 0; i < 32; i++) 
        p32 = p32 * 2;
    printf("2^32 = %llu\n", p32);

    unsigned long long p48 = 1;
    for (int i = 0; i < 48; i++) 
        p48 = p48 * 2;
    printf("2^48 = %llu\n", p48);

    /* 2^64 не помещается в uint64_t (макс. 2^64-1). */ 
    printf("2^64 = 2^64 (overflow for uint64_t; max = 2^64-1 = %llu)\n", UINT64_MAX);

    /* Единицы объёма */
    printf("\n=== Units ===\n");
    unsigned long long bit = 1;
    unsigned long long byte = 8 * bit;
    unsigned long long kib = 1024 * byte; 
    unsigned long long mib = 1024 * kib;
    unsigned long long gib = 1024 * mib; 

    printf("1 byte = %llu bits\n", byte);
    printf("1 KiB  = %llu bytes\n", kib);
    printf("1 MiB  = %llu bytes (or %llu KiB)\n", mib, mib / kib);
    printf("1 GiB  = %llu bytes (or %llu MiB)\n", gib, gib / mib);

    return 0;
}