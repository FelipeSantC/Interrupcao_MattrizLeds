#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "ws2812.pio.h"

#define IS_RGBW false
#define NUM_PIXELS 25
#define WS2812_PIN 7
#define tempo 100
#define  button_A 5
#define  button_B 6

const uint led_pin_red = 13;
const uint32_t BRIGHTNESS = 0xCC; // Ajusta o brilho aqui (0x00 para apagado, 0xFF para brilho máximo)

// Variáveis globais
static volatile uint a = 0;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

// Prototipação da função de interrupção --Botao_A
static void gpio_irq_button(uint gpio, uint32_t events);


// Acionamento da matriz de LEDs - ws2812b
void desenhar_matriz(PIO pio, uint sm, const uint32_t *desenho) {
    for (int i = 0; i < NUM_PIXELS; i++) { // Aplica a cor ao padrão
       pio_sm_put_blocking(pio, sm, (desenho[24-i]) * BRIGHTNESS); 
    }
}

//Funcoes numeros
void numero_0(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000, 
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_1(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x7F000000, 0x00000000, 
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_2(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x00000000, 0x00000000, 
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_3(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x7F000000, 0x7F000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000, 
        0x7F000000, 0x7F000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x7F000000, 0x7F000000, 0x7F000000, 0x00000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_4(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x7F000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 
        0x7F000000, 0x7F000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_5(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x7F000000, 0x00000000, 
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_6(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x7F000000, 0x00000000, 
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_7(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x7F000000, 0x7F000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000, 
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_8(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000, 
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x00000000, 0x7F000000, 0x00000000,
        0x00000000, 0x7F000000, 0x7F000000, 0x7F000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}

void numero_9(PIO pio, uint sm) {
    // Vetor de imagem para matriz de LEDs
    const uint32_t frame1[NUM_PIXELS] = {
         0x7F000000, 0x7F000000, 0x7F000000,  0x00000000,  0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000,  0x7F000000, 
        0x7F000000, 0x7F000000, 0x7F000000, 0x00000000,  0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x7F000000, 0x00000000, 0x00000000
    };
    // Exibindo a animação
    desenhar_matriz(pio, sm, frame1); 
    sleep_ms(200); // Intervalo entre os frames
}


int main(){

    stdio_init_all();
    //configuração pio
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    // Inicializa o LED
    gpio_init(led_pin_red);              // Inicializa o pino do LED
    gpio_set_dir(led_pin_red, GPIO_OUT); // Configura o pino como saída

    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(button_A);         // Habilita o pull-up interno

    gpio_init(button_B);
    gpio_set_dir(button_B, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(button_B);         // Habilita o pull-up interno

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_button);

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_button);


    while (true) {
        gpio_put(led_pin_red, true);
        sleep_ms(tempo);
        gpio_put(led_pin_red, false);
        sleep_ms(tempo);
        switch (a)
        {
        case 0:
            numero_0(pio, sm);
            break;

        case 1:
            numero_1(pio, sm);
            break;
        case 2:
            numero_2(pio, sm);
            break;
        case 3:
            numero_3(pio, sm);
            break;
        case 4:
            numero_4(pio, sm);
            break;
        case 5:
            numero_5(pio, sm);
            break;
        case 6:
            numero_6(pio, sm);
            break;
        case 7:
            numero_7(pio, sm);
            break;
        case 8:
            numero_8(pio, sm);
            break;
        case 9:
            numero_9(pio, sm);
            break;
        default:
            break;
        }
    }
}

// Função de interrupção com debouncing
void gpio_irq_button(uint gpio, uint32_t events)
{
    if (gpio == button_A)
    {
      
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        if (a < 9)
        {
           a++;   // incrementa a variavel de verificação
        }
        printf("Valor de A = %d\n", a);
        printf("Botão A\n");              
    }  
    } else if (gpio == button_B)
    {
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        if (a > 0)
        {
           a--;
           
        }  
        printf("Valor de a = %d\n", a);
        printf("Botão B\n");
    }
}
}

