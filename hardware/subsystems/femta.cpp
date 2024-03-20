#include "femta.h"

///////////////////////////////////////////
//
// PURPOSE: builds and instance of femta subsystem
//
// RETURN: pointer to femta subsystem
//
///////////////////////////////////////////

FEMTAType * createFEMTA(void) {

  FEMTAType * femta = malloc(sizeof(struct FEMTAType));

  //.. mutex
  pthread_mutex_init(&(femta -> mutex), NULL);
  pthread_mutex_lock(&(femta -> mutex));

  
  //.. dac calibrations
  femta -> dac_map[THRUSTER_PPY_FWD] = 4; // femta 1
  femta -> dac_map[THRUSTER_PPY_AFT] = 4; // femta 1
  femta -> dac_map[THRUSTER_PPX_FWD] = 5; // femta 2
  femta -> dac_map[THRUSTER_PPX_AFT] = 5; // femta 2
  femta -> dac_map[THRUSTER_PNX_FWD] = 6; // femta 3
  femta -> dac_map[THRUSTER_PNX_AFT] = 6; // femta 3
  femta -> dac_map[THRUSTER_PNY_FWD] = 7; // femta 4
  femta -> dac_map[THRUSTER_PNY_AFT] = 7; // femta 4
  femta -> dac_map[THRUSTER_NNY_FWD] = 0; // femta 5
  femta -> dac_map[THRUSTER_NNY_AFT] = 0; // femta 5
  femta -> dac_map[THRUSTER_NNX_AFT] = 1; // femta 6
  femta -> dac_map[THRUSTER_NNX_FWD] = 1; // femta 6 
  femta -> dac_map[THRUSTER_NPX_AFT] = 2; // femta 7
  femta -> dac_map[THRUSTER_NPX_FWD] = 2; // femta 7
  femta -> dac_map[THRUSTER_NPY_FWD] = 3; // femta 8
  femta -> dac_map[THRUSTER_NPY_AFT] = 3; // femta 8
 
  
  
  femta -> dac_cal[THRUSTER_PPX_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PPX_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PPY_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PPY_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PNX_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PNX_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PNY_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PNY_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NPX_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NPX_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NPY_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NPY_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NNX_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NNX_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NNY_FWD][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NNY_FWD][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PPX_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PPX_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PPY_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PPY_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PNX_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PNX_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_PNY_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_PNY_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NPX_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NPX_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NPY_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NPY_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NNX_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NNX_AFT][1] = -21.3608;
  femta -> dac_cal[THRUSTER_NNY_AFT][0] = 82.4297;
  femta -> dac_cal[THRUSTER_NNY_AFT][1] = -21.3608;

  
  //.. adc calibrations
  femta -> adc_map[THRUSTER_PPY_FWD] = 9; // femta 1
  femta -> adc_map[THRUSTER_PPY_AFT] = 9; // femta 1
  femta -> adc_map[THRUSTER_PPX_FWD] = 7; // femta 2
  femta -> adc_map[THRUSTER_PPX_AFT] = 7; // femta 2
  femta -> adc_map[THRUSTER_PNX_FWD] = 6; // femta 3
  femta -> adc_map[THRUSTER_PNX_AFT] = 6; // femta 3
  femta -> adc_map[THRUSTER_PNY_FWD] = 5; // femta 4
  femta -> adc_map[THRUSTER_PNY_AFT] = 5; // femta 4
  femta -> adc_map[THRUSTER_NNY_FWD] = 4; // femta 5
  femta -> adc_map[THRUSTER_NNY_AFT] = 4; // femta 5
  femta -> adc_map[THRUSTER_NNX_AFT] = 3; // femta 6
  femta -> adc_map[THRUSTER_NNX_FWD] = 3; // femta 6 
  femta -> adc_map[THRUSTER_NPX_AFT] = 1; // femta 7
  femta -> adc_map[THRUSTER_NPX_FWD] = 1; // femta 7
  femta -> adc_map[THRUSTER_NPY_FWD] = 0; // femta 8
  femta -> adc_map[THRUSTER_NPY_AFT] = 0; // femta 8

  femta -> adc_map[HEATER_TANK_FWD]    = 10;
  femta -> adc_map[HEATER_TANK_FWD+1]  = 11;
  femta -> adc_map[HEATER_FEMTA_FWD]   = 8;
  femta -> adc_map[HEATER_FEMTA_FWD+1] = 2;
  femta -> adc_map[HEATER_TANK_AFT]    = 10;
  femta -> adc_map[HEATER_TANK_AFT+1]  = 11;
  femta -> adc_map[HEATER_FEMTA_AFT]   = 8;
  femta -> adc_map[HEATER_FEMTA_AFT+1] = 2;
  
  
  femta -> adc_cal[THRUSTER_PPX_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PPX_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_PPY_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PPY_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_PNX_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PNX_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_PNY_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PNY_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_NPX_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NPX_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_NPY_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NPY_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_NNX_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NNX_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_NNY_FWD][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NNY_FWD][1]   = 0;
  femta -> adc_cal[THRUSTER_PPX_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PPX_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_PPY_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PPY_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_PNX_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PNX_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_PNY_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_PNY_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_NPX_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NPX_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_NPY_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NPY_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_NNX_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NNX_AFT][1]   = 0;
  femta -> adc_cal[THRUSTER_NNY_AFT][0]   = 0.4639;
  femta -> adc_cal[THRUSTER_NNY_AFT][1]   = 0;
  femta -> adc_cal[HEATER_FEMTA_FWD+1][0]   = 10000;
  femta -> adc_cal[HEATER_FEMTA_FWD+1][1]   = 3570000;
  femta -> adc_cal[HEATER_FEMTA_FWD][0] = 0.4639;
  femta -> adc_cal[HEATER_FEMTA_FWD][1] = 0;
  femta -> adc_cal[HEATER_TANK_FWD+1][0]    = 10000;
  femta -> adc_cal[HEATER_TANK_FWD+1][1]    = 3570000;
  femta -> adc_cal[HEATER_TANK_FWD][0]  = 0.4639;
  femta -> adc_cal[HEATER_TANK_FWD][1]  = 0;
  femta -> adc_cal[HEATER_FEMTA_AFT+1][0]   = 10000;
  femta -> adc_cal[HEATER_FEMTA_AFT+1][1]   = 3570000;
  femta -> adc_cal[HEATER_FEMTA_AFT][0] = 0.4639;
  femta -> adc_cal[HEATER_FEMTA_AFT][1] = 0;
  femta -> adc_cal[HEATER_TANK_AFT+1][0]    = 10000;
  femta -> adc_cal[HEATER_TANK_AFT+1][1]    = 3570000;
  femta -> adc_cal[HEATER_TANK_AFT][0]  = 0.4639;
  femta -> adc_cal[HEATER_TANK_AFT][1]  = 0;
  

  //.. PT Sensors
  femta -> hfe_pt_1_fwd    = createMS5837("HFE_PT_1_FWD",    0x76);
  femta -> hfe_pt_2_fwd    = createMS5837("HFE_PT_2_FWD",    0x75);
  femta -> upw_pt_tank_fwd = createMS5837("UPW_PT_TANK_FWD", 0x74);
  femta -> upw_pt_fill_fwd = createMS5837("UPW_PT_FILL_FWD", 0x77);  
  femta -> hfe_pt_1_aft    = createMS5837("HFE_PT_1_AFT",    0x72);
  femta -> hfe_pt_2_aft    = createMS5837("HFE_PT_2_AFT",    0x71);
  femta -> upw_pt_tank_aft = createMS5837("UPW_PT_TANK_AFT", 0x70);
  femta -> upw_pt_fill_aft = createMS5837("UPW_PT_FILL_AFT", 0x6F);

  //.. Flow Sensors
  femta -> flow_ppx_fwd = createLG160431("FEMTA_PPX_FLOW_FWD", 0x50);
  femta -> flow_ppy_fwd = createLG160431("FEMTA_PPY_FLOW_FWD", 0x51);
  femta -> flow_pnx_fwd = createLG160431("FEMTA_PNX_FLOW_FWD", 0x52);
  femta -> flow_pny_fwd = createLG160431("FEMTA_PNY_FLOW_FWD", 0x43);
  femta -> flow_nnx_fwd = createLG160431("FEMTA_NPX_FLOW_FWD", 0x54);
  femta -> flow_nny_fwd = createLG160431("FEMTA_NPY_FLOW_FWD", 0x55);
  femta -> flow_npx_fwd = createLG160431("FEMTA_NNX_FLOW_FWD", 0x56);
  femta -> flow_npy_fwd = createLG160431("FEMTA_NNY_FLOW_FWD", 0x57);
  femta -> flow_ppx_aft = createLG160431("FEMTA_PPX_FLOW_AFT", 0x58);
  femta -> flow_ppy_aft = createLG160431("FEMTA_PPY_FLOW_AFT", 0x59);
  femta -> flow_pnx_aft = createLG160431("FEMTA_PNX_FLOW_AFT", 0x5A);
  femta -> flow_pny_aft = createLG160431("FEMTA_PNY_FLOW_AFT", 0x5B);
  femta -> flow_nnx_aft = createLG160431("FEMTA_NPX_FLOW_AFT", 0x5C);
  femta -> flow_nny_aft = createLG160431("FEMTA_NPY_FLOW_AFT", 0x5D);
  femta -> flow_npx_aft = createLG160431("FEMTA_NNX_FLOW_AFT", 0x5E);
  femta -> flow_npy_aft = createLG160431("FEMTA_NNY_FLOW_AFT", 0x5F);
  
  //.. GPIOs
  femta -> gpio_fwd = createMAX7300("GPIO_FWD", 0x40);
  femta -> gpio_aft = createMAX7300("GPIO_AFT", 0x44);
  
  //.. ADCs
  femta -> adc_fwd = createAD7490("ADC_FWD", 0);
  femta -> adc_aft = createAD7490("ADC_AFT", 2);
  
  //.. DACs
  femta -> dac_fwd = createLTC2620("DAC_FWD", 1, 5.25);
  femta -> dac_aft = createLTC2620("DAC_AFT", 3, 5.25);
  
  pthread_mutex_unlock(&(femta -> mutex));

  return femta;
};

///////////////////////////////////////////
//
// PURPOSE: Frees FEMTA subsystem
//
// ARGUMENTS: @ satellite - pointer to satellite
//
///////////////////////////////////////////

void freeFEMTA(FEMTAType * femta) {
  
  pthread_mutex_lock(&(femta -> mutex));

  //.. DPT sensors
  freeMS5837(femta -> hfe_pt_1_fwd);
  freeMS5837(femta -> hfe_pt_2_fwd);
  freeMS5837(femta -> upw_pt_tank_fwd);
  freeMS5837(femta -> upw_pt_fill_fwd);  
  freeMS5837(femta -> hfe_pt_1_aft);
  freeMS5837(femta -> hfe_pt_2_aft);
  freeMS5837(femta -> upw_pt_tank_aft);
  freeMS5837(femta -> upw_pt_fill_aft);

  //.. Flow sensors
  freeLG160431(femta -> flow_ppx_fwd);
  freeLG160431(femta -> flow_ppy_fwd);
  freeLG160431(femta -> flow_pnx_fwd);
  freeLG160431(femta -> flow_pny_fwd);
  freeLG160431(femta -> flow_nnx_fwd);
  freeLG160431(femta -> flow_nny_fwd);
  freeLG160431(femta -> flow_npx_fwd);
  freeLG160431(femta -> flow_npy_fwd);
  freeLG160431(femta -> flow_ppx_aft);
  freeLG160431(femta -> flow_ppy_aft);
  freeLG160431(femta -> flow_pnx_aft);
  freeLG160431(femta -> flow_pny_aft);
  freeLG160431(femta -> flow_nnx_aft);
  freeLG160431(femta -> flow_nny_aft);
  freeLG160431(femta -> flow_npx_aft);
  freeLG160431(femta -> flow_npy_aft);
  
  //.. GPIO
  freeMAX7300(femta -> gpio_fwd);
  freeMAX7300(femta -> gpio_aft);

  //.. ADC
  freeAD7490(femta -> adc_fwd);
  freeAD7490(femta -> adc_aft);

  //.. DAC
  freeLTC2620(femta -> dac_fwd);
  freeLTC2620(femta -> dac_aft);

  //.. mutex
  pthread_mutex_unlock(&(femta -> mutex));
  pthread_mutex_destroy(&(femta -> mutex));
  
  free(femta);
}

///////////////////////////////////////////
//
// PURPOSE: boots a femta subsystem
//
// ARGUMENTS: @ femta - pointer to femta subsystem
//
// RESULT: fail / success flag
//
///////////////////////////////////////////

bool bootFEMTA(FEMTAType * femta) {

  bool result = true;
  
  //.. boot GPIO devices
  pthread_mutex_lock(&(femta -> gpio_fwd -> mutex));
  if (!startMAX7300(femta -> gpio_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> gpio_fwd -> mutex));

  pthread_mutex_lock(&(femta -> gpio_aft -> mutex));
  if (!startMAX7300(femta -> gpio_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> gpio_aft -> mutex));
  
  //.. boot ADC devices
  pthread_mutex_lock(&(femta -> adc_fwd -> mutex));
  if (!startAD7490(femta -> adc_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> adc_fwd -> mutex));
  
  pthread_mutex_lock(&(femta -> adc_aft -> mutex));
  if (!startAD7490(femta -> adc_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> adc_aft -> mutex));
  
  //.. boot DAC devices
  pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
  if (!startLTC2620(femta -> dac_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  
  pthread_mutex_lock(&(femta -> dac_aft -> mutex));
  if (!startLTC2620(femta -> dac_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> dac_aft -> mutex));

  //.. boot flow sensors
  pthread_mutex_lock(&(femta -> flow_ppx_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_ppx_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_ppx_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_ppy_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_ppy_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_ppy_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_pnx_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_pnx_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_pnx_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_pny_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_pny_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_pny_fwd -> mutex));
  
  pthread_mutex_lock(&(femta -> flow_npx_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_npx_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_npx_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_npy_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_npy_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_npy_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_nnx_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_nnx_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_nnx_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_nny_fwd -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_nny_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_nny_fwd -> mutex));

  pthread_mutex_lock(&(femta -> flow_ppx_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_ppx_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_ppx_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_ppy_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_ppy_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_ppy_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_pnx_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_pnx_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_pnx_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_pny_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_pny_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_pny_aft -> mutex));
  
  pthread_mutex_lock(&(femta -> flow_npx_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_npx_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_npx_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_npy_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_npy_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_npy_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_nnx_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_nnx_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_nnx_aft -> mutex));

  pthread_mutex_lock(&(femta -> flow_nny_aft -> mutex));
  if (!startFlowMeasLG160431(femta -> flow_nny_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> flow_nny_aft -> mutex));
    
  return result;
}

///////////////////////////////////////////
//
// PURPOSE: shutsdown femta subsystem
//
// ARGUMENTS: @ femta - pointer to femta subsystem
//
// RESULT: fail / success flag
//
///////////////////////////////////////////

bool shutdownFEMTA(FEMTAType * femta) {

  bool result = true;
  
  //.. shutdown GPIO devices
  pthread_mutex_lock(&(femta -> gpio_fwd -> mutex));
  if (!shutdownMAX7300(femta -> gpio_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> gpio_fwd -> mutex));

  pthread_mutex_lock(&(femta -> gpio_aft -> mutex));
  if (!shutdownMAX7300(femta -> gpio_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> gpio_aft -> mutex));
  
  //.. shutdown ADC devices
  pthread_mutex_lock(&(femta -> adc_fwd -> mutex));
  if (!shutdownAD7490(femta -> adc_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> adc_fwd -> mutex));
  
  pthread_mutex_lock(&(femta -> adc_aft -> mutex));
  if (!shutdownAD7490(femta -> adc_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> adc_aft -> mutex));
  
  //.. shutdown DAC devices
  pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
  if (!shutdownLTC2620(femta -> dac_fwd)) { result = false; }
  pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  
  pthread_mutex_lock(&(femta -> dac_aft -> mutex));
  if (!shutdownLTC2620(femta -> dac_aft)) { result = false; }
  pthread_mutex_unlock(&(femta -> dac_aft -> mutex));

  return true;
}

///////////////////////////////////////////
//
// PURPOSE: sets the FEMTA ACS to output a certain torque
//
// ARGUMENTS: @ femta - pointer to femta
//            @ T - torque vector
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool torqueControl(FEMTAType * femta, double T[3]) {

  // HEAD
  
  return true;
}

///////////////////////////////////////////
//
// PURPOSE: controls the thrusters in the FEMTA subsystem
//
// ARGUMENTS: @ femta - pointer to femta
//            @ thr - thruster type
//            @ F - thrust value (uN)
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool thrusterControl(FEMTAType * femta, ThrusterType thr, double F) {

  bool result = true;
  
  //.. Forward PPX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_PPX_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_PPX_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PPX_FWD]));
    printf("\nvolt from thrust: %lf\n",voltFromThrust(F, femta -> dac_cal[THRUSTER_PPX_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft PPX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_PPX_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_PPX_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PPX_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward PPY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_PPY_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_PPY_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PPY_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft PPY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_PPY_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_PPY_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PPY_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }
  
  //.. Forward PNX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_PNX_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_PNX_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PNX_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft PNX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_PNX_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_PNX_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PNX_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward PNY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_PNY_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_PNY_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PNY_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft PNY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_PNY_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_PNY_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_PNY_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward NNX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_NNX_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_NNX_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NNX_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft NNX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_NNX_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_NNX_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NNX_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward NNY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_NNY_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_NNY_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NNY_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft NNY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_NNY_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_NNY_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NNY_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward NPX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_NPX_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_NPX_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NPX_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft NPX FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_NPX_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_NPX_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NPX_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  //.. Forward NPY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_FWD || thr == THRUSTER_NPY_FWD) {

    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    
    setChannelLTC2620(femta -> dac_fwd, 
                      femta -> dac_map[THRUSTER_NPY_FWD], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NPY_FWD]));

    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. Aft NPY FEMTA thruster
  if (thr == THRUSTER_ALL || thr == THRUSTER_AFT || thr == THRUSTER_NPY_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    
    setChannelLTC2620(femta -> dac_aft, 
                      femta -> dac_map[THRUSTER_NPY_AFT], 
                      voltFromThrust(F, femta -> dac_cal[THRUSTER_NPY_AFT]));

    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }

  return result;  
}

///////////////////////////////////////////
//
// PURPOSE: computes the dac voltage from a requested thrust
//
// ARGUMENTS: @ F - thrust
//            @ cal - calibration calibration coefficients
//
// RETURN: dac voltage
//
///////////////////////////////////////////
  
double voltFromThrust(double F, double cal[2]) {

  return (F - cal[1]) / cal[0];
}

///////////////////////////////////////////
//
// PURPOSE: computes the power from a measured adc voltage
//
// ARGUMENTS: @ V - voltage
//            @ cal - calibration calibration coefficients
//
// RETURN: power (mW)
//
///////////////////////////////////////////
  
double powerFromVolt(double V, double cal[2]) {

  return (V * cal[0] + cal[1]) * 1000;
}

///////////////////////////////////////////
//
// PURPOSE: controls valves in the FEMTA subsystem
//
// ARGUMENTS: @ femta - pointer to femta
//            @ valve - valve type
//            @ state - valve state
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool valveControl(FEMTAType * femta, ValveType valve, ValveStateType state) {

  bool result = true;
  
  //.. Foward tank iso
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_TANK_FWD) {

    if (!actuateNCValve(femta -> gpio_fwd, MAX7300_TANK_ISO_OPEN, state)) { result = false; }  
  }

  //.. Aft tank iso
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_TANK_AFT) {

    if (!actuateNCValve(femta -> gpio_aft, MAX7300_TANK_ISO_OPEN, state)) { result = false; }  
  }

  //.. Forward fill valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_FILL_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_TANK_FILL_BYPASS, MAX7300_TANK_FILL_OPEN, state)) { result = false; }
  }

  //.. Aft fill valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_FILL_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_TANK_FILL_BYPASS, MAX7300_TANK_FILL_OPEN, state)) { result = false; }
  }

  //.. Forward PPX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_PPX_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_PPX_CLOSE, MAX7300_FEMTA_PPX_OPEN, state)) { result = false; }
  }

  //.. Aft PPX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_PPX_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_PPX_CLOSE, MAX7300_FEMTA_PPX_OPEN, state)) { result = false; }
  }

  //.. Forward PPY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_PPY_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_PPY_CLOSE, MAX7300_FEMTA_PPY_OPEN, state)) { result = false; }
  }

  //.. Aft PPY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_PPY_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_PPY_CLOSE, MAX7300_FEMTA_PPY_OPEN, state)) { result = false; }
  }
  
  //.. Forward PNX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_PNX_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_PNX_CLOSE, MAX7300_FEMTA_PNX_OPEN, state)) { result = false; }
  }

  //.. Aft PNX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_PNX_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_PNX_CLOSE, MAX7300_FEMTA_PNX_OPEN, state)) { result = false; }
  }

  //.. Forward PNY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_PNY_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_PNY_CLOSE, MAX7300_FEMTA_PNY_OPEN, state)) { result = false; }
  }

  //.. Aft PNY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_PNY_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_PNY_CLOSE, MAX7300_FEMTA_PNY_OPEN, state)) { result = false; }
  }

  //.. Forward NNX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_NNX_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_NNX_CLOSE, MAX7300_FEMTA_NNX_OPEN, state)) { result = false; }
  }

  //.. Aft NNX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_NNX_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_NNX_CLOSE, MAX7300_FEMTA_NNX_OPEN, state)) { result = false; }
  }

  //.. Forward NNY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_NNY_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_NNY_CLOSE, MAX7300_FEMTA_NNY_OPEN, state)) { result = false; }
  }

  //.. Aft NNY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_NNY_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_NNY_CLOSE, MAX7300_FEMTA_NNY_OPEN, state)) { result = false; }
  }

  //.. Forward NPX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_NPX_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_NPX_CLOSE, MAX7300_FEMTA_NPX_OPEN, state)) { result = false; }
  }

  //.. Aft NPX FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_NPX_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_NPX_CLOSE, MAX7300_FEMTA_NPX_OPEN, state)) { result = false; }
  }

  //.. Forward NPY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_FWD || valve == VALVE_NPY_FWD) {

    if (!actuateLatchingValve(femta -> gpio_fwd, MAX7300_FEMTA_NPY_CLOSE, MAX7300_FEMTA_NPY_OPEN, state)) { result = false; }
  }

  //.. Aft NPY FEMTA iso valve
  if (valve == VALVE_ALL || valve == VALVE_AFT || valve == VALVE_NPY_AFT) {

    if (!actuateLatchingValve(femta -> gpio_aft, MAX7300_FEMTA_NPY_CLOSE, MAX7300_FEMTA_NPY_OPEN, state)) { result = false; }
  }

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: actuates a latching valve
//
// ARGUMENTS: @ gpio - pointer to MAX7300
//            @ openpin - gpio pin that the valve open terminal is attached to
//            @ closepin - gpio pin that the valve close terminal is attached to
//            @ state
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool actuateLatchingValve(MAX7300Type * gpio, uint8_t openpin, uint8_t closepin, ValveStateType state) {

  pthread_mutex_lock(&(gpio -> mutex));

  bool result = true;

  uint8_t pin = closepin;
  if (state == VALVE_OPEN) { pin = openpin; }

  if (!setPinMAX7300(gpio, pin, MAX7300_PIN_HIGH)) { result = false; }
  usleep(VALVE_DELAY);
  if (!setPinMAX7300(gpio, pin, MAX7300_PIN_LOW))  { result = false; }
  
  pthread_mutex_unlock(&(gpio -> mutex));

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: actuates a NC valve
//
// ARGUMENTS: @ gpio - pointer to MAX7300
//            @ pin - gpio pin that the valve is attached to
//            @ state - valve state
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool actuateNCValve(MAX7300Type * gpio, uint8_t pin, ValveStateType state) {

  pthread_mutex_lock(&(gpio -> mutex));

  uint8_t level = MAX7300_PIN_LOW;
  if (state == VALVE_OPEN) { level = MAX7300_PIN_HIGH; }

  bool result = setPinMAX7300(gpio, pin, level);

  pthread_mutex_unlock(&(gpio -> mutex));

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: command function for enabling / disabling the heater circuits
//
// ARGUMENTS: @ femta - pointer to femta
//            @ heater - heater type
//            @ state - heater state type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool heaterControl(FEMTAType * femta, HeaterType heater, HeaterStateType state) {

  bool result = true;
  
  //.. Forward tank heater
  if (heater == HEATER_ALL || heater == HEATER_FWD || heater == HEATER_TANK_FWD) {

    if (!toggleHeater(femta -> gpio_fwd,  MAX7300_TANK_HEATER, state)) { result = false; }
  }

  //.. Forward FEMTA heater
  if (heater == HEATER_ALL || heater == HEATER_FWD || heater == HEATER_FEMTA_FWD) {
    
    if (!toggleHeater(femta -> gpio_fwd,  MAX7300_FEMTA_HEATER, state)) { result = false; }
  }

  //.. Aft tank heater
  if (heater == HEATER_ALL || heater == HEATER_AFT || heater == HEATER_TANK_AFT) {

    if (!toggleHeater(femta -> gpio_aft,  MAX7300_TANK_HEATER, state)) { result = false; }
  }

  //.. Aft FEMTA heater
  if (heater == HEATER_ALL || heater == HEATER_AFT || heater == HEATER_FEMTA_AFT) {

    if (!toggleHeater(femta -> gpio_aft,  MAX7300_FEMTA_HEATER, state)) { result = false; }
  }
  
  return result;
}

///////////////////////////////////////////
//
// PURPOSE: command function for enabling / disabling the heater circuits
//
// ARGUMENTS: @ gpio - pointer to max7300
//            @ pin - heater gpio pin
//            @ state - heater state (enabled / disabled)
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool toggleHeater(MAX7300Type * gpio, uint8_t pin, HeaterStateType state) {

  pthread_mutex_lock(&(gpio -> mutex));
  
  uint8_t level = MAX7300_PIN_HIGH;
  if (state == HEATER_ENABLE) { level = MAX7300_PIN_LOW; }

  bool result = setPinMAX7300(gpio, pin, level);

  pthread_mutex_unlock(&(gpio -> mutex));

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: computes the thermistor temp from a measured adc voltage
//
// ARGUMENTS: @ V - voltage
//            @ cal - calibration calibration coefficients
//
// RETURN: temp (C)
//
///////////////////////////////////////////
  
double tempFromVolt(double V, double cal[2]) {

  return 1 / (1 / 25 + (1 / cal[2]) * log((V / THERMISTOR_CURRENT) / cal[1]));
}

///////////////////////////////////////////
//
// PURPOSE: resets gpio(s)
//
// ARGUMENTS: @ femta - pointer to femta
//            @ gpio - gpio type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetGPIO(FEMTAType * femta, GPIOType gpio) {
  
  bool result = true;

  //.. forward GPIO
  if (gpio == GPIO_ALL || gpio == GPIO_FWD) {

    pthread_mutex_lock(&(femta -> gpio_fwd -> mutex));
    if (!resetMAX7300(femta -> gpio_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> gpio_fwd -> mutex));
  }

  //.. aft GPIO
  if (gpio == GPIO_ALL || gpio == GPIO_AFT) {

    pthread_mutex_lock(&(femta -> gpio_aft -> mutex));
    if (!resetMAX7300(femta -> gpio_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> gpio_aft -> mutex));
  }
  
  return result;
}

///////////////////////////////////////////
//
// PURPOSE: resets dpt(s)
//
// ARGUMENTS: @ femta - pointer to femta
//            @ dpt - dpt type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetDPT(FEMTAType * femta, DPTType dpt) {

  bool result = true;

  //.. Forward HFE 1
  if (dpt == DPT_ALL || dpt == DPT_FWD || dpt == DPT_HFE_1_FWD) {

    pthread_mutex_lock(&(femta -> hfe_pt_1_fwd -> mutex));
    if (!resetMS5837(femta -> hfe_pt_1_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> hfe_pt_1_fwd -> mutex));
  }
  
  //.. Forward HFE 2
  if (dpt == DPT_ALL || dpt == DPT_FWD || dpt == DPT_HFE_2_FWD) {

    pthread_mutex_lock(&(femta -> hfe_pt_2_fwd -> mutex));
    if (!resetMS5837(femta -> hfe_pt_2_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> hfe_pt_2_fwd -> mutex));
  }
  
  //.. Forward UPW fill
  if (dpt == DPT_ALL || dpt == DPT_FWD || dpt == DPT_FILL_FWD) {

    pthread_mutex_lock(&(femta -> upw_pt_fill_fwd -> mutex));
    if (!resetMS5837(femta -> upw_pt_fill_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> upw_pt_fill_fwd -> mutex));
  }
  
  //.. Forward UPW tank
  if (dpt == DPT_ALL || dpt == DPT_FWD || dpt == DPT_TANK_FWD) {

    pthread_mutex_lock(&(femta -> upw_pt_tank_fwd -> mutex));
    if (!resetMS5837(femta -> upw_pt_tank_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> upw_pt_tank_fwd -> mutex));
  }

  //.. Aft HFE 1
  if (dpt == DPT_ALL || dpt == DPT_AFT || dpt == DPT_HFE_1_AFT) {

    pthread_mutex_lock(&(femta -> hfe_pt_1_aft -> mutex));
    if (!resetMS5837(femta -> hfe_pt_1_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> hfe_pt_1_aft -> mutex));
  }
  
  //.. Aft HFE 2
  if (dpt == DPT_ALL || dpt == DPT_AFT || dpt == DPT_HFE_2_AFT) {

    pthread_mutex_lock(&(femta -> hfe_pt_2_aft -> mutex));
    if (!resetMS5837(femta -> hfe_pt_2_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> hfe_pt_2_aft -> mutex));
  }
  
  //.. Aft UPW fill
  if (dpt == DPT_ALL || dpt == DPT_AFT || dpt == DPT_FILL_AFT) {

    pthread_mutex_lock(&(femta -> upw_pt_fill_aft -> mutex));
    if (!resetMS5837(femta -> upw_pt_fill_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> upw_pt_fill_aft -> mutex));
  }
  
  //.. Aft UPW tank
  if (dpt == DPT_ALL || dpt == DPT_AFT || dpt == DPT_TANK_AFT) {

    pthread_mutex_lock(&(femta -> upw_pt_tank_aft -> mutex));
    if (!resetMS5837(femta -> upw_pt_tank_aft)) { result = false; }
    pthread_mutex_lock(&(femta -> upw_pt_tank_aft -> mutex));
  }
  
  return result;
}

///////////////////////////////////////////
//
// PURPOSE: resets flow sensor(s)
//
// ARGUMENTS: @ femta - pointer to femta
//            @ flow - thruster type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetFlow(FEMTAType * femta, ThrusterType flow) {

  bool result = true;

  //.. Forward PPX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_PPX_FWD) {

    pthread_mutex_lock(&(femta -> flow_ppx_fwd -> mutex));
    resetLG160431(femta -> flow_ppx_fwd);
    pthread_mutex_unlock(&(femta -> flow_ppx_fwd -> mutex));
  }

  //.. Aft PPX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_PPX_AFT) {

    pthread_mutex_lock(&(femta -> flow_ppx_aft -> mutex));
    resetLG160431(femta -> flow_ppx_aft);
    pthread_mutex_unlock(&(femta -> flow_ppx_aft -> mutex));
  }

  //.. Forward PPY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_PPY_FWD) {

    pthread_mutex_lock(&(femta -> flow_ppy_fwd -> mutex));
    resetLG160431(femta -> flow_ppy_fwd);
    pthread_mutex_unlock(&(femta -> flow_ppy_fwd -> mutex));
  }

  //.. Aft PPY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_PPY_AFT) {

    pthread_mutex_lock(&(femta -> flow_ppy_aft -> mutex));
    resetLG160431(femta -> flow_ppy_aft);
    pthread_mutex_unlock(&(femta -> flow_ppy_aft -> mutex));
  }
  
  //.. Forward PNX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_PNX_FWD) {

    pthread_mutex_lock(&(femta -> flow_pnx_fwd -> mutex));
    resetLG160431(femta -> flow_pnx_fwd);
    pthread_mutex_unlock(&(femta -> flow_pnx_fwd -> mutex));
  }

  //.. Aft PNX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_PNX_AFT) {

    pthread_mutex_lock(&(femta -> flow_pnx_aft -> mutex));
    resetLG160431(femta -> flow_pnx_aft);
    pthread_mutex_unlock(&(femta -> flow_pnx_aft -> mutex));
  }

  //.. Forward PNY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_PNY_FWD) {

    pthread_mutex_lock(&(femta -> flow_pny_fwd -> mutex));
    resetLG160431(femta -> flow_pny_fwd);
    pthread_mutex_unlock(&(femta -> flow_pny_fwd -> mutex));
  }

  //.. Aft PNY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_PNY_AFT) {

    pthread_mutex_lock(&(femta -> flow_pny_aft -> mutex));
    resetLG160431(femta -> flow_pny_aft);
    pthread_mutex_unlock(&(femta -> flow_pny_aft -> mutex));
  }

  //.. Forward NNX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_NNX_FWD) {

    pthread_mutex_lock(&(femta -> flow_nnx_fwd -> mutex));
    resetLG160431(femta -> flow_nnx_fwd);
    pthread_mutex_unlock(&(femta -> flow_nnx_fwd -> mutex));
  }

  //.. Aft NNX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_NNX_AFT) {

    pthread_mutex_lock(&(femta -> flow_nnx_aft -> mutex));
    resetLG160431(femta -> flow_nnx_aft);
    pthread_mutex_unlock(&(femta -> flow_nnx_aft -> mutex));
  }

  //.. Forward NNY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_NNY_FWD) {

    pthread_mutex_lock(&(femta -> flow_nny_fwd -> mutex));
    resetLG160431(femta -> flow_nny_fwd);
    pthread_mutex_unlock(&(femta -> flow_nny_fwd -> mutex));
  }

  //.. Aft NNY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_NNY_AFT) {

    pthread_mutex_lock(&(femta -> flow_nny_aft -> mutex));
    resetLG160431(femta -> flow_nny_aft);
    pthread_mutex_unlock(&(femta -> flow_nny_aft -> mutex));
  }

  //.. Forward NPX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_NPX_FWD) {

    pthread_mutex_lock(&(femta -> flow_npx_fwd -> mutex));
    resetLG160431(femta -> flow_npx_fwd);
    pthread_mutex_unlock(&(femta -> flow_npx_fwd -> mutex));
  }

  //.. Aft NPX FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_NPX_AFT) {

    pthread_mutex_lock(&(femta -> flow_npx_aft -> mutex));
    resetLG160431(femta -> flow_npx_aft);
    pthread_mutex_unlock(&(femta -> flow_npx_aft -> mutex));
  }

  //.. Forward NPY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_FWD || flow == THRUSTER_NPY_FWD) {

    pthread_mutex_lock(&(femta -> flow_npy_fwd -> mutex));
    resetLG160431(femta -> flow_npy_fwd);
    pthread_mutex_unlock(&(femta -> flow_npy_fwd -> mutex));
  }

  //.. Aft NPY FEMTA flow sensor
  if (flow == THRUSTER_ALL || flow == THRUSTER_AFT || flow == THRUSTER_NPY_AFT) {

    pthread_mutex_lock(&(femta -> flow_npy_aft -> mutex));
    resetLG160431(femta -> flow_npy_aft);
    pthread_mutex_unlock(&(femta -> flow_npy_aft -> mutex));
  }

  return result;
}

///////////////////////////////////////////
//
// PURPOSE: resets adc(s)
//
// ARGUMENTS: @ femta - pointer to femta
//            @ adc - adc type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetADC(FEMTAType * femta, ADCType adc) {

  bool result = true;

  //.. forward ADC
  if (adc == ADC_ALL || adc == ADC_FWD) {

    pthread_mutex_lock(&(femta -> adc_fwd -> mutex));
    if (!resetAD7490(femta -> adc_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> adc_fwd -> mutex));
  }

  //.. aft ADC
  if (adc == ADC_ALL || adc == ADC_AFT) {

    pthread_mutex_lock(&(femta -> adc_aft -> mutex));
    if (!resetAD7490(femta -> adc_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> adc_aft -> mutex));
  }
  
  return result;
}

///////////////////////////////////////////
//
// PURPOSE: resets dac(s)
//
// ARGUMENTS: @ femta - pointer to femta
//            @ dac - dac type
//
// RETURN: fail / success flag
//
///////////////////////////////////////////

bool resetDAC(FEMTAType * femta, DACType dac) {
  
  bool result = true;

  //.. forward DAC
  if (dac == DAC_ALL || dac == DAC_FWD) {
    
    pthread_mutex_lock(&(femta -> dac_fwd -> mutex));
    if (!resetLTC2620(femta -> dac_fwd)) { result = false; }
    pthread_mutex_unlock(&(femta -> dac_fwd -> mutex));
  }

  //.. aft DAC
  if (dac == DAC_ALL || dac == DAC_AFT) {

    pthread_mutex_lock(&(femta -> dac_aft -> mutex));
    if (!resetLTC2620(femta -> dac_aft)) { result = false; }
    pthread_mutex_unlock(&(femta -> dac_aft -> mutex));
  }
  
  return result;
}