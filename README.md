
[![Arduino CI](https://github.com/RobTillaart/decibel/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/decibel/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/decibel/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/decibel/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/decibel/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/decibel.svg)](https://github.com/RobTillaart/decibel/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/decibel/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/decibel.svg?maxAge=3600)](https://github.com/RobTillaart/decibel/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/decibel.svg)](https://registry.platformio.org/libraries/robtillaart/decibel)


# decibel

Arduino library for fast decibel routines.


## Description

**Experimental**

This library is to calculate decibel, or dB of a value.

Decibel is in fact just a logarithmic scaling.
Calculating dB is straightforward, often from a single value
or from a ratio e.g. gain in dB uses out/in.

```cpp
dB = 10 x log10(value);
dB = 10 x log10(value1 / value2);
```

Decibel is often used in audio as our hearing is sort of logarithmic.
When the maximum output is defined as 1, so the range is from 0..1
the dB scale goes from -infinity to 0, in practice the lower value
is not infinity bet e.g. from -63 to 0.

The goal of the library is to provide a function to calculate
the dB value faster with less accuracy.
For many applications e.g. display the value this is good enough.

The library also provides an **inverseDecibel()** function to
reverse the math, e.g. to calculate the out/in value from the gain.


### Related

- https://github.com/RobTillaart/fast_math
- https://github.com/RobTillaart?tab=repositories&q=math


### Performance

Time in microseconds per call.

|  Function          |  UNO  |  ESP32  |  Notes  |
|:-------------------|:-----:|:-------:|:--------|
|  decibel()         |  176  |         |
|  inverseDecibel()  |  204  |         |
|  decibelFast()     |   80  |         |
|                    |       |         |

On AVR the decibelFast() is more than 2x as fast.

There is no inverseDBFast() function (yet).


### Accuracy decibelFast

The sketch **decibel_compare.ino** compares the output of the
**decibel()** and the **decibelFast()**

In this sketch the largest absolute error = 0.003993 if steps are 0.001.
So the error seems to be smaller than 0.4%.

The average absolute error = 0.000984 if steps are 0.001, which
is roughly 0.1%.

From the above indications one can conclude that the **decibelFast()** 
will always give 2 or more correct decimals.

If these errors are acceptable differs per application and depends 
on your requirements.


### Accuracy inverseDecibel

The sketch **decibel_inverse.ino** compares the input of the
**decibel()** and the output of **inverseDecibel()**

The accuracy in the test is 6 decimals, which is acceptable when 
using (4 byte) float.


## Interface

```cpp
#include "decibel.h"
```

### Normal

- **float decibel(float alpha)** calculate the decibel value.
This implementation takes the absolute value of alpha so negative values
will not return NAN.
If alpha == 0 the return value is "inf" == infinity.
- **float inverseDecibel(float alpha)** reverse math.
Will always return a positive value.


### optimized

- **float decibelFast(float alpha)** calculate the decibel value.


## Future

#### Must

- improve documentation
- test on more hardware

#### Should


#### Could

- use of double for the accurate functions?
- find related functions?

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


