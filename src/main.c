#include "cpu.h"
#include "bus.h"

#include <stdio.h>

int main(void)
{
    Cpu cpu = { 0 };
    Bus bus = { 0 };
    int cycles = 0;

    cpu_reset(&cpu, &bus);
    while(1) {
        cycles += cpu_tick(&cpu, &bus);
    }

    printf("CPU exited after %d cycles", cycles);

    return 0;
}

