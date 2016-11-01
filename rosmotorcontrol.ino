

/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include "ros.h"
#include "std_msgs/String.h"

int ESCpin1 = 10; 
int ESCpin2 =8;
int ESCpin3 =9;
int ESCpin4 =11;
// ESC signal wire connected to pin 11 on arduino
int val = 0;        //variable to store PWM value
int cal=0;
int v1=0;
String a;
char c;

ros::NodeHandle  nh;

void messageCb( const std_msgs::String&  msg){
      
   a= msg.data;
     char b[50];
      a.toCharArray(b, 50) ;
  c= b[0];

   
   if(c=='1')                                        // check for condition and fly up
 
 {
   for(val = 0; val <= 140; val += 5)
 {
   nh.loginfo ("tyhe val is ");
   
   analogWrite(ESCpin1, val);
   analogWrite(ESCpin2, val);
   analogWrite(ESCpin3, val);
   analogWrite(ESCpin4, val);
   delay(10);
 }
}
 if(c=='2')                                        // fly in left direction 
 
 {
 
 for(val = 0; val <= 150; val += 5)
 {
   analogWrite(ESCpin1, val);
   analogWrite(ESCpin2, val);
   delay(10);
 }
 for(v1 = 0; v1 <= 135; v1 += 5)
 {
   analogWrite(ESCpin3, v1);
   analogWrite(ESCpin4, v1);
   delay(10);
 }
}
 if(c=='3')                                        // fly in left direction 
 
 {
  
 for(val = 0; val <=150; val += 5)  
 {
  
   analogWrite(ESCpin3, val);
   analogWrite(ESCpin4, val);
   delay(10);
 }
 
 for(v1 = 0; v1 <= 135; v1 += 5) 
 {
   analogWrite(ESCpin1, v1);
   analogWrite(ESCpin2, v1);
   delay(10);
 }
}
/*if(c=='4')                                        // fly in one direction 
 
 {
    
 {
   analogWrite(ESCpin1, val);
   analogWrite(ESCpin2, val);
   analogWrite(ESCpin3, val);
   analogWrite(ESCpin4, val);
   delay(10);
 }
}*/
if(c=='5')                                        // fly in one direction 
 
 {
    
 {
   analogWrite(ESCpin1, cal);
   analogWrite(ESCpin2, cal);
   analogWrite(ESCpin3, cal);
   analogWrite(ESCpin4, cal);
   delay(10);
 }
}
}
  
std_msgs::String msg;
ros::Subscriber<std_msgs::String> sub("awesome_topic", &messageCb);
void setup()
{ 
  pinMode(8,OUTPUT);
   pinMode(10,OUTPUT); 
    pinMode(11,OUTPUT);
   pinMode(9,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
 
  
}

void loop()
{
     
  nh.spinOnce();
  delay(1);
}

