//Import the Bitvoice library. 
#include <BitVoicer11.h>
#include <Servo.h>
//Initiate the BitVoicer Serial Class. 
BitVoicerSerial bvSerial = BitVoicerSerial();

// Store the data type retreived by getData()
byte dataType = 4;
Servo servoBase;
Servo servoHorizontal;
Servo servoVertical;
Servo servoClaw;
//create an array for all of the outpins. 
int servoBasePos = 90;
int servoVerticalPos = 90;
int servoHorizontalPos =90;
void setup() {
  // start serial communication at 9600kbs
  Serial.begin(9600);
  servoBase.attach(3);
  servoHorizontal.attach(4);
  servoVertical.attach(5);
  servoClaw.attach(6);
}
  
void loop() {
  // we dont need anything in the loop.
}

// this function runs every time serial data is available. 
void serialEvent()
{
    //Reads the serial bugger and stores the received data type. 
    dataType = bvSerial.getData();
    
    // if data type is string do somethign a little bit different. 
    if (dataType == BV_STR)
    {
        if (bvSerial.strData == "Left")
        {                             
            servoBase.write(servoBasePos-=20);                          
        } 
        else if (bvSerial.strData == "Right")
        {
            servoBase.write(servoBasePos+=20); 
        }
        else if (bvSerial.strData == "Open")
        {
            servoClaw.write(90); 
        }
        else if (bvSerial.strData == "Close")
        {
            servoClaw.write(15); 
        }      
        else if (bvSerial.strData == "Up")
        {
            servoVertical.write(servoVerticalPos += 20); 
        }
        else if (bvSerial.strData == "Down")
        {
            servoVertical.write(servoVerticalPos -= 20); 
        }    
        else if (bvSerial.strData == "Closer")
        {
            servoHorizontal.write(servoHorizontalPos += 20); 
        }
        else if (bvSerial.strData == "Further")
        {
            servoHorizontal.write(servoHorizontalPos -= 20); 
        }    
        
    }
}
