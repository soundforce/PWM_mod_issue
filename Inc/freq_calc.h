#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


void freq_calc();

extern float OSC_frequency;
extern uint32_t CPU_frequency;
extern uint32_t OSC_samples_per_cycle;
extern uint32_t OSC_pulse_width_in_cycles_50;
extern uint32_t OSC_pulse_width_in_cycles_25;
extern uint32_t OSC_pulse_width_in_cycles_12;
extern uint32_t OSC_sample_counter;
extern uint32_t sampling_period_in_hz;
