#include "cpu.h"
#include "bus.h"

#include <assert.h>

void test_cpu_reset(void)
{
    Cpu cpu = { 0xFF };
    Bus bus = { 0 };

    cpu_reset(&cpu, &bus);

    assert(cpu.a == 0);
    assert(cpu.x == 0);
    assert(cpu.y == 0);
    assert(cpu.sp == 0xFF);
    assert(cpu.st == 0x30);
    assert(cpu.pc == 0x0600);
}

void test_cpu_tick_lda(void)
{
    Cpu cpu = { 0 };
    Bus bus = { 0 };
    int cycles = 0;

    bus_write(&bus, 0x0600, 0xA9);
    bus_write(&bus, 0x0601, 0xAA);

    cpu_reset(&cpu, &bus);
    cycles += cpu_tick(&cpu, &bus);

    assert(cpu.pc == 0x0602);
    assert(cpu.a == 0xAA);
    assert(cycles == 2);
}

int main(void)
{
    test_cpu_reset();
    test_cpu_tick_lda();
}

