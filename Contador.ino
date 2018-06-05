
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
boolean flag = false;

//Designamos nuestro pin de datos
#define PIN 6
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS 42
#define delayval 50
#define rojo  pixels.Color(150, 0, 0)
#define  verde  pixels.Color(0, 150, 0)
#define  azul  pixels.Color(0, 0, 20)
unsigned long timer1 = 0;
unsigned long timer2 = 0;
int derecha = 0;
int izquierda = 0;



//Definimos el número de pixeles de la cinta y el pin de datos
//   Parámetro 1 = número de pixeles de la cinta
//   Parámetro 2 = número de pin de datos del Arduino
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANTE: Para reducir el riesgo de dañar los pixeles de la cinta, añada un condensador de 1000 uF a través de
// los cables de alimentación de la cinta, agregue una resistencia de 300-500 Ohm en la entrada de datos del primer pixel
// Y reduzca la distancia entre Arduino y el primera pixel.
// Evite realizar conexiones en el circuito vivo si lo va a hacer, conecte GND primero.

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //Definimos nuestras variables de tipo uint32 para cada color que utilizaremos
  // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255


  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {

  // Pausa de cincuenta milisegundos
  // read the state of the switch into a local variable:
  uint32_t apagado = pixels.Color(0, 0, 0);



  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce º
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {

         derecha = 0;
         izquierda = 0;


      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  //  lastButtonState = reading;



  while (derecha < 10) {

    timer2 = (millis() / 2000);
    if ( timer1 != timer2 ) {
      timer1 = timer2;
      for (int i = 0; i < 43; i++) {
        pixels.setPixelColor(i, apagado); // Brillo moderado en verde
        pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
      }

      numd(derecha);

      numi(izquierda);

      derecha++;    // unidades de segundo se incrementa cada segundo

    }

  }
  derecha = 0;

  izquierda++;
  for (int i = 0; i < 21; i++) {
    pixels.setPixelColor(i, apagado); // Brillo moderado en verde
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  }
  numi(izquierda - 1);


  /* for (izquierda = 0; izquierda < 10; izquierda++) {
     for (derecha = 0; derecha < 10; derecha++) {
       for (int i = 0; i < 50; i++) {
         pixels.setPixelColor(i, apagado); // Brillo moderado en verde
         pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
       }
       numd(derecha);
       numi(izquierda);
       delay(500);
     }
    }*/
}

void tira_uno(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(0, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(1, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(2, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_dos(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(3, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(4, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(5, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_tres(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(6, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(7, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(8, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_cuatro(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(9, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(10, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(11, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_cinco(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(12, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(13, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(14, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_seis(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(15, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(16, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(17, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_siete(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(18, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(19, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(20, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_ocho(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(21, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(22, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(23, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_nueve(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(24, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(25, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(26, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_diez(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(27, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(28, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(29, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_once(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(30, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(31, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(32, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_doce(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(33, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(34, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(35, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_trece(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(36, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(37, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(38, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
} void tira_catorce(char color) {
  Serial.println("funciona, pulsado");
  pixels.setPixelColor(39, color); // Brillo moderado en rojo
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(40, color); // Brillo moderado en verde
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa por un periodo de tiempo (en milisegundos).

  pixels.setPixelColor(41, color); // Brillo moderado en azul
  pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
  // Pausa po
}


void numd(int t) {


  switch (t) {
    case 0:
      tira_trece(azul);
      tira_doce(azul);
      tira_diez(azul);
      tira_nueve(azul);
      tira_ocho(azul);
      tira_catorce(azul);
    case 1:
      tira_catorce(azul);
      tira_diez (azul);
      break;
    case 2:
      tira_trece(azul);
      tira_catorce(azul);
      tira_once(azul);
      tira_ocho(azul);
      tira_nueve(azul);
      break;
    case 3:
      tira_trece(azul);
      tira_catorce(azul);
      tira_once(azul);
      tira_diez(azul);
      tira_nueve(azul);
      break;
    case 4:
      tira_doce(azul);
      tira_once(azul);
      tira_catorce(azul);
      tira_diez(azul);
      break;
    case 5:
      tira_trece(azul);
      tira_once(azul);
      tira_doce(azul);
      tira_diez(azul);
      tira_nueve(azul);
      break;
    case 6:
      tira_trece(azul);
      tira_ocho(azul);
      tira_once(azul);
      tira_doce(azul);
      tira_diez(azul);
      tira_nueve(azul);
      break;
    case 7:
      tira_trece(azul);
      tira_catorce(azul);
      tira_diez(azul);
      break;
    case 8:
      tira_trece(azul);
      tira_once(azul);
      tira_doce(azul);
      tira_diez(azul);
      tira_nueve(azul);
      tira_ocho(azul);
      tira_catorce(azul);
      break;
    case 9:
      tira_trece(azul);
      tira_once(azul);
      tira_doce(azul);
      tira_diez(azul);
      tira_catorce(azul);
      break;
  }
}
void numi(int t) {
  switch (t) {
    case 0:
      break;
    case 1:
      tira_siete(azul);
      tira_tres(azul);
      break;
    case 2:
      tira_seis(azul);
      tira_siete(azul);
      tira_cuatro(azul);
      tira_uno(azul);
      tira_dos(azul);
      break;
    case 3:
      tira_seis(azul);
      tira_siete(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_dos(azul);
      break;
    case 4:
      tira_siete(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_cinco(azul);
      break;
    case 5:
      tira_seis(azul);
      tira_cinco(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_dos(azul);
      break;
    case 6:
      tira_seis(azul);
      tira_cinco(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_dos(azul);
      tira_uno(azul);
      break;
    case 7:
      tira_seis(azul);
      tira_siete(azul);
      tira_tres(azul);
      break;
    case 8:
      tira_seis(azul);
      tira_cinco(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_dos(azul);
      tira_uno(azul);
      tira_siete(azul);
      break;
    case 9:
      tira_seis(azul);
      tira_cinco(azul);
      tira_cuatro(azul);
      tira_tres(azul);
      tira_siete(azul);
      break;
  }
}
