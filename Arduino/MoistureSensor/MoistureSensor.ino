#include <SoftwareSerial.h>
//#include <SparkFunESP8266Client.h>
//#include <SparkFunESP8266Server.h>
#include <SparkFunESP8266WiFi.h>

String myName = "Moisture Sensor 1";
String address = "10.0.0.145";
int port = 3000;

void setup() {
  Serial.begin(9600);
  if(esp8266.begin()){
    Serial.println("ESP8266 available");
  }else{
    Serial.println("Unable to connect ESP8266");
  }
  int conValue = esp8266.connect("3081TechN","w1r3l355n");
  if(conValue < 0){
    Serial.print("Error connecting to network: "+(String)conValue);
  }

  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  int sensorData = analogRead(A0);
  String postData = "{\"Name\":\""+myName+
                    "\",\"Data\":"+(String)sensorData+
                    "}";
  String request = buildPostRequest("/logSensor",address,postData);
  Serial.print(request);
  ESP8266Client client;
  int retVal = client.connect(address, port); // Connect to sparkfun (HTTP port)
  if (retVal > 0) Serial.println("Successfully connected!");
  client.print(request);
  
}

String buildPostRequest(String address, String host, String postData ){
  String postRequest = "POST "+address+" HTTP/1.1\n";
  postRequest += "Host: "+host+"\n";
  postRequest += "Connection: close\n";
  postRequest += "Content-Type: application/json\n";
  postRequest += "Content-Length: ";
  postRequest += (String)postData.length()+"\n\n";
  postRequest += postData +"\n\n";
  return postRequest;
}


