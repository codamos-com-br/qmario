#include "cpu.h"

void cpu_reset(Cpu *cpu, Bus *b)
{
    cpu->a = 0x00;
    cpu->x = 0x00;
    cpu->y = 0x00;
    cpu->sp = 0xFF;
    cpu->st = 0x30;
    cpu->pc = 0x0600;
}

uint8_t cpu_tick(Cpu *cpu, Bus *b)
{
    return 0;
}

