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

- ***SCL:*** Connected to GPIO 5.

- ***SDA:*** Connected to GPIO 6.

- ***IRQ:*** Not connected.



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


Tutorial for pre-flashing the ESP32
-------------------------------
The ESP32-S2 may require going into a 'Download Mode' when first flashing it. This can be reliably diagnosed, when the MCU is in the USB port, but IoTEmpower / Arduino IDE does not see the device. To go into 'Download Mode', follow these steps:

1) Plugging in the ESP32-S2
2) Find the 0 and RST buttons on the sides
3) Press and hold the 0 button.
4) While holding the 0 button, press and release the RST button.
5) Release the 0 button.

After that in terminal `lsusb` should show the port properly. 

And if you run `ls /dev/ttyACM*` then it should show the correct port aswell. No need to manually input it though, as at this point IoTEmpower finds it automatically.

To first pre-flash it, you need to go to {IOT_SYSTEMS_ROOT}/iot-systems/IntelliWood/Keypad and run there `deploy serial`.

After that the device can be flashed OTA.


Tutorial for running the keypad
-------------------------------
To run the code, at this stage of the project, there is a bug in the IoTEmpire source files, specifically in the dev_mpr121.cpp file. You need to swap inside {IOT_SYSTEMS_ROOT}/iot-systems/IntelliWood/Keypad/build/src/dev_mpr121.cpp the content into this:

```cpp
// dev_mpr121.cpp
#include "dev_mpr121.h"

MPR121::MPR121(const char* name) :
    I2C_Device(name) {
    
    add_subdevice(new Subdevice(F(""))); // 0
    // from adafruit example:
    // Default address is 0x5A, if tied to 3.3V its 0x5B
    // If tied to SDA its 0x5C and if SCL then 0x5D
    set_address(0x5A);
}

void MPR121::i2c_start() {
    sensor = new Adafruit_MPR121();

    if(sensor) {
        sensor->begin(get_address());
        sensor->setAutoconfig(true); //if this is not here, then does not work at all
        _started = true;
    } else {
        ulog(F("Can't reserve memory for MPR121."));
    }
}


bool MPR121::measure() {

    uint16_t touched = sensor->touched();

    ulog(F("Meaningless print")); //if this is not here, then consecutive presses on the same button dont work

    value(0).clear();
    for(int i=0; i<12; i++) {
        if(touched&2048) {
            value(0).add(F("1"));
        } else {
            value(0).add(F("0"));
        }
        touched = touched << 1;
    }
    
    return true;
}
```

After that, deploy again, and now it should work.
