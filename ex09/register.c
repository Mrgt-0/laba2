#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>

enum RegisterBit 
{
    REG_POWER = 1u << 0,
    REG_READY = 1u << 1,
    REG_ERROR = 1u << 2,
    REG_TX = 1u << 3,
    REG_RX = 1u << 4
};

static void print_binary8(uint8_t value)
{
    for (int bit = 7; bit >= 0; --bit) 
    {
        putchar((value & (1u << bit)) ? '1' : '0');
    }
}


void print_reg(char* action, uint8_t reg) 
{
    printf("%-25s Dec: %3d | Hex: 0x%02X | Bin: ", action, reg, reg);
    print_binary8(reg);
    printf("\n");
}

int main()
{
    uint8_t reg = 0;

    /* Установить бит */ 
    reg |= REG_POWER; 
    print_reg("Set POWER:", reg);

    /* Установить еще один бит */ 
    reg |= REG_READY;
    print_reg("Set READY:", reg);

    /* Переключить бит */
    reg ^= REG_TX;
    print_reg("Toggle TX (ON):", reg);

    /* Проверить бит  */ 
    if ((reg & REG_TX) != 0) {
        printf("Check TX: TX is ON!\n");
    }

    /* Сформировать маску как 1u << n  */ 
    int n = 5;
    uint8_t mask = 1u << n; 
    /* Проверка, установлен ли 5-й бит */
    if ((reg & mask) != 0) {
        printf("Bit %d is ON\n", n);
    } else {
        printf("Bit %d is OFF\n", n);
    }
    
    /* Сбросить бит */
    reg &= ~REG_POWER;
    print_reg("Reset POWER:", reg);
}