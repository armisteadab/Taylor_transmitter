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
int switch_position1 = 0;
int switch_position1_previous = 0;
int switch_position2 = 0;
int switch_position2_previous = 0;
int switch_position3 = 0;
int switch_position3_previous = 0;
int switch_position4 = 0;
int switch_position4_previous = 0;
int switch_position5 = 0;
int switch_position5_previous = 0;
int switch_position6 = 0;
int switch_position6_previous = 0;
int switch_position7 = 0;
int switch_position7_previous = 0;
int switch_position8 = 0;
int switch_position8_previous = 0;
int switch_position9 = 0;
int switch_position9_previous = 0;
int switch_position10 = 0;
int switch_position10_previous = 0;
bool firstTime = true;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
    Serial.println("begin testing REVISION 1.0");
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
    switch_position1 = 1;
    } else {
    switch_position1 = 0;      
    }
    
  if (digitalRead(switch2) == HIGH) {
    switch_position2 = 1;
    } else {
    switch_position2 = 0;      
    }
  if (digitalRead(switch3) == HIGH) {
    switch_position3 = 1;
    } else {
    switch_position3 = 0;      
    }
  if (digitalRead(switch4) == HIGH) {
    switch_position4 = 1;
    } else {
    switch_position4 = 0;      
    }
  if (digitalRead(switch5) == HIGH) {
    switch_position5 = 1;
    } else {
    switch_position5 = 0;      
    }
  if (digitalRead(switch6) == HIGH) {
    switch_position6 = 1;
    } else {
    switch_position6 = 0;      
    }
  if (digitalRead(switch7) == HIGH) {
    switch_position7 = 1;
    } else {
    switch_position7 = 0;      
    }
  if (digitalRead(switch8) == HIGH) {
    switch_position8 = 1;
    } else {
    switch_position8 = 0;      
    }
  if (digitalRead(switch9) == HIGH) {
    switch_position9 = 1;
    } else {
    switch_position9 = 0;      
    }
  if (digitalRead(switch10) == HIGH) {
    switch_position10 = 1;
    } else {
    switch_position10 = 0;      
    }
     
        char tempChar[7] = "";
        const char *msg = (tempChar);
        String str;
        str = "";
    
  // don't switch anything the first time thru, since we're just getting/saving the values
  
    if (firstTime != true) {
      

        if (switch_position1 != switch_position1_previous){
            str = "~RR1L~";
            if (switch_position1== 1){
               str = "~RR1R~";
            }
          }
    
    
        if (switch_position2 != switch_position2_previous){
            str = "~RR2L~";
            if (switch_position2== 1){
               str = "~RR2R~";
            }
          }
    
    
        if (switch_position3 != switch_position3_previous){
           str = "~RR3L~";
            if (switch_position3== 1){
               str = "~RR3R~";
            }
          }
    
    
        if (switch_position4 != switch_position4_previous){
           str = "~RR4L~";
            if (switch_position4== 1){
               str = "~RR4R~";
            }
          }
    
    
        if (switch_position5 != switch_position5_previous){
           str = "~RR5L~";
            if (switch_position5== 1){
               str = "~RR5R~";
            }
          }
    
        if (switch_position6 != switch_position6_previous){
           str = "~RR6L~";
            if (switch_position6== 1){
               str = "~RR6R~";
            }
         }
    
    
        if (switch_position7 != switch_position7_previous){
           str = "~RR7L~";
            if (switch_position7== 1){
               str = "~RR7R~";
            }
          }
    
    
        if (switch_position8 != switch_position8_previous){
           str = "~RR8L~";
            if (switch_position8== 1){
               str = "~RR8R~";
            }
          }
    
    
        if (switch_position9 != switch_position9_previous){
           str = "~RR9L~";
            if (switch_position9 == HIGH){
               str = "~RR9R~";
            }
          }
    
    
        if (switch_position10 != switch_position10_previous){
            str = "~RRXL~";
            if (switch_position10== 1){
              str = "~RRXR~";
            }
          }

        if (str != ""){
            str.toCharArray(tempChar,7);
            Serial.println(tempChar);
        
            driver.send((uint8_t *)msg, strlen(msg));
            driver.waitPacketSent();          
        }
        delay(200);      

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
