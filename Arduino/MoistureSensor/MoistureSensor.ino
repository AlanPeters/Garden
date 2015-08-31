#include <SparkFunESP8266Client.h>
#include <SparkFunESP8266Server.h>
#include <SparkFunESP8266WiFi.h>

void setup() {
  if(esp8266.begin()){
    Serial.println("ESP8266 available");
  }else{
    Serial.println("Unable to connect ESP8266");
  }
  int conValue = esp8266.connect("3081TechN","w1r3l355n");
  if(conValue < 0){
    Serial.print("Error connecting to network: "+(String)conValue);
  }

  ESP8266Client client;
  
  // put your setup code here, to run once:
    if (client.connect()) {
    Serial.println("connected");
  client.println("POST /tinyFittings/index.php HTTP/1.1");
  client.println("Host:  artiswrong.com");
  client.println("User-Agent: Arduino/1.0");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded;");
  client.print("Content-Length: ");
  client.println(PostData.length());
  client.println();
  client.println(PostData);
  } else {
    Serial.println("connection failed");
  }
}
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

String buildPostRequest(String address, String host, String PostData ){
  String postRequest = "POST "+address+" HTTP/1.1\n";
  postRequest += "Host: " + host+"\n";
  postRequest += "Connection: close\n";
  postRequest += "Content-Type: application/json\n"
  postRequest += "Content-Length: " +(String)PostData.length+"\n";
  postRequest += "Content-Length
  
}


