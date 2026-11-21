#include <stdio.h>

int main(void)
{
    #ifdef __STDC_VERSION__
        printf("__STDC_VERSION__ = %ld\n", (long)__STDC_VERSION__);
    #else
        printf("__STDC_VERSION__ is not defined\n");
    #endif

    _Static_assert(sizeof(int) == 4, "Размер int должен быть 4 байта");

    for (int i = 0; i < 10; i++)
    {
        // some comment
    }
    
    auto bin = 0b100110000;
    auto x = 304;
    printf("bin = %d, x = %d\n", bin, x);

    return 0;
}
