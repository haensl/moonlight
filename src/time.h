#ifndef TIME_H
#define TIME_H

#ifndef HOURS_PER_DAY
#define HOURS_PER_DAY 24.0
#endif

typedef struct Time {
  bool initialized;
  byte hours;
  byte minutes;
  byte seconds;
} Time;

Time parseTime();
Time timeDelta(Time from, Time to);
float timeToMinutes(Time d);
float timeToHours(Time d);
String timeToString(Time d);
bool isBefore(Time t, Time reference);
bool isAfter(Time t, Time reference);
#endif
