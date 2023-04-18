#include<WiFi.h>
#include "esp_wpa2.h" //wpa2 library for connections to Enterprise networks

/* ================== Configuration and Setup ==================*/
#define EAP_IDENTITY "wang.12561" //if connecting from another corporation, use identity@organisation.domain in Eduroam 
#define EAP_USERNAME "wang.12561" //oftentimes just a repeat of the identity
#define EAP_PASSWORD "Wsn@84838485!12" //your Eduroam password
static const char* ssid = "osuwireless"; // Eduroam SSID
static const char* host = ""; //external server domain for HTTP connection after authentification
static int counter = 0;
static int wait_wifi_time = 240;

//String transEncryptionType(wifi_auth_mode_t encryptionType);
//int scanNetworks();
boolean connectWifi();
boolean connect(const char *id, const char *psw);
void closeWifi(void);