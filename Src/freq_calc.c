#include "freq_calc.h"

void freq_calc() {
  //suspect line
  OSC_samples_per_cycle = sampling_period_in_hz / OSC_frequency;

  //safety, if the sample couter is already bigger than the max amout of samples
  if (OSC_sample_counter > OSC_samples_per_cycle) {
    OSC_sample_counter = 0;
  }

  OSC_pulse_width_in_cycles_50 = OSC_samples_per_cycle >> 1 ;
  OSC_pulse_width_in_cycles_25 = OSC_pulse_width_in_cycles_50 >> 1;
  OSC_pulse_width_in_cycles_12 = OSC_pulse_width_in_cycles_25 >> 1;
}
