#include <Thread.h>
#include <ThreadController.h>
#include <TinyGPSPlus.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "HardwareSerial.cpp"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/******************************************************************/
#define __DEBUG__
/******************************************************************/
// Configuración Serial Data ARRAY ********************************/
const char startMarker = '<';
const char endMarker = '>';
const char verificationChar = '@';

// Variables for altitudeData and latitudeData
float altitudeData;
float latitudeData;

// Variables for ledData
char ledColor[8]; // To store HEX color in format "#RRGGBB"
int ledNumber;    // To store the integer number (0-11)
char ledChar;     // To store the character

// Variable for serial data
char serialData[32]; // Adjust the size accordingly
/******************************************************************/
// Configuración Threads ******************************************/
/******************************************************************/
ThreadController controll = ThreadController();
Thread* GPS_Thread = new Thread();
Thread* SERVO_Thread = new Thread();
Thread* SERIAL_Thread = new Thread();
Thread* LED_Thread = new Thread();
#define GPS_INTERVAL 1000
#define SERVO_INTERVAL 1000
#define SERIAL_INTERVAL 1000
#define LED_INTERVAL 1000
/******************************************************************/
// Configuracion OLED**********************************************/
/******************************************************************/
#define ANCHO_PANTALLA 128 
#define ALTO_PANTALLA 64 
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);
/******************************************************************/
// Configuracion Servos PCA9685************************************/
// Config for servo initial positions
int servo1 = 125;
int servo2 = 125;
int servo3 = 125;
int servo4 = 125;
int servo5 = 125;
int servo6 = 125;
/******************************************************************/

/******************************************************************/
// Configuracion puertos I2C y Puertos serie***********************/
/******************************************************************/
#define BAUD_SERIAL1 9600      // Baudrate Puerto gps
#define RXPIN_SERIAL1 16   // cambiar por 16        
#define TXPIN_SERIAL1 17    // cambiar por 17  

#define SDA_PIN 16           // cambiar por 23
#define SCL_PIN 4           // cambiar por 19

TinyGPSPlus gps;
/******************************************************************/
// Configuración de OTROS PINES************************************/
/******************************************************************/
const int ledPin = 22;
/******************************************************************/

/* PROGRAMA A PARTIR DE  AQUI */
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/

void gps_Callback()
{
#ifdef __DEBUG__
  while (Serial1.available() > 0)
  {
    if (gps.encode(Serial1.read()))
    {
      displayGPSInfo();
    }
  }
#endif
  // Replace with actual data
  altitudeData = 13.456789;
  latitudeData = 12.345678;

  sendAltitudeData();
  sendLatitudeData();
}

void sendAltitudeData()
{
  Serial.print(startMarker);
  Serial.print("x");
  Serial.print(altitudeData, 6);
  Serial.print(endMarker);
}

void sendLatitudeData()
{
  Serial.print(startMarker);
  Serial.print("y");
  Serial.print(latitudeData, 6);
  Serial.print(endMarker);
}

void servo_Callback()
{
#ifdef __DEBUG__
#endif

  if (serialData[0] == 'A') {
    // Process servoData with identifier 'A'
    sscanf(&serialData[1], "%d", &servo1);
  } else if (serialData[0] == 'B') {
    // Process servoData with identifier 'B'
    sscanf(&serialData[1], "%d", &servo2);
  } else if (serialData[0] == 'C') {
    // Process servoData with identifier 'C'
    sscanf(&serialData[1], "%d", &servo3);
  } else if (serialData[0] == 'D') {
    // Process servoData with identifier 'D'
    sscanf(&serialData[1], "%d", &servo4);
  } else if (serialData[0] == 'E') {
    // Process servoData with identifier 'E'
    sscanf(&serialData[1], "%d", &servo5);
  } else if (serialData[0] == 'F') {
    // Process servoData with identifier 'F'
    sscanf(&serialData[1], "%d", &servo6);
  }
}

void serial_Callback()
{
#ifdef __DEBUG__
  Serial1.println("test serial1");
#endif
  recvData();
}

void led_Callback()
{
#ifdef __DEBUG__
#endif
  if (serialData[0] == '#') {
    // Process ledData
    sscanf(&serialData[1], "%7s %d %c", ledColor, &ledNumber, &ledChar);
  }
}

void recvData() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;

  while (Serial.available() > 0) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        serialData[ndx] = rc;
        ndx++;
        if (ndx >= sizeof(serialData) - 1) { // -1 to leave space for the null terminator
          ndx = 0;
          recvInProgress = false;
          serialData[sizeof(serialData) - 1] = '\0'; // Null-terminate the array
          if (serialData[0] == startMarker) {
            servo_Callback();
            led_Callback();
            // Send verification char to PC
            Serial.print(verificationChar);
          }
        }
      }
    } else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void displayGPSInfo()
{
  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

void setup()
{
  Serial.flush();
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
  delay(5000); // No quitar, para que de tiempo a debuggear

  /*******************************************************************/
  // Configuracion Puertos Serie *************************************/
  Serial.begin(115200);
  //Serial1.begin(BAUD_SERIAL1, SERIAL_8N1, RXPIN_SERIAL1, TXPIN_SERIAL1);
  /*******************************************************************/
  // Inizializacion y escaneo de I2C *********************************/
  Wire.begin(SDA_PIN, SCL_PIN);
#ifdef __DEBUG__
  byte addressI2C;
  byte errorI2C;
  bool found0x40 = false;
  bool found0x3C = false;

  Serial.println("Scanning I2C bus...");

  for (addressI2C = 1; addressI2C < 127; addressI2C++)
  {
    Wire.beginTransmission(addressI2C);
    errorI2C = Wire.endTransmission();

    if (errorI2C == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (addressI2C < 16)
      {
        Serial.print("0");
      }
      Serial.print(addressI2C, HEX);
      Serial.println();
      // Check if the device with address 0x40 is found
      if (addressI2C == 0x40)
      {
        found0x40 = true;
      }
      // Check if the device with address 0x3C is found
      if (addressI2C == 0x3C)
      {
        found0x3C = true;
      }
    }
  }
  if (!found0x40)
  {
    Serial.println("Servo Controler missing on I2C bus.");
  }
  if (!found0x3C)
  {
    Serial.println("oLED Display missing on I2C bus.");
  }
#endif

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  /*******************************************************************/
  // Iniciar oLED*****************************************************/
  /*******************************************************************/
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  /*******************************************************************/
  // Configuracion Threads********************************************/
  GPS_Thread->onRun(gps_Callback);
  GPS_Thread->setInterval(GPS_INTERVAL);
  controll.add(GPS_Thread);
  SERVO_Thread->onRun(servo_Callback);
  SERVO_Thread->setInterval(SERVO_INTERVAL);
  controll.add(SERVO_Thread);
  SERIAL_Thread->onRun(serial_Callback);
  SERIAL_Thread->setInterval(SERIAL_INTERVAL);
  controll.add(SERIAL_Thread);
  LED_Thread->onRun(led_Callback);
  LED_Thread->setInterval(LED_INTERVAL);
  controll.add(LED_Thread);
  /*******************************************************************/
}

void loop()
{
  controll.run();
}


