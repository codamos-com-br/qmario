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
}

int main(void)
{
    test_cpu_reset();
    test_cpu_tick_lda();
}

