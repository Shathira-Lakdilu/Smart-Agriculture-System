#include <WiFiManager.h>
#include <Wire.h>
#include <BH1750.h>
#include <PubSubClient.h>
#include <time.h>
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4  // Digital pin connected to the DHT sensor
#define fanPIN 6
#define lightPIN 32
#define DHTTYPE DHT11
#define AOUT_PIN 36 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  5        /* Time ESP32 will go to sleep (in seconds) */


WiFiClient espClient;
PubSubClient mqttClient(espClient);

WiFiServer server(80);

BH1750 lightMeter(0x23);

RTC_DATA_ATTR int bootCount = 0;

char luxArr[8];
char humidityArr[6];
char temperatureArr[6];
char hIndexArr[6];
char sMoistureArr[6];

double lux;
double h;
double t;
double hic;
double soil;
double tSoil;

int motorPin= 18;

DHT dht(DHTPIN, DHTTYPE);
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {

Serial.begin(115200); 
Wire.begin();

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

  oledPrint(1, 0, 20, "Waking up now");
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
  oledPrint(1, 0, 30, "Boot number: ");
  oledPrintINT(1, 80, 30, bootCount );
  delay(1000);
  display.clearDisplay();

  //Print the wakeup reason for ESP32
  print_wakeup_reason();

  
  //First we configure the wake up source
 // We set our ESP32 to wake up every 5 seconds

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) +
  " Seconds");
  
WiFiManager wm;
Serial.println("11111111111");
bool res = wm.autoConnect("esp32","123456789");

  if (!res){
    Serial.println("Failed to connect");
    ESP.restart();
  }else{
     Serial.println("Connected...");
  }
Serial.println("222222222222");
dht.begin();

// begin returns a boolean that can be used to detect setup problems.
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }
setupMqtt();
Serial.println("3333333333");
pinMode(motorPin, OUTPUT);
pinMode(lightPIN, OUTPUT);
}

void loop() {

  if(!mqttClient.connected()){
    connectToBroker();

  }
  mqttClient.loop();
/*
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F(" lux: "));
  Serial.println(lux);
  Serial.print(F(" moisture: "));
  Serial.println(soil);
*/
Serial.print(F(" lux: "));
  Serial.println(lux);
  updateLux();
  oledPrint(1, 0, 0, "lux: ");
  oledPrintINT(1, 40, 0, lux );
  
  mqttClient.publish("ghouse/light", luxArr);

  updateHumidity();
  oledPrint(1, 0, 10, "Hum: ");
  oledPrintINT(1, 40, 10, h );
  mqttClient.publish("ghouse/humidity", humidityArr);

  updateTemperature();
  oledPrint(1, 0, 20, "Temp: ");
  oledPrintINT(1, 40, 20, t );
  mqttClient.publish("ghouse/temperature", temperatureArr);
  
  updateHindex();
  mqttClient.publish("ghouse/hIndex", hIndexArr);

  updateSmoisture();
  oledPrint(1, 0, 30, "soil: ");
  oledPrintINT(1, 40, 30, tSoil );
  mqttClient.publish("ghouse/sMoisture", sMoistureArr);
  delay(2000);

display.clearDisplay();

if(t>40 || h>90){
  //turn on fan
  digitalWrite(fanPIN, HIGH);
  delay(5000);
  digitalWrite(fanPIN, LOW);
}

if(lux<200){
  //turn on lights
  digitalWrite(lightPIN, HIGH);
  delay(5000);
  digitalWrite(lightPIN, LOW);
}
if(tSoil<20){
  //turn on lights
  digitalWrite(motorPin, HIGH);
  delay(5000);
  digitalWrite(motorPin, LOW);
}

Serial.println("Going to sleep now");
oledPrint(1, 0, 20, "Going to sleep now");
delay(1000);
display.clearDisplay();
display.display();

Serial.flush(); 
esp_deep_sleep_start();
Serial.println("This will never be printed");

}

void oledPrint(int size, int x, int y, String msg ){
 // display.clearDisplay();

  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  // Display static text
  display.println(msg);
  display.display(); 
}
void oledPrintINT(int size, int x, int y, int msg ){
 // display.clearDisplay();

  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  // Display static text
  display.println(msg);
  display.display(); 
}

/*
Method to print the reason by which ESP32
has been awaken from sleep
*/
void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    display.clearDisplay();
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer");; break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}
