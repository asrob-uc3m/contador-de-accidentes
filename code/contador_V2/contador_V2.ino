#include <EEPROM.h>
#include <Time.h>
#include <TimeLib.h>
#include <Adafruit_NeoPixel.h>
#define PIN A1 //Designamos nuestro pin de datos para la tira led
#define NUMPIXELS 42 //Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define delayval 50 //Varisble para evitar una falsa pulsacion
#define rojo pixels.Color(255, 0, 0) //color rojo
#define verde pixels.Color(0, 255, 0) //color verde
#define azul pixels.Color(0, 0, 50) //color azul
int timer1 = day();
const int buttonPin = 2;    // pin de la seta
int buttonState;             // estado actual del input pin
unsigned long lastDebounceTime = 0;  //la ultima conmutacion del output
unsigned long debounceDelay = 50;    // the debounce time;aumenta si el output fluctua
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int timer2 = EEPROM.read(0);
int ledState = LOW;         // estado actual del OUTPUT
int lastButtonState = LOW;   // estado previo del input
uint32_t apagado = pixels.Color(0, 0, 0);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(buttonPin, INPUT_PULLUP);
  num_print(timer2);

}

void loop() {

  buttonState = digitalRead(buttonPin); //comprueba el estado de la seta

  if ((millis() - lastDebounceTime) > debounceDelay) { //este if es para evitar falsas pulsaciones de la seta
    lastDebounceTime = millis();
    if (buttonState != lastButtonState) { //si el estado del boton ha cambiado
      lastButtonState = buttonState;
      if (buttonState == HIGH) { //en caso de que la seta se haya soltado reseteamos contador
        timer2 = 0;
        for (int i = 0; i < 43; i++) { //bucle que apaga los pixels
          pixels.setPixelColor(i, apagado);
          pixels.show(); //actualiza el estado de los pixels
        }
      }
    }
  }

  //guarda la lectura. proxima vez en el lop sera LastButtonState:
  if ( day() != timer1) {
    timer1 = day();
    timer2++;
  }

  for (int i = 0; i < 43; i++) {
    pixels.setPixelColor(i, apagado);
    pixels.show();
  }
  num_print(timer2);
  EEPROM.update(0, timer2);
}


void num_print(int dayt) {
  int num[2];
  for (int i = 0; i < 2; i++) {
    num[i] = dayt % 10;
    dayt = dayt / 10;
    switch (num[i]) {
      case 0:
        for (int b = 21 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 1:
        for (int b = 27 - 21 * i  ; b <= 29 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 39 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 2:
        for (int b = 21 - 21 * i  ; b <= 26 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 30 - 21 * i  ; b <= 32 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 36 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 3:
        for (int b = 24 - 21 * i  ; b <= 32 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 36 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 4:
        for (int b = 27 - 21 * i  ; b <= 35 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 39 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }

        break;

      case 5:
        for (int b = 24 - 21 * i  ; b <= 38 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 6:
        for (int b = 21 - 21 * i  ; b <= 38 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;
      case 7:
        for (int b = 27 - 21 * i  ; b <= 29 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        for (int b = 36 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 8:
        for (int b = 21 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;

      case 9:
        for (int b = 27 - 21 * i  ; b <= 41 - 21 * i ; b++) {
          pixels.setPixelColor(b, azul);
        }
        break;
    }
    pixels.show();
  }
}
