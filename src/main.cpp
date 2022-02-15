/*
  Titre      : communication entre 2 uC MKR1000 qui est l'esclave
  Auteur     : Duvalier Tsagmo
  Date       : 15/02/2022
  Description: la communication est I2C QUI va se faire entre deux uC
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Wire.h>

// Declaration des variables
const int LED_PIN = 0;
int Recoi_Donnee = 0;
int Allume = 0;

// prototype de fonctionnement pour celui qui recoi
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
