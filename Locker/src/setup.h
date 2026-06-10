#include <iotempower.h>

// On déclare le verrou sur la Pin 12
// MQTT topic automatique : Locker/verrou/set
output(verrou, 12); 

void setup_devices() {
    // Au démarrage, on s'assure que c'est fermé (OFF)
    verrou.off();
}
