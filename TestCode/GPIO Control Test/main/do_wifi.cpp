#include "do_wifi.h"

/*
String transEncryptionType(wifi_auth_mode_t encryptionType)
{ // 对比出该wifi网络加密类型并返回相应的String值
  switch (encryptionType)
  {
  case (WIFI_AUTH_OPEN):
    return "Open";
  case (WIFI_AUTH_WEP):
    return "WEP";
  case (WIFI_AUTH_WPA_PSK):
    return "WPA_PSK";
  case (WIFI_AUTH_WPA2_PSK):
    return "WPA2_PSK";
  case (WIFI_AUTH_WPA_WPA2_PSK):
    return "WPA_WPA2_PSK";
  case (WIFI_AUTH_WPA2_ENTERPRISE):
    return "WPA2_ENTERPRISE";
  default:
    return ("Unkonwn EncryptionType");
  }
}

int scanNetworks()
{ // 扫描周边wifi网络，并显示wifi数量，打印它们的属性（ssid，信号强度，加密方式，mac地址）
  int numberOfNetworks = WiFi.scanNetworks();
  Serial.print("The number of networks found is:");
  Serial.println(numberOfNetworks);
  for (int i = 0; i < numberOfNetworks; i++)
  {
    Serial.print("Networkname: ");
    Serial.println(WiFi.SSID(i));
    Serial.print("Signalstrength: ");
    Serial.println(WiFi.RSSI(i));
    Serial.print("MACaddress: ");
    Serial.println(WiFi.BSSIDstr(i));
    Serial.print("Encryptiontype: ");
    String encryptionTypeDescription = transEncryptionType(WiFi.encryptionType(i));
    Serial.println(encryptionTypeDescription);
    Serial.println("-----------------------");
  }
  return numberOfNetworks;
}
*/


/* ================== Wi-Fi Main code ==================*/
boolean connectWifi()
{                        
  // Connect the Wi-Fi
  WiFi.disconnect(true); // disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA);   // init wifi mode
   Serial.println(ssid);

  // Example1 (most common): a cert-file-free eduroam with PEAP (or TTLS)
  WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);

  // Example 2: a cert-file WPA2 Enterprise with PEAP
  // WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD, ca_pem, client_cert, client_key);

  // Example 3: TLS with cert-files and no password
  // WiFi.begin(ssid, WPA2_AUTH_TLS, EAP_IDENTITY, NULL, NULL, ca_pem, client_cert, client_key);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    counter++;
    if (counter >= wait_wifi_time)
    { // after 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP()); // print LAN IP
  Serial.print("Connecting to website: ");
  Serial.println(host);
  WiFiClient client;
  if (client.connect(host, 80)) {
    String url = "/rele/rele1.txt";
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "User-Agent: ESP32\r\n" + "Connection: close\r\n\r\n");

    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }
    String line = client.readStringUntil('\n');
   Serial.println(line);
  }else{
      Serial.println("Connection unsucessful");
    }  
  return true;
}

boolean connect(const char *id, const char *psw)
{ // 连接到指定wifi
  WiFi.begin(id, psw);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    counter++;
    if (counter >= wait_wifi_time)
    { // after 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP()); // print LAN IP
  Serial.println(host);

  return true;
}

/* ================== Wi-Fi Disconnect ==================*/
void closeWifi(void)
{
  WiFi.mode(WIFI_OFF);
  Serial.println("Wi-Fi Closed!");
}
