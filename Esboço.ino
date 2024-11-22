#include <WiFi.h>
#include <ThingSpeak.h>

// Definindo as credenciais do WiFi e a chave de acesso ao ThingSpeak
#define SSID "seu_wifi"
#define PASSWORD "sua_senha_wifi"
#define THINGSPEAK_CHANNEL_ID 2759086
#define THINGSPEAK_API_KEY "Z4QXJ9GJUBKM0TUP"

// Pinos analógicos para leitura dos sensores
#define PINO_SOLAR 34
#define PINO_BATERIA 35
#define PINO_POTENCIOMETRO 32

WiFiClient client;

// Função para conectar ao WiFi
void conectarWiFi() {
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(SSID, PASSWORD);
  
  // Aguardar até conectar
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("Wi-Fi conectado!");
  Serial.println("Endereço IP: " + WiFi.localIP().toString());
}

// Função para enviar os dados para o ThingSpeak
void enviarDados() {
  // Lê os valores dos sensores
  float tensaoSolar = lerSensor(PINO_SOLAR);
  float tensaoBateria = lerSensor(PINO_BATERIA);
  float valorPotenciometro = lerSensor(PINO_POTENCIOMETRO);
  
  // Atualiza os campos do ThingSpeak
  ThingSpeak.setField(1, tensaoSolar);        // Tensão solar
  ThingSpeak.setField(2, tensaoBateria);     // Tensão da bateria
  ThingSpeak.setField(3, valorPotenciometro); // Valor do potenciômetro
  
  // Envia os dados para o ThingSpeak
  int sucesso = ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, THINGSPEAK_API_KEY);
  if (sucesso == 200) {
    Serial.println("Dados enviados com sucesso!");
  } else {
    Serial.println("Falha ao enviar dados.");
  }
}

// Função para ler o valor de um sensor
float lerSensor(int pino) {
  int leitura = analogRead(pino);  // Lê o valor do pino analógico
  float tensao = leitura * (3.3 / 4095.0); // Converte para tensão (ADC de 12 bits)
  return tensao;
}

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  
  // Conecta ao WiFi
  conectarWiFi();
  
  // Inicializa o ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Envia os dados para o ThingSpeak a cada 20 segundos
  enviarDados();
  delay(20000); // Espera 20 segundos para o próximo envio
}
