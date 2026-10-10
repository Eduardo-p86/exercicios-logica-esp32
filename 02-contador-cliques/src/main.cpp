#include <Arduino.h>
#include "Botao.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Botao botaoMais(2);
Botao botaoMenos(3);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    botaoMais.iniciar();
    botaoMenos.iniciar();

    lcd.setCursor(0, 0);
    lcd.print("Contador de cliques");
}

void loop()
{
    botaoMais.clickMais();
    botaoMenos.clickMenos();

    unsigned int contador = Botao::getContador();

    lcd.setCursor(0, 1);
    lcd.print("Valor: ");
    lcd.print(contador);
    lcd.print("      ");

    lcd.setCursor(0, 2);
    lcd.print(contador % 2 == 0 ? "Par" : "Impar");
    lcd.print("              ");

    Serial.print("contador: ");
    Serial.println(contador);
    delay(20);
}