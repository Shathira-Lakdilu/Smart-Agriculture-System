
void updateLux(){
  lux = lightMeter.readLightLevel();
  dtostrf(lux, 1, 2, luxArr);
}

void updateHumidity(){
h = dht.readHumidity();
dtostrf(h, 6, 2, humidityArr);
}

void updateTemperature(){
t = dht.readTemperature();
dtostrf(t, 6, 2, temperatureArr);
}

void updateHindex(){
hic = dht.computeHeatIndex(t, h, false); 
dtostrf(hic, 6, 2, hIndexArr);
}

void updateSmoisture(){
soil = analogRead(AOUT_PIN); 
tSoil = abs(soil-3220);
dtostrf(tSoil, 6, 2, sMoistureArr);
}
