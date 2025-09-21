#include "i2c.h"
#include "timer.h"

void Config_I2C(){
//	GPIO_InitTypeDef GPIO_InitStruct;
	I2C_InitTypeDef I2C_InitStruct;
	 
	// Bat clock
	RCC -> APB2ENR |= 0x0008; // Bat clock cho GPIOB (bit 3)
	RCC -> APB1ENR |= (1 << 21); //Bat clock cho I2C1 (bit 21)
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	// Cau hình PB6, PB7 là Alternate Function output Open-Drain
	GPIOB -> CRL |= 0xFF000000;
	
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStruct);

	// Cau hình I2C1
	I2C_InitStruct.I2C_ClockSpeed = 100000;      // Toc do truyen 100kHz
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;			 // Che do I2C
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2; // Thigh = Tlow
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;       // STM32 làm master, day la dia chi chinh khi stm lam slave nen ko quan trong
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;		 // Bat ACK: tin hieu xac nhan sau moi byte truyen
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // Che do dia chi 7 bit 
	I2C_Init(I2C1, &I2C_InitStruct);

	//Enable I2C1
	I2C_Cmd(I2C1, ENABLE);
}

void I2C_WriteByte(uint8_t address, uint8_t data){
	// Send START
  I2C_GenerateSTART(I2C1, ENABLE);

  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)); // ktra co SB = 1 xac nhan start thanh cong
  I2C_Send7bitAddress(I2C1, address, I2C_Direction_Transmitter); // gui 7 bit dia chi va 1 bit ghi (W = 0)

  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); // Cho gui xong

  I2C_SendData(I2C1,data); // Gui du lieu cho I2C1
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); // Cho gui xong du lieu, du lieu da duoc nap vao DR
	
	I2C_GenerateSTOP(I2C1, ENABLE);
}
