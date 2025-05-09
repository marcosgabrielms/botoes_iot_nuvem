#include "wifi.h"
#include "pico/cyw43_arch.h"

int conexao_wifi() {

    int conexao;

    while(cyw43_arch_init())
    {
        printf("Falha ao inicializar WIFI\n");
        sleep_ms(100);
        return -1;
    }

    cyw43_arch_enable_sta_mode();

    printf("Conectando ao WIFI '%s'...\n", NOME_WIFI);

    conexao = cyw43_arch_wifi_connect_timeout_ms(NOME_WIFI, SENHA_WIFI, CYW43_AUTH_WPA2_AES_PSK, 10000);

    char *mensagem = (conexao == 0) ? "WIFI Conectado...\n": "Falha ao Conectar...\n";
    printf(mensagem);
    return conexao;
}