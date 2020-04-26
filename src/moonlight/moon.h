#ifndef MOON_H
#define MOON_H

#include "time.h"

typedef struct Moon{
  Time moonrise;
  Time moonset;
  byte maxLuminosity;
} Moon;

byte luminosityForTime(Time t, Moon m);
Time uptime(Moon m);
double scale(Moon m);

#endif
