#include <stdio.h>
#include "device.h"

int main()
{
    device_tick();
    printf("Global runs: %lu\n", global_runs);

    auto int local_value = 304;
    printf("local_value = %d\n", local_value);
    
    auto inferred_value = 304; 
    printf("inferred_value = %d\n", inferred_value);
    
    return 0;
}