//Cytron PS2 Shield (SHIELD-PS2)
//www.cytron.com.my
//sample code to retrieve a btn status on PS2 Controller

//http://www.robotshop.com/media/files/zip/documentation-shield-ps2.zip

#include <Shield_PS2.h>

//declare class objects
PS2 ps2=PS2();                    //PS2 class object: ps2

#define LEDPIN 13


void setup()
{
  
   ps2.init(9600, 10, 11); // 2, 3); // 0,1);   //initialize the main board to use desired (baudrate, rx, tx)
                           //for Arduino Mega use RX:10, TX: 11 for software serial
                           //for Arduino Leonardo use pin 8, 9, 10, 11 as RX and TX for software serial
  
   //Read from Computer
   Serial.begin(9600); 

   //Led PIN 13 Test
   pinMode(LEDPIN, OUTPUT); 
   digitalWrite(LEDPIN,LOW);    

}

void loop()
{

  
  if( ps2.getval(p_select)==0)      //LED on Main Board will light up if Select button is pressed
  {
    //Led PIN 13 Test
    digitalWrite(LEDPIN,HIGH);
    Serial.println("hey");
    delay(500);
  }
  else 
  {
    //Led PIN 13 Test
    digitalWrite(LEDPIN,LOW); 
  }

  //Forward
  if( ps2.getval(p_up)==0)   
  {
    //Magical forward function
    Serial.println("Forward");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  

  //Backward
  if( ps2.getval(p_down)==0)   
  {
    //Magical backward function
    Serial.println("Backward");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  

  //Leftward Strafe
  if( ps2.getval(p_left)==0)   
  {
    //Magical L_Strafe function
    Serial.println("Left Strafe");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  

  //Rightward Strafe
  if( ps2.getval(p_right)==0) 
  {
    //Magical R_Strafe function
    Serial.println("Right Strafe");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  
  
  //Right Rotate (CW)
  if( ps2.getval(p_r1)==0)   
  {
    //Magical R_Rotate function
    Serial.println("Right Rotate");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  
  
  //Left Rotate (CCW)
  if( ps2.getval(p_l1)==0)   
  {
    //Magical L_Rotate function
    Serial.println("Left Rotate");
    delay(500);
  }
  else 
  {
    //Do nothing?
   
  }  




  
  
  
}
