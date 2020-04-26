#include <Process.h>
#include "time.h"

Time parseTime(Process date) {
  while (date.available() > 0) {
    String timeString = date.readString();

    int firstColon = timeString.indexOf(":");
    int secondColon = timeString.lastIndexOf(":");

    String hourString = timeString.substring(0, firstColon);
    String minString = timeString.substring(firstColon + 1, secondColon);
    String secString = timeString.substring(secondColon + 1);

    byte hours = (byte)hourString.toInt();
    byte minutes = (byte)minString.toInt();
    byte seconds = (byte)secString.toInt();

    Time d = {
      true,
      hours,
      minutes,
      seconds
    };

    return d;
  }
}

Time timeDelta(Time from, Time to) {
  int hours = to.hours - from.hours;
  if (hours < 0) {
    hours += 24;
  }

  int minutes = to.minutes - from.minutes;
  if (minutes < 0) {
    minutes += 60;
  }

  int seconds = to.seconds - from.seconds;
  if (seconds < 0) {
    seconds += 60;
  }

  Time d = {
    true,
    (byte)hours,
    (byte)minutes,
    (byte)seconds
  };

  return d;
}

float timeToMinutes(Time d) {
  return (d.hours * 60.0) + d.minutes + (d.seconds / 60.0);
}

float timeToHours(Time d) {
  return timeToMinutes(d) / 60.0;
}

String timeToString(Time d) {
  if (!d.initialized) {
    return "uninitialized";
  }

  return String(String(d.hours) + ":" + String(d.minutes) + ":" + String(d.seconds));
}

bool isBefore(Time t, Time reference) {
  return t.hours < reference.hours
    || (t.hours == reference.hours
      && t.minutes < reference.minutes)
    || (t.hours == reference.hours
      && t.minutes == reference.minutes
      && t.seconds < reference.seconds);
}

bool isAfter(Time t, Time reference) {
  return t.hours > reference.hours
    || (t.hours == reference.hours
      && t.minutes > reference.minutes)
    || (t.hours == reference.hours
      && t.minutes == reference.minutes
      && t.seconds > reference.seconds);
}
