#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "../UART/uart_wds.h"


void USART_Init( uint16_t baud ) {
	UBRRH = (uint8_t)(baud>>8);
	UBRRL = (uint8_t)baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);

	#ifdef UART_DE_PORT
		UART_DE_DIR |= UART_DE_BIT;
		UART_DE_ODBIERANIE;
	#endif

	#ifdef UART_DE_PORT
		UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<TXCIE);
	#else
		UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	#endif
}


#ifdef UART_DE_PORT
ISR( USART_TXC_vect ) {
  UART_DE_PORT &= ~UART_DE_BIT;
}
#endif


void uart_putc( char data ) {
	uint8_t tmp_head;

    tmp_head  = (UART_TxHead + 1) & UART_TX_BUF_MASK;
    while ( tmp_head == UART_TxTail ){}
    UART_TxBuf[tmp_head] = data;
    UART_TxHead = tmp_head;
    UCSRB |= (1<<UDRIE);
}


void uart_puts(char *s)
{
  register char c;
  while ((c = *s++)) uart_putc(c);
}

void uart_putint(int value, int radix)
{
	char string[17];
	itoa(value, string, radix);
	uart_puts(string);
}

ISR( USART_UDRE_vect)  {

    if ( UART_TxHead != UART_TxTail ) {
   	UART_TxTail = (UART_TxTail + 1) & UART_TX_BUF_MASK;
    	UDR = UART_TxBuf[UART_TxTail];
    } else {
	UCSRB &= ~(1<<UDRIE);
    }
}

char uart_getc(void) {

    if ( UART_RxHead == UART_RxTail ) return 0;


    UART_RxTail = (UART_RxTail + 1) & UART_RX_BUF_MASK;

    return UART_RxBuf[UART_RxTail];
}



