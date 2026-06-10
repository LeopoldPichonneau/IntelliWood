// On utilise le driver M5STACK
display(mon_ecran, M5STACK);
input(pir, 26);

void setup_devices() {
    // FORCE LE RETROÉCLAIRAGE (Pin 32 sur M5Stack Core)
    pinMode(32, OUTPUT);
    digitalWrite(32, HIGH); 

    mon_ecran.clear();
    // On met une police simple et on affiche direct
    mon_ecran.println("SYSTEME ACTIF");
    mon_ecran.display();

    pir.on_change([&](Device& d) {
        mon_ecran.clear();
        if (d.is("1")) {
            mon_ecran.println("!!! MOUVEMENT !!!");
        } else {
            mon_ecran.println("... Calme ...");
        }
        mon_ecran.display();
        return true;
    });
}