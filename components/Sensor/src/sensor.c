/*------------------------------------------------------------------------------
* sensor.c
*
*-----------------------------------------------------------------------------*/


#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

#define CTRL_REG 0xf4

#define BMP180_TMP_READ_CMD 0x2E

#define BMP180_PRE_OSS0_CMD 0x34
#define BMP180_PRE_OSS1_CMD 0x74
#define BMP180_PRE_OSS2_CMD 0xB4
#define BMP180_PRE_OSS3_CMD 0xF4

#define AC1_MSB_REG 0xaa
#define AC1_LSB_REG 0xab
#define AC2_MSB_REG 0xac
#define AC2_LSB_REG 0xad
#define AC3_MSB_REG 0xae
#define AC3_LSB_REG 0xaf
#define AC4_MSB_REG 0xb0
#define AC4_LSB_REG 0xb1
#define AC5_MSB_REG 0xb2
#define AC5_LSB_REG 0xb3
#define AC6_MSB_REG 0xb4
#define AC6_LSB_REG 0xb5
#define B1_MSB_REG 0xb6
#define B1_LSB_REG 0xb7
#define B2_MSB_REG 0xb8
#define B2_LSB_REG 0xb9
#define MB_MSB_REG 0xba
#define MB_LSB_REG 0xbb
#define MC_MSB_REG 0xbc
#define MC_LSB_REG 0xbd
#define MD_MSB_REG 0xbe
#define MD_LSB_REG 0xbf

#define BMP180_REG_TMP 0xF6


#define CAL_COEF_IS_VALID(x) (x != 0x0000 && (uint16_t)x != 0xffff)

struct calibration
{
	int16_t ac1;
	int16_t ac2;
	int16_t ac3;
	uint16_t ac4;
	uint16_t ac5;
	uint16_t ac6;
	int16_t b1;
	int16_t b2;
	int16_t mb;
	int16_t mc;
	int16_t md;
} cal;

static int32_t current_temp = 72;


static uint16_t read_eeprom_reg(unsigned char reg)
{
    static i2c_data_t msg;
    msg.buf[0] = reg;
    msg.len = 1;

    i2c_write(msg);

    msg = i2c_read(2);

    //printf("Sensor: msg len=%i, msg.buf[0]=%i, msg.buf[1]=%i\n", msg.len, msg.buf[0], msg.buf[1]);

    //return ((uint16_t)msg.buf[1] << 8) | (uint16_t)msg.buf[0];
    return ((uint16_t)msg.buf[0] << 8) | (uint16_t)msg.buf[1];
}

static uint16_t read_temp(int delay_ms)
{
    static i2c_data_t msg;
    msg.buf[0] = CTRL_REG;
    msg.buf[1] = BMP180_TMP_READ_CMD;
    msg.len = 2;

    i2c_write(msg);

    timer_sleep_ms(delay_ms);

    return read_eeprom_reg(BMP180_REG_TMP);

    // msg = i2c_read(2);
    //
    // printf("Sensor: msg len=%i, msg.buf[0]=%i, msg.buf[1]=%i\n", msg.len, msg.buf[0], msg.buf[1]);
    //
    // return ((uint16_t)msg.buf[1] << 8) | (uint16_t)msg.buf[0];
}

static void read_calibration()
{
    cal.ac1 = read_eeprom_reg(AC1_MSB_REG);
    cal.ac2 = read_eeprom_reg(AC2_MSB_REG);
    cal.ac3 = read_eeprom_reg(AC3_MSB_REG);
    cal.ac4 = read_eeprom_reg(AC4_MSB_REG);
    cal.ac5 = read_eeprom_reg(AC5_MSB_REG);
    cal.ac6 = read_eeprom_reg(AC6_MSB_REG);
    cal.b1 = read_eeprom_reg(B1_MSB_REG);
    cal.b2 = read_eeprom_reg(B2_MSB_REG);
    cal.mb = read_eeprom_reg(MB_MSB_REG);
    cal.mc = read_eeprom_reg(MC_MSB_REG);
    cal.md = read_eeprom_reg(MD_MSB_REG);

    /* Validate. Data sheet says values should not be 0x0000 nor 0xffff */
	if (!CAL_COEF_IS_VALID(cal.ac1) ||
	    !CAL_COEF_IS_VALID(cal.ac2) ||
	    !CAL_COEF_IS_VALID(cal.ac3) ||
	    !CAL_COEF_IS_VALID(cal.ac4) ||
	    !CAL_COEF_IS_VALID(cal.ac5) ||
	    !CAL_COEF_IS_VALID(cal.ac6) ||
	    !CAL_COEF_IS_VALID(cal.b1) ||
	    !CAL_COEF_IS_VALID(cal.b2) ||
	    !CAL_COEF_IS_VALID(cal.mb) ||
	    !CAL_COEF_IS_VALID(cal.mc) ||
        !CAL_COEF_IS_VALID(cal.md)) {

		printf("Sensor: Invalid calibration data found on chip.\n");
	}
}


int data_read()
{
  return current_temp;
}

int run()
{
    i2c_set_address(0xEE); /* BMP180 Specific */
    read_calibration();

    while(1)
    {
        timer_sleep_s(1);

        uint16_t ut = read_temp(5);

        /* convert uncompensated temperature to true temperature */
    	int32_t x1 = ((ut - cal.ac6) * cal.ac5) / (1 << 15);
    	int32_t x2 = (cal.mc * (1 << 11)) / (x1 + cal.md);
    	int32_t b5 = x1 + x2;
    	current_temp = (b5 + 8) / (1 << 4);

        printf("Sensor: temp=%d.%01d\n", current_temp / 10, current_temp % 10);

    	/* save the result */

        // msg.buf[0] = CTRL_REG;
        // msg.buf[1] = BMP180_TMP_READ_CMD;
        // msg.len = 2;
        // i2c_write(msg);
        // msg = i2c_read(2);




        // if(current_temp >= 90)
        // {
        //     temp_swing = -1;
        // }
        // else if(current_temp <= 60)
        // {
        //     temp_swing = 1;
        // }
        //
        // current_temp += temp_swing;

    }

    return 0;
}
