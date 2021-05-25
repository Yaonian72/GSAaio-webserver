#include <Pages.h>
#include <EEPROM.h>

#define MAGIC 0xABEF
#define MAX_STR_LEN  32

// EEPROM content 
#define EEPROM_POS_MAGIC          0
#define EEPROM_POS_KP     (EEPROM_POS_MAGIC + 2)
#define EEPROM_POS_KI      (EEPROM_POS_KP + MAX_STR_LEN)
#define EEPROM_POS_KD            (EEPROM_POS_KI + MAX_STR_LEN)
#define EEPROM_POS_VALVE_STATUS         (EEPROM_POS_KD+MAX_STR_LEN)
#define EEPROM_POS_NOTIFICATIONS  (EEPROM_POS_VALVE_STATUS+MAX_STR_LEN)

float kp=0.01;
float ki=0.01;
float kd=0.01;
bool v_status=0; //0 on 1 off


void userSetFieldCb(const char * field)
{
    // Serial.print("4343420");
    // Serial.println();
      String fld = field;
  Serial.println(fld);
  // kp = (float)webServer.getArgFloat();
  // ki = (float)webServer.getArgFloat();
  // kd = (float)webServer.getArgFloat();
  if( fld == F("kp")){
    kp = (float)webServer.getArgFloat();}
  else if( fld == F("ki")){
    ki = (float)webServer.getArgFloat();}
  else if( fld == F("kd")){
    kd = (float)webServer.getArgFloat();}
  // else if( fld == F("Valve Status"))
  // {
  //   String valve_status = webServer.getArgString();
  //   v_status = ((valve_status == F("on")) ? 0 : 1);
  // }

    Serial.print("4343"); 
    Serial.println();
}

void userLoadCb(const char * url)
{
    // Serial.print("024420");
    // Serial.println();
    // char buf[MAX_STR_LEN];
    webServer.setArgFloat(F("kp"), kp);
    webServer.setArgFloat(F("ki"), ki);
    webServer.setArgFloat(F("kd"), kd);
    // webServer.setArgString(F("Valve Status"), (v_status == 0) ?  F("on") : F("off"));
    // Serial.print("4343420"); 
    Serial.println("4343420");
}

void ButtonPressCb(char * btnId)
{
        String fld = btnId;
  Serial.println(fld);
  Serial.println("Botton pressed!");
}


void PIDInit()
{

  URLHandler *pidPageHandler = webServer.createURLHandler(F("/pid.html.json"));
  pidPageHandler->buttonCb.attach(&ButtonPressCb);
  pidPageHandler->setFieldCb.attach(&userSetFieldCb);
  pidPageHandler->loadCb.attach(&userLoadCb);
  pidPageHandler->refreshCb.attach(&userSetFieldCb);
  
}

void printloop(){
    // webServer.setArgInt(F("KP"), (float)EEPROM[EEPROM_POS_KP]);
    // Serial.print((float)EEPROM[EEPROM_POS_KP]); 
    // webServer.setArgInt(F("KI"), (float)EEPROM[EEPROM_POS_KI]);
    // Serial.print((float)EEPROM[EEPROM_POS_KI]); 
    // webServer.setArgInt(F("KD"), (float)EEPROM[EEPROM_POS_KD]);
    // Serial.print((float)EEPROM[EEPROM_POS_KD]); 
    // Serial.print("4343420"); 
    Serial.print(ki);
    Serial.print(",");
    Serial.print(kp);
    Serial.print(",");
    Serial.print(kd);
    Serial.print(",");
    Serial.println();
    delay(200);
}