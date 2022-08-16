#include "bus.h"
#include <assert.h>

void test_bus_read(void)
{
    Bus b = { 0 };
    b.mem[0x0600] = 0xA9;

    assert(bus_read(&b, 0x0600) == 0xA9);
}

void test_bus_write(void)
{
    Bus b = { 0 };

    bus_write(&b, 0x0600, 0xA9);

    assert(b.mem[0x0600] == 0xA9);
}

int main(void)
{
    test_bus_read();
    test_bus_write();
}

