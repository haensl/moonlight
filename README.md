# moonlight
Arduino PWM dimmer simulating moonlight for my aquascape.

## Requirements

* An Arduino board with access to [Bridge library](https://www.arduino.cc/en/Reference/YunBridgeLibrary).

## Customization

* Set [BAUT_BRIDGE](src/moonlight.ino#L6) and [PIN_MOONLIGHT](src/moonlight.ino#L8) according to your board and setup.

* Adjust [moonrise](src/moonlight.ino#L10), [moonset](src/moonlight.ino#L17) and [maxLuminosity](src/moonlight.ino#L27) according to your wishes. Times are given as `{ true, hours, minutes, seconds }` with 24 hours in mind. Luminosity takes a `byte`, i.e. values between `0` and `255`. See [time.h](src/time.h) and [moon.h](src/moon.h) for further information.

## [Changelog](CHANGELOG.md)

## [Licence](LICENSE.md)
