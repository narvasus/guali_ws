#include <Thread.h>
#include <ThreadController.h>
#include <TinyGPSPlus.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <ESP32Servo.h>

/******************************************************************/
#define __DEBUG__
/******************************************************************/
// Configuración Serial Data ARRAY ********************************/
const char startMarker = '<';
const char endMarker = '>';
const char verificationChar = '@';

// Variables for altitudeData and latitudeData
const int numReadings = 10; // Number of readings to store
double latitude_rawData;
double longitude_rawData;
double latitudeData;
double longitudeData;
double latitudeReadings[numReadings];
double longitudeReadings[numReadings];
int readingsIndex = 0;

// Variables for ledData
char ledChar = 'a'; // To store the character

Adafruit_NeoPixel pixels(12, 2, NEO_GRB + NEO_KHZ800);

// Variable for serial data
char serialData[32]; // Adjust the size accordingly

/******************************************************************/
// Configuración Threads ******************************************/
/******************************************************************/
ThreadController controll = ThreadController();
Thread* GPS_Thread = new Thread();
Thread* SERIAL_Thread = new Thread();
#define GPS_INTERVAL 100  // Cada cuanto tiempo refresca la posición GPS
#define SERIAL_INTERVAL 50 // Cada cuanto tiempo recibe y envía datos al PC

/******************************************************************/
// Configuración OLED**********************************************/
/******************************************************************/
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

/******************************************************************/
// Configuración Servos ********************************************/
// Config for servo initial positions
#define NUM_SERVOS 6
#define SERVO_PIN_1 14  //SERVO A (base)
#define SERVO_PIN_2 27  //SERVO B  
#define SERVO_PIN_3 25  //SERVO C
#define SERVO_PIN_4 26  //SERVO D
#define SERVO_PIN_5 12  //SERVO E
#define SERVO_PIN_6 33  //SERVO F (gripper)

Servo servos[NUM_SERVOS];

// Define the initial positions for each servo (in degrees)
const int initial_servo1 = 80;
const int initial_servo2 = 105;
const int initial_servo3 = 0;
const int initial_servo4 = 160;
const int initial_servo5 = 70;
const int initial_servo6 = 65;

// Define the minimum and maximum angles for each servo
const int SERVO_MIN_ANGLES[NUM_SERVOS] = {0, 0, 0, 0, 0, 0};    // Minimum angles for each servo
const int SERVO_MAX_ANGLES[NUM_SERVOS] = {180, 180, 180, 180, 180, 180};  // Maximum angles for each servo

/******************************************************************/

/******************************************************************/
// Configuración puertos I2C y Puertos serie***********************/
/******************************************************************/
#define BAUD_SERIAL1 9600 // Baudrate Puerto GPS
#define RXPIN_SERIAL1 16   // cambiar por 16
#define TXPIN_SERIAL1 17   // cambiar por 17

#define SDA_PIN 23 // cambiar por 23
#define SCL_PIN 19 // cambiar por 19

TinyGPSPlus gps;

/******************************************************************/
// Configuración de OTROS PINES************************************/
/******************************************************************/
const int ledPin = 22;

/******************************************************************/
/* PROGRAMA A PARTIR DE  AQUI */
/******************************************************************/

double calculateMedian(double readings[], int numValues) {
  // Copy the readings to a temporary array
  double tempArray[numValues];
  for (int i = 0; i < numValues; i++) {
    tempArray[i] = readings[i];
  }

  // Sort the temporary array in ascending order
  for (int i = 0; i < numValues - 1; i++) {
    for (int j = i + 1; j < numValues; j++) {
      if (tempArray[j] < tempArray[i]) {
        // Swap the elements to sort the array
        double temp = tempArray[i];
        tempArray[i] = tempArray[j];
        tempArray[j] = temp;
      }
    }
  }

  // Calculate the median value
  double median;
  if (numValues % 2 == 0) {
    // For an even number of values, take the average of the middle two elements
    int midIndex = numValues / 2;
    median = (tempArray[midIndex - 1] + tempArray[midIndex]) / 2.0;
  } else {
    // For an odd number of values, take the middle element
    int midIndex = numValues / 2;
    median = tempArray[midIndex];
  }

  return median;
}

void gps_Callback() {
#ifdef __DEBUG__
  while (Serial1.available() > 0) {
    if (gps.encode(Serial1.read())) {
      display.fillRect(0, 0, 124, 20, BLACK);
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 0);
      display.print("lat:");
      display.println(latitudeData, 6);
      display.setCursor(10, 10);
      display.print("lng:");
      display.println(longitudeData, 6);
      display.display();
    }
  }
#endif
  if (gps.location.isValid()) {
    latitude_rawData = gps.location.lat();
    longitude_rawData = gps.location.lng();

    // Store the readings in the arrays
    latitudeReadings[readingsIndex] = latitude_rawData;
    longitudeReadings[readingsIndex] = longitude_rawData;
    readingsIndex = (readingsIndex + 1) % numReadings; // Move to the next position in the array

    // Calculate median of latitude and longitude readings
    latitudeData = calculateMedian(latitudeReadings, numReadings);
    longitudeData = calculateMedian(longitudeReadings, numReadings);
  } else {
    
  //pixelLoading();

  }
}

void moveServos(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6) {
 // Restrict angles to servo range
  angle1 = constrain(angle1, SERVO_MIN_ANGLES[0], SERVO_MAX_ANGLES[0]);
  angle2 = constrain(angle2, SERVO_MIN_ANGLES[1], SERVO_MAX_ANGLES[1]);
  angle3 = constrain(angle3, SERVO_MIN_ANGLES[2], SERVO_MAX_ANGLES[2]);
  angle4 = constrain(angle4, SERVO_MIN_ANGLES[3], SERVO_MAX_ANGLES[3]);
  angle5 = constrain(angle5, SERVO_MIN_ANGLES[4], SERVO_MAX_ANGLES[4]);
  angle6 = constrain(angle6, SERVO_MIN_ANGLES[5], SERVO_MAX_ANGLES[5]);

  servos[0].write(angle1);
  servos[1].write(angle2);
  servos[2].write(angle3);
  servos[3].write(angle4);
  servos[4].write(angle5);
  servos[5].write(angle6);
}

void servo_Callback() {
#ifdef __DEBUG__
#endif

  if (serialData[1] == 'A') {
    // Process servoData with identifier 'A'
    Serial.print("servoA");
    sscanf(&serialData[1], "%d", &initial_servo1);
  } else if (serialData[1] == 'B') {
    // Process servoData with identifier 'B'
    sscanf(&serialData[1], "%d", &initial_servo2);
  } else if (serialData[1] == 'C') {
    // Process servoData with identifier 'C'
    sscanf(&serialData[1], "%d", &initial_servo3);
  } else if (serialData[1] == 'D') {
    // Process servoData with identifier 'D'
    sscanf(&serialData[1], "%d", &initial_servo4);
  } else if (serialData[1] == 'E') {
    // Process servoData with identifier 'E'
    sscanf(&serialData[1], "%d", &initial_servo5);
  } else if (serialData[1] == 'F') {
    // Process servoData with identifier 'F'
    sscanf(&serialData[1], "%d", &initial_servo6);
  }
}

void serial_Callback() {
#ifdef __DEBUG__
  Serial1.println("test serial1");
  display.fillRect(0, 20, 120, 64, BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.print("sA:");
  display.println(servos[0].read());
  display.setCursor(50, 20);
  display.print("sB:");
  display.println(servos[1].read());
  display.setCursor(10, 30);
  display.print("sC:");
  display.println(servos[2].read());
  display.setCursor(50, 30);
  display.print("sD:");
  display.println(servos[3].read());
  display.setCursor(10, 40);
  display.print("sE:");
  display.println(servos[4].read());
  display.setCursor(50, 40);
  display.print("sF:");
  display.println(servos[5].read());

  display.setCursor(90, 0);
  display.print("'");
  display.print(ledChar);
  display.print("'");

  display.display();
#endif
  
  /*
  Serial.print(startMarker);
  Serial.print("x");
  Serial.print(latitudeData, 6);
  Serial.println(endMarker);

  Serial.print(startMarker);
  Serial.print("y");
  Serial.print(longitudeData, 6);
  Serial.println(endMarker);
  */

  recvData();
}

void led_Callback() {
#ifdef __DEBUG__
#endif
  ledChar = serialData[1];
}

void recvData() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;

  if (Serial.available() > 0) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != '>') {
        serialData[ndx] = rc;
        ndx++;
        if (ndx >= sizeof(serialData) - 1) { // -1 to leave space for the null terminator
          ndx = 0;
          recvInProgress = false;
          serialData[sizeof(serialData) - 1] = '\0'; // Null-terminate the array
          Serial.print(verificationChar);
        }
      }
    } else if (rc == '<') {
      recvInProgress = true;
    }
  }
  else   pixelFailure();
  }


void displayGPSInfo() {
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid()) {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid()) {
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
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

void pixelLoading() {
  pixels.clear();

  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(50);
  }
  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
  }
}

void pixelReady() {
  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
  }
  delay(1000);
  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
  delay(1000);
}

void pixelFailure() {
  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }
  delay(10);
  for (int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
  delay(10);
}

void setup() {

  delay(5000); // No quitar, para que de tiempo a debuggear

  /*******************************************************************/
  // Configuración Puertos Serie *************************************/
  Serial.begin(115200);
  Serial1.begin(BAUD_SERIAL1, SERIAL_8N1, RXPIN_SERIAL1, TXPIN_SERIAL1);
  /*******************************************************************/
  // Inicialización y escaneo de I2C *********************************/
 Wire.begin(SDA_PIN, SCL_PIN);

  byte addressI2C;
  byte errorI2C;
  bool found0x40 = false;
  bool found0x3C = false;


  for (addressI2C = 1; addressI2C < 127; addressI2C++) {
    Wire.beginTransmission(addressI2C);
    errorI2C = Wire.endTransmission();

    if (errorI2C == 0) {
     #ifdef __DEBUG__ Serial.print("I2C device found at address 0x");
      if (addressI2C < 16) {
        Serial.print("0");
     #endif
      }
    #ifdef __DEBUG__ Serial.print(addressI2C, HEX);
      Serial.println();
      // Check if the device with address 0x40 is found
      if (addressI2C == 0x40) {
        found0x40 = true;
      }
      // Check if the device with address 0x3C is found
      if (addressI2C == 0x3C) {
        found0x3C = true;
      }
    }
    #endif
  }

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  /*******************************************************************/
  // Iniciar controlador servos  *************************************/
  /*******************************************************************/
  servos[0].attach(SERVO_PIN_1);
  servos[1].attach(SERVO_PIN_2);
  servos[2].attach(SERVO_PIN_3);
  servos[3].attach(SERVO_PIN_4);
  servos[4].attach(SERVO_PIN_5);
  servos[5].attach(SERVO_PIN_6);

  // Move the servos to their initial positions
  moveServos(initial_servo1, initial_servo2, initial_servo3, initial_servo4, initial_servo5, initial_servo6);

  /*******************************************************************/
  // Configuración Threads********************************************/
  GPS_Thread->onRun(gps_Callback);
  GPS_Thread->setInterval(GPS_INTERVAL);
  controll.add(GPS_Thread);
  SERIAL_Thread->onRun(serial_Callback);
  SERIAL_Thread->setInterval(SERIAL_INTERVAL);
  controll.add(SERIAL_Thread);
  /*******************************************************************/

  /*******************************************************************/
  // Iniciar oLED y pixel RING**********************************/
  /*******************************************************************/
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pixels.begin();
  /*******************************************************************/
}

void loop() {
 
  controll.run();
}
