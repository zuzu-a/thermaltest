#ifndef FEMTA_H_   
#define FEMTA_H_

// DEFINITIONS

#define NUM_THR            16
#define VALVE_DELAY        15000
#define THERMISTOR_CURRENT 100E-6

// ENUMS

typedef enum {

  THRUSTER_ALL     = 16,
  THRUSTER_FWD     = 17,
  THRUSTER_AFT     = 18,
  THRUSTER_PPX_FWD = 0,
  THRUSTER_PPY_FWD = 1,
  THRUSTER_PNX_FWD = 2,
  THRUSTER_PNY_FWD = 3,
  THRUSTER_NNX_FWD = 4,
  THRUSTER_NNY_FWD = 5,
  THRUSTER_NPX_FWD = 6,
  THRUSTER_NPY_FWD = 7,
  THRUSTER_PPX_AFT = 8,
  THRUSTER_PPY_AFT = 9,
  THRUSTER_PNX_AFT = 10,
  THRUSTER_PNY_AFT = 11,
  THRUSTER_NNX_AFT = 12,
  THRUSTER_NNY_AFT = 13,
  THRUSTER_NPX_AFT = 14,
  THRUSTER_NPY_AFT = 15
  
} ThrusterType;

typedef enum {

  VALVE_ALL      = 0,
  VALVE_FWD      = 1,
  VALVE_AFT      = 2,
  VALVE_TANK_FWD = 3,
  VALVE_FILL_FWD = 4,
  VALVE_PPX_FWD  = 5,
  VALVE_PPY_FWD  = 6,
  VALVE_PNX_FWD  = 7,
  VALVE_PNY_FWD  = 8,
  VALVE_NNX_FWD  = 9,
  VALVE_NNY_FWD  = 10,
  VALVE_NPX_FWD  = 11,
  VALVE_NPY_FWD  = 12,
  VALVE_TANK_AFT = 13,
  VALVE_FILL_AFT = 14,
  VALVE_PPX_AFT  = 15,
  VALVE_PPY_AFT  = 16,
  VALVE_PNX_AFT  = 17,
  VALVE_PNY_AFT  = 18,
  VALVE_NNX_AFT  = 19,
  VALVE_NNY_AFT  = 20,
  VALVE_NPX_AFT  = 21,
  VALVE_NPY_AFT  = 22

} ValveType;

typedef enum {

  VALVE_CLOSE = 0,
  VALVE_OPEN  = 1

} ValveStateType;

typedef enum {

  HEATER_ALL       = 0,
  HEATER_FWD       = 1,
  HEATER_AFT       = 2,
  HEATER_TANK_FWD  = 16,
  HEATER_FEMTA_FWD = 18,
  HEATER_TANK_AFT  = 20,
  HEATER_FEMTA_AFT = 22,

} HeaterType;

typedef enum {

  HEATER_DISABLE = 0,
  HEATER_ENABLE  = 1

} HeaterStateType;

typedef enum {

  GPIO_ALL = 0,
  GPIO_FWD = 1,
  GPIO_AFT = 2

} GPIOType;

typedef enum {

  DPT_ALL       = 0,
  DPT_FWD       = 1,
  DPT_AFT       = 2,
  DPT_HFE_1_FWD = 3,
  DPT_HFE_2_FWD = 4,
  DPT_TANK_FWD  = 5,
  DPT_FILL_FWD  = 6,
  DPT_HFE_1_AFT = 3,
  DPT_HFE_2_AFT = 4,
  DPT_TANK_AFT  = 5,
  DPT_FILL_AFT  = 6

} DPTType;

typedef enum {

  ADC_ALL = 0,
  ADC_FWD = 1,
  ADC_AFT = 2

} ADCType;

typedef enum {

  DAC_ALL = 0,
  DAC_FWD = 1,
  DAC_AFT = 2

} DACType;

// STRUCTURE TYPES

typedef struct FEMTAType FEMTAType;

// STRUCTURE DEFINTIONS

struct Subsystem {

  //.. mutex
  pthread_mutex_t mutex;

  //.. calibrations
  uint8_t dac_map[NUM_THR];
  double  dac_cal[NUM_THR][2];

  uint8_t adc_map[AD7490_NUM_CHAN*2];
  double  adc_cal[AD7490_NUM_CHAN*2][3];
  
  //.. DPT sensors
  MS5837Type * hfe_pt_1_fwd;
  MS5837Type * hfe_pt_2_fwd;
  MS5837Type * upw_pt_tank_fwd;
  MS5837Type * upw_pt_fill_fwd;
  MS5837Type * hfe_pt_1_aft;
  MS5837Type * hfe_pt_2_aft;
  MS5837Type * upw_pt_tank_aft;
  MS5837Type * upw_pt_fill_aft;

  //.. Flow sensors
  LG160431Type * flow_ppx_fwd;
  LG160431Type * flow_ppy_fwd;
  LG160431Type * flow_pnx_fwd;
  LG160431Type * flow_pny_fwd;
  LG160431Type * flow_nnx_fwd;
  LG160431Type * flow_nny_fwd;
  LG160431Type * flow_npx_fwd;
  LG160431Type * flow_npy_fwd;
  LG160431Type * flow_ppx_aft;
  LG160431Type * flow_ppy_aft;
  LG160431Type * flow_pnx_aft;
  LG160431Type * flow_pny_aft;
  LG160431Type * flow_nnx_aft;
  LG160431Type * flow_nny_aft;
  LG160431Type * flow_npx_aft;
  LG160431Type * flow_npy_aft;
  
  //.. GPIO devices
  MAX7300Type * gpio_fwd;
  MAX7300Type * gpio_aft;

  //.. ADC devices
  AD7490Type * adc_fwd;
  AD7490Type * adc_aft;
  
  //.. DAC devices
  LTC2620Type * dac_fwd;
  LTC2620Type * dac_aft;  
};

// FUNCTIONS

FEMTAType *          createFEMTA(void);
void                   freeFEMTA(FEMTAType *);
bool                   bootFEMTA(FEMTAType *);
bool               shutdownFEMTA(FEMTAType *);

bool               torqueControl(FEMTAType *, double[3]);
bool             thrusterControl(FEMTAType *, ThrusterType, double);
double            voltFromThrust(double, double[2]);
double           powerFromThrust(double, double[2]);

bool                valveControl(FEMTAType *, ValveType, ValveStateType);
bool        actuateLatchingValve(MAX7300Type *, uint8_t, uint8_t, ValveStateType);
bool              actuateNCValve(MAX7300Type *, uint8_t, ValveStateType);

bool               heaterControl(FEMTAType *, HeaterType, HeaterStateType);
bool                toggleHeater(MAX7300Type *, uint8_t, HeaterStateType);
double            tempFromThrust(double, double[2]);

bool                   resetGPIO(FEMTAType *, GPIOType);
bool                    resetDPT(FEMTAType *, DPTType);
bool                   resetFlow(FEMTAType *, ThrusterType);
bool                    resetADC(FEMTAType *, ADCType);
bool                    resetDAC(FEMTAType *, DACType);

#endif