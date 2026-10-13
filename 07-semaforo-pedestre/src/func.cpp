#include "led.cpp"
#include <Arduino.h>
#include "botao.cpp"
#include <LiquidCrystal_I2C.h>
#include "func.h"

Botao botaoA(32);

Led LedVerde(2);
Led LedAmarelo(4);
Led LedVermelho(5);

unsigned long tempoPassado = 0;
uint32_t tempoAnterior = 0;
unsigned long tempoRestante = 0;
const unsigned long tempoVerde = 5000;
const unsigned long tempoVermelho = 5000;
const unsigned long tempoAmarelo = 2000;

LiquidCrystal_I2C lcd(0x27, 20, 4);

enum EstadoSemaforo
{
    VERDE,
    AMARELO,
    VERMELHO
};

EstadoSemaforo estado = VERDE;

void atualizaSemaforo()
{
    lcd.init();
    lcd.backlight();
    switch (estado)
    {
    case VERDE:
        tempoPassado = millis() - tempoAnterior;
        tempoRestante = tempoVerde - tempoPassado;

        lcd.setCursor(0, 0);
        lcd.print("Semaforo: VERDE    ");

        lcd.setCursor(0, 1);
        lcd.print("Tempo restante: ");
        lcd.print(tempoRestante / 1000);
        lcd.print(" s   ");

        if (tempoPassado >= 2000 && botaoA.pressionou())
        {
            estado = AMARELO;
            tempoAnterior = millis();
        }

        else if (tempoPassado >= tempoVerde)
        {
            estado = AMARELO;
            tempoAnterior = millis();
        }

        break;

    case AMARELO:
        tempoPassado = millis() - tempoAnterior;

        if (tempoPassado < tempoAmarelo)
        {
            tempoRestante = tempoAmarelo - tempoPassado;
        }
        else
        {
            tempoRestante = 0;
        }

        lcd.setCursor(0, 0);
        lcd.print("Semaforo: AMARELO    ");

        lcd.setCursor(0, 1);
        lcd.print("Tempo restante: ");
        lcd.print(tempoRestante / 1000);
        lcd.print(" s   ");

        if (tempoPassado >= tempoAmarelo)
        {
            estado = VERMELHO;
            tempoAnterior = millis();
        }
        break;

    case VERMELHO:
        tempoPassado = millis() - tempoAnterior;

        if (tempoPassado < tempoVermelho)
        {
            tempoRestante = tempoVermelho - tempoPassado;
        }
        else
        {
            tempoRestante = 0;
        }

        lcd.setCursor(0, 0);
        lcd.print("Semaforo: VERMELHO    ");

        lcd.setCursor(0, 1);
        lcd.print("Tempo restante: ");
        lcd.print(tempoRestante / 1000);
        lcd.print(" s   ");

        if (tempoPassado >= tempoVermelho)
        {
            estado = VERDE;
            tempoAnterior = millis();
        }

        break;
    }
}