#include "max7300.h"

///////////////////////////////////////////
//
// PURPOSE: creates and initializes and instance of the MAX7300 device
//
// ARGUMENTS: @ name - pointer to name
//            @ addr - i2c address
//
// RETURN: pointer to device
//
///////////////////////////////////////////

MAX7300Type * createMAX7300(char * name, uint8_t addr) {

  MAX7300Type * dev = malloc(sizeof(struct MAX7300Type));

  pthread_mutex_init(&(dev -> mutex), NULL);
  pthread_mutex_lock(&(dev -> mutex));

  dev -> name = name;
  dev -> addr = addr;
  dev -> bus  = -1;
  
  //.. opening I2C bus
  if ((dev -> bus = openI2C(0, addr)) < 0) { logError(I2C_BUS_ERROR, name); }

  pthread_mutex_unlock(&(dev -> mutex));

  return dev;
}



///////////////////////////////////////////
//
// PURPOSE: frees and instance of the MAX7300 device
//
// ARGUMENTS: @ dev - pointer to device
//
///////////////////////////////////////////

void freeMAX7300(MAX7300Type * dev) {

  pthread_mutex_lock(&(dev -> mutex));

  //.. shutdown
  shutdownMAX7300(dev);

  //.. close bus
  closeI2C(dev -> bus);

  //.. free mutex
  pthread_mutex_unlock(&(dev -> mutex));
  pthread_mutex_destroy(&(dev -> mutex));

  free(dev);
}

///////////////////////////////////////////
//
// PURPOSE: resets a MAX7300
//
// ARGUMENTS: @ dev - pointer to MAX7300 device
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetMAX7300(MAX7300Type * dev) {

  if (!shutdownMAX7300(dev)) { return false; }
  usleep(10000);
  if (!startMAX7300(dev)) { return false; }

  return true;
}

///////////////////////////////////////////
//
// PURPOSE: starts the MAX7300 into normal operation
//
// ARGUMENTS: @ dev - pointer to device
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool startMAX7300(MAX7300Type * dev) {

  //.. starting device
  char buffer[2] = { MAX7300_CONFIGURATION, (char) 1 };

  if (!writeI2C(dev -> bus, buffer, 2)) { logError(MAX7300_START_WR_ERROR, dev -> name); return false; }

  for (int i = 0; i < 7; i++) {
    
    if (!readConfig(dev, MAX7300_PORTS[i], (dev -> config) + i)) { return false; }
  }

  //.. activate pins
  int pins[28];
  for (int pin = 4 ; pin <= 31 ; pin++) { pins[pin - 4] = pin; }

  if (!configureMAX7300(dev, pins, 28)) { return false; }
  
  return true;
}

///////////////////////////////////////////
//
// PURPOSE: shuts down the MAX7300
//
// ARGUMENTS: @ dev - pointer to device
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool shutdownMAX7300(MAX7300Type * dev) {

  bool result = true;
  
  //.. deenergize pins
  for (int p = 4 ; p <= 31 ; ++p) {

    if (!setPinMAX7300(dev, p, MAX7300_PIN_LOW)) { result = false; }
  }
  
  //.. shutdown device
  char buffer[2] = { MAX7300_CONFIGURATION, (char) 0 };

  if (!writeI2C(dev -> bus, buffer, 2)) { logError(MAX7300_SHUTDOWN_WR_ERROR, dev -> name); return false; }

  for (int i = 0; i < 7; i++) {
    
    if (!readConfig(dev, MAX7300_PORTS[i], (dev -> config) + i)) { result = false; }
  }

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: reads the configuration of a port
//
// ARGUMENTS: @ dev - pointer to device
//            @ port - port address
//            @ config - pointer to result config
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool readConfig(MAX7300Type * dev, char port, char * config) {

  char data[1];
  char buffer[1] = { port };
  
  if (!writeI2C(dev -> bus, buffer, 1)) { logError(MAX7300_RCONFIG_WR_ERROR, dev -> name); return false; }
  if (!readI2C(dev -> bus, data, 1))    { logError(MAX7300_RCONFIG_RD_ERROR, dev -> name); return false; }

  *config = data[0];

  return true;
}

///////////////////////////////////////////
//
// PURPOSE: configures the pins of the MAX7300 as output
//
// ARGUMENTS: @ dev - pointer to device
//            @ pins - array of pins to configure
//            @ npins - number of pins
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool configureMAX7300(MAX7300Type * dev, int pins[], int npins) {

  char config_4_7   = dev -> config[0];
  char config_8_11  = dev -> config[1];
  char config_12_15 = dev -> config[2];
  char config_16_19 = dev -> config[3];
  char config_20_23 = dev -> config[4];
  char config_24_27 = dev -> config[5];
  char config_28_31 = dev -> config[6];
  char cur_config;

  for (int i = 0 ; i < npins ; i++) {
    
    if (pins[i] <= 7 && pins[i] >= 4) {
      replaceBits(&config_4_7, 1, 2*(pins[i] - 4), 2);
    }
    else if (pins[i] <= 11 && pins[i] >= 8) {
      replaceBits(&config_8_11, 1, 2*(pins[i] - 8), 2);  
    }
    else if (pins[i] <= 15 && pins[i] >= 12) {
      replaceBits(&config_12_15, 1, 2*(pins[i] - 12), 2);  
    }
    else if (pins[i] <= 19 && pins[i] >= 16) {
      replaceBits(&config_16_19, 1, 2*(pins[i] - 16), 2);  
    }
    else if (pins[i] <= 23 && pins[i] >= 20) {
      replaceBits(&config_20_23, 1, 2*(pins[i] - 20), 2);  
    }
    else if (pins[i] <= 27 && pins[i] >= 24) {
      replaceBits(&config_24_27, 1, 2*(pins[i] - 24), 2);  
    }
    else if (pins[i] <= 31 && pins[i] >= 28) {
      replaceBits(&config_28_31, 1, 2*(pins[i] - 28), 2);  
    }
  }
    
  for (int i = 0; i < 7; i++) {

    switch(i) {
    case 0:
      cur_config = config_4_7;
      break;
    case 1:
      cur_config = config_8_11;
      break;
    case 2:
      cur_config = config_12_15;
      break;
    case 3:
      cur_config = config_16_19;
      break;
    case 4:
      cur_config = config_20_23;
      break;
    case 5:
      cur_config = config_24_27;
      break;
    case 6:
      cur_config = config_28_31;
      break;
    }
        
    char buffer[2] = { MAX7300_PORTS[i], cur_config };

    if (!writeI2C(dev -> bus, buffer, 2)) { logError(MAX7300_WCONFIG_WR_ERROR, dev -> name); return false; }
    else { dev -> config[i] = cur_config; }
  }
  
  return true;
}

///////////////////////////////////////////
//
// PURPOSE: replaces bits in a byte
//
// ARGUMENTS: @ byte - pointer to byte
//            @ newbits - bits to replace
//            @ start - starting bit index
//            @ n - length of new bits
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

void replaceBits(char * byte, char newbits, int start, int n){
 
  char clearmask = ~(~(~(0) << n) << start);

  *byte = *byte & clearmask;
  *byte = *byte | (newbits << start);
}

///////////////////////////////////////////
//
// PURPOSE: sets a pin to high or low
//
// ARGUMENTS: @ dev - pointer to device
//            @ pin - pin number
//            @ state - pin state (0 = low, 1 = high)
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool setPinMAX7300(MAX7300Type * dev, int pin, int state) {

  if (pin < 4 || pin > 31) { return false; }

  char buffer[2] = { (char) pin + 32, (char) state };
  
  if (!writeI2C(dev -> bus, buffer, 2)) { logError(MAX7300_PSET_WR_ERROR, dev -> name); return false; }

  return true;
}

///////////////////////////////////////////
//
// PURPOSE: reads pin value
//
// ARGUMENTS: @ dev - pointer to device
//            @ pin - pin number
//            @ output - resulting pin output measurement
//
// RETURN: success / fail flag
//
///////////////////////////////////////////

bool readPinMAX7300(MAX7300Type * dev, int pin, int * output) {

  if (pin < 4 || pin > 31) { return false; }

  char data[1];
  char buffer[1] = { pin + 32 };

  if (!writeI2C(dev -> bus, buffer, 1)) { logError(MAX7300_PREAD_WR_ERROR, dev -> name); return false; }
  if (!readI2C(dev -> bus, data, 1))    { logError(MAX7300_PREAD_RD_ERROR, dev -> name); return false; }

  *output = (int) data[0];

  return true;
}