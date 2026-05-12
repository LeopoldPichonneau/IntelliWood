#!/usr/bin/env python3
import paho.mqtt.client as mqtt
import time
import random

# Network Configuration
BROKER_HOST = "192.168.14.1"
BROKER_PORT = 1883
MQTT_TOPIC = "intelliwood/PIR-detector/motion" # Tailored to folder name conventions

def on_connect(client, userdata, flags, rc):
    print(f"Connected to MQTT Broker with result code {rc}")

def run_simulator():
    client = mqtt.Client()
    client.on_connect = on_connect
    
    print(f"Connecting to broker at {BROKER_HOST}...")
    client.connect(BROKER_HOST, BROKER_PORT, 60)
    client.loop_start()
    
    print("PIR Motion Sensor Simulator Operational. Simulating loops...")
    
    try:
        while True:
            # Trigger Active Event
            print("[SIMULATOR] Event: MOTION DETECTED -> Publishing 'ON'")
            client.publish(MQTT_TOPIC, "ON", qos=1)
            
            # Simulated dwell window
            time.sleep(random.randint(4, 7))
            
            # Trigger Return to Idle
            print("[SIMULATOR] Event: NO MOTION -> Publishing 'OFF'")
            client.publish(MQTT_TOPIC, "OFF", qos=1)
            
            # Idle delay phase before next evaluation loop
            time.sleep(random.randint(5, 10))
            
    except KeyboardInterrupt:
        print("\nStopping PIR Simulator execution...")
        client.loop_stop()
        client.disconnect()

if __name__ == "__main__":
    run_simulator()