#include <Arduino.h>
#ifndef _BOTAO_H_
#define _BOTAO_H_

class Botao{
private:
    uint8_t pinoBotao;
    bool estadoAtualBotao = HIGH;
    bool estadoAnteriorBotao = HIGH;
    static unsigned int contadorCliques;

public:
    Botao(uint8_t pino);
    void iniciar();
    bool lerEstado();
    bool atualizar();
    bool pressionou();
    bool soltou();
    bool clickMais();
    bool clickMenos();
    static unsigned int getContador();
    static void resetContador();
};

#endif