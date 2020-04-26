#include <Process.h>
#include <Console.h>
#include "time.h"
#include "moon.h"

const unsigned long BAUT_BRIDGE = 115200L;
const unsigned int BOOT_DELAY = 5000;
const byte PIN_MOONLIGHT = 6;

const Time moonrise = {
  true,
  23,
  0,
  0
};

const Time moonset = {
  true,
  4,
  30,
  0
};

const Moon moon = {
  moonrise,
  moonset,
  8
};

Process date;
Time now;
byte moonlightLuminosity = 0;

void setup() {
  pinMode(PIN_MOONLIGHT, OUTPUT);
  delay(BOOT_DELAY);
  Bridge.begin(BAUT_BRIDGE);
  if (!date.running()) {
    date.begin("date");
    date.addParameter("+%T");
    date.run();
  }
}

void loop() {
  if (!date.running()) {
    date.begin("date");
    date.addParameter("+%T");
    date.run();
  }

  if (date.available() > 0) {
    now = (Time)parseTime(date);
  }

  if (now.initialized) {
    moonlightLuminosity = luminosityForTime(now, moon);
  }
  
  analogWrite(PIN_MOONLIGHT, moonlightLuminosity);
}
