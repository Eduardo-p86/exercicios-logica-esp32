
#include <Arduino.h>
#include "Led.h"
#include <LiquidCrystal_I2C.h>
#include "Botao.h"

enum EstadoJogo
{
    AGUARDANDO,
    ESPERANDO_SINAL,
    SINAL_VERDE,
    RESULTADO,
    QUEIMADA
};

EstadoJogo estado = AGUARDANDO;

unsigned long tempoSinal = 0;
unsigned long tempoInicio = 0;
unsigned long tempoReacao = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

Led LedVerde(2);
Botao botaoA(32);
Botao botaoB(33);

void iniciarJogo()
{
    switch (estado)
    {
        case AGUARDANDO:
            if (botaoA.pressionou())
            {
                LedVerde.desligar();
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Prepare-se!");

                tempoSinal = millis() + random(2000, 5001);
                estado = ESPERANDO_SINAL;
            }
            break;

        case ESPERANDO_SINAL:
            if (botaoB.pressionou())
            {
                estado = QUEIMADA;
            }
            else if (millis() >= tempoSinal)
            {
                LedVerde.ligar();
                tempoInicio = millis();

                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("APERTE B!");

                estado = SINAL_VERDE;
            }
            break;

        case SINAL_VERDE:
            if (botaoB.pressionou())
            {
                tempoReacao = millis() - tempoInicio;
                LedVerde.desligar();

                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Tempo de reacao:");
                lcd.setCursor(0, 1);
                lcd.print(tempoReacao);
                lcd.print(" ms");

                lcd.setCursor(0, 2);

                if (tempoReacao < 200)
                {
                    lcd.print("Reflexo excelente!");
                }
                else if (tempoReacao < 350)
                {
                    lcd.print("Reflexo bom!");
                }
                else
                {
                    lcd.print("Continue treinando!");
                }

                estado = RESULTADO;
            }
            break;

        case RESULTADO:
            if (botaoA.pressionou())
            {
                estado = AGUARDANDO;
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("A para iniciar");
            }
            break;

        case QUEIMADA:
            LedVerde.desligar();

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Queimada de");
            lcd.setCursor(0, 1);
            lcd.print("largada!");

            estado = RESULTADO;
            break;
    }
}
