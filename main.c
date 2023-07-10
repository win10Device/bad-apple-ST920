#include <libu8g2arm/u8g2.h>
#include <libu8g2arm/u8g2arm.h>
#include "temp.c"
u8g2_t u8g2;
int main(void) {
  u8x8_t *p_u8x8 = u8g2_GetU8x8(&u8g2);
  u8g2_Setup_st7920_s_128x64_f(&u8g2, U8G2_R0, u8x8_byte_arm_linux_hw_spi, u8x8_arm_linux_gpio_and_delay);

  if (!u8g2arm_arm_init_hw_spi(p_u8x8, /* bus_number = */ 0, /* cs_number */ 0, /* bus speed */ 4.5)) {
    fprintf(stderr, "could not initialise SPI device");
    exit(1);
  }

  // U8g2 begin
  u8g2_InitDisplay(&u8g2);
  u8g2_ClearDisplay(&u8g2);
  sleep(1);
  for ( int ia = 0; ia < 100; ia++ ) { // play video 1000 times, not needed
    for ( int i = 1; i < 6573; i++ ) { // Every frame of Bad Apple
      char * frame = getFrame(i);
      u8g2_DrawXBMP(&u8g2, 16, 0, 86, 65, frame);
      u8g2_SendBuffer(&u8g2); // transfer internal memory to the display
    }
  }
  sleep(10);
  u8g2_ClearDisplay(&u8g2);
  return 0;
}
