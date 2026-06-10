// Configuration identique au PIR qui marche
display(mon_ecran, U8G2_SH1107_128X128_F_HW_I2C);
output(led, 10);
mfrc522(lecteur);

void setup_devices() {
    led.on();
    mon_ecran.clear();
    mon_ecran.println("Initialisation...");
    mon_ecran.display();

    lecteur.on_change([&](Device& d) {
        mon_ecran.clear();
        mon_ecran.println("Badge lu :");
        mon_ecran.println(d.value());
        mon_ecran.display();

        led.off();
        delay(100);
        led.on();
        return true;
    });
}
