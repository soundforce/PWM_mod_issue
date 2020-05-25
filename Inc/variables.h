//--------------------//
//----For testing-----//
//--------------------//
bool debug_pots = 1;
bool debug_adc = 1;
bool debug_switches = 1;

uint32_t cycle_ticks = 0;

uint32_t ticks_before;
uint32_t ticks_after;
uint32_t ticks_to_us;
uint32_t freq_sampl;

bool reload = 0;

//-----------------------------//
//----LFO and Timer values-----//
//-----------------------------//
int32_t LFO_value = 0;
uint32_t time_since = 0;
int8_t direction = 1;

bool resample = 0;

//uint32_t BBD_min_freq = 28015;
//uint32_t BBD_max_freq = 83000;

int32_t BBD_min_freq = 35775;
int32_t BBD_max_freq = 80000;

uint32_t sampling_period_in_hz = 1000;
uint32_t CPU_frequency = 72000000;

int max_freq_ARR = 0;
int min_freq_ARR = 0;

int32_t overflow_L = 866;
int32_t overflow_R = 866;

bool new_frequency = 1;

bool display = 0;

bool flip_flop = 0;

// 0 = off, 1 = I, 2 = II, 3 = I+II, 4 = MAN, 5 = EXT
uint8_t mode = 1;

uint32_t dac_max = 4095;
uint32_t dac_max_div_3 = 0;
uint32_t dac_max_div_3_times_2 = 0;

//---------------//
//--OSCILLATOR--//
//---------------//
uint32_t OSC_pulse_width_in_cycles_50;
uint32_t OSC_pulse_width_in_cycles_25;
uint32_t OSC_pulse_width_in_cycles_12;
uint32_t OSC_sample_counter;
uint32_t OSC_samples_per_cycle;
uint32_t OSC_osc_out;
uint32_t old_OSC_osc_out;
uint16_t out_debug[4000];
int debug_counter = 0;
uint8_t OSC_wave_type;
float OSC_frequency;
uint8_t OSC_frequency_range;

//---------------//
//--Analog inputs--//
//---------------//
uint32_t adc_buffer[3] = {0,0,0};
int32_t cv_reading[3] = {0, 0, 0};
int32_t cv_reading_memory[3] = {0, 0, 0};

int32_t cv_average[3] = {0, 0, 0};
int32_t previous_cv_reading[3] = {0, 0, 0};
int adc_buffer_counter = 0;
bool new_CV_reading = 0;
bool new_CV_values = 0;
uint32_t adc_threshold = 10;
bool new_CV_values_number[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint16_t pots_index [4] = {
  2, 1, 0, 3,
};
uint16_t mux_counter = 0;
uint16_t round_counter = 0;
int bit_reduction = 4;
bool new_pots_reading = 0;
int32_t pot_reading[4] = {0,0,0,0};
int32_t pot_reading_reduced[4] = {0,0,0,0};
int32_t pot_summing[4] = {0,0,0,0};
int32_t old_pot_reading[4] = {100,100,100,100};
int32_t pot_reading_modulated[4] = {0,0,0,0};
int32_t old_pot_reading_modulated[4] = {0,0,0,0};
uint32_t pots_ticks = 0;
bool new_pots_values = 0;
int16_t pots_threshold = 2;

//------------------//
//--Digital inputs--//
//------------------//
bool new_switch_reading = 0;
bool switch_reading[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool PREVIOUS_switch_reading[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int32_t switch_debounce[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool switch_status[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool switch_readings = 0;
uint16_t switch_index[8] = {2, 1, 0, 3, 5, 4, 7, 6};
int32_t UI_timer = 0;

//-----------------//
//------LEDs-------//
//-----------------//
bool led_status[13]={
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0
};

bool led_index[13]={
  1,2,3,4,
  5,15,14,13,
  12,11,10,9,
  8
};
