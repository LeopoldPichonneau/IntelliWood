#include <iotempower.h>

// Entrée pour la fumée (Pin 34)
input(smoke, 34, "pullup"); 
output(led, 2);

void setup_devices() {
    smoke.on_change([&](Device& d) {
        if (d.is("0")) { // Généralement 0 = Fumée détectée
            led.on();
            ulog("ALERTE : Fumée détectée !");
        } else {
            led.off();
        }
        return true;
    });
}
