

/* 14.1. Параметризованные макросы и ловушки */
#define BAD_SQUARE(x) x * x
#define GOOD_SQUARE(x) ((x) * (x))

/* 14.2. Stringify, token pasting и условная компиляция */
#define STRINGIFY(x) #x
#define CONCAT(a, b) a##b
#ifdef DEBUG
# define DEBUG_LOG(msg) fprintf(stderr, "DEBUG: %s\n", msg)
#else
# define DEBUG_LOG(msg) ((void)0)
#endif

#include <stdio.h>
#include <stddef.h>

int main()
{
    printf("\n--- 14.1 --- \n");
    printf("BAD_SQUARE(2 + 3) = %d\n", BAD_SQUARE(2 + 3)); 
    printf("GOOD_SQUARE(2 + 3) = %d\n", GOOD_SQUARE(2 + 3));

    int i = 5;
    printf("GOOD_SQUARE(i++) = %d (i = %d)\n", GOOD_SQUARE(i++), i);


    /* 14.2. Stringify, Token pasting и Debug  */
    printf("\n--- 14.2 --- \n");

    printf("Stringify: %s\n", STRINGIFY(304)); 
    int CONCAT(my, variable) = 100; 
    printf("Token pasting: myvariable = %d\n", myvariable);

    DEBUG_LOG("DEBUUUUUG");
}