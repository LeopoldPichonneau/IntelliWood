Node Description
================

This node acts as an Environmental Air Quality & Gas Leak Detector. Using the MQ2 MOS (Metal Oxide Semiconductor) sensor, it can detect a wide range of combustible gases and smoke, providing both a safety trigger and a measurement of gas concentration.

Rename the folder to m5_gas_detector. In node.conf, ensure you define the heating/warm-up period (at least 5-10 minutes) before the node starts broadcasting valid data.


Connected devices
-----------------

**M5StickC Plus 1.1:** The main processing unit used for data logging and alert visualization.

**MQ2 Gas Sensor Module:**

***-VCC:*** Connected to the 5V pin of the M5Stick (Required: the internal heater needs 5V to function).

***-GND:*** Connected to GND.

***-AO (Analog Output):*** Connected to G36 (Analog input on M5Stick) to measure gas concentration in PPM.

***-DO (Digital Output):*** Connected to G26 (Digital input) to act as a quick binary alarm trigger.

Functionality
-------------

**Local Functionality**

***Chemiresistive Gas Detection:*** The node utilizes a Tin Dioxide (SnO2) sensing element. When combustible gases come into contact with the heated sensor, the electrical resistance decreases proportionally to the gas concentration.

***Integrated Heating System:*** Locally, the sensor manages an internal Nickel-Chromium heater to maintain the sensing element at the precise temperature required for the chemical reaction with oxygen molecules.

**Dual-Signal Processing:**

***Analog Mapping:*** The M5Stick converts the voltage from the AO pin into a numerical value representing gas intensity (0-4095 on ESP32/M5Stick).

***Hardware Thresholding:*** The onboard LM393 comparator allows for an instant digital "High/Low" signal on the DO pin, adjustable via the built-in potentiometer.

***Visual Status Indication:*** The node uses the M5Stick's LCD to show the current "PPM" levels and utilizes the on-module LED to show when the gas threshold has been breached.

**Network & Scenario Functionality**

***Early Warning System (EWS) Role:*** In a smart home scenario, this node acts as a "Sentinel." It continuously monitors for smoke or LPG leaks and initiates an emergency protocol across the network if levels become dangerous.

***Safety Coordination:*** Upon detection, the node can command a "Ventilation Node" to activate exhaust fans and signal a "Gateway Node" to send an urgent notification to the user's smartphone.

***Data Logging:*** It periodically sends air quality snapshots to a central database node to track long-term environmental trends or to detect slow gas leaks that haven't yet reached the alarm threshold.
