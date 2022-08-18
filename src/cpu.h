#ifndef _cpu_h_
#define _cpu_h_

#include "bus.h"
#include <stdint.h>

// @see https://www.pagetable.com/c64ref/6502/ for reference

typedef struct {
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t sp;
    uint8_t st;
    uint16_t pc;
} Cpu;

/*
 * Resets the 'cpu' registers
 */
void cpu_reset(Cpu *cpu, Bus *b);

/*
 * Runs the next OpCode.
 *
 * Modifies the registers of 'cpu' and returns
 * the number of cycles spent during this execution.
 *
 * This function may write to the 'bus' using the
 * bus_write() function.
 */
uint8_t cpu_tick(Cpu *cpu, Bus *b);

#endif

