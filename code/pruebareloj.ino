int u_hora = 0;           //Cargamos un 0 en la variable "u_hora"
int u_minuto = 0;         //Cargamos un 0 en la variable "u_minuto"
int u_segundo = 0;        //Cargamos un 0 en la variable "u_segundo"
int d_hora = 0;           //Cargamos un 0 en la variable "d_hora"
int d_minuto = 0;         //Cargamos un 0 en la variable "d_minuto"
int d_segundo = 0;        //Cargamos un 0 en la variable "d_segundo"
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  un_seg ();    //Va a la rutina un_seg
   
  contador();   //Va a la rutina contador
   
  escribe_hora();  //Va a la rutina escribe_hora
   
//  set_hora();   //Va a la rutina set_hora
   
}
void un_seg(){    //Rutina para cada segundo
   
timer2=(millis()/1000);    
if ( timer1 != timer2 ) {
 timer1=timer2;
 u_segundo++;    // unidades de segundo se incrementa cada segundo       
 }     
}
 
void contador(){ // Rutina para el reloj
 
if ( u_segundo == 10 ) {
u_segundo =0;
d_segundo++;} 
 
if ( ( d_segundo == 6 ) && ( u_segundo == 0 ) ) {
d_segundo =0;
u_minuto++;} 
 
 
// Rutina de minutos
 
if ( u_minuto == 10 ) {
u_minuto =0;
d_minuto++; } 
 
if ( ( d_minuto == 6 ) && ( u_minuto == 0 ) ) {
d_minuto =0;     
u_hora++;} 
// Rutina de horas
 
if ( u_hora == 10 ) {
u_hora =0;
d_hora++; } 
 
if ( (d_hora == 2) &&  (u_hora == 4) ) {
u_hora =0; 
d_hora =0; } 
 
 
}
   
  void escribe_hora(){ //Rutina para escribir la hora en el Serial
     
 
  Serial.print("Reloj Arduino"); //Escribe el texto entre comillas
 
  Serial.print(d_hora);    //Escribe la cantidad almacenada en la variable d_hora
  Serial.print(u_hora);    //Escribe la cantidad almacenada en la variable u_hora
  Serial.print(":");        //Escribe el texto entre comillas
  Serial.print(d_minuto);  //Escribe la cantidad almacenada en la variable d_minuto
  Serial.print(u_minuto);  //Escribe la cantidad almacenada en la variable u_minuto
  Serial.print(":");        //Escribe el texto entre comillas
  Serial.print(d_segundo);  //Escribe la cantidad almacenada en la variable d_segundo
  Serial.print(u_segundo);  //Escribe la cantidad almacenada en la variable u_segundo
  Serial.print("\n"); 
  }
   
 

