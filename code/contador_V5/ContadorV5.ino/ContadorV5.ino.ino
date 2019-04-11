#include <Time.h>
#include <TimeLib.h>
#include <Adafruit_NeoPixel.h>

const int buttonPin = 2;    // the number of the pushbutton pin
boolean flag = false;

//Designamos nuestro pin de datos
#define PIN 1
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS 63
#define delayval 50
#define rojo  pixels.Color(20, 0, 0)
#define  verde  pixels.Color(0, 20, 0)
#define  azul  pixels.Color(0, 0, 20)




//Definimos el número de pixeles de la cinta y el pin de datos
//   Parámetro 1 = número de pixeles de la cinta
//   Parámetro 2 = número de pin de datos del Arduino
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANTE: Para reducir el riesgo de dañar los pixeles de la cinta, añada un condensador de 1000 uF a través de
// los cables de alimentación de la cinta, agregue una resistencia de 300-500 Ohm en la entrada de datos del primer pixel
// Y reduzca la distancia entre Arduino y el primera pixel.
// Evite realizar conexiones en el circuito vivo si lo va a hacer, conecte GND primero.

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int dia;
int segundos;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void pintar (int led);
void borrar(int);
int show(int, int, int);

void setup()
{
  pixels.begin();
  pinMode(buttonPin, INPUT_PULLUP);
  //Definimos nuestras variables de tipo uint32 para cada color que utilizaremos
  // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255

  show(0, 0, 0);
  segundos = 0;
  dia = 0;
  // set initial LED state
}

void loop() {

  uint32_t apagado = pixels.Color(0, 0, 0);

delay(903);
segundos = segundos + 1;

if (segundos >= 86400)
  {dia = dia + 1;
  segundos = 0;}

  show(dia / 100, (dia / 10) % 10, dia % 10);

}

int show(int centenas, int decenas, int unidades) {
  switch (centenas)                                                  //Aquí la programación de cuáles ledes tienen que encenderse y cuáles apagarse, para las centenas.
  {
    case 0:
      for (int i = 0; i < 21; i++) {
        if (i < 9 || 11 < i) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 1:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (16 < i)) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 2:
      for (int i = 0; i < 21; i++) {
        if (i < 6 || (8 < i && i < 12) || 14 < i) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 3:
      for (int i = 0; i < 21; i++) {
        if ((2 < i && i < 12) ||  14 < i) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 4:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 15) || 17 < i) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 5:
      for (int i = 0; i < 21; i++) {
        if (2 < i && i < 18) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 6:
      for (int i = 0; i < 21; i++) {
        if (i < 18) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 7:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (14 < i)) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 8:
      for (int i = 0; i < 21; i++) {
        if (1) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;

    case 9:
      for (int i = 0; i < 21; i++) {
        if (5 < i) {
          pintar (i);
        }
        else {
          borrar (i);
        }
      }
      break;
  }

  switch (decenas)                                                                //Aquí la programación de cuáles ledes tienen que encenderse y cuáles apagarse, para las decenas.
  {
    case 0:
      for (int i = 0; i < 21; i++) {
        if (i < 9 || 11 < i) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 1:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (16 < i)) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 2:
      for (int i = 0; i < 21; i++) {
        if (i < 6 || (8 < i && i < 12) || 14 < i) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 3:
      for (int i = 0; i < 21; i++) {
        if ((2 < i && i < 12) ||  14 < i) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 4:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 15) || 17 < i) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 5:
      for (int i = 0; i < 21; i++) {
        if (2 < i && i < 18) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 6:
      for (int i = 0; i < 21; i++) {
        if (i < 18) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 7:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (14 < i)) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 8:
      for (int i = 0; i < 21; i++) {
        if (1) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;

    case 9:
      for (int i = 0; i < 21; i++) {
        if (5 < i) {
          pintar (i + 21);
        }
        else {
          borrar (i + 21);
        }
      }
      break;
  }


  switch (unidades)                                                                        //Aquí la programación de cuáles ledes tienen que encenderse y cuáles apagarse, para las unidades.
  {
    case 0:
      for (int i = 0; i < 21; i++) {
        if (i < 9 || 11 < i) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 1:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (16 < i)) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 2:
      for (int i = 0; i < 21; i++) {
        if (i < 6 || (8 < i && i < 12) || 14 < i) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 3:
      for (int i = 0; i < 21; i++) {
        if ((2 < i && i < 12) ||  14 < i) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 4:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 15) || 17 < i) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 5:
      for (int i = 0; i < 21; i++) {
        if (2 < i && i < 18) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 6:
      for (int i = 0; i < 21; i++) {
        if (i < 18) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 7:
      for (int i = 0; i < 21; i++) {
        if ((5 < i && i < 9) || (14 < i)) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 8:
      for (int i = 0; i < 21; i++) {
        if (1) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;

    case 9:
      for (int i = 0; i < 21; i++) {
        if (5 < i) {
          pintar (i + 42);
        }
        else {
          borrar (i + 42);
        }
      }
      break;
  }
}

void pintar (int led) {
  pixels.setPixelColor(led, rojo);  //Función que pinta. Cambiar aquí colores e intensidades
  pixels.show();
}
void borrar (int led) {
  pixels.setPixelColor(led, pixels.Color(0, 0, 0));  //Función que d
  pixels.show();
}
