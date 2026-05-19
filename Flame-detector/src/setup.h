#include <iotempower.h>

// On définit le capteur sur la Pin 27
// On utilise "input" qui est le driver générique
input(flame, 27, "pullup"); 
output(led, 2); // LED de status sur l'ESP32

void setup_devices() {
    flame.on_change([&](Device& d) {
        if (d.is("0")) { // Souvent le capteur passe à 0 quand il voit du feu
            led.on();
            ulog("ALERTE : Flamme détectée !");
        } else {
            led.off();
        }
        return true;
    });
}
