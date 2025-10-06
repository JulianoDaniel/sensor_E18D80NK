/*
 * 
 *  Sketch por:   
 *      Juliano Daniel - Especialista em Engenharia Robótica 
 *      https://github.com/julianodaniel
 *  Função do Software: 
 *      Demonstrativo do sensor modelo E18-D80NK interagindo com Esp32 e módulo PC817 opto 
 *	     onde é enviada uma mensagem 'porta1' ou 'porta2' por Bluetooth BLE em qual pino foi detectado um objeto. 
 *  Ano: 
 *      2025
 *  Versão: 
 *      1.0 
 *  
 */
 
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

// UUIDs customizados (pode gerar novos em https://www.uuidgenerator.net/)
#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;

bool deviceConnected = false;

const int sensorA = 22;
const int sensorB = 23;

unsigned long tempoA = 0;
unsigned long tempoB = 0;

int flagA = HIGH;
int flagB = HIGH;

// Callback de conexão
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void setup() {
  
  // Inicializa BLE
  BLEDevice::init("jogoBotao");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );

  // Adiciona descritor para notificações
  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();

  // Inicia advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  BLEDevice::startAdvertising();

  pinMode(sensorA, INPUT_PULLUP);
  pinMode(sensorB, INPUT_PULLUP);
}

void loop() {

int btnA = digitalRead(sensorA);
int btnB = digitalRead(sensorB);
  
  if (deviceConnected) {
    // sensor ligado ao pino 22
    if ((millis() - tempoA) > 100) {
      
      if (btnA == HIGH && flagA == LOW) {
        
        pCharacteristic->setValue("porta1");
        pCharacteristic->notify();
      }
      flagA = btnA;
      tempoA = millis();
    }
  delay(10);
    // sensor ligado ao pino 23
    if ((millis() - tempoB) > 100) {
      
      if (btnB == HIGH && flagB == LOW) {
        
        pCharacteristic->setValue("porta2");
        pCharacteristic->notify();
      }
      flagB = btnB;
      tempoB = millis();
    }
  }
  delay(10);
}
