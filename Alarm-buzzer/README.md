Node Description
================

This node controls an alarm buzzer connected to a Wemos D1 Mini. It provides an
audible alert when another node or scenario triggers an alarm condition.


Connected devices
-----------------

- VCC+: 3.3V
- VCC-: GND
- SIGNAL: 39

PIN:
...


Functionality
-------------

The alarm buzzer acts as an output node. When it receives an alarm command from
the system, it activates the buzzer to make the alert noticeable nearby. It can
be used together with detector or monitoring nodes to provide immediate local
feedback during an alarm scenario.

<img src="/Pictures/Buzzer/Buzzer.png" width="70%">



MQTT
----

To run it you need to send to "Alarm-buzzer/alarm/set" a message that is either 0 (off) or 200 (on).
