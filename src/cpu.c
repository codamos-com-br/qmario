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
    uint8_t cycles = 0;
    uint8_t next_op = 0;

    next_op = bus_read(b, cpu->pc++);
    cycles++;

    switch (next_op) {
        case 0xA9:
            cpu->a = bus_read(b, cpu->pc++);
            cycles++;
            break;
    }

    return cycles;
}

