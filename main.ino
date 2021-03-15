#include <TinyRTC.h>
#include <TinyOLED.h>

#include <avr/io.h>
#include <avr/interrupt.h>

#define INTERRUPT_PIN PCINT3 
#define INT_PIN PB3           
#define PCINT_VECTOR PCINT0_vect      

// inputs - outputs
#define ADC   3
#define LED   4
#define PULS  5

enum FlagEncoder{ ENC_STATIC, ENC_RIGHT, ENC_LEFT };
FlagEncoder flag_encoder = ENC_STATIC;

enum StateEncoder { ST_A, ST_B, ST_C, ST_D, ST_E, ST_F, ST_G };
StateEncoder st_encoder = ST_A;

bool flag_int = false;

void setup() {   

  cli();                            // Disable interrupts during setup
  PCMSK |= (1 << INTERRUPT_PIN);    // Enable interrupt handler (ISR) for our chosen interrupt pin (PCINT1/PB1/pin 6)
  GIMSK |= (1 << PCIE);             // Enable PCINT interrupt in the general interrupt mask
  pinMode(INT_PIN, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  sei();                            //last line of setup - enable interrupts after setup
  
  TinyOled.init();

  TinyRtc.initAlarm(ALARM_1);
  TinyRtc.initAlarm(ALARM_2);
  TinyRtc.setAlarm(ALARM_1, 30, 40, 12, 1);
  TinyRtc.setAlarm(ALARM_2,  0,  0, 12, 1);
  TinyRtc.customAlarm(ALARM_1, ALARM_SEC_MATCH);
  TinyRtc.customAlarm(ALARM_2, ALARM_MIN_MATCH);
  
  pinMode(LED, OUTPUT);     // LED indicador 

}

// Interrupcion
ISR(PCINT_VECTOR){
  if( digitalRead(INT_PIN) == LOW ) {
    digitalWrite(LED, HIGH);
    flag_int = true;
    TinyRtc.clearAlarm(ALARM_1);
    TinyRtc.clearAlarm(ALARM_2);
  }
}

void loop() {  
  if(flag_int){
    delay(1000);
    digitalWrite(LED, LOW);
    flag_int = false;
  }

  TinyOled.setCursorXY(0x00,0x00); 
  TinyOled.printNumber(TinyRtc.getHours());
  TinyOled.printChar(':');
  TinyOled.printNumber(TinyRtc.getMinutes());
  TinyOled.printChar(':');
  TinyOled.printNumber(TinyRtc.getSeconds());

  TinyOled.setCursorXY(0x00,0x01); 
  TinyOled.printNumber(TinyRtc.getDayMonth());
  TinyOled.printChar('/');
  TinyOled.printNumber(TinyRtc.getMonth());
  TinyOled.printChar('/');
  TinyOled.printNumber(TinyRtc.getYear());  

  delay(1000);
}
