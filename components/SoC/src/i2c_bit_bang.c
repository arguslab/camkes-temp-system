/*------------------------------------------------------------------------------
* i2c_bb.c
*
*-----------------------------------------------------------------------------*/
#include <camkes.h>

#include <local_soc.h>

#include <platsupport/i2c.h>
#include <platsupport/plat/i2c.h>
#include <sel4utils/util.h>

struct i2c_bb i2c_bb;
struct i2c_bus i2c_bus;
int addr; //Temporary since i2c_bitbang only implements start read and start write

void i2c_bit_bang__init()
{
    //i2c_bb_init(&gpio_driver, /*scl*/ 66, /*sda*/ 67, &i2c_bb, &i2c_bus);
    i2c_bb_init(&gpio_driver, 13, 12, &i2c_bb, &i2c_bus);
}

int i2c_bit_bang_set_speed(int bps)
{
    return 0;
}

int i2c_bit_bang_probe_aas()
{
    return 0;
}

i2c_data_t i2c_bit_bang_read(int size)
{
    i2c_data_t ret;
    ret.len = i2c_bus.start_read(&i2c_bus, addr, (void *)&ret.buf, size, NULL, NULL);
    return ret;
}


int i2c_bit_bang_write(i2c_data_t data)
{
    return i2c_bus.start_write(&i2c_bus, addr, &data.buf, data.len, NULL, NULL);
}

i2c_scan_addr_t i2c_bit_bang_scan(int start, int naddr)
{
    i2c_scan_addr_t ret;

    return ret;
}

void i2c_bit_bang_set_address(int a)
{
    addr = a;
    //int ret = i2c_set_address(&i2c_bus, addr, NULL, NULL);
}
