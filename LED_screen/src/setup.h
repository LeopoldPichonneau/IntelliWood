cat <<EOF > src/setup.h
#include <MatrixPanel_I2S_DMA.h>

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup_devices() {
    HUB75_I2S_CFG mxconfig(
        64, 32, 1,
        {
          33, 35, 37, 39, 12, 11, // R1, G1, B1, R2, G2, B2
          9, 7, 5, 3,             // A, B, C, D
          16, 4, 1                // CLK, LAT, OE
        }
    );
    
    dma_display = new MatrixPanel_I2S_DMA(mxconfig);
    
    // Luminosité minimale (1 sur 255)
    dma_display->setPanelBrightness(1); 
    dma_display->begin();
    
    // On éteint tout d'abord
    dma_display->fillScreen(0);
    
    // On allume JUSTE 3 pixels (Rouge, Vert, Bleu) dans le coin en haut à gauche
    dma_display->drawPixel(0, 0, dma_display->color565(255, 0, 0));
    dma_display->drawPixel(1, 0, dma_display->color565(0, 255, 0));
    dma_display->drawPixel(2, 0, dma_display->color565(0, 0, 255));
}
EOF