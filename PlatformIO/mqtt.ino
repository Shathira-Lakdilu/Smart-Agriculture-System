
void setupMqtt(){
  mqttClient.setServer("test.mosquitto.org",1883);
  mqttClient.setCallback(recieveCallback);
}

void recieveCallback(char* topic, byte* payload, unsigned int length){
  Serial.print("Message arrived-");
  Serial.print(topic);
  Serial.print("---");
  
  char payloadCharAr[length];

  for(int i=0; i<length; i++){
    Serial.print((char)payload[i]);
    payloadCharAr[i]=(char)payload[i];
  }
  Serial.println();

  if(strcmp(topic, "ghouse/motor")==0){
    if(payloadCharAr[0]=='1'){
      digitalWrite(motorPin, HIGH);
    }
    else{
      digitalWrite(motorPin, LOW);
    }
 
  }
}

void connectToBroker(){
 while(!mqttClient.connected()) {
  Serial.print("Attempting to connect...");
  if(mqttClient.connect("ESP32")){
    Serial.println("Connected to broker");
    mqttClient.subscribe("ghouse/motor");
  }
  else{
    Serial.println("Error...");
    Serial.println(mqttClient.state());
    delay(5000);
  }
 }
} 
