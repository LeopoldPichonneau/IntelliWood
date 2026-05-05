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
#include <MatrixPanel_I2S_DMA.h>

MatrixPanel_I2S_DMA *display = nullptr;

void setup() {

  HUB75_I2S_CFG mxconfig(
    64, 32, 1,
    {
      33, // R1
      27, // G1
      32, // B1
      14, // R2
      12, // G2
      13, // B2
      23, // A
      19, // B
      5,  // C
      17, // D
      16, // CLK
      4,  // LAT
      15  // OE
    }
  );

  display = new MatrixPanel_I2S_DMA(mxconfig);
  display->begin();

  display->fillScreen(display->color565(255, 0, 0)); // rouge
}

void loop() {
}