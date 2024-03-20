#ifndef CDH_H_   
#define CDH_H_
#include "../../flacsat.h"

// STRUCTURE TYPES

typedef struct CDHType CDHType;

// STRUCTURE DEFINTIONS

struct CDHType {

  //.. mutex
  pthread_mutex_t mutex;

  //.. devices
  RASPI4BType * flight_computer;
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