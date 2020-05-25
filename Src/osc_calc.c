#include "osc_calc.h"

void osc_calc() {
  switch (OSC_wave_type) {

    //STEPPED TRIANGLE
    //-----------------------//
    //-------TRIANGLE--------//
    //-----------------------//
    case 0:

    if(OSC_sample_counter < OSC_pulse_width_in_cycles_25){
      OSC_osc_out = (dac_max * OSC_sample_counter) / ((OSC_samples_per_cycle/2)) + dac_max/2;
    }

    else if(OSC_sample_counter < (OSC_pulse_width_in_cycles_25 + OSC_pulse_width_in_cycles_50)){
      OSC_osc_out = dac_max - (((OSC_sample_counter - (OSC_samples_per_cycle/4)) * 2 * dac_max) / OSC_samples_per_cycle);
    }

    else{
      OSC_osc_out = (dac_max * (OSC_sample_counter - (3*OSC_samples_per_cycle/4) + 1)) / ((OSC_samples_per_cycle/2));
    }
    break;

    //-----------------------//
    //-------RISING SAW------//
    //-----------------------//
    case 2:
    OSC_osc_out = (dac_max * OSC_sample_counter) / OSC_samples_per_cycle;
    break;

    //----------------------//
    //-----FALLING SAW------//
    //----------------------//
    case 3:
    OSC_osc_out = dac_max - (dac_max * OSC_sample_counter) / OSC_samples_per_cycle;
    break;

    //---------------------//
    //-------PULSE 50------//
    //---------------------//
    case 4:
    if (OSC_sample_counter < OSC_pulse_width_in_cycles_50) {
      OSC_osc_out = dac_max;
    }
    else {
      OSC_osc_out = 0;
    }
    break;

  }

OSC_sample_counter++;

if (OSC_sample_counter >= OSC_samples_per_cycle) {
  OSC_sample_counter = 0;
}

if (OSC_osc_out < 0) {
  OSC_osc_out = 0;
}

if (OSC_osc_out > dac_max) {
  OSC_osc_out = dac_max;
}
}
