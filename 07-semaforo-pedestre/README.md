# 07 - Semáforo com Botão de Pedestre

Este projeto implementa um sistema de semáforo veicular integrado com botão de pedestre, temporização não bloqueante com `millis()` e visualização dos estados e contagem regressiva em um display LCD I2C.

## O que foi desenvolvido
- **Máquina de Estados do Semáforo**:
  - **VERDE**: Duração padrão de 5 segundos. Caso o pedestre pressione o botão e o sinal já estiver verde por pelo menos 2 segundos, o ciclo é encurtado, avançando para o estado AMARELO.
  - **AMARELO**: Duração de 2 segundos de transição/atenção.
  - **VERMELHO**: Duração de 5 segundos de parada para os veículos / travessia dos pedestres.
- **Interação com Pedestre**: O Botão A (Pino 32) funciona como a botoeira de travessia. Se pressionado durante o sinal verde, ele antecipa o fechamento respeitando a cláusula de guarda de segurança de tempo mínimo de verde (2 segundos).
- **Display LCD 20x4 (I2C)**:
  - **Linha 1**: Exibe o estado atual do semáforo (`VERDE`, `AMARELO` ou `VERMELHO`).
  - **Linha 2**: Exibe o tempo restante para a mudança de estado em segundos (`Tempo restante: X s`).
- **Temporização não bloqueante**: Lógica desenvolvida inteiramente com `millis()`, garantindo que o botão responda a qualquer momento sem travar o processamento.

## Hardware Utilizado
- 1x ESP32 (ou compatível)
- 3x LEDs:
  - LED Verde (Pino 2)
  - LED Amarelo (Pino 4)
  - LED Vermelho (Pino 5)
- 3x Resistores adequados para os LEDs
- 1x Botão (Push button no Pino 32 com `INPUT_PULLUP`)
- 1x Display LCD 20x4 com módulo I2C (endereço 0x27)
