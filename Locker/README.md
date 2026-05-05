Node Description
================

This node controls a solenoid lock connected to a Wemos D1 Mini through a relay
module. It is used to lock and unlock the IntelliWood storage area as part of
the secure access control subsystem.

The Wemos controls the relay signal, while the solenoid lock is powered by a
separate DC power supply because it requires more current than the
microcontroller can provide directly.


Connected devices
-----------------

- External 12V DC power supply for the solenoid lock
- Relay VCC: 5V
- Relay GND: Ground
- Relay IN: ...
- Solenoid positive wire: Relay NO contact
- Power supply positive wire: Relay COM contact
- Solenoid negative wire: Power supply ground

Functionality
-------------

The Locker acts as an output node. When it receives an unlock command from the
access control system, it activates the relay so that power is supplied to the
solenoid lock.

The relay separates the low-voltage control signal from the higher-current lock
circuit. This allows the Wemos D1 Mini to safely control the lock without
powering the solenoid directly.

In the IntelliWood scenario, this node works together with the NFC reader and
dashboard controls to restrict access to the storage room. Authorized users can
trigger the lock remotely or through an approved access device.

<img src="/Pictures/Locker/Lock.png" width="70%">
