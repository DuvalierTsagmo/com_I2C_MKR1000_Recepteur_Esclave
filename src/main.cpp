
#include <Arduino.h>
#include <Wire.h>

const int LED_PIN = 0;
int Recoi_Donnee = 0;
int Allume = 0;

void Recevoir(int b)
{
    Recoi_Donnee = Wire.read();
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Wire.begin(9);
    Wire.onReceive(Recevoir);
}

void loop()
{
    Allume = map(Recoi_Donnee, 0, 1023, 0, 255);
    analogWrite(LED_PIN, Allume);
}
