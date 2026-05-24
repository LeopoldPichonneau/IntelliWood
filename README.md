# IntelliWood

📖 **[Documentation](https://esaip.mintlify.app)**

## Scenario
IntelliWood is an integrated monitoring and management system designed for wood granule heating and storage. Popular in the Baltic region, these heating systems rely on an oven equipped with automatic ignition and a corkscrew-driven feeding mechanism.

The oven draws fuel from a metal bunker with limited capacity. Maintaining a minimum fuel level is critical -- if the bunker empties, the automatic ignition system continues to try igniting without any fuel. This repetitive dry-firing eventually causes the ignition stick to fail, necessitating a hardware replacement. IntelliWood is designed to help prevent this failure and manage wood granule storage environment through three functionalities.

### 1. Ambient Sensing & Safety
As wood granules are flammable and sensitive to environmental factors, they are typically stored in a separate dedicated room. As high moisture can degrade the granules, humidity and temperature are closely monitored. In addition, we use a CO2, smoke, and flame sensor to trigger immediate notifications in the event of a fire. The sensors are connected to an M5Stick CPlus, which uploads the data over a WiFi connection to a local dedicated server. The M5Stick is powered from the wall socket.

### 2. Secure access control
To maintain the safety of the storage area, an NFC Lock system restricts entry. Users with the authorized keycard or access to the companion dashboard application can unlock the door. The NFC and locking mechanism is connected to a Wemos D2 Mini and powered from the wall socket.

### 3. Storage state logging & Forecasting
The core part of the system is a 3D-printed logging unit situated near the oven's refilling station. This unit tracks the inventory of wood granule bags via an ESP32-S2 microcontroller. When a user refills the bunker, they input the number of bags used via a numeric keypad. To conserve energy, the ESP32-S2 remains in Deep Sleep mode, and wakes only when a button is pressed, triggering a hardware interrupt to wake up the ESP32-S2 to update the internal log, sync the .csv file, and transmit the update over WiFi before powering down again. Instead of just closing the connection immediately, the ESP32-S2 waits for a response from the Raspberry Pi containing the datetime, forecasting when fuel levels will reach critical thresholds. The ESP32-S2 stores this timestamp, and if no new updates via the keypad before the datetime, then it sounds an alarm via a buzzer and turn on a blinking LED.

### 4. Dashboard & Weather forecast
The system tracks the current bag count. By cross-referencing historical usage with external weather APIs, the system forecasts when the bunker will reach a critical threshold. This makes a message into the companion application, and also sends a message to the ESP32-S2 as a response, so it knows when the fuel is expected to empty.

All sub-systems transmit data over a local Wi-Fi network to a central dedicated server (such as a Raspberry Pi), which performs many tasks:
1) Complementing ESP32-S2 data with real-time variables from local weather agencies (temperature, wind speed) to create accurate fuel consumption prediction.
2) Hosts the data for a companion mobile application, providing real-time overview of current storage and fuel levels, ambient sensor readings, remote secure door control, maintenance alerts and refill forecasts.


## Hardware
### Sensor list:
- CO2 sensor
- Humidity sensor
- Temperature sensor
- Smoke detector
- Flame detector
- PIR detector

### Devices list:
- NFC reader
- LED
- Keypad
- Alarm Buzzer
- Screen
- Locker

## Contributors

- [@LeopoldPichonneau](https://github.com/LeopoldPichonneau)
- [@KPPHC](https://github.com/KPPHC)
- [@arthurmrimri-del](https://github.com/arthurmrimri-del)
- [@Miriston](https://github.com/Miriston)

