# IntelliWood

Integrated monitoring and management system for wood granule heating and storage.

## Table of contents

- [Overview](#overview)
- [Features](#features)
- [Hardware](#hardware)
- [Architecture](#architecture)
- [Getting started](#getting-started)
- [MQTT reference](#mqtt-reference)
- [Contributors](#contributors)

## Overview

IntelliWood is an integrated monitoring and management system designed for wood granule heating and storage. Popular in the Baltic region, these heating systems rely on an oven equipped with automatic ignition and a corkscrew-driven feeding mechanism.

The oven draws fuel from a metal bunker with limited capacity. Maintaining a minimum fuel level is critical -- if the bunker empties, the automatic ignition system continues to try igniting without any fuel. This repetitive dry-firing eventually causes the ignition stick to fail, necessitating a hardware replacement. IntelliWood is designed to help prevent this failure and manage wood granule storage through the four functionalities below.

> Some functionalities are still on the roadmap -- see [Hardware](#hardware) for what is currently implemented.

## Features

### 1. Ambient Sensing & Safety
As wood granules are flammable and sensitive to environmental factors, they are typically stored in a separate dedicated room. As high moisture can degrade the granules, humidity and temperature are closely monitored. In addition, we use a CO2, smoke, flame and PIR sensor to trigger immediate notifications in the event of a fire or unexpected presence. The sensors upload their data over Wi-Fi to a local dedicated server, and are powered from the wall socket.

### 2. Secure Access Control (planned)
To maintain the safety of the storage area, an NFC lock system will restrict entry. Users with the authorized keycard or access to the companion dashboard application will be able to unlock the door. This subsystem (NFC reader, electronic lock, status LED) is on the roadmap and not yet implemented.

### 3. Storage State Logging & Forecasting
The core part of the system is a 3D-printed logging unit situated near the oven's refilling station. This unit tracks the inventory of wood granule bags via an ESP32-S2 microcontroller. When a user refills the bunker, they input the number of bags used via a numeric keypad. To conserve energy, the ESP32-S2 remains in Deep Sleep mode, and wakes only when a button is pressed, triggering a hardware interrupt to update the internal log, sync the .csv file, and transmit the update over WiFi before powering down again. Instead of just closing the connection immediately, the ESP32-S2 waits for a response from the Raspberry Pi containing the datetime forecasting when fuel levels will reach critical thresholds. If no new update comes via the keypad before that datetime, it sounds an alarm via the integrated buzzer.

### 4. Dashboard & Weather Forecast
The system tracks the current bag count. By cross-referencing historical usage with external weather APIs, it forecasts when the bunker will reach a critical threshold. This generates a message in the companion application, and a response to the ESP32-S2 so it knows when the fuel is expected to run out.

## Hardware

### Sensors

| Sensor | Status |
|--------|--------|
| CO2 sensor | Implemented |
| Humidity sensor | Implemented |
| Temperature sensor | Implemented |
| Smoke detector | Implemented |
| Flame detector | Implemented |
| PIR detector | Implemented |

### Devices

| Device | Status |
|--------|--------|
| Keypad (with integrated alarm buzzer) | Implemented |
| Dashboard | Implemented |
| NFC reader | Planned |
| Electronic lock (Locker) | Planned |
| LED | Planned |
| Screen | Planned |

### Boards used

| Node | Board | Status |
|------|-------|--------|
| C02-Temperature-Humidity-sensor | ESP32-S2 | Implemented |
| smoke-sensor | ESP32-S2 | Implemented |
| Flame-detector | ESP32-S2 | Implemented |
| PIR-detector | ESP32-S2 | Implemented |
| Keypad (incl. alarm buzzer) | ESP32-S2 | Implemented |
| NFC-reader | ESP32-S2 | Planned |
| Locker | ESP32-S2 | Planned |
| LED | ESP32-S2 | Planned |
| LED_screen | ESP32-S2 | Planned |

## Architecture

All implemented nodes communicate via **MQTT** over the local Wi-Fi network with a central server (e.g. a Raspberry Pi), which:

1. Complements sensor data with real-time variables from local weather agencies (temperature, wind speed) to create accurate fuel consumption predictions.
2. Hosts the data for the companion mobile application, providing a real-time overview of storage and fuel levels, ambient sensor readings, maintenance alerts and refill forecasts.

```
┌──────────────────────────────────────────────────────┐
│                   Central Server                      │
│                  (Raspberry Pi)                       │
│  - MQTT Broker        - REST API                     │
│  - Weather forecasts  - Database / Dashboard         │
└───────────┬──────────────────┬───────────────────────┘
            │     Wi-Fi / MQTT │
   ┌────────┴────────┐   ┌─────┴───────────────┐
   │ Implemented     │   │ Planned (roadmap)    │
   │ nodes           │   │ nodes                │
   │                 │   │                      │
   │ • CO2/Temp/Hum  │   │ • NFC reader         │
   │ • Smoke detector│   │ • Electronic lock    │
   │ • Flame detector│   │ • LED                │
   │ • PIR detector  │   │ • Screen             │
   │ • Keypad+Buzzer │   │                      │
   │   (Deep Sleep)  │   │                      │
   └─────────────────┘   └──────────────────────┘
```

All nodes are built around the **ESP32-S2** microcontroller, with built-in Wi-Fi connectivity:

- **CO2/temperature/humidity, smoke, flame and PIR nodes** -- ambient sensing and safety.
- **Keypad node** -- storage logging with integrated alarm buzzer, kept in **Deep Sleep** to conserve energy and woken by a hardware interrupt.
- **NFC reader / electronic lock / LED / screen** -- planned access-control subsystem, not yet implemented.

## Getting started

### Prerequisites

- [IoTempower](https://github.com/iot-systems/iotempower) installed on your machine
- An available Wi-Fi network
- A configured Raspberry Pi (or equivalent server)
- The hardware for each node you want to deploy

### 1. Configure the network

Edit `system.conf` at the project root with your Wi-Fi credentials and MQTT broker address:

```bash
IOTEMPOWER_AP_NAME="your-ssid"
IOTEMPOWER_AP_PASSWORD="your-password"
IOTEMPOWER_MQTT_HOST="_gateway"
```

- `_gateway` resolves automatically to the router (recommended if mosquitto runs on the router).
- If you run `mqtt_starter` on your own computer instead, replace `_gateway` with your machine's local IP address (`ip a` on Linux/macOS, `ipconfig` on Windows -- also printed when `mqtt_starter` starts). Make sure port **1883** is open on that machine's firewall.

### 2. Flash a node

Each node lives in its own subfolder (`setup.cpp`, `node.conf`, `key.txt`, `README.md`). For a board that has never run IoTempower, do an initial serial flash, then deploy over the air for subsequent updates:

```bash
cd NodeName
deploy serial   # first flash, over USB
deploy          # subsequent updates, over the air
```

> The ESP32-S2 (Keypad) may need **Download Mode**: hold **0**, press and release **RST**, then release **0**. Check it's detected with `ls /dev/ttyACM*`.

### 3. Start the MQTT broker and listen

```bash
mqtt_starter scanif   # start the broker, in a separate terminal
mqtt_listen            # watch sensor data coming in
```

## MQTT reference

All nodes publish and subscribe using the convention `<NodeName>/<device>[/set]` -- without `/set` the node is publishing data, with `/set` it is receiving a command.

### Implemented topics

| Topic | Direction | Format | Description |
|-------|-----------|--------|-------------|
| `C02-Temperature-Humidity-sensor/gas` | node → | `co2,temp,hum` | CO2 (ppm), temperature (°C), humidity (%) |
| `smoke-sensor/smoke` | node → | `smoke detected` / `no smoke` | MQ2 binary detection |
| `Flame-detector/flame` | node → | `flame detected` / `no flame` | Infrared flame detection |
| `PIR-detector/pir` | node → | `motion detected` / `no motion` | Motion in storage room |
| `Keypad/cap` | node → | `000000000000` | State of the 12 capacitive electrodes |
| `Keypad/alarm/set` | → node | `0` / `<value>` | Alarm buzzer: `0` = off, non-zero = on |

### Planned topics (roadmap)

| Topic | Direction | Format | Description |
|-------|-----------|--------|-------------|
| `NFC-reader/card` | node → | `<uid_hex>` | UID of the NFC card read |
| `Locker/lock/set` | → node | `0` / `1` | `0` = locked, `1` = unlocked |
| `LED/rgb/set` | → node | `R,G,B` | LED color (0-255 per channel) |

Filter on a specific node with `mqtt_listen "C02-Temperature-Humidity-sensor/#"`, or send a command manually:

```bash
mqtt_pub Keypad/alarm/set 200   # activate the buzzer
mqtt_pub Keypad/alarm/set 0     # turn it off
```

## Contributors

- [@LeopoldPichonneau](https://github.com/LeopoldPichonneau)
- [@KPPHC](https://github.com/KPPHC)
- [@arthurmrimri-del](https://github.com/arthurmrimri-del)
- [@Miriston](https://github.com/Miriston)
