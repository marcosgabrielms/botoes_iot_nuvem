#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include <stdlib.h>

#include "botoes.h"
#include "conexao.h"
#include "wifi.h"


bool estado_ant_botao_a;
bool estado_ant_botao_b;

int iniciar_conexao_wifi() 
{
   printf("Conectando-se à rede: %s\n", NOME_WIFI);

    int status_conexao = conexao_wifi();
    if (status_conexao == 0) {
        printf("CONEXAO ESTABECIDA\n");
        printf("IP do dispositivo: %s\n", ipaddr_ntoa(&netif_default->ip_addr));
    } else {
        printf("FALHA NA CONEXAO\n");
    }

    sleep_ms(3000);

    return status_conexao;
}
    
int main()
{
    stdio_init_all(); 
    iniciar_botoes(); 
    sleep_ms(1500);

    conexao_wifi();

    estado_ant_botao_a = botao_a_pressionado();
    estado_ant_botao_b = botao_b_pressionado();

    enviar_dados_para_nuvem(estado_botoes);

    while (true){
        cyw43_arch_poll();

        bool estado_atual_botao_a = botao_a_pressionado();
        bool estado_atual_botao_b = botao_b_pressionado();

        if ((estado_ant_botao_a != estado_atual_botao_a) || (estado_ant_botao_b != estado_atual_botao_b))
        {
            estado_botoes->botao_a = estado_atual_botao_a;
            estado_botoes->botao_b = estado_atual_botao_b;

            enviar_dados_para_nuvem(estado_botoes);

            estado_ant_botao_a = estado_botoes->botao_a;
            estado_ant_botao_b = estado_botoes->botao_b;
        }
    }
    cyw43_arch_deinit();
    free(estado_botoes);
    return 0;
}