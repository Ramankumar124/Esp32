// simple wifi station point

#include<WiFi.h>

const char* ssid ="lelo aap bhi ji";
const char* password="11111111";


void initWiFi(){

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.println("Connecting to wifi");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print('.');
    delay(500);
  }
  Serial.println(WiFi.localIP());


}


void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.println("RSSI :");
   Serial.print(WiFi.RSSI());



}

void loop() {
 if(WiFi.status()== WL_CONNECTION_LOST){
  Serial.print("connention lost ho gya jldi vha se hato");
  initWiFi();
 }
}

//wifi station with msg when wifi is disconnected


/*
#include <WiFi.h>

const char *ssid = "lelo aap bhi ji";
const char *password = "11111111";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());
}
void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  
 if(WiFi.status()==WL_DISCONNECTED){
  Serial.print("Diconnect ho gya bhai");
  initWiFi();// reconeecting
 }
  }
*/

//wifi station with multiple condtion like (diconnect , connnected , no ssid)


/*
#include <WiFi.h>

const char *ssid = "lelo aap bhi ji";
const char *password = "11111111";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());
}
void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  int wifiStatus = WiFi.status();

  switch (wifiStatus) {
    case WL_CONNECTED:
      // Your code when connected
      Serial.println("Connected to WiFi");
      break;

    case WL_DISCONNECTED:
      Serial.println("WiFi disconnected");
      // Your code when disconnected
      break;

    case WL_CONNECTION_LOST:
      Serial.println("Connection lost");
      // Your code when connection is lost
      break;

    case WL_IDLE_STATUS:
      // Your code when in idle status
      break;

    case WL_NO_SSID_AVAIL:
      Serial.println("No SSID available");
      // Your code when no SSID is available
      break;

    case WL_SCAN_COMPLETED:
      
      break;

    case WL_CONNECT_FAILED:
      Serial.println("Connection failed");
      // Your code when connection attempt failed
      break;
  }

  delay(1000); // Adjust the delay based on your needs
}
*/

