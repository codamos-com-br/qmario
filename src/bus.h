#ifndef _bus_h_
#define _bus_h_

#include <stdint.h>

typedef struct {
    uint8_t mem[0xFFFF];
} Bus;

uint8_t bus_read(Bus *b, uint16_t addr);
void bus_write(Bus *b, uint16_t addr, uint8_t value);

#endif

