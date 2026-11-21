#include "device.h"
unsigned long global_runs = 0; /* внешняя связь */
static unsigned long internal = 0; /* видима только в device.c */
void device_tick(void)
{
    static unsigned long calls = 0; /* живёт всю программу,
    область видимости локальная */
    ++global_runs;
    ++internal;
    ++calls;
    (void)calls;
}
unsigned long device_internal_calls(void)
{
    return internal;
}