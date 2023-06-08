#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11); // RX, TX pins for Bluetooth module

#define relay2_pin 7

String voice = "";

void setup()

{

  Serial.begin(9600); // Set rate for communicating with phone

  bluetoothSerial.begin(9600); // Initialize Bluetooth serial communication

  pinMode(relay2_pin, OUTPUT); // Set relay2 as an output

  

  digitalWrite(relay2_pin, HIGH);

}

void loop()

{

  while (Serial.available()) // Check if there are available bytes to read from serial di

  {

    delay(10); // Delay to make it stable

    char c = Serial.read(); // Conduct a serial read

    if (c == '#')

    {

      break; // Stop the loop once '#' is detected after a word

    }

    voice += c; // Append character to voice string

  }

  while (bluetoothSerial.available()) // Check if there are available bytes to read from Bluetooth module

  {

    delay(10); // Delay to make it stable

    char c = bluetoothSerial.read(); // Conduct a Bluetooth serial read

    if (c == '#')

    {

      break; // Stop the loop once '#' is detected after a word

    }

    voice += c; // Append character to voice string

  }

  if (voice.length() > 0)

  {

    if (voice == "*2.5 ml")

    {

      digitalWrite(relay2_pin, LOW);

      delay(200);

      digitalWrite(relay2_pin, HIGH); // Turn off relay2 after delay

    }

    else if (voice == "*5 ml")

    {

      digitalWrite(relay2_pin, LOW);

      delay(250);

      digitalWrite(relay2_pin,HIGH); // Turn off relay2 after delay

    }

    else if (voice == "*10 ml")

    {

      digitalWrite(relay2_pin, LOW);

      delay(400);

      digitalWrite(relay2_pin, HIGH); // Turn off relay2 after delay

    }

    else if (voice == "*20 ml")

    {

      digitalWrite(relay2_pin, LOW);

      delay(450);

      digitalWrite(relay2_pin, HIGH); // Turn off relay2 after delay

    }

    voice = ""; // Reset voice string

  }

}
