#include <iotempower.h>

const int BUZZER_PIN = 39;

void setup() {
    // Initialise IoT Empower
    iotempower_init();

    // Configure buzzer PWM
    ledcAttach(BUZZER_PIN, 2000, 8);

    Serial.begin(115200);
    Serial.println("Alarm buzzer started");
}

void loop() {
    // Keep IoT Empower runtime alive
    iotempower_loop();

    // Alarm sound
    ledcWriteTone(BUZZER_PIN, 2500);
    delay(200);

    ledcWriteTone(BUZZER_PIN, 0);
    delay(200);
}