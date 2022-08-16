#include "bus.h"

uint8_t bus_read(Bus *b, uint16_t addr)
{
    return b->mem[addr];
}

void bus_write(Bus *b, uint16_t addr, uint8_t value)
{
    b->mem[addr] = value;
}

