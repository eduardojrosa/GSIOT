<h1 align="center">GS - IOT - Eco Power ☀️ </h1>

<div align="center">


| Integrantes      |            Responsabilidades          | Turma      |   RM     |
| --------------   | ------------------------------------- | ---------- | -------- |
| Cauã Couto       | Desenvolvimento do projeto em Java    |  2TDSS     |  97755   |
| Eduardo Júnio    | Documentação do sistema               |  2TDSPV    |  552374  |
| José dos Santos  | Documentação do sistema               |  2TDSS     |  552367  |
| Kaique Agostinho | Mapeamento das tabelas e relações     |  2TDSS     |  550815  |
| Thiago Gil       | Mapeamento das tabelas e relações     |  2TDSPV    |  551211  |
</div>

# Monitoramento de Energia Solar com ESP32

## Descrição

Este projeto visa criar um sistema de monitoramento de energia solar utilizando o microcontrolador **ESP32**. O sistema coleta dados de sensores de **tensão solar**, **tensão de bateria** e um **potenciômetro**. Esses dados são enviados em tempo real para a plataforma **ThingSpeak**, onde são visualizados em gráficos interativos. 

A solução permite monitorar o estado de um sistema de energia solar, facilitando a gestão e a análise de dados de energia de forma remota.

## Objetivo

O objetivo deste projeto é monitorar as seguintes variáveis:
- **Tensão Solar**: Medição da tensão gerada pelos painéis solares.
- **Tensão da Bateria**: Medição da tensão de uma bateria para verificar o nível de carga.
- **Valor do Potenciômetro**: Medição de um potenciômetro utilizado para ajustar a carga ou outros parâmetros.

Esses dados serão enviados para o **ThingSpeak**, permitindo a visualização de gráficos e facilitando o monitoramento remoto do sistema de energia solar.


![Monitoração thingspeak](https://github.com/eduardojrosa/GSIOT/raw/main/thingspeak.PNG)

 

## Tecnologias Utilizadas

- **ESP32**: Microcontrolador utilizado para a coleta de dados dos sensores e envio para a nuvem.
- **ThingSpeak**: Plataforma IoT para visualização e monitoramento dos dados em tempo real.
- **Arduino IDE**: Ambiente de desenvolvimento utilizado para programar o ESP32.
- **Wokwi**: Simulador de circuitos utilizado para testar o projeto sem a necessidade de hardware real.

## Requisitos

### Hardware

- 1x **ESP32**
- 1x **Sensor de Tensão** (para medir a tensão solar)
- 1x **Sensor de Tensão** (para medir a tensão da bateria)
- 1x **Potenciômetro**
- Fios de conexão

### Software

- **Arduino IDE** (com a biblioteca ThingSpeak instalada)
- Conta no **ThingSpeak** para criar o canal e visualizar os dados
- **Wokwi** para simulação (opcional)

## Configuração e Instalação

### 1. **Configuração do ThingSpeak**
   - Crie uma conta no [ThingSpeak](https://thingspeak.com/).
   - Crie um **novo canal** com os seguintes campos:
     - **Tensão Solar**
     - **Tensão da Bateria**
     - **Potenciômetro**
   - Anote o **Channel ID** e a **Write API Key** fornecidos pelo ThingSpeak.
   - Caso necessário, ative a visualização de gráficos em tempo real para esses campos.

### 2. **Configuração do ESP32**
   - Abra o **Arduino IDE** e instale a biblioteca **ThingSpeak**.
   - Configure o ESP32 para se conectar à sua rede Wi-Fi, utilizando o SSID e a senha apropriada.
   - Adicione o código que foi fornecido anteriormente no código-fonte do seu projeto, substituindo a **Write API Key** e o **Channel ID** do ThingSpeak corretamente.

### 3. **Carregar o Código no ESP32**
   - Selecione a **placa ESP32** no Arduino IDE.
   - Carregue o código para o ESP32 com os sensores de tensão e potenciômetro conectados nas portas adequadas.
   - O ESP32 começará a enviar os dados para o ThingSpeak automaticamente.

### 4. **Visualização no ThingSpeak**
   - Acesse o canal criado no ThingSpeak para ver os dados sendo atualizados em tempo real.
   - Verifique os gráficos de **Tensão Solar**, **Tensão da Bateria** e **Potenciômetro**.

## Como Testar

1. **Conectar o ESP32 ao Wi-Fi**: Após carregar o código, o ESP32 se conectará à sua rede Wi-Fi.
2. **Verificar os Dados no ThingSpeak**: Acesse o seu canal no ThingSpeak e verifique se os gráficos estão sendo atualizados com os dados coletados pelos sensores.
3. **Ajustar o Potenciômetro**: Variações no potenciômetro devem ser refletidas no gráfico da plataforma em tempo real.
4. **Verificar os Gráficos**: A tensão solar e a tensão da bateria devem aparecer como gráficos que mostram a variação desses parâmetros.

## Resultados Esperados

- **Tensão Solar**: O gráfico de Tensão Solar deve mostrar a variação da tensão gerada pelos painéis solares, com valores que vão de acordo com a intensidade da luz solar.
- **Tensão da Bateria**: O gráfico de Tensão da Bateria deve mostrar a variação da carga da bateria. Idealmente, ela deve permanecer entre 3.7V e 4.2V para baterias de lítio.
- **Valor do Potenciômetro**: O gráfico do Potenciômetro mostrará as variações da tensão ajustada por ele, podendo ser utilizado para controlar outros parâmetros do sistema.

## Melhorias Futuras

- **Adição de Mais Sensores**: Monitoramento de outros parâmetros, como temperatura e corrente, para tornar o sistema mais completo.
- **Alertas em Tempo Real**: Implementação de alertas em caso de falha ou valores fora dos padrões ideais.
- **Integração com Outros Sistemas IoT**: Expansão do sistema para trabalhar com outros dispositivos de automação e controle remoto.

## Licença

Este projeto é distribuído sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

---

### Estrutura do Repositório

