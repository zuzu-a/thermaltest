#ifndef FLACSAT_H_
#define FLACSAT_H_

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
#include <cstdint>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
#include <signal.h>

// GLOBAL VARIABLES
volatile bool   MAIN_RUNNING = true;        //.. flag for whether main should continue running

/*
#include "io/fio.cpp"
#include "io/errors.cpp"
*/

#include "hardware/devices/raspi4b.cpp"
#include "hardware/subsystems/cdh.cpp"

/*
#include "hardware/devices/ms5837.cpp"
#include "hardware/devices/lg160431.cpp"
#include "hardware/devices/ltc2620.cpp"
*/

#include "hardware/devices/max7300.cpp"
#include "hardware/devices/ad7490.cpp"
#include "hardware/subsystems/femta.cpp"

#include "hardware/subsystems/adcs.cpp"

/*
#include "hardware/subsystems/comm.cpp"
#include "hardware/subsystems/eps.cpp"
#include "hardware/subsystems/laser.cpp"
*/


#include "hardware/satellite.cpp"

// threads files

/*
#include "threads/mode.cpp"
#include "threads/data.cpp"
#include "io/commands.cpp"
*/

/*
#include "conops/deploy.cpp"
#include "conops/safe.cpp"
#include "conops/standby.cpp"
#include "conops/femta_test.cpp"
#include "conops/femta_pointing.cpp"
#include "conops/adcs_laser.cpp"
#include "conops/femta_laser.cpp"
#include "conops/communication.cpp"
*/

// DEFINITIONS

#define EXIT_NOMINAL        0
#define EXIT_FSYS_FAIL      1
#define EXIT_DATA_INIT_FAIL 2
#define EXIT_MODE_INIT_FAIL 3
#define EXIT_SUPERVISOR_INIT_FAIL 4

// FUNCTIONS

void handleTerminate(int);

#endif