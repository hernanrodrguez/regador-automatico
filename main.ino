#include <TinyWireM.h>
#include <TinyOzOLED.h>

// inputs - outputs
#define ADC   3
#define LED   4
#define PULS  5


enum FlagEncoder{ ENC_STATIC, ENC_RIGHT, ENC_LEFT };
FlagEncoder flag_encoder = ENC_STATIC;

enum StateEncoder { ST_A, ST_B, ST_C, ST_D, ST_E, ST_F, ST_G };
StateEncoder st_encoder = ST_A;

void setup() {       
  OzOled.init();
  OzOled.printString("REGADOR");
  OzOled.setCursorXY(0x00, 0x01);
  OzOled.printString("AUTOMATICO!");
  /*
  pinMode(ADC, INPUT);         
  pinMode(PULS, INPUT);      // pulsador del encoder
  digitalWrite(PULS, HIGH);  // pull up interno
  pinMode(LED, OUTPUT);     // LED indicador */
}

void loop() {  
  
  //ME_Encoder();
  /*
  int adc = ReadADC();
  if(LEVEL_2){
    digitalWrite(LED, HIGH); 
  } else
    digitalWrite(LED, LOW); 
  */
  /*
  if(flag_encoder == ENC_RIGHT){
    digitalWrite(LED, HIGH);  
    delay(1000);
  } else if(flag_encoder == ENC_LEFT){
    digitalWrite(LED, HIGH);
    delay(5000);
  } else {
    digitalWrite(LED, LOW);
  }*/
}
