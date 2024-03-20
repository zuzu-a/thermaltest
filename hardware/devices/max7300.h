#ifndef MAX7300_H_   
#define MAX7300_H_
#include "../../flacsat.h"

// DEFINITIONS

#define MAX7300_NO_OP                  0x00
#define MAX7300_SET_INTERRUPT_MASK     0x03
#define MAX7300_CONFIGURATION          0x04
#define MAX7300_TRANSITION_DETECT_MASK 0x06
#define MAX7300_ADDR_DEFAULT           0x40
#define MAX7300_PIN_LOW                0
#define MAX7300_PIN_HIGH               1
#define MAX7300_TANK_ISO_OPEN          4
#define MAX7300_TANK_FILL_OPEN         31
#define MAX7300_TANK_FILL_BYPASS       5
#define MAX7300_FEMTA_PPX_OPEN         12 // femta 2
#define MAX7300_FEMTA_PPX_CLOSE        8 // femta 2
#define MAX7300_FEMTA_PPY_OPEN         22 // femta 1 
#define MAX7300_FEMTA_PPY_CLOSE        23 // femta 1
#define MAX7300_FEMTA_PNX_OPEN         13 // femta 3
#define MAX7300_FEMTA_PNX_CLOSE        9 // femta 3
#define MAX7300_FEMTA_PNY_OPEN         14 // femta 4
#define MAX7300_FEMTA_PNY_CLOSE        10 // femta 4
#define MAX7300_FEMTA_NNX_OPEN         17 // femta 6
#define MAX7300_FEMTA_NNX_CLOSE        16 // femta 6
#define MAX7300_FEMTA_NNY_OPEN         15 // femta 5
#define MAX7300_FEMTA_NNY_CLOSE        11 // femta 5
#define MAX7300_FEMTA_NPX_OPEN         19 // femta 7
#define MAX7300_FEMTA_NPX_CLOSE        18 // femta 7
#define MAX7300_FEMTA_NPY_OPEN         21 // femta 8
#define MAX7300_FEMTA_NPY_CLOSE        20 // femta 8
#define MAX7300_TANK_HEATER            24 
#define MAX7300_FEMTA_HEATER           25

const char MAX7300_PORTS[7] = { 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

// STRUCTURE TYPES

typedef struct MAX7300Type MAX7300Type;

// STRUCTURE DEFINTIONS

struct MAX7300Type {

  pthread_mutex_t mutex;       //.. mutex

  char * name;                 //.. device name

  int bus;                     //.. I2C bus
  uint8_t addr;                //.. I2C address

  char config[7];              //.. port configurations
};

// FUNCTIONS

MAX7300Type *    createMAX7300(char *, uint8_t);
void               freeMAX7300(MAX7300Type *);
bool              resetMAX7300(MAX7300Type *);
bool              startMAX7300(MAX7300Type *);
bool           shutdownMAX7300(MAX7300Type *);
bool          configureMAX7300(MAX7300Type *, int[], int);
bool                readConfig(MAX7300Type *, char, char *);
void               replaceBits(char *, char, int, int);
bool             setPinMAX7300(MAX7300Type *, int, int);
bool            readPinMAX7300(MAX7300Type *, int, int *);

#endif