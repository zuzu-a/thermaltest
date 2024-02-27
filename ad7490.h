#ifndef AD7490_H_   
#define AD7490_H_

// DEFINITIONS

#define AD7490_NUM_CHAN       16
#define AD7490_SPI_MODE       0
#define AD7490_SPI_SPEED      1000000
#define AD7490_SPI_BPW        8
#define AD7490_RESOLUTION     12
#define AD7490_CMD_START_1    0xFF
#define AD7490_CMD_START_2    0xFF
#define AD7490_CMD_SHUTDOWN_1 0x82
#define AD7490_CMD_SHUTDOWN_2 0x30
#define AD7490_CMD_READ_1     0x83
#define AD7490_CMD_READ_2     0x30

struct Device {
    pthread_mutex_t mutex;     //.. mutex

    char * name;               //.. device name

    int bus;                   //.. SPI bus file
    
    uint8_t cs;                //.. SPI chip select

    double V[AD7490_NUM_CHAN]; //.. ADC channel voltages
    };

// FUNCTIONS

Device *     createAD7490(char *, unsigned char);
bool               openAD7490(Device *);
void               freeAD7490(Device *);
bool              resetAD7490(Device *);
bool              startAD7490(Device *);
bool           shutdownAD7490(Device *);
bool               readAD7490(Device *, uint8_t);
double       codeToVoltAD7490(uint16_t, double, int16_t);

#endif // AD7490_H_
