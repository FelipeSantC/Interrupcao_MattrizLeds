# README

## Descrição

Este código controla uma matriz de LEDs WS2812B com a placa **Raspberry Pi Pico**. Ele exibe números de 0 a 9, que são animados na matriz, e permite alternar entre os números com os botões A e B conectados aos pinos GPIO da placa. O código utiliza a biblioteca `pico-sdk` e a API do Raspberry Pi para controlar a matriz e os botões de forma eficiente.

## Requisitos

- Raspberry Pi Pico
- Matriz de LEDs WS2812B
- Botões conectados aos pinos GPIO 5 e 6
- Ambiente de desenvolvimento configurado para o Raspberry Pi Pico

### Dependências

- **pico-sdk**: A biblioteca do Raspberry Pi para controle do hardware.
- **ws2812.pio**: Programação personalizada para controlar os LEDs WS2812B.

## Pinagem

- **GPIO 7**: Pino de controle da matriz de LEDs WS2812B.
- **GPIO 5**: Botão A para incrementar o número exibido.
- **GPIO 6**: Botão B para decrementar o número exibido.
- **GPIO 13**: LED indicador de status (ligado e desligado).

## Funcionalidade

1. **Matriz de LEDs**: O código faz uso de uma matriz de LEDs WS2812B para exibir os números de 0 a 9. Cada número é representado por um padrão específico de LEDs acesos.
   
2. **Botões A e B**: 
   - Botão A (GPIO 5): Incrementa o número exibido na matriz (de 0 a 9).
   - Botão B (GPIO 6): Decrementa o número exibido na matriz (de 0 a 9).
   
3. **Debouncing**: Implementação de debouncing para garantir que os botões A e B não sejam pressionados repetidamente de forma indesejada.

4. **Brilho do LED**: O brilho do LED é controlado pela constante `BRIGHTNESS`, que pode ser ajustada para um valor entre 0 (apagado) e 255 (brilho máximo).

## Como Funciona

1. **Inicialização**: 
   - O código inicializa a comunicação com a matriz de LEDs WS2812B.
   - Configura os botões A e B com pull-up interno e habilita as interrupções para detecção de pressão.
   
2. **Loop Principal**:
   - A cada iteração, o código alterna o LED indicador (GPIO 13) entre ligado e desligado.
   - Em seguida, dependendo do valor da variável `a`, um número de 0 a 9 é exibido na matriz de LEDs.
   
3. **Interrupções**:
   - Quando um botão é pressionado, a variável `a` é incrementada ou decrementada (dependendo do botão pressionado) e o número correspondente é exibido na matriz.
   
4. **Animação**: A exibição dos números é realizada de forma animada, com cada número sendo exibido por 200ms.

## Compilação e Execução

1. **Compilação**: 
   - Para compilar o código, use o ambiente de desenvolvimento do Raspberry Pi Pico, conforme a documentação oficial da [pico-sdk](https://github.com/raspberrypi/pico-sdk).
   
2. **Flash no Raspberry Pi Pico**:
   - Conecte a placa ao seu computador e envie o arquivo compilado para a memória flash utilizando o **Raspberry Pi Imager** ou outro método de sua preferência.
   
3. **Execução**: 
   - Ao executar o código, a matriz de LEDs começará a exibir números de 0 a 9. Os botões A e B permitirão alternar entre esses números.

## Funções Principais

- **`desenhar_matriz(PIO pio, uint sm, const uint32_t *desenho)`**: 
   - Função responsável por desenhar um número na matriz de LEDs com base no padrão fornecido.

- **Funções de números** (`numero_0`, `numero_1`, ..., `numero_9`): 
   - Cada uma dessas funções contém um vetor que representa o padrão de LEDs para o respectivo número.

- **`gpio_irq_button(uint gpio, uint32_t events)`**:
   - Função de interrupção para detectar pressionamentos nos botões A e B, controlando o valor de `a`.
