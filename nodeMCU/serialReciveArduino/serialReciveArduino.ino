int angleA = 0;
int angleB = 0;
int angleC = 0;
int angleD = 0;
int angleE = 0;
int angleF = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  recvData();
}

static bool isReceivingData = false;
static char receivedChars[7];
static int charIndex = 0;

void recvData() {
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();

    if (receivedChar >= 'A' && receivedChar <= 'F') {
      isReceivingData = true;
      charIndex = 0;
      memset(receivedChars, 0, sizeof(receivedChars));
      receivedChars[charIndex] = receivedChar; // Store the trigger character
      charIndex++;
    } else if (isReceivingData && charIndex < 7 && isDigit(receivedChar)) {
      receivedChars[charIndex] = receivedChar;
      charIndex++;
    } else if (receivedChar == '\n') { // Check for end of message
      isReceivingData = false;
      processData();
    } else {
      isReceivingData = false;
    }
  }
}

void processData() {
  switch (receivedChars[0]) {
    case 'A':
      angleA = atoi(receivedChars + 1);
      Serial.print("Received angleA: ");
      Serial.println(angleA);
      break;
    case 'B':
      angleB = atoi(receivedChars + 1);
      Serial.print("Received angleB: ");
      Serial.println(angleB);
      break;
    case 'C':
      angleC = atoi(receivedChars + 1);
      Serial.print("Received angleC: ");
      Serial.println(angleC);
      break;
    case 'D':
      angleD = atoi(receivedChars + 1);
      Serial.print("Received angleD: ");
      Serial.println(angleD);
      break;
    case 'E':
      angleE = atoi(receivedChars + 1);
      Serial.print("Received angleE: ");
      Serial.println(angleE);
      break;
    case 'F':
      angleF = atoi(receivedChars + 1);
      Serial.print("Received angleF: ");
      Serial.println(angleF);
      break;
    default:
      Serial.println("Invalid angle data");
  }
  memset(receivedChars, 0, sizeof(receivedChars)); // Clear the buffer after processing
  // Add any further processing or actions based on the received data here if needed
}

