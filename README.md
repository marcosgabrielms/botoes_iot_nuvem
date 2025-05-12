
### Arquivos Principais

#### 1. `src/botoes_iot_nuvem.c`
Este é o arquivo principal do projeto. Ele contém a função `main`, que inicializa o Wi-Fi, configura a comunicação I2C e conecta-se à rede. Ele também imprime mensagens no console e exibe o endereço IP obtido.

#### 2. `src/utils/botoes/botoes.c` e `src/utils/botoes/botoes.h`
Estes arquivos implementam a lógica para inicializar e ler o estado de dois botões físicos conectados ao Raspberry Pi Pico W.

- **Funções principais:**
  - `iniciar_botoes()`: Configura os pinos GPIO dos botões.
  - `a_pressionado()`: Retorna `true` se o botão A estiver pressionado.
  - `b_pressionado()`: Retorna `true` se o botão B estiver pressionado.

#### 3. `src/utils/servidor_nuvem/conexao.c` e `src/utils/servidor_nuvem/conexao.h`
Estes arquivos implementam a lógica para enviar dados para um servidor na nuvem via TCP.

- **Funções principais:**
  - `enviar_dados_para_nuvem()`: Resolve o DNS do servidor e envia os dados dos botões em formato JSON.
  - Callbacks para gerenciar conexões TCP e respostas do servidor.

#### 4. `CMakeLists.txt`
Arquivo de configuração do CMake para compilar o projeto. Ele define as dependências, bibliotecas e configurações específicas do Raspberry Pi Pico W.

#### 5. `pico_sdk_import.cmake`
Arquivo que localiza e importa o SDK do Raspberry Pi Pico. Ele permite que o projeto utilize as bibliotecas e APIs fornecidas pelo SDK.

#### 6. `lwipopts.h`
Configurações específicas para a biblioteca LWIP, usada para comunicação de rede. Este arquivo ajusta parâmetros como tamanho de buffer, suporte a DHCP, e opções de depuração.

### Arquivos de Configuração do VS Code

A pasta `.vscode/` contém arquivos para configurar o ambiente de desenvolvimento no Visual Studio Code:

- **`c_cpp_properties.json`**: Configura o IntelliSense para o C/C++.
- **`cmake-kits.json`**: Define o kit de compilação para o CMake.
- **`extensions.json`**: Recomenda extensões úteis para o projeto.
- **`launch.json`**: Configurações de depuração para o Raspberry Pi Pico.
- **`settings.json`**: Configurações específicas do projeto, como caminhos para o SDK e ferramentas.
- **`tasks.json`**: Define tarefas como compilar, executar e flashar o firmware no Pico.

### Arquivo `.gitignore`
Ignora a pasta `build/` para evitar que arquivos gerados durante a compilação sejam adicionados ao repositório Git.

## Como Compilar e Executar

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente.
2. Abra o projeto no Visual Studio Code.
3. Compile o projeto usando a tarefa "Compile Project" (`Ctrl+Shift+B`).
4. Flash o firmware no Pico W usando a tarefa "Flash".
5. Conecte o Pico W a uma rede Wi-Fi e observe os logs no console.

## Dependências

- **Hardware**: Raspberry Pi Pico W, botões físicos conectados aos pinos GPIO 5 e 6.
- **Software**:
  - Raspberry Pi Pico SDK
  - Biblioteca LWIP para comunicação de rede
  - Ferramentas como `ninja`, `cmake`, e `openocd`.

## Expansões Futuras

- Adicionar suporte a mais sensores via I2C.
- Implementar autenticação no servidor na nuvem.
- Melhorar o tratamento de erros na comunicação de rede.

## Licença

Este projeto é distribuído sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
