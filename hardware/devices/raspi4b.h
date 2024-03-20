#ifndef RASPI4B_H_
#define RASPI4B_H_
#include "../../flacsat.h"

// DEFINITIONS

#define NUM_I2C 1    //.. number of I2C buses available
#define NUM_SPI 4    //.. number of SPI channels available

const char * TEMP_FILE_PATH = "/sys/class/thermal/thermal_zone0/temp";    //.. file path for cpu temperature

const char * I2C_FILES[NUM_I2C] = { "/dev/i2c-1" };                                                           //.. i2c bus files
const char * SPI_FILES[NUM_SPI] = { "/dev/spidev0.0", "/dev/spidev0.1", "/dev/spidev1.0", "/dev/spidev1.1" }; //.. spi bus files

// STRUCTURE TYPES

typedef struct RASPI4BType RASPI4BType;

// STRUCTURE DEFINITIONS

struct RASPI4BType {

  pthread_mutex_t mutex;  //.. mutex

  char * name;            //.. device name

  int tfile;              //.. CPU temperature file
  
  float T;                //.. cpu temperature
};

// FUNCTIONS

RASPI4BType *      createRASPI4B(char *);
void                 freeRASPI4B(RASPI4BType *);
bool          readCPUTempRASPI4B(RASPI4BType *);

#endif