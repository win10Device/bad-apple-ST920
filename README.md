# Bad Apple on a 128x64 ST7920 LCD display, using Raspberry Pi.
This project could be much more efficient, but this is a one off project, and I've gotten rusty with C<br>
You'll need <a href="https://github.com/antiprism/libu8g2arm/">libu8g2arm</a> already compiled on your Raspberry Pi,<br>
You'll also need the g++ package, which can be installed with $ `sudo apt install g++`<br>
To compile the project, be in the same directory as the bad apple files, $ `cc main.c -o program -l:libu8g2arm.a`,
Then to run $ `./program`
<hr>

<h3>WARNING!</h3>
Depending on which 128x64 LCD display you have, you'll have to shift 3.3V logic to 5V logic (Something like <a href="https://www.sparkfun.com/products/12009">this</a>), or it WILL destory your Raspberry Pi.<hr>
<h3>Connections</h3>

`GND > GND`<br>
`VCC < +5V`<br><br>
`E   < SCLK (GPIO 11)` <b>(See Warning)</b><br>
`R/W < MOSI (GPIO 10)` <b>(See Warning)</b><br>
`RS(unconnected)` (see note 1)<br><br>
`PSB > GND` (Enables SPI mode on display)<br>
`BLA > +5V`<br>
`BLK < GND`<br><br>
Note 1: `RS` is Chip Select in SPI mode on ST7920, but `CE0`/`CE1` are inverted to the spec of ST7920, So leave this disconnected or you'll have no display output<br>
