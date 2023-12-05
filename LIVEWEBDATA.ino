
#include <ESP32httpUpdate.h>     //Matej sychra
#include <ArduinoHttpClient.h>   //by Arduino
#include <b64.h>
#include <HttpClient.h>   //by Arduino
#include <LiquidCrystal.h>  //arduino
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

const char* ssid = "weah";                //WIFI SSID Name
const char* password = "1234567890";     //WIFI Password
const char* host = "api.thingspeak.com";  //We read the data from this host
const int httpPortRead = 80;

const char* url1 = "/apps/thinghttp/send_request?api_key=HK72KDHRZUGZSSE";  //This URL is mine but I kept it so you can replace the key only
const char* url2 = "/apps/thinghttp/send_request?api_key=77R1OOS3XB3XPXJ";
const char* url3 = "/apps/thinghttp/send_request?api_key=CRQOJIV8671DF8T";
int To_remove;       //There are some irrelevant data on the string and here's how I keep the index
                      //of those characters 
  String Cases,Deaths,Recovered,Data_Raw,Data_Raw_1,Data_Raw_2,Data_Raw_3;  //Here I keep the numbers that I got

  WiFiClient client;      //Create a WiFi client and http client                                                     
  HTTPClient http; 

  
  void setup() {

  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("Weather-UPT");  //Change Your Project Name
  lcd.setCursor(0, 1);
  lcd.print("ELECTRONIC TAMIL");  //Change Name if you want

  Serial.begin(115200);
  WiFi.disconnect();  //Disconnect and reconnect to the Wifi you set
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.println("Connected to the WiFi network");  //Display feedback on the serial monitor
  Serial.println(WiFi.localIP());
}

void loop() {
  

   //Reading 1: Reading of cases
    if( http.begin(host,httpPortRead,url1))        //Connect to the host and the url                                      
      {
        int httpCode = http.GET();                //Check feedback if there's a response                                                  
        if (httpCode > 0)                                                              
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {                
              
              Data_Raw = http.getString();   //Here we store the raw data string
            
              
              Data_Raw_1 = Data_Raw;                                    
              To_remove = Data_Raw_1.indexOf(">");                      //I look for the position of this symbol ">"                                 
              Data_Raw_1.remove(0,To_remove+1);                        //I remove it and everything that's before
              To_remove = Data_Raw_1.indexOf("<");                     //I look for the position of this symbol ">"                                
              Data_Raw_1.remove(To_remove,Data_Raw_1.length());          //I remove it and everything that's after
                                                                     //Example: This is the raw data received <td style="font-weight: bold; text-align:right">63,927</td>
                                                                     //First we look for ">" and we remove everything before it including it
                                                                     //We stay with this 63,927</td>
                                                                     //We look for "<" symbol and we remove it + everything after
                                                                     //We keep only this 63,927 as string
              Cases=Data_Raw_1;
              Serial.print("Cases: ");  //I choosed to display it on the serial monitor to help you debug
              Serial.println(Cases); 
                                                                         
            }
        }
        else //If we can't get data
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        
        http.end();                                                                 
      } 
    else //If we can't connect to the HTTP
      {
        Serial.printf("[HTTP} Unable to connect\n");
      }
    if( http.begin(host,httpPortRead,url2))        //Connect to the host and the url                                      
      {
        int httpCode = http.GET();                //Check feedback if there's a response                                                  
        if (httpCode > 0)                                                              
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {                
              
              Data_Raw = http.getString();   //Here we store the raw data string
            
              
              Data_Raw_2 = Data_Raw;                                    
              To_remove = Data_Raw_2.indexOf(">");                      //I look for the position of this symbol ">"                                 
              Data_Raw_2.remove(0,To_remove+1);                        //I remove it and everything that's before
              To_remove = Data_Raw_2.indexOf("<");                     //I look for the position of this symbol ">"                                
              Data_Raw_2.remove(To_remove,Data_Raw_2.length());          //I remove it and everything that's after
                                                                     //Example: This is the raw data received <td style="font-weight: bold; text-align:right">63,927</td>
                                                                     //First we look for ">" and we remove everything before it including it
                                                                     //We stay with this 63,927</td>
                                                                     //We look for "<" symbol and we remove it + everything after
                                                                     //We keep only this 63,927 as string
              Deaths=Data_Raw_2;
              Serial.print("Deaths: ");  //I choosed to display it on the serial monitor to help you debug
              Serial.println(Deaths); 
                                                                         
            }
        }
        else //If we can't get data
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        
        http.end();                                                                 
      } 
    else //If we can't connect to the HTTP
      {
        Serial.printf("[HTTP} Unable to connect\n");
      }
    if( http.begin(host,httpPortRead,url3))        //Connect to the host and the url                                      
      {
        int httpCode = http.GET();                //Check feedback if there's a response                                                  
        if (httpCode > 0)                                                              
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {                
              
              Data_Raw = http.getString();   //Here we store the raw data string
            
              
              Data_Raw_3 = Data_Raw;                                    
              To_remove = Data_Raw_3.indexOf(">");                      //I look for the position of this symbol ">"                                 
              Data_Raw_3.remove(0,To_remove+1);                        //I remove it and everything that's before
              To_remove = Data_Raw_3.indexOf("<");                     //I look for the position of this symbol ">"                                
              Data_Raw_3.remove(To_remove,Data_Raw_3.length());          //I remove it and everything that's after
                                                                     //Example: This is the raw data received <td style="font-weight: bold; text-align:right">63,927</td>
                                                                     //First we look for ">" and we remove everything before it including it
                                                                     //We stay with this 63,927</td>
                                                                     //We look for "<" symbol and we remove it + everything after
                                                                     //We keep only this 63,927 as string
              Recovered=Data_Raw_3;
              Serial.print("Recovered: ");  //I choosed to display it on the serial monitor to help you debug
              Serial.println(Recovered); 
                                                                         
            }
        }
        else //If we can't get data
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        
        http.end();                                                                 
      } 
    else //If we can't connect to the HTTP
      {
        Serial.printf("[HTTP} Unable to connect\n");
      }

    while (WiFi.status() != WL_CONNECTED)     //In case the Wifi connexion is lost                                    
      { 
        
        WiFi.disconnect();                                                        
        delay(1000);                                                             
        
        WiFi.begin(ssid, password);                                              
        Serial.println("Reconnecting to WiFi.."); 
        
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("connecting");       
  lcd.setCursor(0, 1);
  for(int i=0;i<=15;i++)
  {
    lcd.print("*");
    delay(100);  
  }    
        delay(1000);                                                             
      }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print(Cases);
  lcd.setCursor(2, 1);
  lcd.print("'C");

  lcd.setCursor(6, 0);
  lcd.print("DAY:");
  lcd.setCursor(5, 1);
  lcd.print(Recovered);

  lcd.setCursor(11, 0);
  lcd.print("WIND:");
  lcd.setCursor(12, 1);
  lcd.print(Deaths);
  lcd.setCursor(14, 1);
  lcd.print("Km");
}
