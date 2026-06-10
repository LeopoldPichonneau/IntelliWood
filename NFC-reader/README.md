Node Description
================

This node reads NFC/RFID cards using an RFID-RC522 reader connected to a Wemos
D1 Mini. It is part of the secure access control subsystem of IntelliWood.

The NFC reader identifies authorized cards and can be used to trigger the
Locker node when access to the storage area should be granted.


Connected devices
-----------------

- 3.3V: Power supply for the reader
- GND: Ground
- SDA/SS: ...
- SCK: ...
- MOSI: ...
- MISO: ...
- RST: ...

Functionality
-------------

The NFC reader acts as an input node. It detects when a card or tag is placed
near the reader and reads its identifier.

The card identifier can then be checked against the list of authorized users.
If the card is valid, the system can unlock the storage room by sending a
command to the Locker node. If the card is not authorized, access remains
blocked.

In the IntelliWood scenario, this node works together with the solenoid lock and
dashboard controls to manage secure access to the wood granule storage area.

<img src="/Pictures/NFC-Reader/NFC.png" width="70%">
