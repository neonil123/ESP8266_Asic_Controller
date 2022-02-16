
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"
  #define asic1 5
  #define asic2 4
  #define sense 13
  

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9YMu9gRvk-wlZJZ1nw9jnTOx2-Uh7Klm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "******";
char pass[] = "******";

int state1 =1;
int state2 =1;

WidgetLED led1(V3);

unsigned long time1=0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Salut");
  pinMode(asic1, OUTPUT);
  pinMode(asic2, OUTPUT); 
  pinMode(sense, INPUT); 

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  main1();
}

void main1(){



if( millis()-time1 > 30000){
  Serial.print("Status ");
  Serial.print("ON ");
  
   led1.on();
   
  if(state1 ==1 ){
    
    digitalWrite(asic1, HIGH);
  }
  else{
    digitalWrite(asic1, LOW);
  }
 if(state2 ==1 ){
    digitalWrite(asic2, HIGH);
  }
  else{
    digitalWrite(asic2, LOW);
  }
  
}

else{
  Serial.print("Status ");
  Serial.print("OFF ");
  digitalWrite(asic2, LOW);
  digitalWrite(asic1, LOW);
  led1.off();
}

 if(!digitalRead(sense)){
    time1=millis(); 
  }



  Blynk.virtualWrite(V2, digitalRead(sense));
  Serial.print("power ");
  Serial.print(digitalRead(sense));
  Serial.print(" Asic 1: ");
  Serial.print(state1);
  Serial.print(" Asic 2: ");
  Serial.println(state2);
  delay(100);
}


BLYNK_WRITE(V0)
{   
  state1 = param.asInt(); // Get value as integer
}

BLYNK_WRITE(V1)
{   
  state2 = param.asInt(); // Get value as integer

}
