#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
  private:

    uint8_t _pinoLed;
    bool _estadoLed = 0;
    bool _estaPiscando = false;
    uint32_t _tempoAcaoAnterior_ms = 0;
    uint32_t _tempoEsperaAlternar_ms = 0;


    

    public:

    Led(uint8_t pino);
  
    void iniciar();
    void atualizar();
    void ligar();
    void desligar();
    void ativarPiscar(uint32_t tempoEspera_ms = 500);
    void desativarPiscar();
    void alternar();

    uint8_t getPinoLed();
    void setEstadoLed(bool estado);

};
#endif