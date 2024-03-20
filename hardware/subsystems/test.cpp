#include "test.h"
#include <string>

///////////////////////////////////////////
//
// PURPOSE: dynamic test instance that can initialize anything required
//
// RETURN: pointer to test subsystem
//
///////////////////////////////////////////

class Device {
    public:

    // Initialize custom subsystem.
    Device * create(void) {
      Device * test = new Device; // Allocate memory for the device.

      pthread_mutex_init(&(test -> mutex), NULL); // Initialize mutex.
      pthread_mutex_lock(&(test -> mutex)); // Lock mutex.

      //.. GPIOs
      test -> gpio_fwd = MAX7300("GPIO_FWD", 0x40);
      test -> gpio_aft = MAX7300("GPIO_AFT", 0x44);
      
      //.. ADCs
      test -> adc_fwd = AD7490("ADC_FWD", 0);
      test -> adc_aft = AD7490("ADC_AFT", 2);
      
      //.. DACs
      test -> dac_fwd = LTC2620("DAC_FWD", 1, 5.25);
      test -> dac_aft = LTC2620("DAC_AFT", 3, 5.25);


      pthread_mutex_unlock(&(test -> mutex));
    
      return test;
    }

    bool boot(Device * femta) {
      bool result = true;

      pthread_mutex_lock(&(femta -> gpio_fwd -> mutex));
      if (!MAX7300(femta -> gpio_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> gpio_fwd -> mutex));

      pthread_mutex_lock(&(femta -> gpio_aft -> mutex));
      if (!MAX7300(femta -> gpio_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> gpio_aft -> mutex));
      
      //.. boot ADC devices
      pthread_mutex_lock(&(femta -> adc_fwd -> mutex));
      if (!AD7490(femta -> adc_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> adc_fwd -> mutex));
      
      pthread_mutex_lock(&(femta -> adc_aft -> mutex));
      if (!AD7490(femta -> adc_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> adc_aft -> mutex));
  
    //.. boot DAC devices
      pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
      if (!startLTC2620(femta -> dac_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
      
      pthread_mutex_lock(&(femta -> dac_aft -> mutex));
      if (!startLTC2620(femta -> dac_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> dac_aft -> mutex));

      return result;
    }

    bool shutdown(Device * femta) {
      bool result = true;

      pthread_mutex_lock(&(femta -> gpio_fwd -> mutex));
      if (!MAX7300(femta -> gpio_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> gpio_fwd -> mutex));

      pthread_mutex_lock(&(femta -> gpio_aft -> mutex));
      if (!MAX7300(femta -> gpio_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> gpio_aft -> mutex));
      
      //.. boot ADC devices
      pthread_mutex_lock(&(femta -> adc_fwd -> mutex));
      if (!AD7490(femta -> adc_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> adc_fwd -> mutex));
      
      pthread_mutex_lock(&(femta -> adc_aft -> mutex));
      if (!AD7490(femta -> adc_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> adc_aft -> mutex));
  
    //.. boot DAC devices
      pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
      if (!startLTC2620(femta -> dac_fwd)) { result = false; }
      pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
      
      pthread_mutex_lock(&(femta -> dac_aft -> mutex));
      if (!startLTC2620(femta -> dac_aft)) { result = false; }
      pthread_mutex_unlock(&(femta -> dac_aft -> mutex));

      return result;
    }
};