Node Description
================

This node functions as a Flame and Infrared Radiation Detector. It uses a specialized photodiode to monitor the environment for heat sources or fire by detecting infrared light in the 760nm – 1100nm wavelength range.

Configuration Note: Rename the node_template folder to m5_flame_detector. Update node.conf to define whether the node operates in Digital (threshold-based) or Analog (intensity-based) mode.


Connected devices
-----------------

M5StickC Plus 1.1: The central processing unit, used for visual/audible feedback and network communication.

MH-Series Flame Sensor (Photodiode):

-VCC: Connected to the 5V or 3.3V pin of the M5Stick.

-GND: Connected to the GND pin.

-DO (Digital Output): Connected to G26 (to trigger a binary alarm).

-AO (Analog Output): Connected to G36 (to measure the intensity of the flame/heat).

Functionality
-------------

**Local Functionality**

***-Infrared Spectral Sensing:*** The node specifically monitors the 760nm to 1100nm wavelength range. It ignores most visible light but reacts instantly to the infrared signature produced by a flame or a high-heat source.

***-Threshold Comparison (Digital):*** Using the onboard LM393 chip, the node compares the raw analog signal from the photodiode against a manual setpoint. If the IR intensity exceeds the limit, it flips the digital output (DO) to signal an alert.

***-Intensity Mapping (Analog):*** The node converts the physical flame brightness into a variable voltage (0V-5V). This allows the M5Stick to calculate exactly how large or how close the flame is.

Sensitivity Tuning: Via the blue onboard potentiometer, the user can hardware-calibrate the node to filter out background IR noise (like sunlight or heaters) to prevent false triggers.

**Network & Scenario Functionality**

***-Emergency Trigger Role:*** In a safety scenario, this node acts as the "Initiator." As soon as a flame is confirmed, it sends a high-priority "Fire Event" message across the network to alert all other connected devices.

***-Visual & Audible Alert:*** Locally, the node uses the M5Stick's built-in LCD to flash a red warning and the internal buzzer to sound a high-pitch alarm to notify nearby occupants.

***-Coordinated Response:*** In concert with other nodes, it can trigger a "Ventilation Node" to shut down fans (to avoid spreading fire) or a "Notification Node" to send an emergency SMS to a supervisor via Wi-Fi.


<img src="/Pictures/Flame-detector/flame-scheme.png" width="70%">