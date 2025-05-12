**Projeto: Servidor Web sobre o status dos botões da placa BitDogLab RP2040** 🚀🕹️💡

Este repositório contém o código-fonte e a configuração de build para um servidor web rodando na placa BitDogLab RP2040. O servidor oferece uma interface HTTP simples para ler o estado dos botões e controlar os LEDs integrados via Wi‑Fi. O projeto está modularizado em componentes independentes (`botoes`, `wifi`, `conexao`), cada um construído como uma biblioteca separada usando CMake. 📡🧩⚙️

---

## Sumário 📘📑🧭

1. [Hardware e Pré-requisitos](#hardware-e-pré-requisitos)
2. [Estrutura de Diretórios](#estrutura-de-diretórios)
3. [Build e Flash](#build-e-flash)
4. [Visão Geral dos Módulos](#visão-geral-dos-módulos)

   * [Botões (`botoes/`)](#botões-botoes)
   * [Wi‑Fi (`wifi/`)](#wi‑fi-wifi)
   * [Conexão (`conexao/`)](#conexão-conexao)
   * [Aplicação Principal (`main.c`)](#aplicação-principal-mainc)
5. [Configuração](#configuração)
6. [Uso](#uso)
7. [Solução de Problemas](#solução-de-problemas)
8. [Licença](#licença)

---

## Hardware e Pré-requisitos 🧰📡🔌

* **Placa**: BitDogLab RP2040
* **Host de Desenvolvimento**: Qualquer PC com CMake (>= 3.13), Ninja ou Make, e Pico SDK instalado
* **Conexões**:

  * Botão A → GP16
  * Botão B → GP17
  * LEDs → GP18 (Verde), GP19 (Azul), GP20 (Vermelho)
  * 5V e GND conforme pinagem da placa
* **Rede**: SSID e senha do Wi‑Fi configurados em `wifi/wifi.h`.

---

## Estrutura de Diretórios 📁🧱📂

```text
project_root/
├── CMakeLists.txt             # Script de build principal
├── main.c                     # Ponto de entrada: inicialização e loop principal
├── botoes/                    # Módulo de manipulação dos botões
│   ├── CMakeLists.txt
│   ├── botoes.h
│   └── botoes.c
├── wifi/                      # Módulo de inicialização e gestão de Wi‑Fi
│   ├── CMakeLists.txt
│   ├── wifi.h
│   └── wifi.c
└── conexao/                   # Módulo de conexão TCP / HTTP POST
    ├── CMakeLists.txt
    ├── conexao.h
    └── conexao.c
```

---

## Build e Flash 🧪🛠️📤

1. **Inicializar o SDK** (apenas na primeira vez):

   ```bash
   git clone https://github.com/raspberrypi/pico-sdk.git
   cd pico-sdk
   git submodule update --init
   ```

2. **Construir o projeto**:

   ```bash
   cd project_root
   mkdir build && cd build
   cmake .. -G Ninja
   ninja
   ```

3. **Gravar o UF2**:

   * Segure BOOTSEL na RP2040 e conecte via USB.
   * Copie `led_control_webserver.uf2` de `build/` para a unidade montada.

---

## Visão Geral dos Módulos 🧩🧠📦

### Botões (`botoes/`) 🟢🔘👆

* **Interface**: `botoes.h`
* **Funções**:

  * `void iniciar_botoes(void);`
    Configura os pinos GP16 e GP17 como entradas com pull-up.
  * `bool botao_a_pressionado(void);`
    Retorna `true` se o botão A estiver pressionado.
  * `bool botao_b_pressionado(void);`
    Retorna `true` se o botão B estiver pressionado.

### Wi‑Fi (`wifi/`) 📶📲🔐

* **Interface**: `wifi.h`
* **Funções**:

  * `int iniciar_conexao_wifi(void);`
    Inicializa o hardware Wi‑Fi, conecta à rede definida em `NOME_WIFI` e imprime o IP.

> **Nota**: SSID e senha estão definidos em `wifi.h`:
>
> ```c
> #define NOME_WIFI  "MARCOS_5G"
> #define SENHA_WIFI "Piy211940"
> ```

### Conexão (`conexao/`) 🌐🔌📨

* **Interface**: `conexao.h`
* **Função**:

  * `void enviar_dados_para_nuvem(const EstadoBotoes *estado);`
    Resolve o DNS de `PROXY_HOST`, abre conexão TCP e envia JSON com os estados dos botões.
* **Callbacks**:

  * Resolução DNS, conexão TCP, envio de dados (`callback_conectado`), recebimento da resposta (`callback_resposta_recebida`).
* **Configuração**:

  ```c
  #define PROXY_HOST "meu.proxy.exemplo.com"
  #define PROXY_PORT 8080
  ```

### Aplicação Principal (`main.c`) 🎯🔁💻

1. **Inicializa I/O padrão** (`stdio_init_all()`)
2. **Botões**: `iniciar_botoes()`
3. **Wi‑Fi**: `iniciar_conexao_wifi()`
4. **Aloca e inicializa** struct `EstadoBotoes`
5. **Loop principal**:

   * Poll de Wi‑Fi: `cyw43_arch_poll()`
   * Leitura dos estados dos botões
   * Ao detectar mudança, preenche `EstadoBotoes` e chama `enviar_dados_para_nuvem()`

---

## Configuração ⚙️📄📝

* **Credenciais Wi‑Fi**: `wifi/wifi.h`
* **Servidor Proxy**: `conexao/conexao.h`
* **Pinos GPIO**: definidos em `botoes/botoes.h` (ajuste conforme fiação)

---

## Uso 🖱️🌍🧪

1. Ligue a placa.
2. Observe a saída serial a 115200 baud: status de conexão, endereço IP, resolução DNS, detalhes da requisição e resposta do servidor.
3. Pressione o Botão A ou B para enviar mudanças de estado em JSON para seu endpoint proxy.

Exemplo de payload JSON:

```json
{ "botao_a": 1, "botao_b": 0 }
```

---

## Solução de Problemas 🐞🧯🛠️

* **Falha na conexão Wi‑Fi**: verifique SSID/senha em `wifi.h` e intensidade do sinal.
* **DNS não resolve**: confirme `PROXY_HOST` ou tente usar IP estático.
* **Erro TCP**: verifique porta e disponibilidade do servidor.
* **Malloc falhou**: recursos limitados; use buffers estáticos se necessário.

---

## Licença 📄🔓🧾

Este projeto está licenciado sob a **MIT License**. Veja `LICENSE` para mais detalhes. 📘✅📥
