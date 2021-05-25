#ifndef PAGES_H
#define PAGES_H

#include <SoftwareSerial.h>
#include <ELClient.h>
#include <ELClientWebServer.h>

extern SoftwareSerial mySerial;

extern ELClient esp;

// Initialize the Web-Server client
extern ELClientWebServer webServer;

struct AppConfig{
    uint8_t airspeed = 80;
    uint8_t fragspeed = 80;
};

void PIDInit();
void userSetFieldCb();
void userLoadCb();
void printloop();



#endif /* PAGES_H */