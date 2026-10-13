#include <LiquidCrystal_I2C.h>
#include "Botao.h"
#include "Led.h"

int intensidade = 0;
Led LedVermelho(2);
Led LedAmarelo(4);
Led LedVerde(5);
Botao botaoA(32);
Botao botaoB(33);

LiquidCrystal_I2C lcd(0x27,20,4);

void inicializar()
{
    LedVermelho.iniciar();
    LedAmarelo.iniciar();
    LedVerde.iniciar();       

    botaoA.iniciar();
    botaoB.iniciar();

    lcd.init();
    lcd.backlight();

}
void nivelLeds()
{
    static int intensidade = 0;

    if (botaoA.clickMais() && intensidade < 10)
    {
        intensidade++;
    }

    if (botaoB.clickMais() && intensidade > 0)
    {
        intensidade--;
    } 

    ledcWrite(LedVermelho.getPinoLed(), intensidade * 255 / 10);
    ledcWrite(LedAmarelo.getPinoLed(), intensidade * 255 / 10);
    ledcWrite(LedVerde.getPinoLed(), intensidade * 255 / 10);

    if (intensidade == 10)
    {
        LedVermelho.ativarPiscar(500);
    }
}
 
void atualizarLeds()
{
    LedVermelho.atualizar();
    LedAmarelo.atualizar();
    LedVerde.atualizar();
}

void atualizarLCD()
{
    int porcentagem = intensidade * 10;

    lcd.setCursor(0, 0);
    lcd.print("Intensidade: ");
    lcd.print(porcentagem);
    lcd.print("%   ");

    lcd.setCursor(0, 1);

    for (int i = 0; i < 10; i++)
    {
        if (i < intensidade)
        {
            lcd.print("#");
        }
        else
        {
            lcd.print("-");
        }
    }
}