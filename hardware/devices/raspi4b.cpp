#include "raspi4b.h"

///////////////////////////////////////////
//
// PURPOSE: builds and instance of a RASPI4B device
//
// ARGUMENTS: @ name - name of raspiberry pi
//
// RETURN: pointer to RASPI4B
//
///////////////////////////////////////////

RASPI4BType * createRASPI4B(char * name) {

  RASPI4BType * dev = malloc(sizeof(struct RASPI4BType));

  pthread_mutex_init(&(dev -> mutex), NULL);
  pthread_mutex_lock(&(dev -> mutex));

  dev -> name = name;

  //.. open temperature file
  if ((dev -> tfile = open(TEMP_FILE_PATH, O_RDONLY)) == -1) { logError(RASPI4B_TCPU_OPEN_ERROR, dev -> name); }
  
  pthread_mutex_unlock(&(dev -> mutex));

  return dev;
};

///////////////////////////////////////////
//
// PURPOSE: Frees RASPI4B device
//
// ARGUMENTS: @ dev - pointer to RASPI4B
//
///////////////////////////////////////////

void freeRASPI4B(RASPI4BType * dev) {

  pthread_mutex_lock(&(dev -> mutex));

  //.. freeing temp file
  if (dev -> tfile != -1) { close(dev -> tfile); }
  
  //.. free mutex
  pthread_mutex_unlock(&(dev -> mutex));
  pthread_mutex_destroy(&(dev -> mutex));

  free(dev);
}

///////////////////////////////////////////
//
// PURPOSE: reads the RASPI4B cpu temp
//
// ARGUMENTS: @ dev - pointer to RASPI4B
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool readCPUTempRASPI4B(RASPI4BType * dev) {

  // reset the file pointer to the beginning of the file
  lseek(dev -> tfile, 0, SEEK_SET);

  // read the temperature string from the file
  int rlen;
  char tstr[256];
  
  if ((rlen = read(dev -> tfile, tstr, 255)) == -1) { logError(RASPI4B_TCPU_READ_ERROR, dev -> name); return false; }
  tstr[rlen] = '\0';

  // convert the temperature string to a floating-point value
  dev -> T = atof(tstr) / 1000.0;
  
  return true;
}