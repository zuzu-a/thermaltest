#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <float.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
/* #include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
#include <signal.h>
*/

#ifndef CDH_H_   
#define CDH_H_

// DEFINITIONS

#define NUM_I2C 1    //.. number of I2C buses available
#define NUM_SPI 4    //.. number of SPI channels available

// STRUCTURE TYPES

typedef struct CDHType CDHType;

// STRUCTURE DEFINTIONS

struct CDHType {

  //.. mutex
  pthread_mutex_t mutex;

  //.. devices
};

// FUNCTIONS

CDHType * createCDH(void);
void        freeCDH(CDHType *);
int         openSPI(uint8_t, uint8_t, uint8_t, uint32_t);
void       closeSPI(int);
bool        readSPI(int, uint8_t *, uint8_t, uint16_t);
bool       writeSPI(int, uint8_t *, uint8_t, uint16_t);
bool    transferSPI(int, uint8_t *, uint8_t *, uint8_t, uint16_t);
int         openI2C(uint8_t, uint8_t);
void       closeI2C(int);
bool        readI2C(int, uint8_t *, uint8_t);
bool       writeI2C(int, uint8_t *, uint8_t);

#endif