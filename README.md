# 🌾📡 Smart Agriculture System: Greenhouse and Field Monitoring 🏡🚜
![smart agcriculture system](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/8287c726-92ed-426f-9456-1f47a2b173e9)

Welcome to our Smart Agriculture System GitHub repository! 🌱 This comprehensive project is designed to revolutionize agriculture by combining two vital components: Greenhouse Monitoring and Field Monitoring. Our solution provides farmers with a sophisticated yet user-friendly system for optimizing crop conditions in both controlled environments and remote fields. Explore each part of our project:

![Screenshot 2023-10-23 194711](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/4f741304-1b0a-4bc2-9040-34d85d5f5d5d)

## 1. Greenhouse Monitoring and Controlling 🏡

![Screenshot 2023-10-23 201137](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/3f374758-07dc-4e76-b29c-c724a8469fa3)

Our Greenhouse Monitoring module focuses on creating an interconnected network of greenhouses using Wi-Fi technology. Here's what it offers:

-   🌍 **Networked Greenhouses:** Connect multiple greenhouses to a central Raspberry Pi hub over Wi-Fi, enabling centralized control and monitoring.
    
-   🌡️ **Environmental Sensors:** Utilize sensors for temperature, humidity, and other key parameters to ensure optimal greenhouse conditions.
    
-   🌐 **Dashboard Interface:** Access a farmer-friendly dashboard for real-time insights into each greenhouse's environmental status.
    
-   📊 **Control Mechanisms:** Implement automated control mechanisms for factors like irrigation, ventilation, and lighting to optimize crop growth.
    

## 2. Field Monitoring and Controlling 🚜


The Field Monitoring module extends our system to remote fields, overcoming connectivity challenges. Here's what it includes:

-   🌱 **LoRa Connectivity:** Use LoRa (SX1278 module) for remote field communication, ensuring reliable data transmission in areas with limited Wi-Fi coverage.
    
-   🌧️ **Moisture Sensors:** Deploy moisture sensors in the field to gather crucial soil moisture data for informed irrigation decisions.
    
-   📡 **Integration with Raspberry Pi Hub:** Connect field sensors to the central Raspberry Pi hub, aggregating data for a holistic view of the agricultural landscape.
    
-   🚀 **Precision Agriculture:** Empower farmers with data-driven insights to make informed decisions for optimizing crop yield and resource efficiency.

  ## The key features
Our automated greenhouse is a cutting-edge solution for precision agriculture. It incorporates a range of essential components to optimize crop growth and environmental conditions. The key features include:

🌧️ **Environmental Monitoring:**

-   DHT11 Sensor: Measures humidity and temperature.
-   Soil Moisture Sensor: Monitors soil moisture levels.
-   BH1750 Ambient Light Sensor: Measures lux value for precise light intensity control.

🧠 **Control Hub:**

-   ESP32 Microcontroller: Powers the greenhouse automation, collecting and processing data from the sensors.

⚙️ **Parameter Control Modules:**

-   Solenoid Valve: Manages irrigation to ensure optimal soil moisture.
-   LED Grow Lights: Adjusts lighting conditions for different growth stages.
-   Exhaust Fan: Regulates temperature and humidity levels by activating the exhaust system.

🌡️ **Automated Regulation:** Our program facilitates the automatic regulation of the greenhouse environment:

-   **Temperature Control:** The exhaust fan is activated to maintain the desired temperature.
-   **Humidity Control:** The exhaust fan contributes to humidity regulation.
-   **Soil Moisture Management:** The solenoid water valve ensures optimal soil moisture levels.
-   **Lighting Adjustment:** LED grow lights are dynamically controlled to achieve the desired light intensity.

  ## MQTT Protocol: Simplifying IoT Communication 🌐📡

MQTT, or Message Queuing Telemetry Transport, is a lightweight and efficient messaging protocol designed for reliable communication in the Internet of Things (IoT) landscape. It operates on the publish-subscribe model, making it ideal for scenarios where small, intermittent, or low-bandwidth connections are common.

### Key Features of MQTT:

-   **Publish-Subscribe Model:** Devices communicate via a broker, where publishers send messages without knowing who the subscribers are, and subscribers receive messages based on topics of interest.
    
-   **QoS Levels:** Offers three Quality of Service levels, ensuring reliable message delivery even in challenging network conditions.
    
-   **Retained Messages:** The broker can store the last message on a topic, making it available to new subscribers when they connect.
    
-   **Lightweight:** Designed for resource-constrained environments, MQTT minimizes bandwidth usage and processing overhead.
    

## Raspberry Pi MQTT Broker: Centralized IoT Communication Hub 🍓📡

In our Smart Agriculture System, the Raspberry Pi serves as a powerful MQTT broker, acting as a centralized hub for communication between various components. Here's why the Raspberry Pi is an excellent choice for hosting an MQTT broker:

### Raspberry Pi Benefits:

-   **Low-Cost Solution:** Raspberry Pi offers a cost-effective yet robust solution for hosting an MQTT broker, making it accessible for a wide range of IoT projects.
    
-   **Wi-Fi Connectivity:** With built-in Wi-Fi capabilities, Raspberry Pi allows seamless communication with devices within the network, such as greenhouses and sensors.
    
-   **GPIO Pins for Sensor Integration:** Raspberry Pi's General Purpose Input/Output (GPIO) pins enable easy integration with sensors, making it versatile for gathering environmental data.
    
-   **Open-Source Software Support:** Various MQTT broker software, such as Mosquitto, can be easily installed on Raspberry Pi, ensuring flexibility and compatibility.

## Node-RED Dashboard: Visualize, Interact, Innovate 🚀📊

Welcome to the heart of our Smart Agriculture System's user experience – the Node-RED Dashboard. Designed for simplicity and functionality, the Node-RED Dashboard transforms complex IoT data into an interactive and visually engaging interface.

![nodered](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/c410bc3c-fcf8-4bb3-bfcd-40373b92534f)

### Key Features:

🔍 **Visual Flow Programming:** Node-RED Dashboard allows you to build intuitive workflows visually. Easily connect nodes, process MQTT data, and design a customized dashboard tailored to your agricultural needs.

📈 **Real-Time Monitoring:** Witness real-time updates of environmental parameters such as temperature, humidity, and soil moisture. Stay informed about the health and conditions of your greenhouses and remote fields at a glance.

🎛️ **Intuitive Control Widgets:** Take control effortlessly with interactive widgets. From adjusting lighting conditions to managing irrigation, the Node-RED Dashboard provides a user-friendly interface for seamless control of your Smart Agriculture System.

🌐 **Customizable Dashboards:** Tailor dashboards to suit your preferences. Highlight essential information, rearrange widgets, and create a personalized view that aligns with your farming priorities.

### Empowering Agriculture:

Node-RED Dashboard acts as the bridge between the complexity of IoT data and the user's need for simplicity. Empower farmers with the tools to make informed decisions, all within a visually appealing and accessible interface.

# Hardware Components

### Central Control Hub:

1.  Raspberry Pi (or any other microcontroller)
2.  MicroSD Card (for Raspberry Pi)
3.  Power Supply for Raspberry Pi

### Environmental Sensors:

4.  DHT11 Sensor (Humidity and Temperature)
5.  Soil Moisture Sensor
6.  BH1750 Ambient Light Sensor (Lux value)

### Actuators:

7.  Solenoid Water Valve (for irrigation)
8.  LED Grow Lights
9.  Exhaust Fan

### Communication:

10.  LoRa Module (SX1278) for remote fields

# PCB Design with Altium Designer

![PCB](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/31dab4ac-3f1e-4f27-9574-2d5e5e87d2e1)

## Schematic diagram

![Schematic](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/3193cd8e-7ee9-4b7c-b6c3-b03517e5a791)

## Top layer

![toplayer](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/f017930c-a578-468d-8991-1086b4b7a74f)

## Bottom Layer

![bottomlayer](https://github.com/Shathira-Lakdilu/Smart-Agriculture-System/assets/127112210/ee9cb39e-1dbd-4c57-9301-2027ddd12d72)

