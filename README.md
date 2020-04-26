# moonlight
Arduino PWM dimmer simulating moonlight for my aquascape.

## Requirements

* An Arduino board with access to [Bridge library](https://www.arduino.cc/en/Reference/YunBridgeLibrary).

## Customization

* Adjust [moonrise](src/moonlight.ino#10) and [moonset](src/moonlight.ino#17) according to your wishes. Times are given as `{ true, hours, minutes, seconds }` with 24 hours in mind. See [time.h](src/time.h) and [moon.h](src/moon.h) for further information.

## [Changelog](CHANGELOG.md)

## [Licence](LICENSE.md)
