#include<WiFi.h>
#include <WiFiMulti.h>


WiFiMulti  WiFiMulti;   //object of wifimulti

// WiFi connect timeout per AP. Increase when connecting takes longer.
const int connectionTimeout=10000;

const char *ssid1 = "lelo aap bhi ji";// router 1 wifi ssid 
const char *password1 = "11111111";

const char *ssid2 = "BUDDY";  // router 2 wifi ssid 
const char *password2 = "11111111";

void setup() {
  Serial.begin(115200);


  WiFi.mode(WIFI_STA);      // wifi in station mode

  WiFiMulti.addAP(ssid1,password1);   // adding 1st router details 
  WiFiMulti.addAP(ssid2,password1);  // adding 2nd  router details 

    int n=WiFi.scanNetworks();// used to check no of available networks
    if(n==0){
      Serial.print("No network found ");
    }

    else{
      Serial.print(n);
        Serial.println("  Network found!!!");

        for(int i=0;i<n;i++){
          Serial.print(i+1);
          Serial.print(":");
          Serial.print(WiFi.SSID(i));
          Serial.print("(");
          Serial.print(WiFi.RSSI(i));
             Serial.println(")");
        Serial.print(" | Encryption: ");
    Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?"Open":"Secured");    // used to check wifi is open of secured 

        }
        delay(10);

    }
}

void loop() {
   //if the connection to the stongest hotstop is lost, it will connect to the next network on the list
   
 if(WiFiMulti.run(connectionTimeout)==WL_CONNECTED){/*WiFiMulti.run(connectionTimeout): This method
                                                    is used to iterate through the list of configured
                                                    Wi-Fi networks and attempt to connect to each one. It 
                                                    takeses a connectionTimeout parameter, which is the maximum time to wait 
                                                       for a connection attempt to succeed in milliseconds.*/
  Serial.println("Wifi connected ");
  Serial.print(WiFi.SSID());
  Serial.print(" IP : ");
  Serial.println(WiFi.localIP());
  Serial.print("   ");
  Serial.println(WiFi.RSSI());
 }
 else{
    Serial.print("Wifi not connected");
 }

delay(1000);

}
