/* setup.cpp
 * This is the configuration code for a IoTempower node.
 * Here, you define all the devices (and eventually their interactions)
 * connected to the node specified with this directory.
 * If you want to see more device configuration examples,
 * check $IOTEMPOWER_ROOT/examples/running-node-test-setup.cpp
 *
 * Or check out the command reference for potential devices you can add.
 * 
 * This whole comment block can be deleted
 * */


 #include <iotempower.h>

void setup_devices() {
    // Tu dis à IoTempower : "J'ai une entrée (input) appelée 'motion', branchée sur la broche 'G26'"
    input(motion, "G26", "pullup");
}