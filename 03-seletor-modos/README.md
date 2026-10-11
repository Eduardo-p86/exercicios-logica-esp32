# 03 - Seletor de Modos com LEDs e LCD

Este exercício implementa um seletor de modos de iluminação para múltiplos LEDs, controlado por botões e com feedback visual em tempo real em um display LCD I2C.

## O que foi desenvolvido
- **Máquina de Estados / Seleção de Modos**: Alternância entre 4 modos de operação distintos:
  - **Modo 0 ("Todos apagados")**: Todos os LEDs permanecem desligados.
  - **Modo 1 ("Todos acesos")**: LEDs vermelho, amarelo e verde ficam continuamente ligados.
  - **Modo 2 ("Todos piscam 500ms")**: Todos os LEDs piscam sincronizados a cada 500ms usando temporização não bloqueante com `millis()`.
  - **Modo 3 ("Vermelho pisca 150ms")**: Apenas o LED vermelho pisca rapidamente a cada 150ms via `millis()`, com os demais desligados.
- **Controle por Botões**:
  - **Botão A (Pino 2)**: Avança sequencialmente entre os modos (`(modoAtual + 1) % 4`).
  - **Botão B (Pino 3)**: Reseta imediatamente para o Modo 0.
- **Display LCD 20x4 (I2C)**: Exibe na primeira linha o número do modo atual e na segunda linha a descrição do comportamento dos LEDs.
- **Temporização não bloqueante**: Utilização de `millis()` para controle das piscadas sem travar a leitura dos botões ou a atualização da tela.

## Hardware Utilizado
- 1x ESP32 (ou compatível)
- 3x LEDs:
  - Vermelho (Pino 13)
  - Amarelo (Pino 12)
  - Verde (Pino 14)
- 3x Resistores para os LEDs
- 2x Botões (Push buttons nos pinos 2 e 3)
- 1x Display LCD 20x4 com adaptador I2C (endereço 0x27)
