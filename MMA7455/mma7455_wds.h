#include <avr/io.h>

// ADRES I2C UKLADU
#define ACC_ADDR (0x1d << 1)

// ADRES REJESTRU TRYBU UKLADU + BITY
#define MODE_ADDR 0x16
#define MODE0 (1<<0)
#define MODE1 (1<<1)
#define GLVL0 (1<<2)
#define GLVL1 (1<<3)

// ADRESY REJESTROW KALIBRACJI
#define X_CAL_ADDR 0x10
#define Y_CAL_ADDR 0x12
#define Z_CAL_ADDR 0x14

// ADRESY WARTOSCI DO POMIARU
#define X_8b_ADDR 0x06
#define Y_8b_ADDR 0x07
#define Z_8b_ADDR 0x08

// WARTOSCI DOMYSLNEJ KALIBRACJI
#define X_CAL_DEF 0x4e
#define Y_CAL_DEF 0x76
#define Z_CAL_DEF 0x12

// STRUKTURY NA POMIARY
typedef struct
{
	int8_t x, y, z;
} meas_8b;

void mma_wds_init();
meas_8b mma_measure8b();
void mma_cal_default();
void mma_cal_cust(int16_t *cal);

