Node Description
================

This node acts as a Multi-Point Capacitive Touch Interface. It leverages the ESP32’s powerful processing and I2C capabilities to turn up to 12 conductive surfaces into interactive touch buttons.

Rename the node_template folder name to something more descriptive.
Make sure to adjust ``node.conf``.


mpr121 capacitif 


Connected devices
-----------------

**ESP32 Development Board:** The main microcontroller with integrated Wi-Fi and Bluetooth.

**MPR121 Breakout Board:**

- ***VCC:*** Connected to 3.3V from the ESP32.

- ***GND:*** Connected to GND.

- ***SCL:*** Connected to GPIO 22 (default I2C Clock).

- ***SDA:*** Connected to GPIO 21 (default I2C Data).

- ***IRQ:*** Connected to GPIO 4 (Optional, used for interrupt-driven detection).

**Electrodes:** Conductive materials (foil, wires, metal) connected to the 12 input pads of the MPR121.

Functionality
-------------

***Local Functionality***

**-Capacitive Displacement Measurement:** The node measures the electrical capacitance of 12 individual electrodes. It detects a "touch" by sensing the minute change in capacitance caused by the proximity of a human finger.

**-I2C Digital Translation:** Locally, the MPR121 chip converts complex analog capacitance readings into simple digital data, which is then sent to the ESP32 via the I2C protocol.

**-Filtering and Debouncing:** The onboard controller automatically filters out electrical noise and "debounces" the touch events to ensure that one physical touch results in only one stable trigger signal.

**-Low-Power Monitoring:** The node operates with extremely low current consumption (approx. 29 µA), allowing the ESP32 to remain in deep sleep until a touch "wakes" it up via the IRQ pin.

***Network & Scenario Functionality***

**-Custom Interface Hub:** In a larger system, this node acts as a "Input Hub." It can translate physical touches on objects into MQTT commands to control other devices (lights, motors, or fans) over Wi-Fi.

**-Touch-to-Action Logic:** Locally, the ESP32 processes which electrode was touched (0-11) and can execute complex logic, such as "Long Press" for dimming lights or "Double Tap" to arm a security system.

**-Coordinated Feedback:** This node can work with a "Sound Node" or "Light Node" on the network to provide immediate audio-visual confirmation whenever a touch is registered.
