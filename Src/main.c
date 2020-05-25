#include "main.h"
#include "tim.h"
#include "gpio.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "variables.h"
#include "freq_calc.h"
#include "osc_calc.h"

void SystemClock_Config(void);
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM1_Init();

  int delay = 5625/4;
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  TIM1->PSC = 0;
  TIM1->ARR = delay;
  TIM1->CCR1 = delay >> 1;

  max_freq_ARR = CPU_frequency / BBD_max_freq;
  min_freq_ARR = CPU_frequency / BBD_min_freq;

  OSC_pulse_width_in_cycles_50 = 0;
  OSC_pulse_width_in_cycles_25 = 0 ;
  OSC_pulse_width_in_cycles_12 = 0;
  OSC_sample_counter = 0;
  OSC_samples_per_cycle = 0;
  OSC_osc_out = 0;
  OSC_wave_type = 0;
  OSC_frequency = 1;

  freq_calc();

  //Core cycles counter
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CYCCNT = 0;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;


  while (1)
  {

    if ((DWT->CYCCNT - UI_timer) > 84000) {
      UI_timer = DWT->CYCCNT;

      LD2_GPIO_Port->ODR ^= LD2_Pin;

      //And set the new timer frequencies
      //PWM alwayas 50%
      TIM1->ARR = overflow_R;
      unsigned int ccr1 = (unsigned int)(overflow_R >> 1) + 1;
      TIM1->CCR1 =  ccr1;
      //TIM1->CCR1 = (999*OSC_osc_out)/dac_max;

      TIM3->ARR = overflow_L;
      TIM3->CCR1 =  (unsigned int)(overflow_L >> 1);

      //Calculating the LFO value
      osc_calc();
      overflow_R = map(OSC_osc_out, 0, dac_max, max_freq_ARR, min_freq_ARR);

      /*
      out_debug[debug_counter] = ccr1;
      debug_counter++;

      if(debug_counter == 4000){
      for(int i=0; i < sizeof(out_debug)/2; i++){
    }
    debug_counter = 0;
  }
  */

}
}
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /**Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Error_Handler(void)
{

}

#ifdef  USE_FULL_ASSERT
/
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif 
