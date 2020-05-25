#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


extern uint32_t dac_max;
extern uint32_t dac_max_div_3;
extern uint32_t dac_max_div_3_times_2;

void osc_calc();

extern uint32_t OSC_pulse_width_in_cycles_50;
extern uint32_t OSC_pulse_width_in_cycles_25;
extern uint32_t OSC_pulse_width_in_cycles_12;
extern uint32_t OSC_sample_counter;
extern uint32_t OSC_samples_per_cycle;
extern uint32_t OSC_osc_out;
extern uint32_t old_OSC_osc_out;
extern int debug_counter;
extern uint8_t OSC_wave_type;
extern float OSC_frequency;
extern uint8_t OSC_frequency_range;
