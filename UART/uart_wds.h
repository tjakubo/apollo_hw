#define UART_BAUD 115200
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)

#define UART_DE_PORT PORTD
#define UART_DE_DIR DDRD
#define UART_DE_BIT (1<<PD2)

#define UART_DE_ODBIERANIE  UART_DE_PORT |= UART_DE_BIT
#define UART_DE_NADAWANIE  UART_DE_PORT &= ~UART_DE_BIT



#define UART_RX_BUF_SIZE 8
#define UART_RX_BUF_MASK ( UART_RX_BUF_SIZE - 1)

#define UART_TX_BUF_SIZE 8
#define UART_TX_BUF_MASK ( UART_TX_BUF_SIZE - 1)


volatile char UART_RxBuf[UART_RX_BUF_SIZE];
volatile uint8_t UART_RxHead;
volatile uint8_t UART_RxTail;


volatile char UART_TxBuf[UART_TX_BUF_SIZE];
volatile uint8_t UART_TxHead;
volatile uint8_t UART_TxTail;

void USART_Init( uint16_t baud );

char uart_getc(void);
void uart_putc(char data);
void uart_puts(char *s);
void uart_putint(int value, int radix);
