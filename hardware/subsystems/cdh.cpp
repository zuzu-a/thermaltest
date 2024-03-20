#include "cdh.h"

///////////////////////////////////////////
//
// PURPOSE: builds and instance of CDH subsystem
//
// RETURN: pointer to cdh subsystem
//
///////////////////////////////////////////

CDHType * createCDH(void) {

  CDHType * cdh = malloc(sizeof(struct CDHType));

  //.. initialize mutex
  pthread_mutex_init(&(cdh -> mutex), NULL);
  pthread_mutex_lock(&(cdh -> mutex));

  //.. devices
  cdh -> flight_computer = createRASPI4B("RASPI4B");
  
  pthread_mutex_unlock(&(cdh -> mutex));

  return cdh;
};

///////////////////////////////////////////
//
// PURPOSE: Frees CDH subsystem
//
// ARGUMENTS: @ cdh - pointer to cdh
//
///////////////////////////////////////////

void freeCDH(CDHType * cdh) {

  pthread_mutex_lock(&(cdh -> mutex));

  //.. free devices
  freeRASPI4B(cdh -> flight_computer);
  
  //.. free mutex
  pthread_mutex_unlock(&(cdh -> mutex));
  pthread_mutex_destroy(&(cdh -> mutex));

  free(cdh);
}

///////////////////////////////////////////
//
// PURPOSE: opens an instance of an SPI bus using the spidev library
//
// ARGUMENTS: @ cs - chip select index
//            @ mode - spi mode identifier
//            @ bpw - spi bits per word size
//            @ speed - spi device clock speed
//
// RETURN: bus file identifier (-1 if invalid)
//
//////////////////////////////////////////

int openSPI(uint8_t cs, uint8_t mode, uint8_t bpw, uint32_t speed) {
  
  int bus;

  //.. opening file
  if (cs > NUM_SPI - 1 || (bus = open(SPI_FILES[cs], O_RDWR)) < 0) { return -1; }

  //.. setting mode
  if (ioctl(bus, SPI_IOC_WR_MODE, &mode) < 0) { return -1; }
  if (ioctl(bus, SPI_IOC_RD_MODE, &mode) < 0) { return -1; }

  //.. setting word size
  if (ioctl(bus, SPI_IOC_WR_BITS_PER_WORD, &bpw) < 0) { return -1; }
  if (ioctl(bus, SPI_IOC_RD_BITS_PER_WORD, &bpw) < 0) { return -1; }

  //.. setting speed
  if (ioctl(bus, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) { return -1; }
  if (ioctl(bus, SPI_IOC_RD_MAX_SPEED_HZ, &speed) < 0) { return -1; }
  
  return bus;
}

///////////////////////////////////////////
//
// PURPOSE: closes and instance of the spi bus file
//
// ARGUMENTS: @ bus - bus file identifier
//
//////////////////////////////////////////

void closeSPI(int bus) {

  //.. closing file
  if (bus != -1) { close(bus); }
}

///////////////////////////////////////////
//
// PURPOSE: spi read function
//
// ARGUMENTS: @ bus - bus file
//            @ rx - rx data buffer
//            @ len - buffer length
//            @ delay - microsecond delay
//
// RETURN: success fail flag
//
//////////////////////////////////////////

bool readSPI(int bus, uint8_t * rx, uint8_t len, uint16_t delay) {

  struct spi_ioc_transfer message[1];
  memset(message, 0, sizeof(message));

  message[0].rx_buf      = (unsigned long)rx;
  message[0].len         = len;
  message[0].delay_usecs = delay;
    
  return ioctl(bus, SPI_IOC_MESSAGE(1), message) != -1;
}

///////////////////////////////////////////
//
// PURPOSE: spi write function
//
// ARGUMENTS: @ bus - bus file
//            @ tx - tx data buffer
//            @ len - buffer length
//            @ delay - microsecond delay
//
// RETURN: success fail flag
//
//////////////////////////////////////////

bool writeSPI(int bus, uint8_t * tx, uint8_t len, uint16_t delay) {

  struct spi_ioc_transfer message[1];
  memset(message, 0, sizeof(message));

  message[0].tx_buf      = (unsigned long)tx;
  message[0].len         = len;
  message[0].delay_usecs = delay;
  
  return ioctl(bus, SPI_IOC_MESSAGE(1), message) != -1;
}

///////////////////////////////////////////
//
// PURPOSE: simultaneous spi read / write function
//
// ARGUMENTS: @ bus - bus file
//            @ tx - tx data buffer
//            @ rx - rx data buffer
//            @ len - buffer length
//            @ delay - microsecond delay
//
// RETURN: success / fail flag
//
//////////////////////////////////////////

bool transferSPI(int bus, uint8_t * tx, uint8_t * rx, uint8_t len, uint16_t delay) {

  struct spi_ioc_transfer message[1];
  memset(message, 0, sizeof(message));

  message[0].rx_buf      = (unsigned long)rx;
  message[0].tx_buf      = (unsigned long)tx;
  message[0].len         = len;
  message[0].delay_usecs = delay;
  
  return ioctl(bus, SPI_IOC_MESSAGE(1), message) != -1;
}

///////////////////////////////////////////
//
// PURPOSE: opens i2c bus
//
// ARGUMENTS: @ bus - i2c bus index
//            @ addr - i2c address
//
// RETURN: bus file identifier
//
///////////////////////////////////////////

int openI2C(uint8_t bus, uint8_t addr) {

  if (bus > NUM_I2C - 1) { return -1; }
  
  int file;
  
  //.. opening I2C bus
  if ((file = open(I2C_FILES[0], O_RDWR)) < 0) { return -1; }

  //.. setting I2C slave address
  if (ioctl(file, I2C_SLAVE, addr) < 0) { return -1; }

  return file;
}

///////////////////////////////////////////
//
// PURPOSE: closes and instance of the i2c bus file
//
// ARGUMENTS: @ bus - bus file identifier
//
//////////////////////////////////////////

void closeI2C(int bus) {

  //.. closing file
  if (bus != -1) { close(bus); }
}

///////////////////////////////////////////
//
// PURPOSE: reads data from an i2c bus
//
// ARGUMENTS: @ bus - i2c bus index
//            @ rx - buffer to read to
//            @ N - read length
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool readI2C(int bus, uint8_t * rx, uint8_t N) {

  if (read(bus, rx, N) != N) { return false; }

  return true;
}

///////////////////////////////////////////
//
// PURPOSE: writes data to an i2c bus
//
// ARGUMENTS: @ bus - i2c bus index
//            @ tx - buffer to write to
//            @ N - write length
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool writeI2C(int bus, uint8_t * tx, uint8_t N) {

  if (write(bus, tx, N) != N) { return false; }

  return true;
}