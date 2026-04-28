Node Description
================

This node acts as a Passive Infrared (PIR) Motion Detector. It is designed to sense movement by detecting changes in infrared radiation levels emitted by surrounding objects (such as humans or animals).
Configuration Note: Rename the node_template folder to pir_motion_sensor. Ensure that node.conf is updated to handle a single digital input signal.


Connected devices
-----------------

The node utilizes a standard PIR motion module, which integrates the following components into a single unit:

- PIR Sensor Module (3-pin connector):

Fresnel Lens (The "White Dome"): A plastic cover that focuses infrared light and expands the detection range into multiple zones.
Pyroelectric Sensor: The internal element that detects heat signatures.
BISS0001 Controller: The onboard chip that processes raw signals into a clean digital output.

- Interface:

VCC: Power input (typically 5V - 12V).

OUT: Digital signal (3.3V High when motion is detected / 0V Low when idle).

GND: Ground connection.

Functionality
-------------

Local Functionality

- Differential Detection: The node monitors heat fluctuations. It triggers a "High" signal only when a heat source moves across the sensor's field of view, creating a differential change between the internal sensing elements.

- Signal Conditioning: Locally, the module converts the analog spikes from the sensor into a stable digital pulse.

- Adjustable Timing & Sensitivity: Through the onboard potentiometers (if available), the node manages the "dwell time" (how long the signal stays High) and the detection distance (up to 6 meters).



<img src="Pictures/PIR/PIR-1.png" width="70%" height="40%">