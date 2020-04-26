#include "moon.h"
#include "time.h"

#ifndef PI
#define PI 3.141592653589793
#endif

Time uptime(Moon m) {
  return timeDelta(m.moonrise, m.moonset);
}

double scale(Moon m) {
  return timeToHours(uptime(m)) / PI;
}

byte luminosityForTime(Time t, Moon m) {
  if (isAfter(t, moonset) && isBefore(t, moonrise)) {
    return 0;
  }

  Time dt = timeDelta(m.moonrise, t);
  return (byte)abs(
    m.maxLuminosity * sin(
      timeToHours(dt) / scale(m)
    )
  );
}
