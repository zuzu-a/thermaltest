#include "max7300.h"

class MAX7300 {
    public:

    // Initialize the device.
    Device * initialize(char * name, uint8_t addr) {

        Device * dev = new Device; // Allocate memory for the device.

        pthread_mutex_init(&(dev -> mutex), NULL); // Initialize mutex.
        pthread_mutex_lock(&(dev -> mutex)); // Lock mutex.

        // Set name of the device.
        dev -> name = name;

        // Set address.
        dev -> addr = addr;

        // Set the I2C bus.
        dev -> bus = -1;

        if((dev -> bus = openI2C(0, addr)) < 0) {
            logError(I2C_BUS_ERROR, name);
        }

        pthread_mutex_unlock(&(dev -> mutex));

        return dev;
        }
    };

    void free(Device * dev) {

        pthread_mutex_lock(&(dev -> mutex));

        //.. shutdown
        Device.shutdown(dev);

        //.. close bus
        closeI2C(dev -> bus);

        //.. free mutex
        pthread_mutex_unlock(&(dev -> mutex));
        pthread_mutex_destroy(&(dev -> mutex));

        free(dev);
    }

    bool reset(Device * dev) {

    if (!Device.shutdown(dev)) { return false; }
    usleep(10000);
    if (!Device.start(dev)) { return false; }

    return true;
    }



};