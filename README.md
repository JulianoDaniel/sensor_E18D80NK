# Sensor E18-D80NK com ESP32 e Comunicação Bluetooth BLE

## Descrição do Projeto
Este projeto implementa uma aplicação utilizando o **sensor infravermelho E18-D80NK** conectado a um **ESP32** através de um **módulo optoacoplador PC817**.  
O sistema detecta a presença de objetos e envia uma mensagem via **Bluetooth BLE**, informando qual porta (sensor) foi ativada.

---

## Funcionalidade
- O sensor **E18-D80NK** detecta a presença de um objeto.
- O sinal passa pelo **módulo PC817**, garantindo isolamento elétrico entre o sensor e o ESP32.
- O **ESP32** interpreta o sinal e envia, via **Bluetooth BLE**, uma mensagem de texto:
  - `"porta1"` → quando o objeto é detectado no pino 1.  
  - `"porta2"` → quando o objeto é detectado no pino 2.

A aplicação pode interagir com **qualquer dispositivo compatível com Bluetooth BLE**, como smartphones, tablets ou computadores.

---

## Componentes Utilizados
|      Componente      |                    Função                      |
|----------------------|------------------------------------------------|
| ESP32                | Microcontrolador principal com suporte a BLE   |        |
| Sensor E18-D80NK     | Detecção de objetos por infravermelho          |
| Optoacoplador PC817  | Isolamento elétrico entre o sensor e o ESP32   |
| Resistores           | Ajuste de corrente e polarização dos circuitos |
| Jumpers e Protoboard | Conexões e montagem experimental               |

---

## Comunicação BLE
- **Protocolo:** Bluetooth Low Energy (BLE)
- **Mensagens enviadas:** `"porta1"` e `"porta2"`
- **Compatibilidade:** Dispositivos Android, iOS ou PCs com suporte BLE

---

## Possíveis Aplicações
- Sistemas de automação residencial  
- Contadores de objetos ou pessoas  
- Sensoriamento simples  
- Barreiras ópticas 

---

## Observações Técnicas
- O uso do **PC817** garante proteção ao ESP32 contra ruídos e picos de tensão.  
- O resistor de **pull-up de 10kΩ** é recomendado conforme especificação do sensor **E18-D80NK**.  
- Certifique-se de alimentar corretamente o sensor (5v) e o ESP32 (5v em VIN ou USB).  

---

## 🪪 Licença

Este projeto é licenciado sob a licença **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)**.

Você pode copiar, modificar e redistribuir este trabalho para fins **não comerciais**, desde que forneça crédito apropriado ao autor.

🔗 Saiba mais em: [https://creativecommons.org/licenses/by-nc/4.0/](https://creativecommons.org/licenses/by-nc/4.0/)

---