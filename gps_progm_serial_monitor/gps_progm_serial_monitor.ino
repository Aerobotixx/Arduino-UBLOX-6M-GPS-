//**********************READ INSTRUCTIONS CAREFULLY****************************
//This is tested & working code based on Mikal Hart's Library & example code.
//Download TinyGPSPlus Library from this link : https://github.com/mikalhart/TinyGPSPlus
//Visit this site to learn about all functions of library : http://arduiniana.org/libraries/tinygpsplus/
//GET OTHER EXAMPLES HERE : https://github.com/mikalhart/TinyGPSPlus/tree/master/examples
//*****************************************************************************

#include <TinyGPS++.h>        //GPS Library

//LEARN ABOUT SOFTWARE SERIAL FIRST : https://www.arduino.cc/en/Reference/softwareSerial

#include <SoftwareSerial.h>   //To use Virtual Serial port for GPS. 
SoftwareSerial mySerial(2, 3); //Creating object for Software Serial Port. D2 = Rx & D3 = Tx
TinyGPSPlus gps;      //Creating object for GPS

double latitude, longitude;   //Global variables to store latitude & longitude

void setup()
{
  mySerial.begin(9600);  //Setting baudrate of GPS
  Serial.begin(9600);    //Setting baud rate of arduino
}

void loop()
{
  while (mySerial.available())  //Check for data coming from GPS
  {
    int data = mySerial.read();  //Local variable to Store the raw data(NMEA) received from GPS device
    if (gps.encode(data))       //Decoding the NMEA data to retrieve latitude & Longitude
    {
      latitude = (gps.location.lat());  //get value of latitude in degrees
      longitude = (gps.location.lng()); //get value of longitude in degrees

      Serial.print ("latitude: ");   //Print on serial monitor
      Serial.print (latitude, 6);   //Print value upto 6 places

      Serial.print ("\t longitude: ");
      Serial.print (longitude, 6);

      //To display connected satellite's count:
      Serial.print ("\t Satellites: ");
      Serial.println(gps.satellites.value());

      delay (500);        //Print on serial monitor after every 500 milliseconds

    }
  }
}
