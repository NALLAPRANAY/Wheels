#define BLYNK_PRINT Serial



/* Fill-in your Template ID (only if using Blynk.Cloud) */

#define BLYNK_TEMPLATE_ID "TMPL3uibYZNoe"
#define BLYNK_TEMPLATE_NAME "LabAutomation"
#define BLYNK_AUTH_TOKEN "s2291g1WHa7xVg5Sz8MD1Kx2nJ_BfwpL"
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266_SSL.h>



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).
 
char auth[] = "s2291g1WHa7xVg5Sz8MD1Kx2nJ_BfwpL";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "Redmi8A";

char pass[] = "srinunalla";



int M1PWM = D5; //GPIO14

int M2PWM = D6; //GPIO12

int M1P = D1;  //GPIO5

int M1N = D2;  //GPIO4

int M2P = D3;  //GPIO0

int M2N = D4;  //GPIO2



int pinValue1;

int pinValue2;



BLYNK_WRITE(V2)



{



  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable



  analogWrite(M1PWM,pinValue1);



  Blynk.virtualWrite(V1, pinValue1);



  Serial.print("V1 Slider value is: ");



  Serial.println(pinValue1);



}



BLYNK_WRITE(V3)



{



  int pinValue2 = param.asInt(); // assigning incoming value from pin V2 to a variable



  analogWrite(M2PWM,pinValue2);



  Blynk.virtualWrite(V2, pinValue2);



  Serial.print("V2 Slider value is: ");



  Serial.println(pinValue2);



}

void setup()

{

  pinMode (M1PWM,OUTPUT);

  pinMode (M2PWM,OUTPUT);

  pinMode (M1P,OUTPUT);

  pinMode (M1N,OUTPUT);

  pinMode (M2P,OUTPUT);

  pinMode (M2N,OUTPUT);

  // Debug console

  Serial.begin(9600);



  Blynk.begin(auth, ssid, pass);

}



void loop()

{

  Blynk.run();

}
