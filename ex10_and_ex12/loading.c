#include <stdio.h>
#include <stdint.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

enum LabStage {
    STAGE_FOR,
    STAGE_WHILE,
    STAGE_DO_WHILE,
    STAGE_DONE
};

enum LabFlag {
    FLAG_TYPES   = 1u << 0,
    FLAG_ARRAYS  = 1u << 1,
    FLAG_BITS    = 1u << 2,
    FLAG_FOR     = 1u << 3,
    FLAG_WHILE   = 1u << 4,
    FLAG_DO      = 1u << 5
};

static void print_progress(const char *stage, unsigned percent);
static void print_flags(unsigned completed);
static double highres_seconds(void);

int main() {
    enum LabStage stage = STAGE_FOR;
    unsigned completed = 0;
    const uint64_t LOAD_SIZE = 1000000000; 
    uint64_t checksum = 0;
    
    time_t wall_start = time(NULL);
    clock_t cpu_start = clock();
    double hi_start = highres_seconds();

    while (stage != STAGE_DONE) {
        switch (stage) {
            case STAGE_FOR: {
                completed |= FLAG_TYPES | FLAG_ARRAYS;
                uint64_t local_sum = 0;
                
                for (uint64_t i = 0; i < LOAD_SIZE; i++) {
                    local_sum ^= (i + 1337); 
                    local_sum += (i * 31);
                    
                    if (i % (LOAD_SIZE / 100) == 0) {
                        print_progress("FOR", (unsigned)(i * 100 / LOAD_SIZE));
                    }
                }
                checksum += local_sum; 
                completed |= FLAG_FOR;
                stage = STAGE_WHILE; 
                printf("\n"); 
                break;
            }
            case STAGE_WHILE: 
            {
                uint64_t local_sum = 0;
                uint64_t i = 0;

                while (i < LOAD_SIZE) 
                {
                    local_sum ^= (i + 1337);
                    local_sum += (i * 31);
                    
                    if (i % (LOAD_SIZE / 100) == 0) 
                    {
                        print_progress("WHILE", (unsigned)(i * 100 / LOAD_SIZE));
                    }
                    i++;
                }
                checksum += local_sum;
                completed |= FLAG_WHILE;
                stage = STAGE_DO_WHILE;
                printf("\n");
                break;
            }
            case STAGE_DO_WHILE: 
            {
                uint64_t local_sum = 0;
                uint64_t i = 0;

                do 
                {
                    local_sum ^= (i + 1337);
                    local_sum += (i * 31);
                    
                    if (i % (LOAD_SIZE / 100) == 0) 
                    {
                        print_progress("DO_WHILE", (unsigned)(i * 100 / LOAD_SIZE));
                    }
                    i++;
                } 
                while (i < LOAD_SIZE);
                
                checksum += local_sum;
                completed |= FLAG_DO | FLAG_BITS;
                stage = STAGE_DONE;
                printf("\n");
                break;
            }
            case STAGE_DONE:
                break; 
        }
    }
    time_t wall_end = time(NULL);
    clock_t cpu_end = clock();

    printf("\n=== FINAL RESULTS ===\n");
    printf("Checksum: %llu\n", (unsigned long long)checksum);
    
    /* 10.4. Вывод маски флагов */
    print_flags(completed);
    
    unsigned required_flags = FLAG_TYPES | FLAG_ARRAYS | FLAG_BITS | FLAG_FOR | FLAG_WHILE | FLAG_DO;
    if ((completed & required_flags) == required_flags) 
    {
        printf("All required flags are set! Success.\n");
    } else 
    {
        printf("Error: some flags are missing.\n");
    }

    printf("time/difftime: %.0f s\n", difftime(wall_end, wall_start));

    double cpu_seconds = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC;
    printf("clock: %.6f s\n", cpu_seconds);

    double hi_end = highres_seconds();
    printf("high-resolution time: %.6f s\n", hi_end - hi_start);

    return 0;
}

static void print_progress(const char *stage, unsigned percent) 
{
    const unsigned width = 30;
    unsigned filled = percent * width / 100;

    printf("\r%-12s [", stage);
    for (unsigned i = 0; i < width; ++i) {
        putchar(i < filled ? '#' : '-');
    }
    printf("] %3u%%", percent);
    fflush(stdout);
}

/* Вывода флагов в hex и bin */ 
static void print_flags(unsigned completed) 
{
    printf("\nCompleted mask: 0x%02X | Binary: ", completed);
    for (int bit = 7; bit >= 0; --bit) 
    {
        putchar((completed & (1u << bit)) ? '1' : '0');
    }
    printf("\n");
}

static double highres_seconds(void) {
#ifdef _WIN32
    LARGE_INTEGER counter, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)frequency.QuadPart;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
#endif
}