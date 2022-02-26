// taylor_transmitter.pde
// simulates operation of Taylor Interlocking Switching control w/ levers
// radios out the switches to another arduino w receiver unit
// unit then throws switches, changes signals et al.

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver(2000, 40, 40, 40); // TX on D40 (pin 3 on attiny85), 

const int switch1 = 26;
const int switch2 = 27;
const int switch3 = 28;
const int switch4 = 29;
const int switch5 = 30;
const int switch6 = 31;
const int switch7 = 32;
const int switch8 = 33;
const int switch9 = 34;
const int switch10 = 35;
char switch_position1 = "L";
char switch_position1_previous = "L";
char switch_position2 = "L";
char switch_position2_previous = "L";
char switch_position3 = "L";
char switch_position3_previous = "L";
char switch_position4 = "L";
char switch_position4_previous = "L";
char switch_position5 = "L";
char switch_position5_previous = "L";
char switch_position6 = "L";
char switch_position6_previous = "L";
char switch_position7 = "L";
char switch_position7_previous = "L";
char switch_position8 = "L";
char switch_position8_previous = "L";
char switch_position9 = "L";
char switch_position9_previous = "L";
char switch_position10 = "L";
char switch_position10_previous = "L";
bool firstTime = true;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
    Serial.println("begin testing");
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif


  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  pinMode(switch5, INPUT);
  pinMode(switch6, INPUT);
  pinMode(switch8, INPUT);
  pinMode(switch9, INPUT);
  pinMode(switch10, INPUT);

   switch_position1="L"; // clear
   switch_position2="L"; // clear
   switch_position3="L"; // clear
   switch_position4="L"; // clear
   switch_position5="L"; // clear
   switch_position6="L"; // clear
   switch_position7="L"; // clear
   switch_position8="L"; // clear
   switch_position9="L"; // clear
   switch_position10="L"; // clear

}

void loop()
{


  if (digitalRead(switch1) == HIGH) {
    switch_position1 = "H";
    } else {
    switch_position1 = "L";      
    }
    
  if (digitalRead(switch2) == HIGH) {
    switch_position2 = "H";
    } else {
    switch_position2 = "L";      
    }
  if (digitalRead(switch3) == HIGH) {
    switch_position3 = "H";
    } else {
    switch_position3 = "L";      
    }
  if (digitalRead(switch4) == HIGH) {
    switch_position4 = "H";
    } else {
    switch_position4 = "L";      
    }
  if (digitalRead(switch5) == HIGH) {
    switch_position5 = "H";
    } else {
    switch_position5 = "L";      
    }
  if (digitalRead(switch6) == HIGH) {
    switch_position6 = "H";
    } else {
    switch_position6 = "L";      
    }
  if (digitalRead(switch7) == HIGH) {
    switch_position7 = "H";
    } else {
    switch_position7 = "L";      
    }
  if (digitalRead(switch8) == HIGH) {
    switch_position8 = "H";
    } else {
    switch_position8 = "L";      
    }
  if (digitalRead(switch9) == HIGH) {
    switch_position9 = "H";
    } else {
    switch_position9 = "L";      
    }
  if (digitalRead(switch10) == HIGH) {
    switch_position10 = "H";
    } else {
    switch_position10 = "L";      
    }

  // don't switch anything the first time thru, since we're just getting/saving the values
  
    if (firstTime != true) {
      

        if (switch_position1 != switch_position1_previous){
            char *msg = "RRSW1L";
            if (switch_position1 == HIGH){
               *msg = "RRSW1H";
            }
    
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position2 != switch_position2_previous){
            char *msg = "RRSW2L";
            if (switch_position2 == HIGH){
               *msg = "RRSW2H";
            }
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position3 != switch_position3_previous){
           char *msg = "RRSW3L";
            if (switch_position3 == HIGH){
               *msg = "RRSW3H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position4 != switch_position4_previous){
           char *msg = "RRSW4L";
            if (switch_position4 == HIGH){
               *msg = "RRSW4H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position5 != switch_position5_previous){
           char *msg = "RRSW5L";
            if (switch_position5 == HIGH){
               *msg = "RRSW5H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
        if (switch_position6 != switch_position6_previous){
           char *msg = "RRSW6L";
            if (switch_position6 == HIGH){
               *msg = "RRSW6H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
         }
    
    
        if (switch_position7 != switch_position7_previous){
           char *msg = "RRSW7L";
            if (switch_position7 == HIGH){
               *msg = "RRSW7H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position8 != switch_position8_previous){
           char *msg = "RRSW8L";
            if (switch_position8 == HIGH){
               *msg = "RRSW8H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
    
          }
    
    
        if (switch_position9 != switch_position9_previous){
           char *msg = "RRSW9L";
            if (switch_position9 == HIGH){
               *msg = "RRSW9H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    
    
        if (switch_position10 != switch_position10_previous){
           char *msg = "RRSW10L";
            if (switch_position10 == HIGH){
               *msg = "RRSW10H";
            }
     
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(200);      
          }
    }

       firstTime = false;
       delay(100);

   switch_position1_previous = switch_position1; // clear
   switch_position2_previous = switch_position2; // clear
   switch_position3_previous = switch_position3; // clear
   switch_position4_previous = switch_position4; // clear
   switch_position5_previous = switch_position5; // clear
   switch_position6_previous = switch_position6; // clear
   switch_position7_previous = switch_position7; // clear
   switch_position8_previous = switch_position8; // clear
   switch_position9_previous = switch_position9; // clear
   switch_position10_previous = switch_position10; // clear    
}
