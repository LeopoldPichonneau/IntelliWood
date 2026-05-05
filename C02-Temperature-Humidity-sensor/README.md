Node Description
================

This node monitors the storage room air quality and environmental conditions
using a CO2, temperature, and humidity sensor connected to a Wemos D1 Mini. It
is part of the ambient sensing and safety subsystem of IntelliWood.

The measurements help detect unsafe air conditions and track whether the wood
granules are stored in a suitable environment.


Connected devices
-----------------

VCC: 3.3V or 5V depending on the sensor module
GND: Ground
SDA: ...
SCL: ...

Functionality
-------------

The node acts as an input sensor node. It periodically reads the CO2
concentration, room temperature, and relative humidity in the wood granule
storage area.

The temperature and humidity values are used to monitor storage quality, since
high humidity can damage the granules and reduce their heating performance. The
CO2 value contributes to the safety monitoring system and can be used together
with the smoke and flame detector nodes to identify abnormal or dangerous
conditions.

The measured values are intended to be sent over Wi-Fi to the central
IntelliWood server, where they can be displayed in the dashboard and used for
alerts, logging, and long-term monitoring.

<img src="/Pictures/C02-Temperature_humidity-sensor/CO2.png" width="70%">