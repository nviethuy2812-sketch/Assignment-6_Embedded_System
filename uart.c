#include "uart.h"

//Ham duoi day de goi printf ra uart
struct __FILE {
    int dummy;
};
FILE __stdout;
//Ham gui 1 ki tu
void uart_SendChar(char _chr){
	USART_SendData(USART1,_chr);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==0); // Doi co TC len 1 la truyen xong
}
 
int fputc(int ch, FILE *f) {
 
    uart_SendChar(ch);
  
    return ch;
}

void uart_Init(void){

	RCC -> APB2ENR |= 0x4004; // Bat bit 2 (GPIOA) va bit 14 (UART1)

	
	GPIOA -> ODR |= (1 << 10); // Pull-up RX-PA10
	GPIOA -> CRH = 0x000008B0; // Cau hinh A9 (AF-PP) A10 (IPU)

	USART1->BRR = 7500;	 // 72MHz/9600bps = 7500
	USART1->CR1 = 0x200C; // Enable UART, TE, RE (chuc nang truyen nhan)

}



//Gui 1 chuoi string
void uart_SendStr(char *str){
	while(*str){
		uart_SendChar(*str++);		
	}
}
