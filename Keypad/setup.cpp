pwm(alarm, 33, 2000);
mpr121(cap).i2c(5,6);

void setup_devices() {
    // BIP de test au démarrage
    alarm.on(); 
    delay(1000);
    alarm.off();
    
    // Allumer quand on appuie
    cap.on_press(0, [&](Device& d) {
        alarm.on();
        return true;
    });

    // ÉTEINDRE quand on relâche (sinon ça sonne à l'infini !)
    cap.on_release(0, [&](Device& d) {
        alarm.off();
        return true;
    });
}
