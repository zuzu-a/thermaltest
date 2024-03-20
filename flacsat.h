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


#include "io/fio.c"
#include "io/errors.c"

#include "hardware/devices/raspi4b.c"
#include "hardware/subsystems/cdh.c"

#include "hardware/devices/ms5837.c"
#include "hardware/devices/lg160431.c"
#include "hardware/devices/max7300.c"
#include "hardware/devices/ltc2620.c"
#include "hardware/devices/ad7490.c"
#include "hardware/subsystems/femta.c"

#include "hardware/subsystems/comm.c"
#include "hardware/subsystems/eps.c"
#include "hardware/subsystems/adcs.c"
#include "hardware/subsystems/laser.c"

#include "hardware/satellite.c"

// threads files
#include "threads/mode.c"
#include "threads/data.c"
#include "io/commands.c"

#include "conops/deploy.c"
#include "conops/safe.c"
#include "conops/standby.c"
#include "conops/femta_test.c"
#include "conops/femta_pointing.c"
#include "conops/adcs_laser.c"
#include "conops/femta_laser.c"
#include "conops/communication.c"


// DEFINITIONS

#define EXIT_NOMINAL        0
#define EXIT_FSYS_FAIL      1
#define EXIT_DATA_INIT_FAIL 2
#define EXIT_MODE_INIT_FAIL 3
#define EXIT_SUPERVISOR_INIT_FAIL 4

// FUNCTIONS

void handleTerminate(int);

#endif