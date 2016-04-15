#include "mma7455_wds.h"
#include "../I2C_TWI/i2c_twi.h"

void mma_wds_init()
{
	uint8_t meas_2g_mode = MODE0 | GLVL0;
	TWI_write_byte(ACC_ADDR, MODE_ADDR, meas_2g_mode);
	mma_cal_default();

	return;
}

meas_8b mma_measure8b()
{
	meas_8b measure;
	TWI_read_byte(ACC_ADDR, X_8b_ADDR, &(measure.x));
	TWI_read_byte(ACC_ADDR, Y_8b_ADDR, &(measure.y));
	TWI_read_byte(ACC_ADDR, Z_8b_ADDR, &(measure.z));
	return measure;
}

void mma_cal_default()
{
	TWI_write_byte(ACC_ADDR, X_CAL_ADDR, X_CAL_DEF);
	TWI_write_byte(ACC_ADDR, Y_CAL_ADDR, Y_CAL_DEF);
	TWI_write_byte(ACC_ADDR, Z_CAL_ADDR, Z_CAL_DEF);
	return;
}
void mma_cal_cust(int16_t *cal){ return; }
