#include <FS.h>                   //this needs to be first, or it all crashes and burns...

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include <SoftwareSerial.h>
//needed for library
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

WiFiManager wifiManager;

String module = "f117032019"; //Type.Number.DD.MM.YYYY
int flag=0;

//Web/Server address to read/write from
const char *host = "xx.xxx.xx.xxx"; //Change it to the host server address
SoftwareSerial sw(13,33);

//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  delay(1000);

  Serial.begin(115200);
  sw.begin(115200);

  wifiManager.setBreakAfterConfig(true);
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {

  if(WiFi.status() != WL_CONNECTED){
  if (!wifiManager.autoConnect("H.E.A.R.", "password")) {
    Serial.println("failed to connect, we should reset and see if it connects");
    delay(1000);
    ESP.restart();
    delay(1000);
  }
    //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");


  Serial.println("local ip");
  Serial.println(WiFi.localIP());
  }

  String content = "";

  char character ;

  while(sw.available()) {

      character = sw.read();

      if(!(isAlphaNumeric(character) || character=='.' || character==',')){
        content="";
        break;
      }

        content.concat(character);

  }

  Serial.println(content);

  if(content.charAt(0) =='f' && flag == 1){

    flag = 0;

  HTTPClient http;    //Declare object of class HTTPClient

  String latitude, longitude;
  String postData;
  int sepIndx = 1;

  for(;sepIndx<content.length();sepIndx++){
    if(content.charAt(sepIndx)==',')
    break;
  }

  latitude = content.substring(1, sepIndx);

    int lastIndex= sepIndx+1;

  for(;lastIndex<content.length();lastIndex++){
   if(!((content.charAt(lastIndex)>='0' && content.charAt(lastIndex)<='9') || content.charAt(lastIndex)=='.'))
    break;
  }

  longitude = content.substring(sepIndx+1,lastIndex);

  //Post Data
  postData = "id=" + module + "&flag=" + flag + "&latitude=" + latitude + "&longitude=" + longitude ;

  http.begin("http://xx.xxx.xx.xxx/insertdata.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  Serial.println(postData);

  http.end();  //Close connection

  }

  else if(content.charAt(0) == 't' && flag == 0){

    flag = 1;

  HTTPClient http;    //Declare object of class HTTPClient

  String latitude, longitude;
  String postData;
  int sepIndx = 1;

  for(;sepIndx<content.length();sepIndx++){
    if(content.charAt(sepIndx)==',')
    break;
  }

  latitude = content.substring(1, sepIndx);   //String to interger conversion

  int lastIndex= sepIndx+1;

  for(;lastIndex<content.length();lastIndex++){
  if(!((content.charAt(lastIndex)>='0' && content.charAt(lastIndex)<='9') || content.charAt(lastIndex)=='.'))
    break;
  }

  longitude = content.substring(sepIndx+1,lastIndex);

  //Post Data
  postData = "id=" + module + "&flag=" + flag + "&latitude=" + latitude + "&longitude=" + longitude ;

  http.begin("http://xx.xxx.xx.xxx/insertdata.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  Serial.println(postData);

  http.end();  //Close connection

 }

 delay(2000);
}
