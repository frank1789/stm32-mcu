# STMicroelectronics STM32 MCU evaluation

![Clock](./doc/NUCLEO-L476RG-Clock.jpg)

Clock application with STM32L476RG

## IDE

- [TrueSTUDIO](https://atollic.com/truestudio/)
- [STM32 CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)

## Evaluation

### [STM32L476 Nucleo-64](http://www.st.com/en/evaluation-tools/nucleo-l476rg.html) board

#### Applications

- [HelloWorld](./STM32L476-Nucleo-64/HelloWorld)
- [GPIO_Interrupt](./STM32L476-Nucleo-64/GPIO_Interrupt)
- [Clock](./STM32L476-Nucleo-64/Clock/README.md)
- [CAN](./STM32L476-Nucleo-64/CAN/README.md)
- [MEMSMIC(MEMS mic expansion board)](./STM32L476-Nucleo-64/MEMSMIC/README.md)
- [ADC with DMA](./STM32L476-Nucleo-64/ADC/README.md)
- [DAC with triangular wave and sine wave](./STM32L476-Nucleo-64/DAC/README.md)
- [Mic->ADC->DAC pipeline](./STM32L476-Nucleo-64/Mic_ADC_DAC/README.md)
- [Sound Effector](./STM32L476-Nucleo-64/Sound_Effector)

### [STM32F4 Discovery](http://www.st.com/en/evaluation-tools/stm32f4discovery.html) board

#### Applications

- [BlueSwitch](./STM32F4-Discovery/BlueSwitch)
- [HelloWorld](./STM32F4-Discovery/HelloWorld)
- [LED_blinking](./STM32F4-Discovery/LED_blinking)
- [PWM-output](./STM32F4-Discovery/PWM-output)

#### printf issue

I managed to support printf on USART2.

![UART](./doc/STM32F4_Discovery_UART.jpg)

Physical configuration:

```
STM32F407
               +------------+
            X 5V            |
GND     ----- GND  FTDI     |
PA3(RX) ----- TX  USB-UART  ===== USB ======> PC
PA2(TX) ----- RX  converter |
               +------------+
```

Include the following snippet in main.c to support printf:

```
int _write(int file, char *pbuf, int len)
{
  HAL_UART_Transmit(&huart2, (uint8_t *)pbuf, len, 1000);
  return len;
}
```

#### PWM test

PWM output (100Hz, 50% duty) to PA8:

![waveform](./doc/PWM_waveform.jpg)

## Tips

- [CMSIS DSP RFFT pitfalls](./tips/CMSIS_DSP_RFFT.md)
- [Enabling DSP on STM32](./tips/ENABLE_DSP_AND_PRINTF.md)
- [PCM data resolution on STM32L4 DFSDM](./tips/RESOLUTION.md)

## References

### STM32L476 Nucleo-64

- [Schematics](http://www.st.com/resource/en/schematic_pack/nucleo_64pins_sch.zip)
- [Datasheet](http://www.st.com/resource/en/datasheet/stm32l476je.pdf)
- [STM32CubeL4](https://my.st.com/content/my_st_com/en/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32cube-mcu-packages/stm32cubel4.license%3d1524847579867.html)

### STM32F4 Discovery board

- [Schematics](http://www.st.com/resource/en/schematic_pack/stm32f4discovery_sch.zip)
- [Datasheet](http://www.st.com/resource/en/datasheet/dm00037051.pdf)

## Other interests

- [STM32L0 Discovery Kit LPWA](http://www.st.com/en/evaluation-tools/b-l072z-lrwan1.html)
- [AWS FreeRTOS](https://aws.amazon.com/freertos/getting-started/)
- [ESP-IDF](https://esp-idf.readthedocs.io/en/v2.0/index.html)
