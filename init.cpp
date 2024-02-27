#include <cstdint>
#include <pthread.h>
#include "init.h"


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