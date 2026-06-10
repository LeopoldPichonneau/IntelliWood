#include <iotempower.h>

// On déclare la LED. IoTempower va écouter sur MQTT 
// le topic "LED/led1" (ou le nom de ta node/led1)
output(led1, 2); 

void setup_devices() {
    // Pas besoin de code ici pour la réception MQTT, 
    // IoTempower s'en occupe tout seul !
}
