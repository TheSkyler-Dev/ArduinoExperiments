#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  Serial.println("OLED begun");

  //show image buffer
  display.display();
  delay(3000);

  //buffer clear
  display.clearDisplay();
  display.display();
  Serial.println("Display test");

  //display text
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("HELLO WORLD");
  display.println(" ^w^ ");
  display.println("AWOO");
  display.println("Display test success");
  display.setCursor(0,0);
  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
