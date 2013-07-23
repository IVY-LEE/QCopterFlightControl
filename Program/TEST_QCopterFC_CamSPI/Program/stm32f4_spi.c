/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_spi.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**��� : SPI_RW
**�\�� : Receive 1Byte Data
**��J : SPIx
**��X : None
**�ϥ� : Read = SPI_RW(SPI1, 0xFF);
**=====================================================================================================*/
/*=====================================================================================================*/
u8 SPI_RW( SPI_TypeDef* SPIx, u8 WriteByte )
{
	while((SPIx->SR & SPI_I2S_FLAG_TXE) == (u16)RESET);
	SPIx->DR = WriteByte;
	while((SPIx->SR & SPI_I2S_FLAG_RXNE) == (u16)RESET);

	return SPIx->DR;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**��� : SPI_WriteByte
**�\�� : Transmit 1Byte Data
**��J : SPIx, WriteByte
**��X : None
**�ϥ� : SPI_WriteByte(SPI1, 0xFF);
**=====================================================================================================*/
/*=====================================================================================================*/
void SPI_WriteByte( SPI_TypeDef* SPIx, u8 WriteByte )
{
  while((SPIx->SR & SPI_I2S_FLAG_TXE) == (u16)RESET);
  SPIx->DR = WriteByte;
  while((SPIx->SR & SPI_I2S_FLAG_RXNE) == (u16)RESET);
  SPIx->DR;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**��� : SPI_ReadByte
**�\�� : Receive 1Byte Data
**��J : SPIx
**��X : None
**�ϥ� : Read = SPI_ReadByte(SPI1);
**=====================================================================================================*/
/*=====================================================================================================*/
u8 SPI_ReadByte( SPI_TypeDef* SPIx )
{
  while((SPIx->SR & SPI_I2S_FLAG_TXE) == (u16)RESET);
  SPIx->DR = 0xFF;
  while((SPIx->SR & SPI_I2S_FLAG_RXNE) == (u16)RESET);

  return SPIx->DR;
}
/*=====================================================================================================*/
/*=====================================================================================================*/