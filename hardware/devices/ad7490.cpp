// Includes
#include "ad7490.h"

class AD7490 {
    public:

    // Initialize the device.
    Device * initialize(char * name, uint8_t cs) {

        Device * dev = new Device; // Allocate memory for the device.

        pthread_mutex_init(&(dev -> mutex), NULL); // Initialize mutex.
        pthread_mutex_lock(&(dev -> mutex)); // Lock mutex.

        // Set name of the device.
        dev -> name = name;
        // Set chip select pin.
        dev -> cs = cs;

        if((dev -> bus = openSPI(cs, AD7490_SPI_MODE, AD7490_SPI_BPW, AD7490_SPI_SPEED)) == -1) {
            logError(SPI_BUS_ERROR, name);
            return -1;

        return dev;
        }
    };

    void open(Device * dev) {
        // Initialize SPI
        spi.begin(dev -> bus);
    }

    void close(Device * dev) {
        // Close SPI
        spi.end();
    }

};