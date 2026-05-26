NOT IMPLEMENTED
===============

While this node was planned, it was not implemented due to time constraints.



Node Description
================

This node controls an RGB LED connected to a Wemos D1 Mini. It provides a visual
status indicator for the IntelliWood system and can display different colors
depending on the current state or alert condition.


Connected devices
-----------------

- Resistors for the red, green, and blue channels
- Red channel pin: ...
- Green channel pin: ...
- Blue channel pin: ...
- GND: Ground


Functionality
-------------

The RGB LED acts as an output node. It gives immediate visual feedback about the
state of the storage and monitoring system.

It can be used to show normal operation, warnings, or alarm states with
different colors. For example, the LED can indicate that the system is active,
that a monitored value is close to a threshold, or that an alert has been
triggered by another node.

In the IntelliWood scenario, the RGB LED can work together with the alarm buzzer
to make critical states easier to notice locally.

<img src="/Pictures/LED/LED.png" width="70%">
