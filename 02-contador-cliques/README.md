# 02 - Contador de Cliques com LCD

Este exercício implementa um sistema de contador de cliques que é controlado por dois botões e exibe os resultados em tempo real em um display LCD via I2C.

## O que foi desenvolvido
- **Classe `Botao`**: Criação de uma classe dedicada a gerenciar a leitura dos pinos dos botões (pinos 2 e 3) e contabilizar os cliques de forma segura, possivelmente lidando com transições de estado.
- **Integração com Display LCD I2C**: Uso da biblioteca `LiquidCrystal_I2C` para apresentar os dados em uma tela (20x4).
- **Lógica de Paridade**: O código verifica dinamicamente se o contador atual é um número "Par" ou "Ímpar" e exibe essa informação no display.
- **Depuração Serial**: O valor do contador também é enviado para a porta Serial (9600 bps) para fins de monitoramento e debug.

## Hardware Utilizado
- 1x ESP32 (ou compatível)
- 2x Botões (Push buttons nos pinos 2 e 3)
- 1x Display LCD I2C (endereço 0x27)
