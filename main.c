#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#include "LCD/lcd44780.h"
#include "I2C_TWI/i2c_twi.h"
#include "MMA7455/mma7455_wds.h"
#include "MKUART/mkuart.h"

int main(void) {

	// podswietlenie LCD
	DDRA |= (1<<PA7);
	PORTA |= (1<<PA7);

	//lcd_init();
	i2cSetBitrate( 125 ); // 125kHz na magistrali
	mma_wds_init();
	USART_Init( __UBRR );
	sei();
	while(1)
	{
		//lcd_cls();
		meas_8b meas = mma_measure8b();
		char out[30];
		sprintf(out, "X:%4d Y:%4d Z:%4d \r\n", meas.x, meas.y, meas.z);
		uart_puts(out);
		//uart_puts("X:"); uart_putint(meas.x, 10);
		//uart_puts(" Y:"); uart_putint(meas.y, 10);
		//uart_puts(" Z:"); uart_putint(meas.z, 10);
		//uart_puts("\r \n");
		_delay_ms(100);
	}

}
