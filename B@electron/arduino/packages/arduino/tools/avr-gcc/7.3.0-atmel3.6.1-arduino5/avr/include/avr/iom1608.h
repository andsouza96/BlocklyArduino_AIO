/*****************************************************************************
 *
 * Copyright (C) 2018 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************/


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom1608.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_ATMEGA1608_H_INCLUDED
#define _AVR_ATMEGA1608_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

#define GPIOR0  _SFR_MEM8(0x001C)  /* General Purpose IO Register 0 */
#define GPIOR1  _SFR_MEM8(0x001D)  /* General Purpose IO Register 1 */
#define GPIOR2  _SFR_MEM8(0x001E)  /* General Purpose IO Register 2 */
#define GPIOR3  _SFR_MEM8(0x001F)  /* General Purpose IO Register 3 */

/* Deprecated */
#define GPIO0  _SFR_MEM8(0x001C)  /* General Purpose IO Register 0 */
#define GPIO1  _SFR_MEM8(0x001D)  /* General Purpose IO Register 1 */
#define GPIO2  _SFR_MEM8(0x001E)  /* General Purpose IO Register 2 */
#define GPIO3  _SFR_MEM8(0x001F)  /* General Purpose IO Register 3 */

/* C Language Only */
#if !defined (__ASSEMBLER__)

#include <stdint.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;


#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname)   \
    __extension__ union \
    { \
        register16_t regname; \
        struct \
        { \
            register8_t regname ## L; \
            register8_t regname ## H; \
        }; \
    }

#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname)  \
    __extension__ union \
    { \
        register32_t regname; \
        struct \
        { \
            register8_t regname ## 0; \
            register8_t regname ## 1; \
            register8_t regname ## 2; \
            register8_t regname ## 3; \
        }; \
    }


/*
==========================================================================
IO Module Structures
==========================================================================
*/


/*
--------------------------------------------------------------------------
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_0x01;
    register8_t MUXCTRLA;  /* Mux Control A */
    register8_t reserved_0x03;
    register8_t DACREF;  /* Referance scale control */
    register8_t reserved_0x05;
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
} AC_t;

/* Hysteresis Mode select */
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_OFF_gc = (0x00<<1),  /* No hysteresis */
    AC_HYSMODE_10mV_gc = (0x01<<1),  /* 10mV hysteresis */
    AC_HYSMODE_25mV_gc = (0x02<<1),  /* 25mV hysteresis */
    AC_HYSMODE_50mV_gc = (0x03<<1),  /* 50mV hysteresis */
} AC_HYSMODE_t;

/* Interrupt Mode select */
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_BOTHEDGE_gc = (0x00<<4),  /* Any Edge */
    AC_INTMODE_NEGEDGE_gc = (0x02<<4),  /* Negative Edge */
    AC_INTMODE_POSEDGE_gc = (0x03<<4),  /* Positive Edge */
} AC_INTMODE_t;

/* Low Power Mode select */
typedef enum AC_LPMODE_enum
{
    AC_LPMODE_DIS_gc = (0x00<<3),  /* Low power mode disabled */
    AC_LPMODE_EN_gc = (0x01<<3),  /* Low power mode enabled */
} AC_LPMODE_t;

/* Negative Input MUX Selection select */
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_PIN0_gc = (0x00<<0),  /* Negative Pin 0 */
    AC_MUXNEG_PIN1_gc = (0x01<<0),  /* Negative Pin 1 */
    AC_MUXNEG_PIN2_gc = (0x02<<0),  /* Negative Pin 2 */
    AC_MUXNEG_DACREF_gc = (0x03<<0),  /* DAC Voltage Reference */
} AC_MUXNEG_t;

/* Positive Input MUX Selection select */
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_PIN0_gc = (0x00<<3),  /* Positive Pin 0 */
    AC_MUXPOS_PIN1_gc = (0x01<<3),  /* Positive Pin 1 */
    AC_MUXPOS_PIN2_gc = (0x02<<3),  /* Positive Pin 2 */
    AC_MUXPOS_PIN3_gc = (0x03<<3),  /* Positive Pin 3 */
} AC_MUXPOS_t;

/*
--------------------------------------------------------------------------
ADC - Analog to Digital Converter
--------------------------------------------------------------------------
*/

/* Analog to Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t SAMPCTRL;  /* Sample Control */
    register8_t MUXPOS;  /* Positive mux input */
    register8_t reserved_0x07;
    register8_t COMMAND;  /* Command */
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Data */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    _WORDREGISTER(RES);  /* ADC Accumulator Result */
    _WORDREGISTER(WINLT);  /* Window comparator low threshold */
    _WORDREGISTER(WINHT);  /* Window comparator high threshold */
    register8_t CALIB;  /* Calibration */
    register8_t reserved_0x17;
} ADC_t;

/* Automatic Sampling Delay Variation select */
typedef enum ADC_ASDV_enum
{
    ADC_ASDV_ASVOFF_gc = (0x00<<4),  /* The Automatic Sampling Delay Variation is disabled */
    ADC_ASDV_ASVON_gc = (0x01<<4),  /* The Automatic Sampling Delay Variation is enabled */
} ADC_ASDV_t;

/* Duty Cycle select */
typedef enum ADC_DUTYCYC_enum
{
    ADC_DUTYCYC_DUTY50_gc = (0x00<<0),  /* 50% Duty cycle */
    ADC_DUTYCYC_DUTY25_gc = (0x01<<0),  /* 25% Duty cycle */
} ADC_DUTYCYC_t;

/* Initial Delay Selection select */
typedef enum ADC_INITDLY_enum
{
    ADC_INITDLY_DLY0_gc = (0x00<<5),  /* Delay 0 CLK_ADC cycles */
    ADC_INITDLY_DLY16_gc = (0x01<<5),  /* Delay 16 CLK_ADC cycles */
    ADC_INITDLY_DLY32_gc = (0x02<<5),  /* Delay 32 CLK_ADC cycles */
    ADC_INITDLY_DLY64_gc = (0x03<<5),  /* Delay 64 CLK_ADC cycles */
    ADC_INITDLY_DLY128_gc = (0x04<<5),  /* Delay 128 CLK_ADC cycles */
    ADC_INITDLY_DLY256_gc = (0x05<<5),  /* Delay 256 CLK_ADC cycles */
} ADC_INITDLY_t;

/* Analog Channel Selection Bits select */
typedef enum ADC_MUXPOS_enum
{
    ADC_MUXPOS_AIN0_gc = (0x00<<0),  /* ADC input pin 0 */
    ADC_MUXPOS_AIN1_gc = (0x01<<0),  /* ADC input pin 1 */
    ADC_MUXPOS_DACREF_gc = (0x1C<<0),  /* AC DAC Reference */
    ADC_MUXPOS_TEMPSENSE_gc = (0x1E<<0),  /* Temperature sensor */
    ADC_MUXPOS_GND_gc = (0x1F<<0),  /* 0V (GND) */
    ADC_MUXPOS_AIN2_gc = (0x02<<0),  /* ADC input pin 2 */
    ADC_MUXPOS_AIN3_gc = (0x03<<0),  /* ADC input pin 3 */
    ADC_MUXPOS_AIN4_gc = (0x04<<0),  /* ADC input pin 4 */
    ADC_MUXPOS_AIN5_gc = (0x05<<0),  /* ADC input pin 5 */
    ADC_MUXPOS_AIN6_gc = (0x06<<0),  /* ADC input pin 6 */
    ADC_MUXPOS_AIN7_gc = (0x07<<0),  /* ADC input pin 7 */
    ADC_MUXPOS_AIN8_gc = (0x08<<0),  /* ADC input pin 8 */
    ADC_MUXPOS_AIN9_gc = (0x09<<0),  /* ADC input pin 9 */
    ADC_MUXPOS_AIN10_gc = (0x0A<<0),  /* ADC input pin 10 */
    ADC_MUXPOS_AIN11_gc = (0x0B<<0),  /* ADC input pin 11 */
    ADC_MUXPOS_AIN12_gc = (0x0C<<0),  /* ADC input pin 12 */
    ADC_MUXPOS_AIN13_gc = (0x0D<<0),  /* ADC input pin 13 */
    ADC_MUXPOS_AIN14_gc = (0x0E<<0),  /* ADC input pin 14 */
    ADC_MUXPOS_AIN15_gc = (0x0F<<0),  /* ADC input pin 15 */
} ADC_MUXPOS_t;

/* Clock Pre-scaler select */
typedef enum ADC_PRESC_enum
{
    ADC_PRESC_DIV2_gc = (0x00<<0),  /* CLK_PER divided by 2 */
    ADC_PRESC_DIV4_gc = (0x01<<0),  /* CLK_PER divided by 4 */
    ADC_PRESC_DIV8_gc = (0x02<<0),  /* CLK_PER divided by 8 */
    ADC_PRESC_DIV16_gc = (0x03<<0),  /* CLK_PER divided by 16 */
    ADC_PRESC_DIV32_gc = (0x04<<0),  /* CLK_PER divided by 32 */
    ADC_PRESC_DIV64_gc = (0x05<<0),  /* CLK_PER divided by 64 */
    ADC_PRESC_DIV128_gc = (0x06<<0),  /* CLK_PER divided by 128 */
    ADC_PRESC_DIV256_gc = (0x07<<0),  /* CLK_PER divided by 256 */
} ADC_PRESC_t;

/* Reference Selection select */
typedef enum ADC_REFSEL_enum
{
    ADC_REFSEL_INTREF_gc = (0x00<<4),  /* Internal reference */
    ADC_REFSEL_VDDREF_gc = (0x01<<4),  /* VDD */
    ADC_REFSEL_VREFA_gc = (0x02<<4),  /* External reference */
} ADC_REFSEL_t;

/* ADC Resolution select */
typedef enum ADC_RESSEL_enum
{
    ADC_RESSEL_10BIT_gc = (0x00<<2),  /* 10-bit mode */
    ADC_RESSEL_8BIT_gc = (0x01<<2),  /* 8-bit mode */
} ADC_RESSEL_t;

/* Accumulation Samples select */
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_ACC1_gc = (0x00<<0),  /* 1 ADC sample */
    ADC_SAMPNUM_ACC2_gc = (0x01<<0),  /* Accumulate 2 samples */
    ADC_SAMPNUM_ACC4_gc = (0x02<<0),  /* Accumulate 4 samples */
    ADC_SAMPNUM_ACC8_gc = (0x03<<0),  /* Accumulate 8 samples */
    ADC_SAMPNUM_ACC16_gc = (0x04<<0),  /* Accumulate 16 samples */
    ADC_SAMPNUM_ACC32_gc = (0x05<<0),  /* Accumulate 32 samples */
    ADC_SAMPNUM_ACC64_gc = (0x06<<0),  /* Accumulate 64 samples */
} ADC_SAMPNUM_t;

/* Window Comparator Mode select */
typedef enum ADC_WINCM_enum
{
    ADC_WINCM_NONE_gc = (0x00<<0),  /* No Window Comparison */
    ADC_WINCM_BELOW_gc = (0x01<<0),  /* Below Window */
    ADC_WINCM_ABOVE_gc = (0x02<<0),  /* Above Window */
    ADC_WINCM_INSIDE_gc = (0x03<<0),  /* Inside Window */
    ADC_WINCM_OUTSIDE_gc = (0x04<<0),  /* Outside Window */
} ADC_WINCM_t;

/*
--------------------------------------------------------------------------
BOD - Bod interface
--------------------------------------------------------------------------
*/

/* Bod interface */
typedef struct BOD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t reserved_0x02;
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t VLMCTRLA;  /* Voltage level monitor Control */
    register8_t INTCTRL;  /* Voltage level monitor interrupt Control */
    register8_t INTFLAGS;  /* Voltage level monitor interrupt Flags */
    register8_t STATUS;  /* Voltage level monitor status */
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} BOD_t;

/* Operation in active mode select */
typedef enum BOD_ACTIVE_enum
{
    BOD_ACTIVE_DIS_gc = (0x00<<2),  /* Disabled */
    BOD_ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled */
    BOD_ACTIVE_SAMPLED_gc = (0x02<<2),  /* Sampled */
    BOD_ACTIVE_ENWAKE_gc = (0x03<<2),  /* Enabled with wake-up halted until BOD is ready */
} BOD_ACTIVE_t;

/* Bod level select */
typedef enum BOD_LVL_enum
{
    BOD_LVL_BODLEVEL0_gc = (0x00<<0),  /* 1.8 V */
    BOD_LVL_BODLEVEL1_gc = (0x01<<0),  /* 2.1 V */
    BOD_LVL_BODLEVEL2_gc = (0x02<<0),  /* 2.6 V */
    BOD_LVL_BODLEVEL3_gc = (0x03<<0),  /* 2.9 V */
    BOD_LVL_BODLEVEL4_gc = (0x04<<0),  /* 3.3 V */
    BOD_LVL_BODLEVEL5_gc = (0x05<<0),  /* 3.7 V */
    BOD_LVL_BODLEVEL6_gc = (0x06<<0),  /* 4.0 V */
    BOD_LVL_BODLEVEL7_gc = (0x07<<0),  /* 4.2 V */
} BOD_LVL_t;

/* Sample frequency select */
typedef enum BOD_SAMPFREQ_enum
{
    BOD_SAMPFREQ_1KHZ_gc = (0x00<<4),  /* 1kHz sampling frequency */
    BOD_SAMPFREQ_125HZ_gc = (0x01<<4),  /* 125Hz sampling frequency */
} BOD_SAMPFREQ_t;

/* Operation in sleep mode select */
typedef enum BOD_SLEEP_enum
{
    BOD_SLEEP_DIS_gc = (0x00<<0),  /* Disabled */
    BOD_SLEEP_ENABLED_gc = (0x01<<0),  /* Enabled */
    BOD_SLEEP_SAMPLED_gc = (0x02<<0),  /* Sampled */
} BOD_SLEEP_t;

/* Configuration select */
typedef enum BOD_VLMCFG_enum
{
    BOD_VLMCFG_BELOW_gc = (0x00<<1),  /* Interrupt when supply goes below VLM level */
    BOD_VLMCFG_ABOVE_gc = (0x01<<1),  /* Interrupt when supply goes above VLM level */
    BOD_VLMCFG_CROSS_gc = (0x02<<1),  /* Interrupt when supply crosses VLM level */
} BOD_VLMCFG_t;

/* voltage level monitor level select */
typedef enum BOD_VLMLVL_enum
{
    BOD_VLMLVL_5ABOVE_gc = (0x00<<0),  /* VLM threshold 5% above BOD level */
    BOD_VLMLVL_15ABOVE_gc = (0x01<<0),  /* VLM threshold 15% above BOD level */
    BOD_VLMLVL_25ABOVE_gc = (0x02<<0),  /* VLM threshold 25% above BOD level */
} BOD_VLMLVL_t;

/*
--------------------------------------------------------------------------
CCL - Configurable Custom Logic
--------------------------------------------------------------------------
*/

/* Configurable Custom Logic */
typedef struct CCL_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t SEQCTRL0;  /* Sequential Control 0 */
    register8_t SEQCTRL1;  /* Sequential Control 1 */
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t INTCTRL0;  /* Interrupt Control 0 */
    register8_t reserved_0x06;
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t LUT0CTRLA;  /* LUT Control 0 A */
    register8_t LUT0CTRLB;  /* LUT Control 0 B */
    register8_t LUT0CTRLC;  /* LUT Control 0 C */
    register8_t TRUTH0;  /* Truth 0 */
    register8_t LUT1CTRLA;  /* LUT Control 1 A */
    register8_t LUT1CTRLB;  /* LUT Control 1 B */
    register8_t LUT1CTRLC;  /* LUT Control 1 C */
    register8_t TRUTH1;  /* Truth 1 */
    register8_t LUT2CTRLA;  /* LUT Control 2 A */
    register8_t LUT2CTRLB;  /* LUT Control 2 B */
    register8_t LUT2CTRLC;  /* LUT Control 2 C */
    register8_t TRUTH2;  /* Truth 2 */
    register8_t LUT3CTRLA;  /* LUT Control 3 A */
    register8_t LUT3CTRLB;  /* LUT Control 3 B */
    register8_t LUT3CTRLC;  /* LUT Control 3 C */
    register8_t TRUTH3;  /* Truth 3 */
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    register8_t reserved_0x20;
    register8_t reserved_0x21;
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    register8_t reserved_0x26;
    register8_t reserved_0x27;
    register8_t reserved_0x28;
    register8_t reserved_0x29;
    register8_t reserved_0x2A;
    register8_t reserved_0x2B;
    register8_t reserved_0x2C;
    register8_t reserved_0x2D;
    register8_t reserved_0x2E;
    register8_t reserved_0x2F;
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    register8_t reserved_0x36;
    register8_t reserved_0x37;
    register8_t reserved_0x38;
    register8_t reserved_0x39;
    register8_t reserved_0x3A;
    register8_t reserved_0x3B;
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} CCL_t;

/* Clock Source Selection select */
typedef enum CCL_CLKSRC_enum
{
    CCL_CLKSRC_CLKPER_gc = (0x00<<1),  /* CLK_PER is clocking the LUT */
    CCL_CLKSRC_IN2_gc = (0x01<<1),  /* IN[2] is clocking the LUT */
    CCL_CLKSRC_OSC20M_gc = (0x04<<1),  /* 20MHz oscillator before prescaler is clocking the LUT */
    CCL_CLKSRC_OSCULP32K_gc = (0x05<<1),  /* 32kHz oscillator is clocking the LUT */
    CCL_CLKSRC_OSCULP1K_gc = (0x06<<1),  /* 32kHz oscillator after DIV32 is clocking the LUT */
} CCL_CLKSRC_t;

/* Edge Detection Enable select */
typedef enum CCL_EDGEDET_enum
{
    CCL_EDGEDET_DIS_gc = (0x00<<7),  /* Edge detector is disabled */
    CCL_EDGEDET_EN_gc = (0x01<<7),  /* Edge detector is enabled */
} CCL_EDGEDET_t;

/* Filter Selection select */
typedef enum CCL_FILTSEL_enum
{
    CCL_FILTSEL_DISABLE_gc = (0x00<<4),  /* Filter disabled */
    CCL_FILTSEL_SYNCH_gc = (0x01<<4),  /* Synchronizer enabled */
    CCL_FILTSEL_FILTER_gc = (0x02<<4),  /* Filter enabled */
} CCL_FILTSEL_t;

/* LUT Input 0 Source Selection select */
typedef enum CCL_INSEL0_enum
{
    CCL_INSEL0_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL0_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL0_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL0_EVENTA_gc = (0x03<<0),  /* Event input source A */
    CCL_INSEL0_EVENTB_gc = (0x04<<0),  /* Event input source B */
    CCL_INSEL0_IO_gc = (0x05<<0),  /* IO pin LUTn-IN0 input source */
    CCL_INSEL0_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL0_USART0_gc = (0x08<<0),  /* USART0 TXD input source */
    CCL_INSEL0_SPI0_gc = (0x09<<0),  /* SPI0 MOSI input source */
    CCL_INSEL0_TCA0_gc = (0x0A<<0),  /* TCA0 WO0 input source */
    CCL_INSEL0_TCB0_gc = (0x0C<<0),  /* TCB0 WO input source */
} CCL_INSEL0_t;

/* LUT Input 1 Source Selection select */
typedef enum CCL_INSEL1_enum
{
    CCL_INSEL1_MASK_gc = (0x00<<4),  /* Masked input */
    CCL_INSEL1_FEEDBACK_gc = (0x01<<4),  /* Feedback input source */
    CCL_INSEL1_LINK_gc = (0x02<<4),  /* Linked LUT input source */
    CCL_INSEL1_EVENTA_gc = (0x03<<4),  /* Event input source A */
    CCL_INSEL1_EVENTB_gc = (0x04<<4),  /* Event input source B */
    CCL_INSEL1_IO_gc = (0x05<<4),  /* IO pin LUTn-N1 input source */
    CCL_INSEL1_AC0_gc = (0x06<<4),  /* AC0 OUT input source */
    CCL_INSEL1_USART1_gc = (0x08<<4),  /* USART1 TXD input source */
    CCL_INSEL1_SPI0_gc = (0x09<<4),  /* SPI0 MOSI input source */
    CCL_INSEL1_TCA0_gc = (0x0A<<4),  /* TCA0 WO1 input source */
    CCL_INSEL1_TCB1_gc = (0x0C<<4),  /* TCB1 WO input source */
} CCL_INSEL1_t;

/* LUT Input 2 Source Selection select */
typedef enum CCL_INSEL2_enum
{
    CCL_INSEL2_MASK_gc = (0x00<<0),  /* Masked input */
    CCL_INSEL2_FEEDBACK_gc = (0x01<<0),  /* Feedback input source */
    CCL_INSEL2_LINK_gc = (0x02<<0),  /* Linked LUT input source */
    CCL_INSEL2_EVENTA_gc = (0x03<<0),  /* Event input source A */
    CCL_INSEL2_EVENTB_gc = (0x04<<0),  /* Event input source B */
    CCL_INSEL2_IO_gc = (0x05<<0),  /* IO pin LUTn-IN2 input source */
    CCL_INSEL2_AC0_gc = (0x06<<0),  /* AC0 OUT input source */
    CCL_INSEL2_USART2_gc = (0x08<<0),  /* USART2 TXD input source */
    CCL_INSEL2_SPI0_gc = (0x09<<0),  /* SPI0 SCK input source */
    CCL_INSEL2_TCA0_gc = (0x0A<<0),  /* TCA0 WO2 input source */
    CCL_INSEL2_TCB2_gc = (0x0C<<0),  /* TCB2 WO input source */
} CCL_INSEL2_t;

/* Interrupt Mode for LUT0 select */
typedef enum CCL_INTMODE0_enum
{
    CCL_INTMODE0_INTDISABLE_gc = (0x00<<0),  /* Interrupt disabled */
    CCL_INTMODE0_RISING_gc = (0x01<<0),  /* Sense rising edge */
    CCL_INTMODE0_FALLING_gc = (0x02<<0),  /* Sense falling edge */
    CCL_INTMODE0_BOTH_gc = (0x03<<0),  /* Sense both edges */
} CCL_INTMODE0_t;

/* Interrupt Mode for LUT1 select */
typedef enum CCL_INTMODE1_enum
{
    CCL_INTMODE1_INTDISABLE_gc = (0x00<<2),  /* Interrupt disabled */
    CCL_INTMODE1_RISING_gc = (0x01<<2),  /* Sense rising edge */
    CCL_INTMODE1_FALLING_gc = (0x02<<2),  /* Sense falling edge */
    CCL_INTMODE1_BOTH_gc = (0x03<<2),  /* Sense both edges */
} CCL_INTMODE1_t;

/* Interrupt Mode for LUT2 select */
typedef enum CCL_INTMODE2_enum
{
    CCL_INTMODE2_INTDISABLE_gc = (0x00<<4),  /* Interrupt disabled */
    CCL_INTMODE2_RISING_gc = (0x01<<4),  /* Sense rising edge */
    CCL_INTMODE2_FALLING_gc = (0x02<<4),  /* Sense falling edge */
    CCL_INTMODE2_BOTH_gc = (0x03<<4),  /* Sense both edges */
} CCL_INTMODE2_t;

/* Interrupt Mode for LUT3 select */
typedef enum CCL_INTMODE3_enum
{
    CCL_INTMODE3_INTDISABLE_gc = (0x00<<6),  /* Interrupt disabled */
    CCL_INTMODE3_RISING_gc = (0x01<<6),  /* Sense rising edge */
    CCL_INTMODE3_FALLING_gc = (0x02<<6),  /* Sense falling edge */
    CCL_INTMODE3_BOTH_gc = (0x03<<6),  /* Sense both edges */
} CCL_INTMODE3_t;

/* Sequential Selection select */
typedef enum CCL_SEQSEL0_enum
{
    CCL_SEQSEL0_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL0_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL0_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL0_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL0_RS_gc = (0x04<<0),  /* RS Latch */
} CCL_SEQSEL0_t;

/* Sequential Selection select */
typedef enum CCL_SEQSEL1_enum
{
    CCL_SEQSEL1_DISABLE_gc = (0x00<<0),  /* Sequential logic disabled */
    CCL_SEQSEL1_DFF_gc = (0x01<<0),  /* D FlipFlop */
    CCL_SEQSEL1_JK_gc = (0x02<<0),  /* JK FlipFlop */
    CCL_SEQSEL1_LATCH_gc = (0x03<<0),  /* D Latch */
    CCL_SEQSEL1_RS_gc = (0x04<<0),  /* RS Latch */
} CCL_SEQSEL1_t;

/*
--------------------------------------------------------------------------
CLKCTRL - Clock controller
--------------------------------------------------------------------------
*/

/* Clock controller */
typedef struct CLKCTRL_struct
{
    register8_t MCLKCTRLA;  /* MCLK Control A */
    register8_t MCLKCTRLB;  /* MCLK Control B */
    register8_t MCLKLOCK;  /* MCLK Lock */
    register8_t MCLKSTATUS;  /* MCLK Status */
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t OSC20MCTRLA;  /* OSC20M Control A */
    register8_t OSC20MCALIBA;  /* OSC20M Calibration A */
    register8_t OSC20MCALIBB;  /* OSC20M Calibration B */
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t OSC32KCTRLA;  /* OSC32K Control A */
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t XOSC32KCTRLA;  /* XOSC32K Control A */
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
} CLKCTRL_t;

/* clock select select */
typedef enum CLKCTRL_CLKSEL_enum
{
    CLKCTRL_CLKSEL_OSC20M_gc = (0x00<<0),  /* 20MHz oscillator */
    CLKCTRL_CLKSEL_OSCULP32K_gc = (0x01<<0),  /* 32KHz oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768kHz crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0),  /* External clock */
} CLKCTRL_CLKSEL_t;

/* Crystal startup time select */
typedef enum CLKCTRL_CSUT_enum
{
    CLKCTRL_CSUT_1K_gc = (0x00<<4),  /* 1k cycles */
    CLKCTRL_CSUT_16K_gc = (0x01<<4),  /* 16k cycles */
    CLKCTRL_CSUT_32K_gc = (0x02<<4),  /* 32k cycles */
    CLKCTRL_CSUT_64K_gc = (0x03<<4),  /* 64k cycles */
} CLKCTRL_CSUT_t;

/* Prescaler division select */
typedef enum CLKCTRL_PDIV_enum
{
    CLKCTRL_PDIV_2X_gc = (0x00<<1),  /* 2X */
    CLKCTRL_PDIV_4X_gc = (0x01<<1),  /* 4X */
    CLKCTRL_PDIV_8X_gc = (0x02<<1),  /* 8X */
    CLKCTRL_PDIV_16X_gc = (0x03<<1),  /* 16X */
    CLKCTRL_PDIV_32X_gc = (0x04<<1),  /* 32X */
    CLKCTRL_PDIV_64X_gc = (0x05<<1),  /* 64X */
    CLKCTRL_PDIV_6X_gc = (0x08<<1),  /* 6X */
    CLKCTRL_PDIV_10X_gc = (0x09<<1),  /* 10X */
    CLKCTRL_PDIV_12X_gc = (0x0A<<1),  /* 12X */
    CLKCTRL_PDIV_24X_gc = (0x0B<<1),  /* 24X */
    CLKCTRL_PDIV_48X_gc = (0x0C<<1),  /* 48X */
} CLKCTRL_PDIV_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

/* CCP signature select */
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),  /* SPM Instruction Protection */
    CCP_IOREG_gc = (0xD8<<0),  /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CPUINT - Interrupt Controller
--------------------------------------------------------------------------
*/

/* Interrupt Controller */
typedef struct CPUINT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t LVL0PRI;  /* Interrupt Level 0 Priority */
    register8_t LVL1VEC;  /* Interrupt Level 1 Priority Vector */
} CPUINT_t;


/*
--------------------------------------------------------------------------
CRCSCAN - CRCSCAN
--------------------------------------------------------------------------
*/

/* CRCSCAN */
typedef struct CRCSCAN_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t reserved_0x03;
} CRCSCAN_t;

/* CRC Flash Access Mode select */
typedef enum CRCSCAN_MODE_enum
{
    CRCSCAN_MODE_PRIORITY_gc = (0x00<<4),  /* Priority to flash */
    CRCSCAN_MODE_RESERVED_gc = (0x01<<4),  /* Reserved */
    CRCSCAN_MODE_BACKGROUND_gc = (0x02<<4),  /* Lowest priority to flash */
    CRCSCAN_MODE_CONTINUOUS_gc = (0x03<<4),  /* Continuous checks in background */
} CRCSCAN_MODE_t;

/* CRC Source select */
typedef enum CRCSCAN_SRC_enum
{
    CRCSCAN_SRC_FLASH_gc = (0x00<<0),  /* CRC on entire flash */
    CRCSCAN_SRC_APPLICATION_gc = (0x01<<0),  /* CRC on boot and appl section of flash */
    CRCSCAN_SRC_BOOT_gc = (0x02<<0),  /* CRC on boot section of flash */
} CRCSCAN_SRC_t;

/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t STROBE;  /* Channel Strobe */
    register8_t reserved_0x01;
    register8_t reserved_0x02;
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t CHANNEL0;  /* Multiplexer Channel 0 */
    register8_t CHANNEL1;  /* Multiplexer Channel 1 */
    register8_t CHANNEL2;  /* Multiplexer Channel 2 */
    register8_t CHANNEL3;  /* Multiplexer Channel 3 */
    register8_t CHANNEL4;  /* Multiplexer Channel 4 */
    register8_t CHANNEL5;  /* Multiplexer Channel 5 */
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    register8_t USERCCLLUT0A;  /* User CCL LUT0 Event A */
    register8_t USERCCLLUT0B;  /* User CCL LUT0 Event B */
    register8_t USERCCLLUT1A;  /* User CCL LUT1 Event A */
    register8_t USERCCLLUT1B;  /* User CCL LUT1 Event B */
    register8_t USERCCLLUT2A;  /* User CCL LUT2 Event A */
    register8_t USERCCLLUT2B;  /* User CCL LUT2 Event B */
    register8_t USERCCLLUT3A;  /* User CCL LUT3 Event A */
    register8_t USERCCLLUT3B;  /* User CCL LUT3 Event B */
    register8_t USERADC0;  /* User ADC0 */
    register8_t USEREVOUTA;  /* User EVOUT Port A */
    register8_t USEREVOUTB;  /* User EVOUT Port B */
    register8_t USEREVOUTC;  /* User EVOUT Port C */
    register8_t USEREVOUTD;  /* User EVOUT Port D */
    register8_t USEREVOUTE;  /* User EVOUT Port E */
    register8_t USEREVOUTF;  /* User EVOUT Port F */
    register8_t USERUSART0;  /* User USART0 */
    register8_t USERUSART1;  /* User USART1 */
    register8_t USERUSART2;  /* User USART2 */
    register8_t USERUSART3;  /* User USART3 */
    register8_t USERTCA0;  /* User TCA0 */
    register8_t USERTCB0;  /* User TCB0 */
    register8_t USERTCB1;  /* User TCB1 */
    register8_t USERTCB2;  /* User TCB2 */
    register8_t USERTCB3;  /* User TCB3 */
    register8_t reserved_0x38;
    register8_t reserved_0x39;
    register8_t reserved_0x3A;
    register8_t reserved_0x3B;
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} EVSYS_t;

/* Channel selector select */
typedef enum EVSYS_CHANNEL_enum
{
    EVSYS_CHANNEL_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL_CHANNEL0_gc = (0x01<<0),  /* Connect user to event channel 0 */
    EVSYS_CHANNEL_CHANNEL1_gc = (0x02<<0),  /* Connect user to event channel 1 */
    EVSYS_CHANNEL_CHANNEL2_gc = (0x03<<0),  /* Connect user to event channel 2 */
    EVSYS_CHANNEL_CHANNEL3_gc = (0x04<<0),  /* Connect user to event channel 3 */
    EVSYS_CHANNEL_CHANNEL4_gc = (0x05<<0),  /* Connect user to event channel 4 */
    EVSYS_CHANNEL_CHANNEL5_gc = (0x06<<0),  /* Connect user to event channel 5 */
} EVSYS_CHANNEL_t;

/* Generator selector select */
typedef enum EVSYS_GENERATOR_enum
{
    EVSYS_GENERATOR_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_GENERATOR_UPDI_gc = (0x01<<0),  /* Unified Program and Debug Interface */
    EVSYS_GENERATOR_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_GENERATOR_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_GENERATOR_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_GENERATOR_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_GENERATOR_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_GENERATOR_ADC0_COMP_gc = (0x24<<0),  /* ADC 0 Comparator Event */
    EVSYS_GENERATOR_PORT0_PIN0_gc = (0x40<<0),  /* Port 0 Pin 0 */
    EVSYS_GENERATOR_PORT0_PIN1_gc = (0x41<<0),  /* Port 0 Pin 1 */
    EVSYS_GENERATOR_PORT0_PIN2_gc = (0x42<<0),  /* Port 0 Pin 2 */
    EVSYS_GENERATOR_PORT0_PIN3_gc = (0x43<<0),  /* Port 0 Pin 3 */
    EVSYS_GENERATOR_PORT0_PIN4_gc = (0x44<<0),  /* Port 0 Pin 4 */
    EVSYS_GENERATOR_PORT0_PIN5_gc = (0x45<<0),  /* Port 0 Pin 5 */
    EVSYS_GENERATOR_PORT0_PIN6_gc = (0x46<<0),  /* Port 0 Pin 6 */
    EVSYS_GENERATOR_PORT0_PIN7_gc = (0x47<<0),  /* Port 0 Pin 7 */
    EVSYS_GENERATOR_PORT1_PIN0_gc = (0x48<<0),  /* Port 1 Pin 0 */
    EVSYS_GENERATOR_PORT1_PIN1_gc = (0x49<<0),  /* Port 1 Pin 1 */
    EVSYS_GENERATOR_PORT1_PIN2_gc = (0x4A<<0),  /* Port 1 Pin 2 */
    EVSYS_GENERATOR_PORT1_PIN3_gc = (0x4B<<0),  /* Port 1 Pin 3 */
    EVSYS_GENERATOR_PORT1_PIN4_gc = (0x4C<<0),  /* Port 1 Pin 4 */
    EVSYS_GENERATOR_PORT1_PIN5_gc = (0x4D<<0),  /* Port 1 Pin 5 */
    EVSYS_GENERATOR_PORT1_PIN6_gc = (0x4E<<0),  /* Port 1 Pin 6 */
    EVSYS_GENERATOR_PORT1_PIN7_gc = (0x4F<<0),  /* Port 1 Pin 7 */
    EVSYS_GENERATOR_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_GENERATOR_USART0_XCK_gc = (0x60<<0),  /* USART 0 Xclock */
    EVSYS_GENERATOR_USART1_XCK_gc = (0x61<<0),  /* USART 1 Xclock */
    EVSYS_GENERATOR_USART2_XCK_gc = (0x62<<0),  /* USART 2 Xclock */
    EVSYS_GENERATOR_USART3_XCK_gc = (0x63<<0),  /* USART 3 Xclock */
    EVSYS_GENERATOR_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 Sclock */
    EVSYS_GENERATOR_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_GENERATOR_RTC_PIT0_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_GENERATOR_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte underflow */
    EVSYS_GENERATOR_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte underflow (split mode) */
    EVSYS_GENERATOR_TCA0_CMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 */
    EVSYS_GENERATOR_TCA0_CMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 */
    EVSYS_GENERATOR_TCA0_CMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 */
    EVSYS_GENERATOR_RTC_PIT1_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_GENERATOR_RTC_PIT2_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_GENERATOR_TCB0_CMP0_gc = (0xA0<<0),  /* Timer/Counter B0 compare 0 */
    EVSYS_GENERATOR_TCB1_CMP0_gc = (0xA2<<0),  /* Timer/Counter B1 compare 0 */
    EVSYS_GENERATOR_TCB2_CMP0_gc = (0xA4<<0),  /* Timer/Counter B2 compare 0 */
    EVSYS_GENERATOR_TCB3_CMP0_gc = (0xA6<<0),  /* Timer/Counter B3 compare 0 */
    EVSYS_GENERATOR_RTC_PIT3_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
} EVSYS_GENERATOR_t;

/* Software event on channels select */
typedef enum EVSYS_STROBE0_enum
{
    EVSYS_STROBE0_EV_STROBE_CH0_gc = (0x01<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH1_gc = (0x02<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH2_gc = (0x04<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH3_gc = (0x08<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH4_gc = (0x10<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH5_gc = (0x20<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH6_gc = (0x40<<0),  /*  */
    EVSYS_STROBE0_EV_STROBE_CH7_gc = (0x80<<0),  /*  */
} EVSYS_STROBE0_t;

/*
--------------------------------------------------------------------------
FUSE - Fuses
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct FUSE_struct
{
    register8_t WDTCFG;  /* Watchdog Configuration */
    register8_t BODCFG;  /* BOD Configuration */
    register8_t OSCCFG;  /* Oscillator Configuration */
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t SYSCFG0;  /* System Configuration 0 */
    register8_t SYSCFG1;  /* System Configuration 1 */
    register8_t APPEND;  /* Application Code Section End */
    register8_t BOOTEND;  /* Boot Section End */
} FUSE_t;


/* avr-libc typedef for avr/fuse.h */
typedef FUSE_t NVM_FUSES_t;

/* BOD Operation in Active Mode select */
typedef enum ACTIVE_enum
{
    ACTIVE_DIS_gc = (0x00<<2),  /* Disabled */
    ACTIVE_ENABLED_gc = (0x01<<2),  /* Enabled */
    ACTIVE_SAMPLED_gc = (0x02<<2),  /* Sampled */
    ACTIVE_ENWAKE_gc = (0x03<<2),  /* Enabled with wake-up halted until BOD is ready */
} ACTIVE_t;

/* CRC Source select */
typedef enum CRCSRC_enum
{
    CRCSRC_FLASH_gc = (0x00<<6),  /* The CRC is performed on the entire Flash (boot, application code and application data section). */
    CRCSRC_BOOT_gc = (0x01<<6),  /* The CRC is performed on the boot section of Flash */
    CRCSRC_BOOTAPP_gc = (0x02<<6),  /* The CRC is performed on the boot and application code section of Flash */
    CRCSRC_NOCRC_gc = (0x03<<6),  /* Disable CRC. */
} CRCSRC_t;

/* Frequency Select select */
typedef enum FREQSEL_enum
{
    FREQSEL_16MHZ_gc = (0x01<<0),  /* 16 MHz */
    FREQSEL_20MHZ_gc = (0x02<<0),  /* 20 MHz */
} FREQSEL_t;

/* BOD Level select */
typedef enum LVL_enum
{
    LVL_BODLEVEL0_gc = (0x00<<5),  /* 1.8 V */
    LVL_BODLEVEL1_gc = (0x01<<5),  /* 2.1 V */
    LVL_BODLEVEL2_gc = (0x02<<5),  /* 2.6 V */
    LVL_BODLEVEL3_gc = (0x03<<5),  /* 2.9 V */
    LVL_BODLEVEL4_gc = (0x04<<5),  /* 3.3 V */
    LVL_BODLEVEL5_gc = (0x05<<5),  /* 3.7 V */
    LVL_BODLEVEL6_gc = (0x06<<5),  /* 4.0 V */
    LVL_BODLEVEL7_gc = (0x07<<5),  /* 4.2 V */
} LVL_t;

/* Watchdog Timeout Period select */
typedef enum PERIOD_enum
{
    PERIOD_OFF_gc = (0x00<<0),  /* Off */
    PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    PERIOD_8KCLK_gc = (0x0B<<0),  /* 8K cycles (8.2s) */
} PERIOD_t;

/* Reset Pin Configuration select */
typedef enum RSTPINCFG_enum
{
    RSTPINCFG_GPIO_gc = (0x00<<3),  /* GPIO mode */
    RSTPINCFG_RST_gc = (0x01<<3),  /* Reset mode */
} RSTPINCFG_t;

/* BOD Sample Frequency select */
typedef enum SAMPFREQ_enum
{
    SAMPFREQ_1KHZ_gc = (0x00<<4),  /* 1kHz sampling frequency */
    SAMPFREQ_125HZ_gc = (0x01<<4),  /* 125Hz sampling frequency */
} SAMPFREQ_t;

/* BOD Operation in Sleep Mode select */
typedef enum SLEEP_enum
{
    SLEEP_DIS_gc = (0x00<<0),  /* Disabled */
    SLEEP_ENABLED_gc = (0x01<<0),  /* Enabled */
    SLEEP_SAMPLED_gc = (0x02<<0),  /* Sampled */
} SLEEP_t;

/* Startup Time select */
typedef enum SUT_enum
{
    SUT_0MS_gc = (0x00<<0),  /* 0 ms */
    SUT_1MS_gc = (0x01<<0),  /* 1 ms */
    SUT_2MS_gc = (0x02<<0),  /* 2 ms */
    SUT_4MS_gc = (0x03<<0),  /* 4 ms */
    SUT_8MS_gc = (0x04<<0),  /* 8 ms */
    SUT_16MS_gc = (0x05<<0),  /* 16 ms */
    SUT_32MS_gc = (0x06<<0),  /* 32 ms */
    SUT_64MS_gc = (0x07<<0),  /* 64 ms */
} SUT_t;

/* Watchdog Window Timeout Period select */
typedef enum WINDOW_enum
{
    WINDOW_OFF_gc = (0x00<<4),  /* Off */
    WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WINDOW_8KCLK_gc = (0x0B<<4),  /* 8K cycles (8.2s) */
} WINDOW_t;

/*
--------------------------------------------------------------------------
LOCKBIT - Lockbit
--------------------------------------------------------------------------
*/

/* Lockbit */
typedef struct LOCKBIT_struct
{
    register8_t LOCKBIT;  /* Lock Bits */
    register8_t reserved_0x01;
} LOCKBIT_t;

/* Lock Bits select */
typedef enum LB_enum
{
    LB_RWLOCK_gc = (0x3A<<0),  /* Read and write lock */
    LB_NOLOCK_gc = (0xC5<<0),  /* No locks */
} LB_t;

/*
--------------------------------------------------------------------------
NVMCTRL - Non-volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVMCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_0x05;
    _WORDREGISTER(DATA);  /* Data */
    _WORDREGISTER(ADDR);  /* Address */
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} NVMCTRL_t;

/* Command select */
typedef enum NVMCTRL_CMD_enum
{
    NVMCTRL_CMD_NONE_gc = (0x00<<0),  /* No Command */
    NVMCTRL_CMD_PAGEWRITE_gc = (0x01<<0),  /* Write page */
    NVMCTRL_CMD_PAGEERASE_gc = (0x02<<0),  /* Erase page */
    NVMCTRL_CMD_PAGEERASEWRITE_gc = (0x03<<0),  /* Erase and write page */
    NVMCTRL_CMD_PAGEBUFCLR_gc = (0x04<<0),  /* Page buffer clear */
    NVMCTRL_CMD_CHIPERASE_gc = (0x05<<0),  /* Chip erase */
    NVMCTRL_CMD_EEERASE_gc = (0x06<<0),  /* EEPROM erase */
    NVMCTRL_CMD_FUSEWRITE_gc = (0x07<<0),  /* Write fuse (PDI only) */
} NVMCTRL_CMD_t;

/*
--------------------------------------------------------------------------
PORT - I/O Ports
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t DIRSET;  /* Data Direction Set */
    register8_t DIRCLR;  /* Data Direction Clear */
    register8_t DIRTGL;  /* Data Direction Toggle */
    register8_t OUT;  /* Output Value */
    register8_t OUTSET;  /* Output Value Set */
    register8_t OUTCLR;  /* Output Value Clear */
    register8_t OUTTGL;  /* Output Value Toggle */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t PORTCTRL;  /* Port Control */
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t PIN0CTRL;  /* Pin 0 Control */
    register8_t PIN1CTRL;  /* Pin 1 Control */
    register8_t PIN2CTRL;  /* Pin 2 Control */
    register8_t PIN3CTRL;  /* Pin 3 Control */
    register8_t PIN4CTRL;  /* Pin 4 Control */
    register8_t PIN5CTRL;  /* Pin 5 Control */
    register8_t PIN6CTRL;  /* Pin 6 Control */
    register8_t PIN7CTRL;  /* Pin 7 Control */
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
} PORT_t;

/* Input/Sense Configuration select */
typedef enum PORT_ISC_enum
{
    PORT_ISC_INTDISABLE_gc = (0x00<<0),  /* Interrupt disabled but input buffer enabled */
    PORT_ISC_BOTHEDGES_gc = (0x01<<0),  /* Sense Both Edges */
    PORT_ISC_RISING_gc = (0x02<<0),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc = (0x03<<0),  /* Sense Falling Edge */
    PORT_ISC_INPUT_DISABLE_gc = (0x04<<0),  /* Digital Input Buffer disabled */
    PORT_ISC_LEVEL_gc = (0x05<<0),  /* Sense low Level */
} PORT_ISC_t;

/*
--------------------------------------------------------------------------
PORTMUX - Port Multiplexer
--------------------------------------------------------------------------
*/

/* Port Multiplexer */
typedef struct PORTMUX_struct
{
    register8_t EVSYSROUTEA;  /* Port Multiplexer EVSYS */
    register8_t CCLROUTEA;  /* Port Multiplexer CCL */
    register8_t USARTROUTEA;  /* Port Multiplexer USART register A */
    register8_t TWISPIROUTEA;  /* Port Multiplexer TWI and SPI */
    register8_t TCAROUTEA;  /* Port Multiplexer TCA */
    register8_t TCBROUTEA;  /* Port Multiplexer TCB */
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} PORTMUX_t;

/* Port Multiplexer SPI0 select */
typedef enum PORTMUX_SPI0_enum
{
    PORTMUX_SPI0_DEFAULT_gc = (0x00<<0),  /* SPI0 on PA[7:4] */
    PORTMUX_SPI0_ALT1_gc = (0x01<<0),  /* SPI0 on PC[3:0] */
    PORTMUX_SPI0_ALT2_gc = (0x02<<0),  /* SPI0 on PE[3:0] */
    PORTMUX_SPI0_NONE_gc = (0x03<<0),  /* Not connected to any pins */
} PORTMUX_SPI0_t;

/* Port Multiplexer TCA0 select */
typedef enum PORTMUX_TCA0_enum
{
    PORTMUX_TCA0_PORTA_gc = (0x00<<0),  /* TCA0 pins on PA[5:0] */
    PORTMUX_TCA0_PORTB_gc = (0x01<<0),  /* TCA0 pins on PB[5:0] */
    PORTMUX_TCA0_PORTC_gc = (0x02<<0),  /* TCA0 pins on PC[5:0] */
    PORTMUX_TCA0_PORTD_gc = (0x03<<0),  /* TCA0 pins on PD[5:0] */
    PORTMUX_TCA0_PORTE_gc = (0x04<<0),  /* TCA0 pins on PE[5:0] */
    PORTMUX_TCA0_PORTF_gc = (0x05<<0),  /* TCA0 pins on PF[5:0] */
} PORTMUX_TCA0_t;

/* Port Multiplexer TWI0 select */
typedef enum PORTMUX_TWI0_enum
{
    PORTMUX_TWI0_DEFAULT_gc = (0x00<<4),  /* SCL/SDA on PA[3:2], Slave mode on PC[3:2] in dual TWI mode */
    PORTMUX_TWI0_ALT1_gc = (0x01<<4),  /* SCL/SDA on PA[3:2], Slave mode on PF[3:2] in dual TWI mode */
    PORTMUX_TWI0_ALT2_gc = (0x02<<4),  /* SCL/SDA on PC[3:2], Slave mode on PF[3:2] in dual TWI mode */
    PORTMUX_TWI0_NONE_gc = (0x03<<4),  /* Not connected to any pins */
} PORTMUX_TWI0_t;

/* Port Multiplexer USART0 select */
typedef enum PORTMUX_USART0_enum
{
    PORTMUX_USART0_DEFAULT_gc = (0x00<<0),  /* USART0 on PA[3:0] */
    PORTMUX_USART0_ALT1_gc = (0x01<<0),  /* USART0 on PA[7:4] */
    PORTMUX_USART0_NONE_gc = (0x03<<0),  /* Not connected to any pins */
} PORTMUX_USART0_t;

/* Port Multiplexer USART1 select */
typedef enum PORTMUX_USART1_enum
{
    PORTMUX_USART1_DEFAULT_gc = (0x00<<2),  /* USART1 on PC[3:0] */
    PORTMUX_USART1_ALT1_gc = (0x01<<2),  /* USART1 on PC[7:4] */
    PORTMUX_USART1_NONE_gc = (0x03<<2),  /* Not connected to any pins */
} PORTMUX_USART1_t;

/* Port Multiplexer USART2 select */
typedef enum PORTMUX_USART2_enum
{
    PORTMUX_USART2_DEFAULT_gc = (0x00<<4),  /* USART2 on PF[3:0] */
    PORTMUX_USART2_ALT1_gc = (0x01<<4),  /* USART2 on PF[6:4] */
    PORTMUX_USART2_NONE_gc = (0x03<<4),  /* Not connected to any pins */
} PORTMUX_USART2_t;

/* Port Multiplexer USART3 select */
typedef enum PORTMUX_USART3_enum
{
    PORTMUX_USART3_DEFAULT_gc = (0x00<<6),  /* USART3 on PB[3:0] */
    PORTMUX_USART3_ALT1_gc = (0x01<<6),  /* USART3 on PB[5:4] */
    PORTMUX_USART3_NONE_gc = (0x03<<6),  /* Not connected to any pins */
} PORTMUX_USART3_t;

/*
--------------------------------------------------------------------------
RSTCTRL - Reset controller
--------------------------------------------------------------------------
*/

/* Reset controller */
typedef struct RSTCTRL_struct
{
    register8_t RSTFR;  /* Reset Flags */
    register8_t SWRR;  /* Software Reset */
    register8_t reserved_0x02;
    register8_t reserved_0x03;
} RSTCTRL_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Counter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary */
    register8_t DBGCTRL;  /* Debug control */
    register8_t CALIB;  /* Calibration */
    register8_t CLKSEL;  /* Clock Select */
    _WORDREGISTER(CNT);  /* Counter */
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP);  /* Compare */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t PITCTRLA;  /* PIT Control A */
    register8_t PITSTATUS;  /* PIT Status */
    register8_t PITINTCTRL;  /* PIT Interrupt Control */
    register8_t PITINTFLAGS;  /* PIT Interrupt Flags */
    register8_t reserved_0x14;
    register8_t PITDBGCTRL;  /* PIT Debug control */
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
} RTC_t;

/* Clock Select select */
typedef enum RTC_CLKSEL_enum
{
    RTC_CLKSEL_INT32K_gc = (0x00<<0),  /* Internal 32kHz OSC */
    RTC_CLKSEL_INT1K_gc = (0x01<<0),  /* Internal 1kHz OSC */
    RTC_CLKSEL_TOSC32K_gc = (0x02<<0),  /* 32KHz Crystal OSC */
    RTC_CLKSEL_EXTCLK_gc = (0x03<<0),  /* External Clock */
} RTC_CLKSEL_t;

/* Period select */
typedef enum RTC_PERIOD_enum
{
    RTC_PERIOD_OFF_gc = (0x00<<3),  /* Off */
    RTC_PERIOD_CYC4_gc = (0x01<<3),  /* RTC Clock Cycles 4 */
    RTC_PERIOD_CYC8_gc = (0x02<<3),  /* RTC Clock Cycles 8 */
    RTC_PERIOD_CYC16_gc = (0x03<<3),  /* RTC Clock Cycles 16 */
    RTC_PERIOD_CYC32_gc = (0x04<<3),  /* RTC Clock Cycles 32 */
    RTC_PERIOD_CYC64_gc = (0x05<<3),  /* RTC Clock Cycles 64 */
    RTC_PERIOD_CYC128_gc = (0x06<<3),  /* RTC Clock Cycles 128 */
    RTC_PERIOD_CYC256_gc = (0x07<<3),  /* RTC Clock Cycles 256 */
    RTC_PERIOD_CYC512_gc = (0x08<<3),  /* RTC Clock Cycles 512 */
    RTC_PERIOD_CYC1024_gc = (0x09<<3),  /* RTC Clock Cycles 1024 */
    RTC_PERIOD_CYC2048_gc = (0x0A<<3),  /* RTC Clock Cycles 2048 */
    RTC_PERIOD_CYC4096_gc = (0x0B<<3),  /* RTC Clock Cycles 4096 */
    RTC_PERIOD_CYC8192_gc = (0x0C<<3),  /* RTC Clock Cycles 8192 */
    RTC_PERIOD_CYC16384_gc = (0x0D<<3),  /* RTC Clock Cycles 16384 */
    RTC_PERIOD_CYC32768_gc = (0x0E<<3),  /* RTC Clock Cycles 32768 */
} RTC_PERIOD_t;

/* Prescaling Factor select */
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_DIV1_gc = (0x00<<3),  /* RTC Clock / 1 */
    RTC_PRESCALER_DIV2_gc = (0x01<<3),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV4_gc = (0x02<<3),  /* RTC Clock / 4 */
    RTC_PRESCALER_DIV8_gc = (0x03<<3),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc = (0x04<<3),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV32_gc = (0x05<<3),  /* RTC Clock / 32 */
    RTC_PRESCALER_DIV64_gc = (0x06<<3),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV128_gc = (0x07<<3),  /* RTC Clock / 128 */
    RTC_PRESCALER_DIV256_gc = (0x08<<3),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV512_gc = (0x09<<3),  /* RTC Clock / 512 */
    RTC_PRESCALER_DIV1024_gc = (0x0A<<3),  /* RTC Clock / 1024 */
    RTC_PRESCALER_DIV2048_gc = (0x0B<<3),  /* RTC Clock / 2048 */
    RTC_PRESCALER_DIV4096_gc = (0x0C<<3),  /* RTC Clock / 4096 */
    RTC_PRESCALER_DIV8192_gc = (0x0D<<3),  /* RTC Clock / 8192 */
    RTC_PRESCALER_DIV16384_gc = (0x0E<<3),  /* RTC Clock / 16384 */
    RTC_PRESCALER_DIV32768_gc = (0x0F<<3),  /* RTC Clock / 32768 */
} RTC_PRESCALER_t;

/*
--------------------------------------------------------------------------
SIGROW - Signature row
--------------------------------------------------------------------------
*/

/* Signature row */
typedef struct SIGROW_struct
{
    register8_t DEVICEID0;  /* Device ID Byte 0 */
    register8_t DEVICEID1;  /* Device ID Byte 1 */
    register8_t DEVICEID2;  /* Device ID Byte 2 */
    register8_t SERNUM0;  /* Serial Number Byte 0 */
    register8_t SERNUM1;  /* Serial Number Byte 1 */
    register8_t SERNUM2;  /* Serial Number Byte 2 */
    register8_t SERNUM3;  /* Serial Number Byte 3 */
    register8_t SERNUM4;  /* Serial Number Byte 4 */
    register8_t SERNUM5;  /* Serial Number Byte 5 */
    register8_t SERNUM6;  /* Serial Number Byte 6 */
    register8_t SERNUM7;  /* Serial Number Byte 7 */
    register8_t SERNUM8;  /* Serial Number Byte 8 */
    register8_t SERNUM9;  /* Serial Number Byte 9 */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t OSCCAL32K;  /* Oscillator Calibration for 32kHz ULP */
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t OSCCAL16M0;  /* Oscillator Calibration 16 MHz Byte 0 */
    register8_t OSCCAL16M1;  /* Oscillator Calibration 16 MHz Byte 1 */
    register8_t OSCCAL20M0;  /* Oscillator Calibration 20 MHz Byte 0 */
    register8_t OSCCAL20M1;  /* Oscillator Calibration 20 MHz Byte 1 */
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    register8_t TEMPSENSE0;  /* Temperature Sensor Calibration Byte 0 */
    register8_t TEMPSENSE1;  /* Temperature Sensor Calibration Byte 1 */
    register8_t OSC16ERR3V;  /* OSC16 error at 3V */
    register8_t OSC16ERR5V;  /* OSC16 error at 5V */
    register8_t OSC20ERR3V;  /* OSC20 error at 3V */
    register8_t OSC20ERR5V;  /* OSC20 error at 5V */
    register8_t reserved_0x26;
    register8_t reserved_0x27;
    register8_t reserved_0x28;
    register8_t reserved_0x29;
    register8_t reserved_0x2A;
    register8_t reserved_0x2B;
    register8_t reserved_0x2C;
    register8_t reserved_0x2D;
    register8_t reserved_0x2E;
    register8_t CHECKSUM1;  /* CRC Checksum Byte 1 */
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    register8_t reserved_0x36;
    register8_t reserved_0x37;
    register8_t reserved_0x38;
    register8_t reserved_0x39;
    register8_t reserved_0x3A;
    register8_t reserved_0x3B;
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} SIGROW_t;


/*
--------------------------------------------------------------------------
SLPCTRL - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLPCTRL_struct
{
    register8_t CTRLA;  /* Control */
    register8_t reserved_0x01;
} SLPCTRL_t;

/* Sleep mode select */
typedef enum SLPCTRL_SMODE_enum
{
    SLPCTRL_SMODE_IDLE_gc = (0x00<<1),  /* Idle mode */
    SLPCTRL_SMODE_STDBY_gc = (0x01<<1),  /* Standby Mode */
    SLPCTRL_SMODE_PDOWN_gc = (0x02<<1),  /* Power-down Mode */
} SLPCTRL_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_STANDBY (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DATA;  /* Data */
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
} SPI_t;

/* SPI Mode select */
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<0),  /* SPI Mode 0 */
    SPI_MODE_1_gc = (0x01<<0),  /* SPI Mode 1 */
    SPI_MODE_2_gc = (0x02<<0),  /* SPI Mode 2 */
    SPI_MODE_3_gc = (0x03<<0),  /* SPI Mode 3 */
} SPI_MODE_t;

/* Prescaler select */
typedef enum SPI_PRESC_enum
{
    SPI_PRESC_DIV4_gc = (0x00<<1),  /* System Clock / 4 */
    SPI_PRESC_DIV16_gc = (0x01<<1),  /* System Clock / 16 */
    SPI_PRESC_DIV64_gc = (0x02<<1),  /* System Clock / 64 */
    SPI_PRESC_DIV128_gc = (0x03<<1),  /* System Clock / 128 */
} SPI_PRESC_t;

/*
--------------------------------------------------------------------------
SYSCFG - System Configuration Registers
--------------------------------------------------------------------------
*/

/* System Configuration Registers */
typedef struct SYSCFG_struct
{
    register8_t reserved_0x00;
    register8_t REVID;  /* Revision ID */
    register8_t EXTBRK;  /* External Break */
    register8_t reserved_0x03;
    register8_t reserved_0x04;
    register8_t reserved_0x05;
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t reserved_0x0A;
    register8_t reserved_0x0B;
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t OCDM;  /* OCD Message Register */
    register8_t OCDMS;  /* OCD Message Status */
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
} SYSCFG_t;


/*
--------------------------------------------------------------------------
TCA - 16-bit Timer/Counter Type A
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type A - Single Mode */
typedef struct TCA_SINGLE_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t reserved_0x08;
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t TEMP;  /* Temporary data for 16-bit Access */
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP0);  /* Compare 0 */
    _WORDREGISTER(CMP1);  /* Compare 1 */
    _WORDREGISTER(CMP2);  /* Compare 2 */
    register8_t reserved_0x2E;
    register8_t reserved_0x2F;
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CMP0BUF);  /* Compare 0 Buffer */
    _WORDREGISTER(CMP1BUF);  /* Compare 1 Buffer */
    _WORDREGISTER(CMP2BUF);  /* Compare 2 Buffer */
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} TCA_SINGLE_t;


/* 16-bit Timer/Counter Type A - Split Mode */
typedef struct TCA_SPLIT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t reserved_0x06;
    register8_t reserved_0x07;
    register8_t reserved_0x08;
    register8_t reserved_0x09;
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_0x0C;
    register8_t reserved_0x0D;
    register8_t DBGCTRL;  /* Degbug Control */
    register8_t reserved_0x0F;
    register8_t reserved_0x10;
    register8_t reserved_0x11;
    register8_t reserved_0x12;
    register8_t reserved_0x13;
    register8_t reserved_0x14;
    register8_t reserved_0x15;
    register8_t reserved_0x16;
    register8_t reserved_0x17;
    register8_t reserved_0x18;
    register8_t reserved_0x19;
    register8_t reserved_0x1A;
    register8_t reserved_0x1B;
    register8_t reserved_0x1C;
    register8_t reserved_0x1D;
    register8_t reserved_0x1E;
    register8_t reserved_0x1F;
    register8_t LCNT;  /* Low Count */
    register8_t HCNT;  /* High Count */
    register8_t reserved_0x22;
    register8_t reserved_0x23;
    register8_t reserved_0x24;
    register8_t reserved_0x25;
    register8_t LPER;  /* Low Period */
    register8_t HPER;  /* High Period */
    register8_t LCMP0;  /* Low Compare */
    register8_t HCMP0;  /* High Compare */
    register8_t LCMP1;  /* Low Compare */
    register8_t HCMP1;  /* High Compare */
    register8_t LCMP2;  /* Low Compare */
    register8_t HCMP2;  /* High Compare */
    register8_t reserved_0x2E;
    register8_t reserved_0x2F;
    register8_t reserved_0x30;
    register8_t reserved_0x31;
    register8_t reserved_0x32;
    register8_t reserved_0x33;
    register8_t reserved_0x34;
    register8_t reserved_0x35;
    register8_t reserved_0x36;
    register8_t reserved_0x37;
    register8_t reserved_0x38;
    register8_t reserved_0x39;
    register8_t reserved_0x3A;
    register8_t reserved_0x3B;
    register8_t reserved_0x3C;
    register8_t reserved_0x3D;
    register8_t reserved_0x3E;
    register8_t reserved_0x3F;
} TCA_SPLIT_t;


/* 16-bit Timer/Counter Type A */
typedef union TCA_union
{
    TCA_SINGLE_t SINGLE;  /* 16-bit Timer/Counter Type A - Single Mode */
    TCA_SPLIT_t SPLIT;  /* 16-bit Timer/Counter Type A - Split Mode */
} TCA_t;

/* Clock Selection select */
typedef enum TCA_SINGLE_CLKSEL_enum
{
    TCA_SINGLE_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SINGLE_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SINGLE_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SINGLE_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SINGLE_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SINGLE_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SINGLE_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SINGLE_CLKSEL_DIV1024_gc = (0x07<<1),  /* System Clock / 1024 */
} TCA_SINGLE_CLKSEL_t;

/* Command select */
typedef enum TCA_SINGLE_CMD_enum
{
    TCA_SINGLE_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SINGLE_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SINGLE_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SINGLE_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TCA_SINGLE_CMD_t;

/* Direction select */
typedef enum TCA_SINGLE_DIR_enum
{
    TCA_SINGLE_DIR_UP_gc = (0x00<<0),  /* Count up */
    TCA_SINGLE_DIR_DOWN_gc = (0x01<<0),  /* Count down */
} TCA_SINGLE_DIR_t;

/* Event Action select */
typedef enum TCA_SINGLE_EVACT_enum
{
    TCA_SINGLE_EVACT_POSEDGE_gc = (0x00<<1),  /* Count on positive edge event */
    TCA_SINGLE_EVACT_ANYEDGE_gc = (0x01<<1),  /* Count on any edge event */
    TCA_SINGLE_EVACT_HIGHLVL_gc = (0x02<<1),  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACT_UPDOWN_gc = (0x03<<1),  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACT_t;

/* Waveform generation mode select */
typedef enum TCA_SINGLE_WGMODE_enum
{
    TCA_SINGLE_WGMODE_NORMAL_gc = (0x00<<0),  /* Normal Mode */
    TCA_SINGLE_WGMODE_FRQ_gc = (0x01<<0),  /* Frequency Generation Mode */
    TCA_SINGLE_WGMODE_SINGLESLOPE_gc = (0x03<<0),  /* Single Slope PWM */
    TCA_SINGLE_WGMODE_DSTOP_gc = (0x05<<0),  /* Dual Slope PWM, overflow on TOP */
    TCA_SINGLE_WGMODE_DSBOTH_gc = (0x06<<0),  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCA_SINGLE_WGMODE_DSBOTTOM_gc = (0x07<<0),  /* Dual Slope PWM, overflow on BOTTOM */
} TCA_SINGLE_WGMODE_t;

/* Clock Selection select */
typedef enum TCA_SPLIT_CLKSEL_enum
{
    TCA_SPLIT_CLKSEL_DIV1_gc = (0x00<<1),  /* System Clock */
    TCA_SPLIT_CLKSEL_DIV2_gc = (0x01<<1),  /* System Clock / 2 */
    TCA_SPLIT_CLKSEL_DIV4_gc = (0x02<<1),  /* System Clock / 4 */
    TCA_SPLIT_CLKSEL_DIV8_gc = (0x03<<1),  /* System Clock / 8 */
    TCA_SPLIT_CLKSEL_DIV16_gc = (0x04<<1),  /* System Clock / 16 */
    TCA_SPLIT_CLKSEL_DIV64_gc = (0x05<<1),  /* System Clock / 64 */
    TCA_SPLIT_CLKSEL_DIV256_gc = (0x06<<1),  /* System Clock / 256 */
    TCA_SPLIT_CLKSEL_DIV1024_gc = (0x07<<1),  /* System Clock / 1024 */
} TCA_SPLIT_CLKSEL_t;

/* Command select */
typedef enum TCA_SPLIT_CMD_enum
{
    TCA_SPLIT_CMD_NONE_gc = (0x00<<2),  /* No Command */
    TCA_SPLIT_CMD_UPDATE_gc = (0x01<<2),  /* Force Update */
    TCA_SPLIT_CMD_RESTART_gc = (0x02<<2),  /* Force Restart */
    TCA_SPLIT_CMD_RESET_gc = (0x03<<2),  /* Force Hard Reset */
} TCA_SPLIT_CMD_t;

/*
--------------------------------------------------------------------------
TCB - 16-bit Timer Type B
--------------------------------------------------------------------------
*/

/* 16-bit Timer Type B */
typedef struct TCB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control Register B */
    register8_t reserved_0x02;
    register8_t reserved_0x03;
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Value */
    _WORDREGISTER(CNT);  /* Count */
    _WORDREGISTER(CCMP);  /* Compare or Capture */
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
} TCB_t;

/* Clock Select select */
typedef enum TCB_CLKSEL_enum
{
    TCB_CLKSEL_CLKDIV1_gc = (0x00<<1),  /* CLK_PER (No Prescaling) */
    TCB_CLKSEL_CLKDIV2_gc = (0x01<<1),  /* CLK_PER/2 (From Prescaler) */
    TCB_CLKSEL_CLKTCA_gc = (0x02<<1),  /* Use Clock from TCA */
} TCB_CLKSEL_t;

/* Timer Mode select */
typedef enum TCB_CNTMODE_enum
{
    TCB_CNTMODE_INT_gc = (0x00<<0),  /* Periodic Interrupt */
    TCB_CNTMODE_TIMEOUT_gc = (0x01<<0),  /* Periodic Timeout */
    TCB_CNTMODE_CAPT_gc = (0x02<<0),  /* Input Capture Event */
    TCB_CNTMODE_FRQ_gc = (0x03<<0),  /* Input Capture Frequency measurement */
    TCB_CNTMODE_PW_gc = (0x04<<0),  /* Input Capture Pulse-Width measurement */
    TCB_CNTMODE_FRQPW_gc = (0x05<<0),  /* Input Capture Frequency and Pulse-Width measurement */
    TCB_CNTMODE_SINGLE_gc = (0x06<<0),  /* Single Shot */
    TCB_CNTMODE_PWM8_gc = (0x07<<0),  /* 8-bit PWM */
} TCB_CNTMODE_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t DUALCTRL;  /* Dual Control */
    register8_t DBGCTRL;  /* Debug Control Register */
    register8_t MCTRLA;  /* Master Control A */
    register8_t MCTRLB;  /* Master Control B */
    register8_t MSTATUS;  /* Master Status */
    register8_t MBAUD;  /* Master Baurd Rate Control */
    register8_t MADDR;  /* Master Address */
    register8_t MDATA;  /* Master Data */
    register8_t SCTRLA;  /* Slave Control A */
    register8_t SCTRLB;  /* Slave Control B */
    register8_t SSTATUS;  /* Slave Status */
    register8_t SADDR;  /* Slave Address */
    register8_t SDATA;  /* Slave Data */
    register8_t SADDRMASK;  /* Slave Address Mask */
    register8_t reserved_0x0F;
} TWI_t;

/* Acknowledge Action select */
typedef enum TWI_ACKACT_enum
{
    TWI_ACKACT_ACK_gc = (0x00<<2),  /* Send ACK */
    TWI_ACKACT_NACK_gc = (0x01<<2),  /* Send NACK */
} TWI_ACKACT_t;

/* Slave Address or Stop select */
typedef enum TWI_AP_enum
{
    TWI_AP_STOP_gc = (0x00<<0),  /* Stop condition generated APIF */
    TWI_AP_ADR_gc = (0x01<<0),  /* Address detection generated APIF */
} TWI_AP_t;

/* Bus State select */
typedef enum TWI_BUSSTATE_enum
{
    TWI_BUSSTATE_UNKNOWN_gc = (0x00<<0),  /* Unknown Bus State */
    TWI_BUSSTATE_IDLE_gc = (0x01<<0),  /* Bus is Idle */
    TWI_BUSSTATE_OWNER_gc = (0x02<<0),  /* This Module Controls The Bus */
    TWI_BUSSTATE_BUSY_gc = (0x03<<0),  /* The Bus is Busy */
} TWI_BUSSTATE_t;

/* Command select */
typedef enum TWI_MCMD_enum
{
    TWI_MCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_MCMD_REPSTART_gc = (0x01<<0),  /* Issue Repeated Start Condition */
    TWI_MCMD_RECVTRANS_gc = (0x02<<0),  /* Receive or Transmit Data, depending on DIR */
    TWI_MCMD_STOP_gc = (0x03<<0),  /* Issue Stop Condition */
} TWI_MCMD_t;

/* Command select */
typedef enum TWI_SCMD_enum
{
    TWI_SCMD_NOACT_gc = (0x00<<0),  /* No Action */
    TWI_SCMD_COMPTRANS_gc = (0x02<<0),  /* Used To Complete a Transaction */
    TWI_SCMD_RESPONSE_gc = (0x03<<0),  /* Used in Response to Address/Data Interrupt */
} TWI_SCMD_t;

/* SDA Hold Time select */
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<2),  /* SDA hold time off */
    TWI_SDAHOLD_50NS_gc = (0x01<<2),  /* Typical 50ns hold time */
    TWI_SDAHOLD_300NS_gc = (0x02<<2),  /* Typical 300ns hold time */
    TWI_SDAHOLD_500NS_gc = (0x03<<2),  /* Typical 500ns hold time */
} TWI_SDAHOLD_t;

/* SDA Setup Time select */
typedef enum TWI_SDASETUP_enum
{
    TWI_SDASETUP_4CYC_gc = (0x00<<4),  /* SDA setup time is 4 clock cycles */
    TWI_SDASETUP_8CYC_gc = (0x01<<4),  /* SDA setup time is 8 clock cycles */
} TWI_SDASETUP_t;

/* Inactive Bus Timeout select */
typedef enum TWI_TIMEOUT_enum
{
    TWI_TIMEOUT_DISABLED_gc = (0x00<<2),  /* Bus Timeout Disabled */
    TWI_TIMEOUT_50US_gc = (0x01<<2),  /* 50 Microseconds */
    TWI_TIMEOUT_100US_gc = (0x02<<2),  /* 100 Microseconds */
    TWI_TIMEOUT_200US_gc = (0x03<<2),  /* 200 Microseconds */
} TWI_TIMEOUT_t;

/*
--------------------------------------------------------------------------
USART - Universal Synchronous and Asynchronous Receiver and Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous and Asynchronous Receiver and Transmitter */
typedef struct USART_struct
{
    register8_t RXDATAL;  /* Receive Data Low Byte */
    register8_t RXDATAH;  /* Receive Data High Byte */
    register8_t TXDATAL;  /* Transmit Data Low Byte */
    register8_t TXDATAH;  /* Transmit Data High Byte */
    register8_t STATUS;  /* Status */
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    _WORDREGISTER(BAUD);  /* Baud Rate */
    register8_t CTRLD;  /* Control D */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t TXPLCTRL;  /* IRCOM Transmitter Pulse Length Control */
    register8_t RXPLCTRL;  /* IRCOM Receiver Pulse Length Control */
    register8_t reserved_0x0F;
} USART_t;

/* Auto Baud Window select */
typedef enum USART_ABW_enum
{
    USART_ABW_WDW0_gc = (0x00<<6),  /* 18% tolerance */
    USART_ABW_WDW1_gc = (0x01<<6),  /* 15% tolerance */
    USART_ABW_WDW2_gc = (0x02<<6),  /* 21% tolerance */
    USART_ABW_WDW3_gc = (0x03<<6),  /* 25% tolerance */
} USART_ABW_t;

/* Character Size select */
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc = (0x01<<0),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc = (0x02<<0),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc = (0x03<<0),  /* Character size: 8 bit */
    USART_CHSIZE_9BITL_gc = (0x06<<0),  /* Character size: 9 bit read low byte first */
    USART_CHSIZE_9BITH_gc = (0x07<<0),  /* Character size: 9 bit read high byte first */
} USART_CHSIZE_t;

/* Communication Mode select */
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),  /* Synchronous Mode */
    USART_CMODE_IRCOM_gc = (0x02<<6),  /* Infrared Communication */
    USART_CMODE_MSPI_gc = (0x03<<6),  /* Master SPI Mode */
} USART_CMODE_t;

/* Parity Mode select */
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),  /* No Parity */
    USART_PMODE_EVEN_gc = (0x02<<4),  /* Even Parity */
    USART_PMODE_ODD_gc = (0x03<<4),  /* Odd Parity */
} USART_PMODE_t;

/* RS485 Mode internal transmitter select */
typedef enum USART_RS485_enum
{
    USART_RS485_OFF_gc = (0x00<<0),  /* RS485 Mode disabled */
    USART_RS485_EXT_gc = (0x01<<0),  /* RS485 Mode External drive */
    USART_RS485_INT_gc = (0x02<<0),  /* RS485 Mode Internal drive */
} USART_RS485_t;

/* Receiver Mode select */
typedef enum USART_RXMODE_enum
{
    USART_RXMODE_NORMAL_gc = (0x00<<1),  /* Normal mode */
    USART_RXMODE_CLK2X_gc = (0x01<<1),  /* CLK2x mode */
    USART_RXMODE_GENAUTO_gc = (0x02<<1),  /* Generic autobaud mode */
    USART_RXMODE_LINAUTO_gc = (0x03<<1),  /* LIN constrained autobaud mode */
} USART_RXMODE_t;

/* Stop Bit Mode select */
typedef enum USART_SBMODE_enum
{
    USART_SBMODE_1BIT_gc = (0x00<<3),  /* 1 stop bit */
    USART_SBMODE_2BIT_gc = (0x01<<3),  /* 2 stop bits */
} USART_SBMODE_t;

/*
--------------------------------------------------------------------------
USERROW - User Row
--------------------------------------------------------------------------
*/

/* User Row */
typedef struct USERROW_struct
{
    register8_t USERROW0;  /* User Row Byte 0 */
    register8_t USERROW1;  /* User Row Byte 1 */
    register8_t USERROW2;  /* User Row Byte 2 */
    register8_t USERROW3;  /* User Row Byte 3 */
    register8_t USERROW4;  /* User Row Byte 4 */
    register8_t USERROW5;  /* User Row Byte 5 */
    register8_t USERROW6;  /* User Row Byte 6 */
    register8_t USERROW7;  /* User Row Byte 7 */
    register8_t USERROW8;  /* User Row Byte 8 */
    register8_t USERROW9;  /* User Row Byte 9 */
    register8_t USERROW10;  /* User Row Byte 10 */
    register8_t USERROW11;  /* User Row Byte 11 */
    register8_t USERROW12;  /* User Row Byte 12 */
    register8_t USERROW13;  /* User Row Byte 13 */
    register8_t USERROW14;  /* User Row Byte 14 */
    register8_t USERROW15;  /* User Row Byte 15 */
    register8_t USERROW16;  /* User Row Byte 16 */
    register8_t USERROW17;  /* User Row Byte 17 */
    register8_t USERROW18;  /* User Row Byte 18 */
    register8_t USERROW19;  /* User Row Byte 19 */
    register8_t USERROW20;  /* User Row Byte 20 */
    register8_t USERROW21;  /* User Row Byte 21 */
    register8_t USERROW22;  /* User Row Byte 22 */
    register8_t USERROW23;  /* User Row Byte 23 */
    register8_t USERROW24;  /* User Row Byte 24 */
    register8_t USERROW25;  /* User Row Byte 25 */
    register8_t USERROW26;  /* User Row Byte 26 */
    register8_t USERROW27;  /* User Row Byte 27 */
    register8_t USERROW28;  /* User Row Byte 28 */
    register8_t USERROW29;  /* User Row Byte 29 */
    register8_t USERROW30;  /* User Row Byte 30 */
    register8_t USERROW31;  /* User Row Byte 31 */
    register8_t USERROW32;  /* User Row Byte 32 */
    register8_t USERROW33;  /* User Row Byte 33 */
    register8_t USERROW34;  /* User Row Byte 34 */
    register8_t USERROW35;  /* User Row Byte 35 */
    register8_t USERROW36;  /* User Row Byte 36 */
    register8_t USERROW37;  /* User Row Byte 37 */
    register8_t USERROW38;  /* User Row Byte 38 */
    register8_t USERROW39;  /* User Row Byte 39 */
    register8_t USERROW40;  /* User Row Byte 40 */
    register8_t USERROW41;  /* User Row Byte 41 */
    register8_t USERROW42;  /* User Row Byte 42 */
    register8_t USERROW43;  /* User Row Byte 43 */
    register8_t USERROW44;  /* User Row Byte 44 */
    register8_t USERROW45;  /* User Row Byte 45 */
    register8_t USERROW46;  /* User Row Byte 46 */
    register8_t USERROW47;  /* User Row Byte 47 */
    register8_t USERROW48;  /* User Row Byte 48 */
    register8_t USERROW49;  /* User Row Byte 49 */
    register8_t USERROW50;  /* User Row Byte 50 */
    register8_t USERROW51;  /* User Row Byte 51 */
    register8_t USERROW52;  /* User Row Byte 52 */
    register8_t USERROW53;  /* User Row Byte 53 */
    register8_t USERROW54;  /* User Row Byte 54 */
    register8_t USERROW55;  /* User Row Byte 55 */
    register8_t USERROW56;  /* User Row Byte 56 */
    register8_t USERROW57;  /* User Row Byte 57 */
    register8_t USERROW58;  /* User Row Byte 58 */
    register8_t USERROW59;  /* User Row Byte 59 */
    register8_t USERROW60;  /* User Row Byte 60 */
    register8_t USERROW61;  /* User Row Byte 61 */
    register8_t USERROW62;  /* User Row Byte 62 */
    register8_t USERROW63;  /* User Row Byte 63 */
} USERROW_t;


/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Ports */
typedef struct VPORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t OUT;  /* Output Value */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
} VPORT_t;


/*
--------------------------------------------------------------------------
VREF - Voltage reference
--------------------------------------------------------------------------
*/

/* Voltage reference */
typedef struct VREF_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
} VREF_t;

/* AC0 reference select select */
typedef enum VREF_AC0REFSEL_enum
{
    VREF_AC0REFSEL_0V55_gc = (0x00<<0),  /* Voltage reference at 0.55V */
    VREF_AC0REFSEL_1V1_gc = (0x01<<0),  /* Voltage reference at 1.1V */
    VREF_AC0REFSEL_2V5_gc = (0x02<<0),  /* Voltage reference at 2.5V */
    VREF_AC0REFSEL_4V34_gc = (0x03<<0),  /* Voltage reference at 4.34V */
    VREF_AC0REFSEL_1V5_gc = (0x04<<0),  /* Voltage reference at 1.5V */
    VREF_AC0REFSEL_AVDD_gc = (0x07<<0),  /* AVDD as Voltage reference */
} VREF_AC0REFSEL_t;

/* ADC0 reference select select */
typedef enum VREF_ADC0REFSEL_enum
{
    VREF_ADC0REFSEL_0V55_gc = (0x00<<4),  /* Voltage reference at 0.55V */
    VREF_ADC0REFSEL_1V1_gc = (0x01<<4),  /* Voltage reference at 1.1V */
    VREF_ADC0REFSEL_2V5_gc = (0x02<<4),  /* Voltage reference at 2.5V */
    VREF_ADC0REFSEL_4V34_gc = (0x03<<4),  /* Voltage reference at 4.34V */
    VREF_ADC0REFSEL_1V5_gc = (0x04<<4),  /* Voltage reference at 1.5V */
} VREF_ADC0REFSEL_t;

/*
--------------------------------------------------------------------------
WDT - Watch-Dog Timer
--------------------------------------------------------------------------
*/

/* Watch-Dog Timer */
typedef struct WDT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
} WDT_t;

/* Period select */
typedef enum WDT_PERIOD_enum
{
    WDT_PERIOD_OFF_gc = (0x00<<0),  /* Off */
    WDT_PERIOD_8CLK_gc = (0x01<<0),  /* 8 cycles (8ms) */
    WDT_PERIOD_16CLK_gc = (0x02<<0),  /* 16 cycles (16ms) */
    WDT_PERIOD_32CLK_gc = (0x03<<0),  /* 32 cycles (32ms) */
    WDT_PERIOD_64CLK_gc = (0x04<<0),  /* 64 cycles (64ms) */
    WDT_PERIOD_128CLK_gc = (0x05<<0),  /* 128 cycles (0.128s) */
    WDT_PERIOD_256CLK_gc = (0x06<<0),  /* 256 cycles (0.256s) */
    WDT_PERIOD_512CLK_gc = (0x07<<0),  /* 512 cycles (0.512s) */
    WDT_PERIOD_1KCLK_gc = (0x08<<0),  /* 1K cycles (1.0s) */
    WDT_PERIOD_2KCLK_gc = (0x09<<0),  /* 2K cycles (2.0s) */
    WDT_PERIOD_4KCLK_gc = (0x0A<<0),  /* 4K cycles (4.1s) */
    WDT_PERIOD_8KCLK_gc = (0x0B<<0),  /* 8K cycles (8.2s) */
} WDT_PERIOD_t;

/* Window select */
typedef enum WDT_WINDOW_enum
{
    WDT_WINDOW_OFF_gc = (0x00<<4),  /* Off */
    WDT_WINDOW_8CLK_gc = (0x01<<4),  /* 8 cycles (8ms) */
    WDT_WINDOW_16CLK_gc = (0x02<<4),  /* 16 cycles (16ms) */
    WDT_WINDOW_32CLK_gc = (0x03<<4),  /* 32 cycles (32ms) */
    WDT_WINDOW_64CLK_gc = (0x04<<4),  /* 64 cycles (64ms) */
    WDT_WINDOW_128CLK_gc = (0x05<<4),  /* 128 cycles (0.128s) */
    WDT_WINDOW_256CLK_gc = (0x06<<4),  /* 256 cycles (0.256s) */
    WDT_WINDOW_512CLK_gc = (0x07<<4),  /* 512 cycles (0.512s) */
    WDT_WINDOW_1KCLK_gc = (0x08<<4),  /* 1K cycles (1.0s) */
    WDT_WINDOW_2KCLK_gc = (0x09<<4),  /* 2K cycles (2.0s) */
    WDT_WINDOW_4KCLK_gc = (0x0A<<4),  /* 4K cycles (4.1s) */
    WDT_WINDOW_8KCLK_gc = (0x0B<<4),  /* 8K cycles (8.2s) */
} WDT_WINDOW_t;
/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORTA              (*(VPORT_t *) 0x0000) /* Virtual Ports */
#define VPORTB              (*(VPORT_t *) 0x0004) /* Virtual Ports */
#define VPORTC              (*(VPORT_t *) 0x0008) /* Virtual Ports */
#define VPORTD              (*(VPORT_t *) 0x000C) /* Virtual Ports */
#define VPORTE              (*(VPORT_t *) 0x0010) /* Virtual Ports */
#define VPORTF              (*(VPORT_t *) 0x0014) /* Virtual Ports */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0060) /* Clock controller */
#define BOD                   (*(BOD_t *) 0x0080) /* Bod interface */
#define VREF                 (*(VREF_t *) 0x00A0) /* Voltage reference */
#define WDT                   (*(WDT_t *) 0x0100) /* Watch-Dog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0110) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0120) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define EVSYS               (*(EVSYS_t *) 0x0180) /* Event System */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTB                (*(PORT_t *) 0x0420) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define PORTD                (*(PORT_t *) 0x0460) /* I/O Ports */
#define PORTE                (*(PORT_t *) 0x0480) /* I/O Ports */
#define PORTF                (*(PORT_t *) 0x04A0) /* I/O Ports */
#define PORTMUX           (*(PORTMUX_t *) 0x05E0) /* Port Multiplexer */
#define ADC0                  (*(ADC_t *) 0x0600) /* Analog to Digital Converter */
#define AC0                    (*(AC_t *) 0x0680) /* Analog Comparator */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1              (*(USART_t *) 0x0820) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART2              (*(USART_t *) 0x0840) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x08A0) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x08C0) /* Serial Peripheral Interface */
#define TCA0                  (*(TCA_t *) 0x0A00) /* 16-bit Timer/Counter Type A */
#define TCB0                  (*(TCB_t *) 0x0A80) /* 16-bit Timer Type B */
#define TCB1                  (*(TCB_t *) 0x0A90) /* 16-bit Timer Type B */
#define TCB2                  (*(TCB_t *) 0x0AA0) /* 16-bit Timer Type B */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define SIGROW             (*(SIGROW_t *) 0x1100) /* Signature row */
#define FUSE                 (*(FUSE_t *) 0x1280) /* Fuses */
#define LOCKBIT           (*(LOCKBIT_t *) 0x128A) /* Lockbit */
#define USERROW           (*(USERROW_t *) 0x1300) /* User Row */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* VPORT (VPORTA) - Virtual Ports */
#define VPORTA_DIR  _SFR_MEM8(0x0000)
#define VPORTA_OUT  _SFR_MEM8(0x0001)
#define VPORTA_IN  _SFR_MEM8(0x0002)
#define VPORTA_INTFLAGS  _SFR_MEM8(0x0003)


/* VPORT (VPORTB) - Virtual Ports */
#define VPORTB_DIR  _SFR_MEM8(0x0004)
#define VPORTB_OUT  _SFR_MEM8(0x0005)
#define VPORTB_IN  _SFR_MEM8(0x0006)
#define VPORTB_INTFLAGS  _SFR_MEM8(0x0007)


/* VPORT (VPORTC) - Virtual Ports */
#define VPORTC_DIR  _SFR_MEM8(0x0008)
#define VPORTC_OUT  _SFR_MEM8(0x0009)
#define VPORTC_IN  _SFR_MEM8(0x000A)
#define VPORTC_INTFLAGS  _SFR_MEM8(0x000B)


/* VPORT (VPORTD) - Virtual Ports */
#define VPORTD_DIR  _SFR_MEM8(0x000C)
#define VPORTD_OUT  _SFR_MEM8(0x000D)
#define VPORTD_IN  _SFR_MEM8(0x000E)
#define VPORTD_INTFLAGS  _SFR_MEM8(0x000F)


/* VPORT (VPORTE) - Virtual Ports */
#define VPORTE_DIR  _SFR_MEM8(0x0010)
#define VPORTE_OUT  _SFR_MEM8(0x0011)
#define VPORTE_IN  _SFR_MEM8(0x0012)
#define VPORTE_INTFLAGS  _SFR_MEM8(0x0013)


/* VPORT (VPORTF) - Virtual Ports */
#define VPORTF_DIR  _SFR_MEM8(0x0014)
#define VPORTF_OUT  _SFR_MEM8(0x0015)
#define VPORTF_IN  _SFR_MEM8(0x0016)
#define VPORTF_INTFLAGS  _SFR_MEM8(0x0017)


/* GPIO - General Purpose IO */
#define GPIO_GPIOR0  _SFR_MEM8(0x001C)
#define GPIO_GPIOR1  _SFR_MEM8(0x001D)
#define GPIO_GPIOR2  _SFR_MEM8(0x001E)
#define GPIO_GPIOR3  _SFR_MEM8(0x001F)


/* Deprecated */
#define GPIO_GPIO0  _SFR_MEM8(0x001C)
#define GPIO_GPIO1  _SFR_MEM8(0x001D)
#define GPIO_GPIO2  _SFR_MEM8(0x001E)
#define GPIO_GPIO3  _SFR_MEM8(0x001F)


/* CPU - CPU */
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* RSTCTRL - Reset controller */
#define RSTCTRL_RSTFR  _SFR_MEM8(0x0040)
#define RSTCTRL_SWRR  _SFR_MEM8(0x0041)


/* SLPCTRL - Sleep Controller */
#define SLPCTRL_CTRLA  _SFR_MEM8(0x0050)


/* CLKCTRL - Clock controller */
#define CLKCTRL_MCLKCTRLA  _SFR_MEM8(0x0060)
#define CLKCTRL_MCLKCTRLB  _SFR_MEM8(0x0061)
#define CLKCTRL_MCLKLOCK  _SFR_MEM8(0x0062)
#define CLKCTRL_MCLKSTATUS  _SFR_MEM8(0x0063)
#define CLKCTRL_OSC20MCTRLA  _SFR_MEM8(0x0070)
#define CLKCTRL_OSC20MCALIBA  _SFR_MEM8(0x0071)
#define CLKCTRL_OSC20MCALIBB  _SFR_MEM8(0x0072)
#define CLKCTRL_OSC32KCTRLA  _SFR_MEM8(0x0078)
#define CLKCTRL_XOSC32KCTRLA  _SFR_MEM8(0x007C)


/* BOD - Bod interface */
#define BOD_CTRLA  _SFR_MEM8(0x0080)
#define BOD_CTRLB  _SFR_MEM8(0x0081)
#define BOD_VLMCTRLA  _SFR_MEM8(0x0088)
#define BOD_INTCTRL  _SFR_MEM8(0x0089)
#define BOD_INTFLAGS  _SFR_MEM8(0x008A)
#define BOD_STATUS  _SFR_MEM8(0x008B)


/* VREF - Voltage reference */
#define VREF_CTRLA  _SFR_MEM8(0x00A0)
#define VREF_CTRLB  _SFR_MEM8(0x00A1)


/* WDT - Watch-Dog Timer */
#define WDT_CTRLA  _SFR_MEM8(0x0100)
#define WDT_STATUS  _SFR_MEM8(0x0101)


/* CPUINT - Interrupt Controller */
#define CPUINT_CTRLA  _SFR_MEM8(0x0110)
#define CPUINT_STATUS  _SFR_MEM8(0x0111)
#define CPUINT_LVL0PRI  _SFR_MEM8(0x0112)
#define CPUINT_LVL1VEC  _SFR_MEM8(0x0113)


/* CRCSCAN - CRCSCAN */
#define CRCSCAN_CTRLA  _SFR_MEM8(0x0120)
#define CRCSCAN_CTRLB  _SFR_MEM8(0x0121)
#define CRCSCAN_STATUS  _SFR_MEM8(0x0122)


/* RTC - Real-Time Counter */
#define RTC_CTRLA  _SFR_MEM8(0x0140)
#define RTC_STATUS  _SFR_MEM8(0x0141)
#define RTC_INTCTRL  _SFR_MEM8(0x0142)
#define RTC_INTFLAGS  _SFR_MEM8(0x0143)
#define RTC_TEMP  _SFR_MEM8(0x0144)
#define RTC_DBGCTRL  _SFR_MEM8(0x0145)
#define RTC_CALIB  _SFR_MEM8(0x0146)
#define RTC_CLKSEL  _SFR_MEM8(0x0147)
#define RTC_CNT  _SFR_MEM16(0x0148)
#define RTC_CNTL  _SFR_MEM8(0x0148)
#define RTC_CNTH  _SFR_MEM8(0x0149)
#define RTC_PER  _SFR_MEM16(0x014A)
#define RTC_PERL  _SFR_MEM8(0x014A)
#define RTC_PERH  _SFR_MEM8(0x014B)
#define RTC_CMP  _SFR_MEM16(0x014C)
#define RTC_CMPL  _SFR_MEM8(0x014C)
#define RTC_CMPH  _SFR_MEM8(0x014D)
#define RTC_PITCTRLA  _SFR_MEM8(0x0150)
#define RTC_PITSTATUS  _SFR_MEM8(0x0151)
#define RTC_PITINTCTRL  _SFR_MEM8(0x0152)
#define RTC_PITINTFLAGS  _SFR_MEM8(0x0153)
#define RTC_PITDBGCTRL  _SFR_MEM8(0x0155)


/* EVSYS - Event System */
#define EVSYS_STROBE  _SFR_MEM8(0x0180)
#define EVSYS_CHANNEL0  _SFR_MEM8(0x0190)
#define EVSYS_CHANNEL1  _SFR_MEM8(0x0191)
#define EVSYS_CHANNEL2  _SFR_MEM8(0x0192)
#define EVSYS_CHANNEL3  _SFR_MEM8(0x0193)
#define EVSYS_CHANNEL4  _SFR_MEM8(0x0194)
#define EVSYS_CHANNEL5  _SFR_MEM8(0x0195)
#define EVSYS_USERCCLLUT0A  _SFR_MEM8(0x01A0)
#define EVSYS_USERCCLLUT0B  _SFR_MEM8(0x01A1)
#define EVSYS_USERCCLLUT1A  _SFR_MEM8(0x01A2)
#define EVSYS_USERCCLLUT1B  _SFR_MEM8(0x01A3)
#define EVSYS_USERCCLLUT2A  _SFR_MEM8(0x01A4)
#define EVSYS_USERCCLLUT2B  _SFR_MEM8(0x01A5)
#define EVSYS_USERCCLLUT3A  _SFR_MEM8(0x01A6)
#define EVSYS_USERCCLLUT3B  _SFR_MEM8(0x01A7)
#define EVSYS_USERADC0  _SFR_MEM8(0x01A8)
#define EVSYS_USEREVOUTA  _SFR_MEM8(0x01A9)
#define EVSYS_USEREVOUTB  _SFR_MEM8(0x01AA)
#define EVSYS_USEREVOUTC  _SFR_MEM8(0x01AB)
#define EVSYS_USEREVOUTD  _SFR_MEM8(0x01AC)
#define EVSYS_USEREVOUTE  _SFR_MEM8(0x01AD)
#define EVSYS_USEREVOUTF  _SFR_MEM8(0x01AE)
#define EVSYS_USERUSART0  _SFR_MEM8(0x01AF)
#define EVSYS_USERUSART1  _SFR_MEM8(0x01B0)
#define EVSYS_USERUSART2  _SFR_MEM8(0x01B1)
#define EVSYS_USERUSART3  _SFR_MEM8(0x01B2)
#define EVSYS_USERTCA0  _SFR_MEM8(0x01B3)
#define EVSYS_USERTCB0  _SFR_MEM8(0x01B4)
#define EVSYS_USERTCB1  _SFR_MEM8(0x01B5)
#define EVSYS_USERTCB2  _SFR_MEM8(0x01B6)
#define EVSYS_USERTCB3  _SFR_MEM8(0x01B7)


/* CCL - Configurable Custom Logic */
#define CCL_CTRLA  _SFR_MEM8(0x01C0)
#define CCL_SEQCTRL0  _SFR_MEM8(0x01C1)
#define CCL_SEQCTRL1  _SFR_MEM8(0x01C2)
#define CCL_INTCTRL0  _SFR_MEM8(0x01C5)
#define CCL_INTFLAGS  _SFR_MEM8(0x01C7)
#define CCL_LUT0CTRLA  _SFR_MEM8(0x01C8)
#define CCL_LUT0CTRLB  _SFR_MEM8(0x01C9)
#define CCL_LUT0CTRLC  _SFR_MEM8(0x01CA)
#define CCL_TRUTH0  _SFR_MEM8(0x01CB)
#define CCL_LUT1CTRLA  _SFR_MEM8(0x01CC)
#define CCL_LUT1CTRLB  _SFR_MEM8(0x01CD)
#define CCL_LUT1CTRLC  _SFR_MEM8(0x01CE)
#define CCL_TRUTH1  _SFR_MEM8(0x01CF)
#define CCL_LUT2CTRLA  _SFR_MEM8(0x01D0)
#define CCL_LUT2CTRLB  _SFR_MEM8(0x01D1)
#define CCL_LUT2CTRLC  _SFR_MEM8(0x01D2)
#define CCL_TRUTH2  _SFR_MEM8(0x01D3)
#define CCL_LUT3CTRLA  _SFR_MEM8(0x01D4)
#define CCL_LUT3CTRLB  _SFR_MEM8(0x01D5)
#define CCL_LUT3CTRLC  _SFR_MEM8(0x01D6)
#define CCL_TRUTH3  _SFR_MEM8(0x01D7)


/* PORT (PORTA) - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0400)
#define PORTA_DIRSET  _SFR_MEM8(0x0401)
#define PORTA_DIRCLR  _SFR_MEM8(0x0402)
#define PORTA_DIRTGL  _SFR_MEM8(0x0403)
#define PORTA_OUT  _SFR_MEM8(0x0404)
#define PORTA_OUTSET  _SFR_MEM8(0x0405)
#define PORTA_OUTCLR  _SFR_MEM8(0x0406)
#define PORTA_OUTTGL  _SFR_MEM8(0x0407)
#define PORTA_IN  _SFR_MEM8(0x0408)
#define PORTA_INTFLAGS  _SFR_MEM8(0x0409)
#define PORTA_PORTCTRL  _SFR_MEM8(0x040A)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0410)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0411)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0412)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0413)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0414)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0415)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0416)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0417)


/* PORT (PORTB) - I/O Ports */
#define PORTB_DIR  _SFR_MEM8(0x0420)
#define PORTB_DIRSET  _SFR_MEM8(0x0421)
#define PORTB_DIRCLR  _SFR_MEM8(0x0422)
#define PORTB_DIRTGL  _SFR_MEM8(0x0423)
#define PORTB_OUT  _SFR_MEM8(0x0424)
#define PORTB_OUTSET  _SFR_MEM8(0x0425)
#define PORTB_OUTCLR  _SFR_MEM8(0x0426)
#define PORTB_OUTTGL  _SFR_MEM8(0x0427)
#define PORTB_IN  _SFR_MEM8(0x0428)
#define PORTB_INTFLAGS  _SFR_MEM8(0x0429)
#define PORTB_PORTCTRL  _SFR_MEM8(0x042A)
#define PORTB_PIN0CTRL  _SFR_MEM8(0x0430)
#define PORTB_PIN1CTRL  _SFR_MEM8(0x0431)
#define PORTB_PIN2CTRL  _SFR_MEM8(0x0432)
#define PORTB_PIN3CTRL  _SFR_MEM8(0x0433)
#define PORTB_PIN4CTRL  _SFR_MEM8(0x0434)
#define PORTB_PIN5CTRL  _SFR_MEM8(0x0435)
#define PORTB_PIN6CTRL  _SFR_MEM8(0x0436)
#define PORTB_PIN7CTRL  _SFR_MEM8(0x0437)


/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0440)
#define PORTC_DIRSET  _SFR_MEM8(0x0441)
#define PORTC_DIRCLR  _SFR_MEM8(0x0442)
#define PORTC_DIRTGL  _SFR_MEM8(0x0443)
#define PORTC_OUT  _SFR_MEM8(0x0444)
#define PORTC_OUTSET  _SFR_MEM8(0x0445)
#define PORTC_OUTCLR  _SFR_MEM8(0x0446)
#define PORTC_OUTTGL  _SFR_MEM8(0x0447)
#define PORTC_IN  _SFR_MEM8(0x0448)
#define PORTC_INTFLAGS  _SFR_MEM8(0x0449)
#define PORTC_PORTCTRL  _SFR_MEM8(0x044A)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0450)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0451)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0452)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0453)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0454)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0455)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0456)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0457)


/* PORT (PORTD) - I/O Ports */
#define PORTD_DIR  _SFR_MEM8(0x0460)
#define PORTD_DIRSET  _SFR_MEM8(0x0461)
#define PORTD_DIRCLR  _SFR_MEM8(0x0462)
#define PORTD_DIRTGL  _SFR_MEM8(0x0463)
#define PORTD_OUT  _SFR_MEM8(0x0464)
#define PORTD_OUTSET  _SFR_MEM8(0x0465)
#define PORTD_OUTCLR  _SFR_MEM8(0x0466)
#define PORTD_OUTTGL  _SFR_MEM8(0x0467)
#define PORTD_IN  _SFR_MEM8(0x0468)
#define PORTD_INTFLAGS  _SFR_MEM8(0x0469)
#define PORTD_PORTCTRL  _SFR_MEM8(0x046A)
#define PORTD_PIN0CTRL  _SFR_MEM8(0x0470)
#define PORTD_PIN1CTRL  _SFR_MEM8(0x0471)
#define PORTD_PIN2CTRL  _SFR_MEM8(0x0472)
#define PORTD_PIN3CTRL  _SFR_MEM8(0x0473)
#define PORTD_PIN4CTRL  _SFR_MEM8(0x0474)
#define PORTD_PIN5CTRL  _SFR_MEM8(0x0475)
#define PORTD_PIN6CTRL  _SFR_MEM8(0x0476)
#define PORTD_PIN7CTRL  _SFR_MEM8(0x0477)


/* PORT (PORTE) - I/O Ports */
#define PORTE_DIR  _SFR_MEM8(0x0480)
#define PORTE_DIRSET  _SFR_MEM8(0x0481)
#define PORTE_DIRCLR  _SFR_MEM8(0x0482)
#define PORTE_DIRTGL  _SFR_MEM8(0x0483)
#define PORTE_OUT  _SFR_MEM8(0x0484)
#define PORTE_OUTSET  _SFR_MEM8(0x0485)
#define PORTE_OUTCLR  _SFR_MEM8(0x0486)
#define PORTE_OUTTGL  _SFR_MEM8(0x0487)
#define PORTE_IN  _SFR_MEM8(0x0488)
#define PORTE_INTFLAGS  _SFR_MEM8(0x0489)
#define PORTE_PORTCTRL  _SFR_MEM8(0x048A)
#define PORTE_PIN0CTRL  _SFR_MEM8(0x0490)
#define PORTE_PIN1CTRL  _SFR_MEM8(0x0491)
#define PORTE_PIN2CTRL  _SFR_MEM8(0x0492)
#define PORTE_PIN3CTRL  _SFR_MEM8(0x0493)
#define PORTE_PIN4CTRL  _SFR_MEM8(0x0494)
#define PORTE_PIN5CTRL  _SFR_MEM8(0x0495)
#define PORTE_PIN6CTRL  _SFR_MEM8(0x0496)
#define PORTE_PIN7CTRL  _SFR_MEM8(0x0497)


/* PORT (PORTF) - I/O Ports */
#define PORTF_DIR  _SFR_MEM8(0x04A0)
#define PORTF_DIRSET  _SFR_MEM8(0x04A1)
#define PORTF_DIRCLR  _SFR_MEM8(0x04A2)
#define PORTF_DIRTGL  _SFR_MEM8(0x04A3)
#define PORTF_OUT  _SFR_MEM8(0x04A4)
#define PORTF_OUTSET  _SFR_MEM8(0x04A5)
#define PORTF_OUTCLR  _SFR_MEM8(0x04A6)
#define PORTF_OUTTGL  _SFR_MEM8(0x04A7)
#define PORTF_IN  _SFR_MEM8(0x04A8)
#define PORTF_INTFLAGS  _SFR_MEM8(0x04A9)
#define PORTF_PORTCTRL  _SFR_MEM8(0x04AA)
#define PORTF_PIN0CTRL  _SFR_MEM8(0x04B0)
#define PORTF_PIN1CTRL  _SFR_MEM8(0x04B1)
#define PORTF_PIN2CTRL  _SFR_MEM8(0x04B2)
#define PORTF_PIN3CTRL  _SFR_MEM8(0x04B3)
#define PORTF_PIN4CTRL  _SFR_MEM8(0x04B4)
#define PORTF_PIN5CTRL  _SFR_MEM8(0x04B5)
#define PORTF_PIN6CTRL  _SFR_MEM8(0x04B6)
#define PORTF_PIN7CTRL  _SFR_MEM8(0x04B7)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_EVSYSROUTEA  _SFR_MEM8(0x05E0)
#define PORTMUX_CCLROUTEA  _SFR_MEM8(0x05E1)
#define PORTMUX_USARTROUTEA  _SFR_MEM8(0x05E2)
#define PORTMUX_TWISPIROUTEA  _SFR_MEM8(0x05E3)
#define PORTMUX_TCAROUTEA  _SFR_MEM8(0x05E4)
#define PORTMUX_TCBROUTEA  _SFR_MEM8(0x05E5)


/* ADC (ADC0) - Analog to Digital Converter */
#define ADC0_CTRLA  _SFR_MEM8(0x0600)
#define ADC0_CTRLB  _SFR_MEM8(0x0601)
#define ADC0_CTRLC  _SFR_MEM8(0x0602)
#define ADC0_CTRLD  _SFR_MEM8(0x0603)
#define ADC0_CTRLE  _SFR_MEM8(0x0604)
#define ADC0_SAMPCTRL  _SFR_MEM8(0x0605)
#define ADC0_MUXPOS  _SFR_MEM8(0x0606)
#define ADC0_COMMAND  _SFR_MEM8(0x0608)
#define ADC0_EVCTRL  _SFR_MEM8(0x0609)
#define ADC0_INTCTRL  _SFR_MEM8(0x060A)
#define ADC0_INTFLAGS  _SFR_MEM8(0x060B)
#define ADC0_DBGCTRL  _SFR_MEM8(0x060C)
#define ADC0_TEMP  _SFR_MEM8(0x060D)
#define ADC0_RES  _SFR_MEM16(0x0610)
#define ADC0_RESL  _SFR_MEM8(0x0610)
#define ADC0_RESH  _SFR_MEM8(0x0611)
#define ADC0_WINLT  _SFR_MEM16(0x0612)
#define ADC0_WINLTL  _SFR_MEM8(0x0612)
#define ADC0_WINLTH  _SFR_MEM8(0x0613)
#define ADC0_WINHT  _SFR_MEM16(0x0614)
#define ADC0_WINHTL  _SFR_MEM8(0x0614)
#define ADC0_WINHTH  _SFR_MEM8(0x0615)
#define ADC0_CALIB  _SFR_MEM8(0x0616)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0680)
#define AC0_MUXCTRLA  _SFR_MEM8(0x0682)
#define AC0_DACREF  _SFR_MEM8(0x0684)
#define AC0_INTCTRL  _SFR_MEM8(0x0686)
#define AC0_STATUS  _SFR_MEM8(0x0687)


/* USART (USART0) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART0_RXDATAL  _SFR_MEM8(0x0800)
#define USART0_RXDATAH  _SFR_MEM8(0x0801)
#define USART0_TXDATAL  _SFR_MEM8(0x0802)
#define USART0_TXDATAH  _SFR_MEM8(0x0803)
#define USART0_STATUS  _SFR_MEM8(0x0804)
#define USART0_CTRLA  _SFR_MEM8(0x0805)
#define USART0_CTRLB  _SFR_MEM8(0x0806)
#define USART0_CTRLC  _SFR_MEM8(0x0807)
#define USART0_BAUD  _SFR_MEM16(0x0808)
#define USART0_BAUDL  _SFR_MEM8(0x0808)
#define USART0_BAUDH  _SFR_MEM8(0x0809)
#define USART0_CTRLD  _SFR_MEM8(0x080A)
#define USART0_DBGCTRL  _SFR_MEM8(0x080B)
#define USART0_EVCTRL  _SFR_MEM8(0x080C)
#define USART0_TXPLCTRL  _SFR_MEM8(0x080D)
#define USART0_RXPLCTRL  _SFR_MEM8(0x080E)


/* USART (USART1) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1_RXDATAL  _SFR_MEM8(0x0820)
#define USART1_RXDATAH  _SFR_MEM8(0x0821)
#define USART1_TXDATAL  _SFR_MEM8(0x0822)
#define USART1_TXDATAH  _SFR_MEM8(0x0823)
#define USART1_STATUS  _SFR_MEM8(0x0824)
#define USART1_CTRLA  _SFR_MEM8(0x0825)
#define USART1_CTRLB  _SFR_MEM8(0x0826)
#define USART1_CTRLC  _SFR_MEM8(0x0827)
#define USART1_BAUD  _SFR_MEM16(0x0828)
#define USART1_BAUDL  _SFR_MEM8(0x0828)
#define USART1_BAUDH  _SFR_MEM8(0x0829)
#define USART1_CTRLD  _SFR_MEM8(0x082A)
#define USART1_DBGCTRL  _SFR_MEM8(0x082B)
#define USART1_EVCTRL  _SFR_MEM8(0x082C)
#define USART1_TXPLCTRL  _SFR_MEM8(0x082D)
#define USART1_RXPLCTRL  _SFR_MEM8(0x082E)


/* USART (USART2) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART2_RXDATAL  _SFR_MEM8(0x0840)
#define USART2_RXDATAH  _SFR_MEM8(0x0841)
#define USART2_TXDATAL  _SFR_MEM8(0x0842)
#define USART2_TXDATAH  _SFR_MEM8(0x0843)
#define USART2_STATUS  _SFR_MEM8(0x0844)
#define USART2_CTRLA  _SFR_MEM8(0x0845)
#define USART2_CTRLB  _SFR_MEM8(0x0846)
#define USART2_CTRLC  _SFR_MEM8(0x0847)
#define USART2_BAUD  _SFR_MEM16(0x0848)
#define USART2_BAUDL  _SFR_MEM8(0x0848)
#define USART2_BAUDH  _SFR_MEM8(0x0849)
#define USART2_CTRLD  _SFR_MEM8(0x084A)
#define USART2_DBGCTRL  _SFR_MEM8(0x084B)
#define USART2_EVCTRL  _SFR_MEM8(0x084C)
#define USART2_TXPLCTRL  _SFR_MEM8(0x084D)
#define USART2_RXPLCTRL  _SFR_MEM8(0x084E)


/* TWI (TWI0) - Two-Wire Interface */
#define TWI0_CTRLA  _SFR_MEM8(0x08A0)
#define TWI0_DUALCTRL  _SFR_MEM8(0x08A1)
#define TWI0_DBGCTRL  _SFR_MEM8(0x08A2)
#define TWI0_MCTRLA  _SFR_MEM8(0x08A3)
#define TWI0_MCTRLB  _SFR_MEM8(0x08A4)
#define TWI0_MSTATUS  _SFR_MEM8(0x08A5)
#define TWI0_MBAUD  _SFR_MEM8(0x08A6)
#define TWI0_MADDR  _SFR_MEM8(0x08A7)
#define TWI0_MDATA  _SFR_MEM8(0x08A8)
#define TWI0_SCTRLA  _SFR_MEM8(0x08A9)
#define TWI0_SCTRLB  _SFR_MEM8(0x08AA)
#define TWI0_SSTATUS  _SFR_MEM8(0x08AB)
#define TWI0_SADDR  _SFR_MEM8(0x08AC)
#define TWI0_SDATA  _SFR_MEM8(0x08AD)
#define TWI0_SADDRMASK  _SFR_MEM8(0x08AE)


/* SPI (SPI0) - Serial Peripheral Interface */
#define SPI0_CTRLA  _SFR_MEM8(0x08C0)
#define SPI0_CTRLB  _SFR_MEM8(0x08C1)
#define SPI0_INTCTRL  _SFR_MEM8(0x08C2)
#define SPI0_INTFLAGS  _SFR_MEM8(0x08C3)
#define SPI0_DATA  _SFR_MEM8(0x08C4)


/* TCA (TCA0) - 16-bit Timer/Counter Type A */
#define TCA0_SINGLE_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SINGLE_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SINGLE_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SINGLE_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SINGLE_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SINGLE_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SINGLE_CTRLFCLR  _SFR_MEM8(0x0A06)
#define TCA0_SINGLE_CTRLFSET  _SFR_MEM8(0x0A07)
#define TCA0_SINGLE_EVCTRL  _SFR_MEM8(0x0A09)
#define TCA0_SINGLE_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SINGLE_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SINGLE_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SINGLE_TEMP  _SFR_MEM8(0x0A0F)
#define TCA0_SINGLE_CNT  _SFR_MEM16(0x0A20)
#define TCA0_SINGLE_PER  _SFR_MEM16(0x0A26)
#define TCA0_SINGLE_CMP0  _SFR_MEM16(0x0A28)
#define TCA0_SINGLE_CMP1  _SFR_MEM16(0x0A2A)
#define TCA0_SINGLE_CMP2  _SFR_MEM16(0x0A2C)
#define TCA0_SINGLE_PERBUF  _SFR_MEM16(0x0A36)
#define TCA0_SINGLE_CMP0BUF  _SFR_MEM16(0x0A38)
#define TCA0_SINGLE_CMP1BUF  _SFR_MEM16(0x0A3A)
#define TCA0_SINGLE_CMP2BUF  _SFR_MEM16(0x0A3C)


#define TCA0_SPLIT_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SPLIT_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SPLIT_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SPLIT_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SPLIT_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SPLIT_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SPLIT_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SPLIT_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SPLIT_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SPLIT_LCNT  _SFR_MEM8(0x0A20)
#define TCA0_SPLIT_HCNT  _SFR_MEM8(0x0A21)
#define TCA0_SPLIT_LPER  _SFR_MEM8(0x0A26)
#define TCA0_SPLIT_HPER  _SFR_MEM8(0x0A27)
#define TCA0_SPLIT_LCMP0  _SFR_MEM8(0x0A28)
#define TCA0_SPLIT_HCMP0  _SFR_MEM8(0x0A29)
#define TCA0_SPLIT_LCMP1  _SFR_MEM8(0x0A2A)
#define TCA0_SPLIT_HCMP1  _SFR_MEM8(0x0A2B)
#define TCA0_SPLIT_LCMP2  _SFR_MEM8(0x0A2C)
#define TCA0_SPLIT_HCMP2  _SFR_MEM8(0x0A2D)




/* TCB (TCB0) - 16-bit Timer Type B */
#define TCB0_CTRLA  _SFR_MEM8(0x0A80)
#define TCB0_CTRLB  _SFR_MEM8(0x0A81)
#define TCB0_EVCTRL  _SFR_MEM8(0x0A84)
#define TCB0_INTCTRL  _SFR_MEM8(0x0A85)
#define TCB0_INTFLAGS  _SFR_MEM8(0x0A86)
#define TCB0_STATUS  _SFR_MEM8(0x0A87)
#define TCB0_DBGCTRL  _SFR_MEM8(0x0A88)
#define TCB0_TEMP  _SFR_MEM8(0x0A89)
#define TCB0_CNT  _SFR_MEM16(0x0A8A)
#define TCB0_CNTL  _SFR_MEM8(0x0A8A)
#define TCB0_CNTH  _SFR_MEM8(0x0A8B)
#define TCB0_CCMP  _SFR_MEM16(0x0A8C)
#define TCB0_CCMPL  _SFR_MEM8(0x0A8C)
#define TCB0_CCMPH  _SFR_MEM8(0x0A8D)


/* TCB (TCB1) - 16-bit Timer Type B */
#define TCB1_CTRLA  _SFR_MEM8(0x0A90)
#define TCB1_CTRLB  _SFR_MEM8(0x0A91)
#define TCB1_EVCTRL  _SFR_MEM8(0x0A94)
#define TCB1_INTCTRL  _SFR_MEM8(0x0A95)
#define TCB1_INTFLAGS  _SFR_MEM8(0x0A96)
#define TCB1_STATUS  _SFR_MEM8(0x0A97)
#define TCB1_DBGCTRL  _SFR_MEM8(0x0A98)
#define TCB1_TEMP  _SFR_MEM8(0x0A99)
#define TCB1_CNT  _SFR_MEM16(0x0A9A)
#define TCB1_CNTL  _SFR_MEM8(0x0A9A)
#define TCB1_CNTH  _SFR_MEM8(0x0A9B)
#define TCB1_CCMP  _SFR_MEM16(0x0A9C)
#define TCB1_CCMPL  _SFR_MEM8(0x0A9C)
#define TCB1_CCMPH  _SFR_MEM8(0x0A9D)


/* TCB (TCB2) - 16-bit Timer Type B */
#define TCB2_CTRLA  _SFR_MEM8(0x0AA0)
#define TCB2_CTRLB  _SFR_MEM8(0x0AA1)
#define TCB2_EVCTRL  _SFR_MEM8(0x0AA4)
#define TCB2_INTCTRL  _SFR_MEM8(0x0AA5)
#define TCB2_INTFLAGS  _SFR_MEM8(0x0AA6)
#define TCB2_STATUS  _SFR_MEM8(0x0AA7)
#define TCB2_DBGCTRL  _SFR_MEM8(0x0AA8)
#define TCB2_TEMP  _SFR_MEM8(0x0AA9)
#define TCB2_CNT  _SFR_MEM16(0x0AAA)
#define TCB2_CNTL  _SFR_MEM8(0x0AAA)
#define TCB2_CNTH  _SFR_MEM8(0x0AAB)
#define TCB2_CCMP  _SFR_MEM16(0x0AAC)
#define TCB2_CCMPL  _SFR_MEM8(0x0AAC)
#define TCB2_CCMPH  _SFR_MEM8(0x0AAD)


/* SYSCFG - System Configuration Registers */
#define SYSCFG_REVID  _SFR_MEM8(0x0F01)
#define SYSCFG_EXTBRK  _SFR_MEM8(0x0F02)
#define SYSCFG_OCDM  _SFR_MEM8(0x0F18)
#define SYSCFG_OCDMS  _SFR_MEM8(0x0F19)


/* NVMCTRL - Non-volatile Memory Controller */
#define NVMCTRL_CTRLA  _SFR_MEM8(0x1000)
#define NVMCTRL_CTRLB  _SFR_MEM8(0x1001)
#define NVMCTRL_STATUS  _SFR_MEM8(0x1002)
#define NVMCTRL_INTCTRL  _SFR_MEM8(0x1003)
#define NVMCTRL_INTFLAGS  _SFR_MEM8(0x1004)
#define NVMCTRL_DATA  _SFR_MEM16(0x1006)
#define NVMCTRL_DATAL  _SFR_MEM8(0x1006)
#define NVMCTRL_DATAH  _SFR_MEM8(0x1007)
#define NVMCTRL_ADDR  _SFR_MEM16(0x1008)
#define NVMCTRL_ADDRL  _SFR_MEM8(0x1008)
#define NVMCTRL_ADDRH  _SFR_MEM8(0x1009)


/* SIGROW - Signature row */
#define SIGROW_DEVICEID0  _SFR_MEM8(0x1100)
#define SIGROW_DEVICEID1  _SFR_MEM8(0x1101)
#define SIGROW_DEVICEID2  _SFR_MEM8(0x1102)
#define SIGROW_SERNUM0  _SFR_MEM8(0x1103)
#define SIGROW_SERNUM1  _SFR_MEM8(0x1104)
#define SIGROW_SERNUM2  _SFR_MEM8(0x1105)
#define SIGROW_SERNUM3  _SFR_MEM8(0x1106)
#define SIGROW_SERNUM4  _SFR_MEM8(0x1107)
#define SIGROW_SERNUM5  _SFR_MEM8(0x1108)
#define SIGROW_SERNUM6  _SFR_MEM8(0x1109)
#define SIGROW_SERNUM7  _SFR_MEM8(0x110A)
#define SIGROW_SERNUM8  _SFR_MEM8(0x110B)
#define SIGROW_SERNUM9  _SFR_MEM8(0x110C)
#define SIGROW_OSCCAL32K  _SFR_MEM8(0x1114)
#define SIGROW_OSCCAL16M0  _SFR_MEM8(0x1118)
#define SIGROW_OSCCAL16M1  _SFR_MEM8(0x1119)
#define SIGROW_OSCCAL20M0  _SFR_MEM8(0x111A)
#define SIGROW_OSCCAL20M1  _SFR_MEM8(0x111B)
#define SIGROW_TEMPSENSE0  _SFR_MEM8(0x1120)
#define SIGROW_TEMPSENSE1  _SFR_MEM8(0x1121)
#define SIGROW_OSC16ERR3V  _SFR_MEM8(0x1122)
#define SIGROW_OSC16ERR5V  _SFR_MEM8(0x1123)
#define SIGROW_OSC20ERR3V  _SFR_MEM8(0x1124)
#define SIGROW_OSC20ERR5V  _SFR_MEM8(0x1125)
#define SIGROW_CHECKSUM1  _SFR_MEM8(0x112F)


/* FUSE - Fuses */
#define FUSE_WDTCFG  _SFR_MEM8(0x1280)
#define FUSE_BODCFG  _SFR_MEM8(0x1281)
#define FUSE_OSCCFG  _SFR_MEM8(0x1282)
#define FUSE_SYSCFG0  _SFR_MEM8(0x1285)
#define FUSE_SYSCFG1  _SFR_MEM8(0x1286)
#define FUSE_APPEND  _SFR_MEM8(0x1287)
#define FUSE_BOOTEND  _SFR_MEM8(0x1288)


/* LOCKBIT - Lockbit */
#define LOCKBIT_LOCKBIT  _SFR_MEM8(0x128A)


/* USERROW - User Row */
#define USERROW_USERROW0  _SFR_MEM8(0x1300)
#define USERROW_USERROW1  _SFR_MEM8(0x1301)
#define USERROW_USERROW2  _SFR_MEM8(0x1302)
#define USERROW_USERROW3  _SFR_MEM8(0x1303)
#define USERROW_USERROW4  _SFR_MEM8(0x1304)
#define USERROW_USERROW5  _SFR_MEM8(0x1305)
#define USERROW_USERROW6  _SFR_MEM8(0x1306)
#define USERROW_USERROW7  _SFR_MEM8(0x1307)
#define USERROW_USERROW8  _SFR_MEM8(0x1308)
#define USERROW_USERROW9  _SFR_MEM8(0x1309)
#define USERROW_USERROW10  _SFR_MEM8(0x130A)
#define USERROW_USERROW11  _SFR_MEM8(0x130B)
#define USERROW_USERROW12  _SFR_MEM8(0x130C)
#define USERROW_USERROW13  _SFR_MEM8(0x130D)
#define USERROW_USERROW14  _SFR_MEM8(0x130E)
#define USERROW_USERROW15  _SFR_MEM8(0x130F)
#define USERROW_USERROW16  _SFR_MEM8(0x1310)
#define USERROW_USERROW17  _SFR_MEM8(0x1311)
#define USERROW_USERROW18  _SFR_MEM8(0x1312)
#define USERROW_USERROW19  _SFR_MEM8(0x1313)
#define USERROW_USERROW20  _SFR_MEM8(0x1314)
#define USERROW_USERROW21  _SFR_MEM8(0x1315)
#define USERROW_USERROW22  _SFR_MEM8(0x1316)
#define USERROW_USERROW23  _SFR_MEM8(0x1317)
#define USERROW_USERROW24  _SFR_MEM8(0x1318)
#define USERROW_USERROW25  _SFR_MEM8(0x1319)
#define USERROW_USERROW26  _SFR_MEM8(0x131A)
#define USERROW_USERROW27  _SFR_MEM8(0x131B)
#define USERROW_USERROW28  _SFR_MEM8(0x131C)
#define USERROW_USERROW29  _SFR_MEM8(0x131D)
#define USERROW_USERROW30  _SFR_MEM8(0x131E)
#define USERROW_USERROW31  _SFR_MEM8(0x131F)
#define USERROW_USERROW32  _SFR_MEM8(0x1320)
#define USERROW_USERROW33  _SFR_MEM8(0x1321)
#define USERROW_USERROW34  _SFR_MEM8(0x1322)
#define USERROW_USERROW35  _SFR_MEM8(0x1323)
#define USERROW_USERROW36  _SFR_MEM8(0x1324)
#define USERROW_USERROW37  _SFR_MEM8(0x1325)
#define USERROW_USERROW38  _SFR_MEM8(0x1326)
#define USERROW_USERROW39  _SFR_MEM8(0x1327)
#define USERROW_USERROW40  _SFR_MEM8(0x1328)
#define USERROW_USERROW41  _SFR_MEM8(0x1329)
#define USERROW_USERROW42  _SFR_MEM8(0x132A)
#define USERROW_USERROW43  _SFR_MEM8(0x132B)
#define USERROW_USERROW44  _SFR_MEM8(0x132C)
#define USERROW_USERROW45  _SFR_MEM8(0x132D)
#define USERROW_USERROW46  _SFR_MEM8(0x132E)
#define USERROW_USERROW47  _SFR_MEM8(0x132F)
#define USERROW_USERROW48  _SFR_MEM8(0x1330)
#define USERROW_USERROW49  _SFR_MEM8(0x1331)
#define USERROW_USERROW50  _SFR_MEM8(0x1332)
#define USERROW_USERROW51  _SFR_MEM8(0x1333)
#define USERROW_USERROW52  _SFR_MEM8(0x1334)
#define USERROW_USERROW53  _SFR_MEM8(0x1335)
#define USERROW_USERROW54  _SFR_MEM8(0x1336)
#define USERROW_USERROW55  _SFR_MEM8(0x1337)
#define USERROW_USERROW56  _SFR_MEM8(0x1338)
#define USERROW_USERROW57  _SFR_MEM8(0x1339)
#define USERROW_USERROW58  _SFR_MEM8(0x133A)
#define USERROW_USERROW59  _SFR_MEM8(0x133B)
#define USERROW_USERROW60  _SFR_MEM8(0x133C)
#define USERROW_USERROW61  _SFR_MEM8(0x133D)
#define USERROW_USERROW62  _SFR_MEM8(0x133E)
#define USERROW_USERROW63  _SFR_MEM8(0x133F)



/*================== Bitfield Definitions ================== */

/* AC - Analog Comparator */
/* AC.CTRLA  bit masks and bit positions */
#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */
#define AC_HYSMODE_gm  0x06  /* Hysteresis Mode group mask. */
#define AC_HYSMODE_gp  1  /* Hysteresis Mode group position. */
#define AC_HYSMODE0_bm  (1<<1)  /* Hysteresis Mode bit 0 mask. */
#define AC_HYSMODE0_bp  1  /* Hysteresis Mode bit 0 position. */
#define AC_HYSMODE1_bm  (1<<2)  /* Hysteresis Mode bit 1 mask. */
#define AC_HYSMODE1_bp  2  /* Hysteresis Mode bit 1 position. */
#define AC_LPMODE_bm  0x08  /* Low Power Mode bit mask. */
#define AC_LPMODE_bp  3  /* Low Power Mode bit position. */
#define AC_INTMODE_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE1_bp  5  /* Interrupt Mode bit 1 position. */
#define AC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define AC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define AC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define AC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* AC.MUXCTRLA  bit masks and bit positions */
#define AC_MUXNEG_gm  0x03  /* Negative Input MUX Selection group mask. */
#define AC_MUXNEG_gp  0  /* Negative Input MUX Selection group position. */
#define AC_MUXNEG0_bm  (1<<0)  /* Negative Input MUX Selection bit 0 mask. */
#define AC_MUXNEG0_bp  0  /* Negative Input MUX Selection bit 0 position. */
#define AC_MUXNEG1_bm  (1<<1)  /* Negative Input MUX Selection bit 1 mask. */
#define AC_MUXNEG1_bp  1  /* Negative Input MUX Selection bit 1 position. */
#define AC_MUXPOS_gm  0x18  /* Positive Input MUX Selection group mask. */
#define AC_MUXPOS_gp  3  /* Positive Input MUX Selection group position. */
#define AC_MUXPOS0_bm  (1<<3)  /* Positive Input MUX Selection bit 0 mask. */
#define AC_MUXPOS0_bp  3  /* Positive Input MUX Selection bit 0 position. */
#define AC_MUXPOS1_bm  (1<<4)  /* Positive Input MUX Selection bit 1 mask. */
#define AC_MUXPOS1_bp  4  /* Positive Input MUX Selection bit 1 position. */
#define AC_INVERT_bm  0x80  /* Invert AC Output bit mask. */
#define AC_INVERT_bp  7  /* Invert AC Output bit position. */

/* AC.DACREF  bit masks and bit positions */
#define AC_DATA_gm  0xFF  /* DAC voltage reference group mask. */
#define AC_DATA_gp  0  /* DAC voltage reference group position. */
#define AC_DATA0_bm  (1<<0)  /* DAC voltage reference bit 0 mask. */
#define AC_DATA0_bp  0  /* DAC voltage reference bit 0 position. */
#define AC_DATA1_bm  (1<<1)  /* DAC voltage reference bit 1 mask. */
#define AC_DATA1_bp  1  /* DAC voltage reference bit 1 position. */
#define AC_DATA2_bm  (1<<2)  /* DAC voltage reference bit 2 mask. */
#define AC_DATA2_bp  2  /* DAC voltage reference bit 2 position. */
#define AC_DATA3_bm  (1<<3)  /* DAC voltage reference bit 3 mask. */
#define AC_DATA3_bp  3  /* DAC voltage reference bit 3 position. */
#define AC_DATA4_bm  (1<<4)  /* DAC voltage reference bit 4 mask. */
#define AC_DATA4_bp  4  /* DAC voltage reference bit 4 position. */
#define AC_DATA5_bm  (1<<5)  /* DAC voltage reference bit 5 mask. */
#define AC_DATA5_bp  5  /* DAC voltage reference bit 5 position. */
#define AC_DATA6_bm  (1<<6)  /* DAC voltage reference bit 6 mask. */
#define AC_DATA6_bp  6  /* DAC voltage reference bit 6 position. */
#define AC_DATA7_bm  (1<<7)  /* DAC voltage reference bit 7 mask. */
#define AC_DATA7_bp  7  /* DAC voltage reference bit 7 position. */

/* AC.INTCTRL  bit masks and bit positions */
#define AC_CMP_bm  0x01  /* Analog Comparator 0 Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Analog Comparator 0 Interrupt Enable bit position. */

/* AC.STATUS  bit masks and bit positions */
/* AC_CMP  is already defined. */
#define AC_STATE_bm  0x10  /* Analog Comparator State bit mask. */
#define AC_STATE_bp  4  /* Analog Comparator State bit position. */

/* ADC - Analog to Digital Converter */
/* ADC.CTRLA  bit masks and bit positions */
#define ADC_ENABLE_bm  0x01  /* ADC Enable bit mask. */
#define ADC_ENABLE_bp  0  /* ADC Enable bit position. */
#define ADC_FREERUN_bm  0x02  /* ADC Freerun mode bit mask. */
#define ADC_FREERUN_bp  1  /* ADC Freerun mode bit position. */
#define ADC_RESSEL_bm  0x04  /* ADC Resolution bit mask. */
#define ADC_RESSEL_bp  2  /* ADC Resolution bit position. */
#define ADC_RUNSTBY_bm  0x80  /* Run standby mode bit mask. */
#define ADC_RUNSTBY_bp  7  /* Run standby mode bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_SAMPNUM_gm  0x07  /* Accumulation Samples group mask. */
#define ADC_SAMPNUM_gp  0  /* Accumulation Samples group position. */
#define ADC_SAMPNUM0_bm  (1<<0)  /* Accumulation Samples bit 0 mask. */
#define ADC_SAMPNUM0_bp  0  /* Accumulation Samples bit 0 position. */
#define ADC_SAMPNUM1_bm  (1<<1)  /* Accumulation Samples bit 1 mask. */
#define ADC_SAMPNUM1_bp  1  /* Accumulation Samples bit 1 position. */
#define ADC_SAMPNUM2_bm  (1<<2)  /* Accumulation Samples bit 2 mask. */
#define ADC_SAMPNUM2_bp  2  /* Accumulation Samples bit 2 position. */

/* ADC.CTRLC  bit masks and bit positions */
#define ADC_PRESC_gm  0x07  /* Clock Pre-scaler group mask. */
#define ADC_PRESC_gp  0  /* Clock Pre-scaler group position. */
#define ADC_PRESC0_bm  (1<<0)  /* Clock Pre-scaler bit 0 mask. */
#define ADC_PRESC0_bp  0  /* Clock Pre-scaler bit 0 position. */
#define ADC_PRESC1_bm  (1<<1)  /* Clock Pre-scaler bit 1 mask. */
#define ADC_PRESC1_bp  1  /* Clock Pre-scaler bit 1 position. */
#define ADC_PRESC2_bm  (1<<2)  /* Clock Pre-scaler bit 2 mask. */
#define ADC_PRESC2_bp  2  /* Clock Pre-scaler bit 2 position. */
#define ADC_REFSEL_gm  0x30  /* Reference Selection group mask. */
#define ADC_REFSEL_gp  4  /* Reference Selection group position. */
#define ADC_REFSEL0_bm  (1<<4)  /* Reference Selection bit 0 mask. */
#define ADC_REFSEL0_bp  4  /* Reference Selection bit 0 position. */
#define ADC_REFSEL1_bm  (1<<5)  /* Reference Selection bit 1 mask. */
#define ADC_REFSEL1_bp  5  /* Reference Selection bit 1 position. */
#define ADC_SAMPCAP_bm  0x40  /* Sample Capacitance Selection bit mask. */
#define ADC_SAMPCAP_bp  6  /* Sample Capacitance Selection bit position. */

/* ADC.CTRLD  bit masks and bit positions */
#define ADC_SAMPDLY_gm  0x0F  /* Sampling Delay Selection group mask. */
#define ADC_SAMPDLY_gp  0  /* Sampling Delay Selection group position. */
#define ADC_SAMPDLY0_bm  (1<<0)  /* Sampling Delay Selection bit 0 mask. */
#define ADC_SAMPDLY0_bp  0  /* Sampling Delay Selection bit 0 position. */
#define ADC_SAMPDLY1_bm  (1<<1)  /* Sampling Delay Selection bit 1 mask. */
#define ADC_SAMPDLY1_bp  1  /* Sampling Delay Selection bit 1 position. */
#define ADC_SAMPDLY2_bm  (1<<2)  /* Sampling Delay Selection bit 2 mask. */
#define ADC_SAMPDLY2_bp  2  /* Sampling Delay Selection bit 2 position. */
#define ADC_SAMPDLY3_bm  (1<<3)  /* Sampling Delay Selection bit 3 mask. */
#define ADC_SAMPDLY3_bp  3  /* Sampling Delay Selection bit 3 position. */
#define ADC_ASDV_bm  0x10  /* Automatic Sampling Delay Variation bit mask. */
#define ADC_ASDV_bp  4  /* Automatic Sampling Delay Variation bit position. */
#define ADC_INITDLY_gm  0xE0  /* Initial Delay Selection group mask. */
#define ADC_INITDLY_gp  5  /* Initial Delay Selection group position. */
#define ADC_INITDLY0_bm  (1<<5)  /* Initial Delay Selection bit 0 mask. */
#define ADC_INITDLY0_bp  5  /* Initial Delay Selection bit 0 position. */
#define ADC_INITDLY1_bm  (1<<6)  /* Initial Delay Selection bit 1 mask. */
#define ADC_INITDLY1_bp  6  /* Initial Delay Selection bit 1 position. */
#define ADC_INITDLY2_bm  (1<<7)  /* Initial Delay Selection bit 2 mask. */
#define ADC_INITDLY2_bp  7  /* Initial Delay Selection bit 2 position. */

/* ADC.CTRLE  bit masks and bit positions */
#define ADC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define ADC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define ADC_WINCM0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define ADC_WINCM0_bp  0  /* Window Comparator Mode bit 0 position. */
#define ADC_WINCM1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define ADC_WINCM1_bp  1  /* Window Comparator Mode bit 1 position. */
#define ADC_WINCM2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define ADC_WINCM2_bp  2  /* Window Comparator Mode bit 2 position. */

/* ADC.SAMPCTRL  bit masks and bit positions */
#define ADC_SAMPLEN_gm  0x1F  /* Sample lenght group mask. */
#define ADC_SAMPLEN_gp  0  /* Sample lenght group position. */
#define ADC_SAMPLEN0_bm  (1<<0)  /* Sample lenght bit 0 mask. */
#define ADC_SAMPLEN0_bp  0  /* Sample lenght bit 0 position. */
#define ADC_SAMPLEN1_bm  (1<<1)  /* Sample lenght bit 1 mask. */
#define ADC_SAMPLEN1_bp  1  /* Sample lenght bit 1 position. */
#define ADC_SAMPLEN2_bm  (1<<2)  /* Sample lenght bit 2 mask. */
#define ADC_SAMPLEN2_bp  2  /* Sample lenght bit 2 position. */
#define ADC_SAMPLEN3_bm  (1<<3)  /* Sample lenght bit 3 mask. */
#define ADC_SAMPLEN3_bp  3  /* Sample lenght bit 3 position. */
#define ADC_SAMPLEN4_bm  (1<<4)  /* Sample lenght bit 4 mask. */
#define ADC_SAMPLEN4_bp  4  /* Sample lenght bit 4 position. */

/* ADC.MUXPOS  bit masks and bit positions */
#define ADC_MUXPOS_gm  0x1F  /* Analog Channel Selection Bits group mask. */
#define ADC_MUXPOS_gp  0  /* Analog Channel Selection Bits group position. */
#define ADC_MUXPOS0_bm  (1<<0)  /* Analog Channel Selection Bits bit 0 mask. */
#define ADC_MUXPOS0_bp  0  /* Analog Channel Selection Bits bit 0 position. */
#define ADC_MUXPOS1_bm  (1<<1)  /* Analog Channel Selection Bits bit 1 mask. */
#define ADC_MUXPOS1_bp  1  /* Analog Channel Selection Bits bit 1 position. */
#define ADC_MUXPOS2_bm  (1<<2)  /* Analog Channel Selection Bits bit 2 mask. */
#define ADC_MUXPOS2_bp  2  /* Analog Channel Selection Bits bit 2 position. */
#define ADC_MUXPOS3_bm  (1<<3)  /* Analog Channel Selection Bits bit 3 mask. */
#define ADC_MUXPOS3_bp  3  /* Analog Channel Selection Bits bit 3 position. */
#define ADC_MUXPOS4_bm  (1<<4)  /* Analog Channel Selection Bits bit 4 mask. */
#define ADC_MUXPOS4_bp  4  /* Analog Channel Selection Bits bit 4 position. */

/* ADC.COMMAND  bit masks and bit positions */
#define ADC_STCONV_bm  0x01  /* Start Conversion Operation bit mask. */
#define ADC_STCONV_bp  0  /* Start Conversion Operation bit position. */

/* ADC.EVCTRL  bit masks and bit positions */
#define ADC_STARTEI_bm  0x01  /* Start Event Input Enable bit mask. */
#define ADC_STARTEI_bp  0  /* Start Event Input Enable bit position. */

/* ADC.INTCTRL  bit masks and bit positions */
#define ADC_RESRDY_bm  0x01  /* Result Ready Interrupt Enable bit mask. */
#define ADC_RESRDY_bp  0  /* Result Ready Interrupt Enable bit position. */
#define ADC_WCMP_bm  0x02  /* Window Comparator Interrupt Enable bit mask. */
#define ADC_WCMP_bp  1  /* Window Comparator Interrupt Enable bit position. */

/* ADC.INTFLAGS  bit masks and bit positions */
/* ADC_RESRDY  is already defined. */
/* ADC_WCMP  is already defined. */

/* ADC.DBGCTRL  bit masks and bit positions */
#define ADC_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define ADC_DBGRUN_bp  0  /* Debug run bit position. */

/* ADC.TEMP  bit masks and bit positions */
#define ADC_TEMP_gm  0xFF  /* Temporary group mask. */
#define ADC_TEMP_gp  0  /* Temporary group position. */
#define ADC_TEMP0_bm  (1<<0)  /* Temporary bit 0 mask. */
#define ADC_TEMP0_bp  0  /* Temporary bit 0 position. */
#define ADC_TEMP1_bm  (1<<1)  /* Temporary bit 1 mask. */
#define ADC_TEMP1_bp  1  /* Temporary bit 1 position. */
#define ADC_TEMP2_bm  (1<<2)  /* Temporary bit 2 mask. */
#define ADC_TEMP2_bp  2  /* Temporary bit 2 position. */
#define ADC_TEMP3_bm  (1<<3)  /* Temporary bit 3 mask. */
#define ADC_TEMP3_bp  3  /* Temporary bit 3 position. */
#define ADC_TEMP4_bm  (1<<4)  /* Temporary bit 4 mask. */
#define ADC_TEMP4_bp  4  /* Temporary bit 4 position. */
#define ADC_TEMP5_bm  (1<<5)  /* Temporary bit 5 mask. */
#define ADC_TEMP5_bp  5  /* Temporary bit 5 position. */
#define ADC_TEMP6_bm  (1<<6)  /* Temporary bit 6 mask. */
#define ADC_TEMP6_bp  6  /* Temporary bit 6 position. */
#define ADC_TEMP7_bm  (1<<7)  /* Temporary bit 7 mask. */
#define ADC_TEMP7_bp  7  /* Temporary bit 7 position. */




/* ADC.CALIB  bit masks and bit positions */
#define ADC_DUTYCYC_bm  0x01  /* Duty Cycle bit mask. */
#define ADC_DUTYCYC_bp  0  /* Duty Cycle bit position. */

/* BOD - Bod interface */
/* BOD.CTRLA  bit masks and bit positions */
#define BOD_SLEEP_gm  0x03  /* Operation in sleep mode group mask. */
#define BOD_SLEEP_gp  0  /* Operation in sleep mode group position. */
#define BOD_SLEEP0_bm  (1<<0)  /* Operation in sleep mode bit 0 mask. */
#define BOD_SLEEP0_bp  0  /* Operation in sleep mode bit 0 position. */
#define BOD_SLEEP1_bm  (1<<1)  /* Operation in sleep mode bit 1 mask. */
#define BOD_SLEEP1_bp  1  /* Operation in sleep mode bit 1 position. */
#define BOD_ACTIVE_gm  0x0C  /* Operation in active mode group mask. */
#define BOD_ACTIVE_gp  2  /* Operation in active mode group position. */
#define BOD_ACTIVE0_bm  (1<<2)  /* Operation in active mode bit 0 mask. */
#define BOD_ACTIVE0_bp  2  /* Operation in active mode bit 0 position. */
#define BOD_ACTIVE1_bm  (1<<3)  /* Operation in active mode bit 1 mask. */
#define BOD_ACTIVE1_bp  3  /* Operation in active mode bit 1 position. */
#define BOD_SAMPFREQ_bm  0x10  /* Sample frequency bit mask. */
#define BOD_SAMPFREQ_bp  4  /* Sample frequency bit position. */

/* BOD.CTRLB  bit masks and bit positions */
#define BOD_LVL_gm  0x07  /* Bod level group mask. */
#define BOD_LVL_gp  0  /* Bod level group position. */
#define BOD_LVL0_bm  (1<<0)  /* Bod level bit 0 mask. */
#define BOD_LVL0_bp  0  /* Bod level bit 0 position. */
#define BOD_LVL1_bm  (1<<1)  /* Bod level bit 1 mask. */
#define BOD_LVL1_bp  1  /* Bod level bit 1 position. */
#define BOD_LVL2_bm  (1<<2)  /* Bod level bit 2 mask. */
#define BOD_LVL2_bp  2  /* Bod level bit 2 position. */

/* BOD.VLMCTRLA  bit masks and bit positions */
#define BOD_VLMLVL_gm  0x03  /* voltage level monitor level group mask. */
#define BOD_VLMLVL_gp  0  /* voltage level monitor level group position. */
#define BOD_VLMLVL0_bm  (1<<0)  /* voltage level monitor level bit 0 mask. */
#define BOD_VLMLVL0_bp  0  /* voltage level monitor level bit 0 position. */
#define BOD_VLMLVL1_bm  (1<<1)  /* voltage level monitor level bit 1 mask. */
#define BOD_VLMLVL1_bp  1  /* voltage level monitor level bit 1 position. */

/* BOD.INTCTRL  bit masks and bit positions */
#define BOD_VLMIE_bm  0x01  /* voltage level monitor interrrupt enable bit mask. */
#define BOD_VLMIE_bp  0  /* voltage level monitor interrrupt enable bit position. */
#define BOD_VLMCFG_gm  0x06  /* Configuration group mask. */
#define BOD_VLMCFG_gp  1  /* Configuration group position. */
#define BOD_VLMCFG0_bm  (1<<1)  /* Configuration bit 0 mask. */
#define BOD_VLMCFG0_bp  1  /* Configuration bit 0 position. */
#define BOD_VLMCFG1_bm  (1<<2)  /* Configuration bit 1 mask. */
#define BOD_VLMCFG1_bp  2  /* Configuration bit 1 position. */

/* BOD.INTFLAGS  bit masks and bit positions */
#define BOD_VLMIF_bm  0x01  /* Voltage level monitor interrupt flag bit mask. */
#define BOD_VLMIF_bp  0  /* Voltage level monitor interrupt flag bit position. */

/* BOD.STATUS  bit masks and bit positions */
#define BOD_VLMS_bm  0x01  /* Voltage level monitor status bit mask. */
#define BOD_VLMS_bp  0  /* Voltage level monitor status bit position. */

/* CCL - Configurable Custom Logic */
/* CCL.CTRLA  bit masks and bit positions */
#define CCL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CCL_ENABLE_bp  0  /* Enable bit position. */
#define CCL_RUNSTDBY_bm  0x40  /* Run in Standby bit mask. */
#define CCL_RUNSTDBY_bp  6  /* Run in Standby bit position. */

/* CCL.SEQCTRL0  bit masks and bit positions */
#define CCL_SEQSEL0_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL0_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL00_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL00_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL01_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL01_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL02_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL02_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.SEQCTRL1  bit masks and bit positions */
#define CCL_SEQSEL1_gm  0x07  /* Sequential Selection group mask. */
#define CCL_SEQSEL1_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL10_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL10_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL11_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL11_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL12_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL12_bp  2  /* Sequential Selection bit 2 position. */

/* CCL.INTCTRL0  bit masks and bit positions */
#define CCL_INTMODE0_gm  0x03  /* Interrupt Mode for LUT0 group mask. */
#define CCL_INTMODE0_gp  0  /* Interrupt Mode for LUT0 group position. */
#define CCL_INTMODE00_bm  (1<<0)  /* Interrupt Mode for LUT0 bit 0 mask. */
#define CCL_INTMODE00_bp  0  /* Interrupt Mode for LUT0 bit 0 position. */
#define CCL_INTMODE01_bm  (1<<1)  /* Interrupt Mode for LUT0 bit 1 mask. */
#define CCL_INTMODE01_bp  1  /* Interrupt Mode for LUT0 bit 1 position. */
#define CCL_INTMODE1_gm  0x0C  /* Interrupt Mode for LUT1 group mask. */
#define CCL_INTMODE1_gp  2  /* Interrupt Mode for LUT1 group position. */
#define CCL_INTMODE10_bm  (1<<2)  /* Interrupt Mode for LUT1 bit 0 mask. */
#define CCL_INTMODE10_bp  2  /* Interrupt Mode for LUT1 bit 0 position. */
#define CCL_INTMODE11_bm  (1<<3)  /* Interrupt Mode for LUT1 bit 1 mask. */
#define CCL_INTMODE11_bp  3  /* Interrupt Mode for LUT1 bit 1 position. */
#define CCL_INTMODE2_gm  0x30  /* Interrupt Mode for LUT2 group mask. */
#define CCL_INTMODE2_gp  4  /* Interrupt Mode for LUT2 group position. */
#define CCL_INTMODE20_bm  (1<<4)  /* Interrupt Mode for LUT2 bit 0 mask. */
#define CCL_INTMODE20_bp  4  /* Interrupt Mode for LUT2 bit 0 position. */
#define CCL_INTMODE21_bm  (1<<5)  /* Interrupt Mode for LUT2 bit 1 mask. */
#define CCL_INTMODE21_bp  5  /* Interrupt Mode for LUT2 bit 1 position. */
#define CCL_INTMODE3_gm  0xC0  /* Interrupt Mode for LUT3 group mask. */
#define CCL_INTMODE3_gp  6  /* Interrupt Mode for LUT3 group position. */
#define CCL_INTMODE30_bm  (1<<6)  /* Interrupt Mode for LUT3 bit 0 mask. */
#define CCL_INTMODE30_bp  6  /* Interrupt Mode for LUT3 bit 0 position. */
#define CCL_INTMODE31_bm  (1<<7)  /* Interrupt Mode for LUT3 bit 1 mask. */
#define CCL_INTMODE31_bp  7  /* Interrupt Mode for LUT3 bit 1 position. */

/* CCL.INTFLAGS  bit masks and bit positions */
#define CCL_INT_gm  0x0F  /* Interrupt Flags group mask. */
#define CCL_INT_gp  0  /* Interrupt Flags group position. */
#define CCL_INT0_bm  (1<<0)  /* Interrupt Flags bit 0 mask. */
#define CCL_INT0_bp  0  /* Interrupt Flags bit 0 position. */
#define CCL_INT1_bm  (1<<1)  /* Interrupt Flags bit 1 mask. */
#define CCL_INT1_bp  1  /* Interrupt Flags bit 1 position. */
#define CCL_INT2_bm  (1<<2)  /* Interrupt Flags bit 2 mask. */
#define CCL_INT2_bp  2  /* Interrupt Flags bit 2 position. */
#define CCL_INT3_bm  (1<<3)  /* Interrupt Flags bit 3 mask. */
#define CCL_INT3_bp  3  /* Interrupt Flags bit 3 position. */

/* CCL.LUT0CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
#define CCL_CLKSRC_gm  0x0E  /* Clock Source Selection group mask. */
#define CCL_CLKSRC_gp  1  /* Clock Source Selection group position. */
#define CCL_CLKSRC0_bm  (1<<1)  /* Clock Source Selection bit 0 mask. */
#define CCL_CLKSRC0_bp  1  /* Clock Source Selection bit 0 position. */
#define CCL_CLKSRC1_bm  (1<<2)  /* Clock Source Selection bit 1 mask. */
#define CCL_CLKSRC1_bp  2  /* Clock Source Selection bit 1 position. */
#define CCL_CLKSRC2_bm  (1<<3)  /* Clock Source Selection bit 2 mask. */
#define CCL_CLKSRC2_bp  3  /* Clock Source Selection bit 2 position. */
#define CCL_FILTSEL_gm  0x30  /* Filter Selection group mask. */
#define CCL_FILTSEL_gp  4  /* Filter Selection group position. */
#define CCL_FILTSEL0_bm  (1<<4)  /* Filter Selection bit 0 mask. */
#define CCL_FILTSEL0_bp  4  /* Filter Selection bit 0 position. */
#define CCL_FILTSEL1_bm  (1<<5)  /* Filter Selection bit 1 mask. */
#define CCL_FILTSEL1_bp  5  /* Filter Selection bit 1 position. */
#define CCL_OUTEN_bm  0x40  /* Output Enable bit mask. */
#define CCL_OUTEN_bp  6  /* Output Enable bit position. */
#define CCL_EDGEDET_bm  0x80  /* Edge Detection Enable bit mask. */
#define CCL_EDGEDET_bp  7  /* Edge Detection Enable bit position. */

/* CCL.LUT0CTRLB  bit masks and bit positions */
#define CCL_INSEL0_gm  0x0F  /* LUT Input 0 Source Selection group mask. */
#define CCL_INSEL0_gp  0  /* LUT Input 0 Source Selection group position. */
#define CCL_INSEL00_bm  (1<<0)  /* LUT Input 0 Source Selection bit 0 mask. */
#define CCL_INSEL00_bp  0  /* LUT Input 0 Source Selection bit 0 position. */
#define CCL_INSEL01_bm  (1<<1)  /* LUT Input 0 Source Selection bit 1 mask. */
#define CCL_INSEL01_bp  1  /* LUT Input 0 Source Selection bit 1 position. */
#define CCL_INSEL02_bm  (1<<2)  /* LUT Input 0 Source Selection bit 2 mask. */
#define CCL_INSEL02_bp  2  /* LUT Input 0 Source Selection bit 2 position. */
#define CCL_INSEL03_bm  (1<<3)  /* LUT Input 0 Source Selection bit 3 mask. */
#define CCL_INSEL03_bp  3  /* LUT Input 0 Source Selection bit 3 position. */
#define CCL_INSEL1_gm  0xF0  /* LUT Input 1 Source Selection group mask. */
#define CCL_INSEL1_gp  4  /* LUT Input 1 Source Selection group position. */
#define CCL_INSEL10_bm  (1<<4)  /* LUT Input 1 Source Selection bit 0 mask. */
#define CCL_INSEL10_bp  4  /* LUT Input 1 Source Selection bit 0 position. */
#define CCL_INSEL11_bm  (1<<5)  /* LUT Input 1 Source Selection bit 1 mask. */
#define CCL_INSEL11_bp  5  /* LUT Input 1 Source Selection bit 1 position. */
#define CCL_INSEL12_bm  (1<<6)  /* LUT Input 1 Source Selection bit 2 mask. */
#define CCL_INSEL12_bp  6  /* LUT Input 1 Source Selection bit 2 position. */
#define CCL_INSEL13_bm  (1<<7)  /* LUT Input 1 Source Selection bit 3 mask. */
#define CCL_INSEL13_bp  7  /* LUT Input 1 Source Selection bit 3 position. */

/* CCL.LUT0CTRLC  bit masks and bit positions */
#define CCL_INSEL2_gm  0x0F  /* LUT Input 2 Source Selection group mask. */
#define CCL_INSEL2_gp  0  /* LUT Input 2 Source Selection group position. */
#define CCL_INSEL20_bm  (1<<0)  /* LUT Input 2 Source Selection bit 0 mask. */
#define CCL_INSEL20_bp  0  /* LUT Input 2 Source Selection bit 0 position. */
#define CCL_INSEL21_bm  (1<<1)  /* LUT Input 2 Source Selection bit 1 mask. */
#define CCL_INSEL21_bp  1  /* LUT Input 2 Source Selection bit 1 position. */
#define CCL_INSEL22_bm  (1<<2)  /* LUT Input 2 Source Selection bit 2 mask. */
#define CCL_INSEL22_bp  2  /* LUT Input 2 Source Selection bit 2 position. */
#define CCL_INSEL23_bm  (1<<3)  /* LUT Input 2 Source Selection bit 3 mask. */
#define CCL_INSEL23_bp  3  /* LUT Input 2 Source Selection bit 3 position. */


/* CCL.LUT1CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT1CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT1CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */


/* CCL.LUT2CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT2CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT2CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */


/* CCL.LUT3CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT3CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT3CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */


/* CLKCTRL - Clock controller */
/* CLKCTRL.MCLKCTRLA  bit masks and bit positions */
#define CLKCTRL_CLKSEL_gm  0x03  /* clock select group mask. */
#define CLKCTRL_CLKSEL_gp  0  /* clock select group position. */
#define CLKCTRL_CLKSEL0_bm  (1<<0)  /* clock select bit 0 mask. */
#define CLKCTRL_CLKSEL0_bp  0  /* clock select bit 0 position. */
#define CLKCTRL_CLKSEL1_bm  (1<<1)  /* clock select bit 1 mask. */
#define CLKCTRL_CLKSEL1_bp  1  /* clock select bit 1 position. */
#define CLKCTRL_CLKOUT_bm  0x80  /* System clock out bit mask. */
#define CLKCTRL_CLKOUT_bp  7  /* System clock out bit position. */

/* CLKCTRL.MCLKCTRLB  bit masks and bit positions */
#define CLKCTRL_PEN_bm  0x01  /* Prescaler enable bit mask. */
#define CLKCTRL_PEN_bp  0  /* Prescaler enable bit position. */
#define CLKCTRL_PDIV_gm  0x1E  /* Prescaler division group mask. */
#define CLKCTRL_PDIV_gp  1  /* Prescaler division group position. */
#define CLKCTRL_PDIV0_bm  (1<<1)  /* Prescaler division bit 0 mask. */
#define CLKCTRL_PDIV0_bp  1  /* Prescaler division bit 0 position. */
#define CLKCTRL_PDIV1_bm  (1<<2)  /* Prescaler division bit 1 mask. */
#define CLKCTRL_PDIV1_bp  2  /* Prescaler division bit 1 position. */
#define CLKCTRL_PDIV2_bm  (1<<3)  /* Prescaler division bit 2 mask. */
#define CLKCTRL_PDIV2_bp  3  /* Prescaler division bit 2 position. */
#define CLKCTRL_PDIV3_bm  (1<<4)  /* Prescaler division bit 3 mask. */
#define CLKCTRL_PDIV3_bp  4  /* Prescaler division bit 3 position. */

/* CLKCTRL.MCLKLOCK  bit masks and bit positions */
#define CLKCTRL_LOCKEN_bm  0x01  /* lock ebable bit mask. */
#define CLKCTRL_LOCKEN_bp  0  /* lock ebable bit position. */

/* CLKCTRL.MCLKSTATUS  bit masks and bit positions */
#define CLKCTRL_SOSC_bm  0x01  /* System Oscillator changing bit mask. */
#define CLKCTRL_SOSC_bp  0  /* System Oscillator changing bit position. */
#define CLKCTRL_OSC20MS_bm  0x10  /* 20MHz oscillator status bit mask. */
#define CLKCTRL_OSC20MS_bp  4  /* 20MHz oscillator status bit position. */
#define CLKCTRL_OSC32KS_bm  0x20  /* 32KHz oscillator status bit mask. */
#define CLKCTRL_OSC32KS_bp  5  /* 32KHz oscillator status bit position. */
#define CLKCTRL_XOSC32KS_bm  0x40  /* 32.768 kHz Crystal Oscillator status bit mask. */
#define CLKCTRL_XOSC32KS_bp  6  /* 32.768 kHz Crystal Oscillator status bit position. */
#define CLKCTRL_EXTS_bm  0x80  /* External Clock status bit mask. */
#define CLKCTRL_EXTS_bp  7  /* External Clock status bit position. */

/* CLKCTRL.OSC20MCTRLA  bit masks and bit positions */
#define CLKCTRL_RUNSTDBY_bm  0x02  /* Run standby bit mask. */
#define CLKCTRL_RUNSTDBY_bp  1  /* Run standby bit position. */

/* CLKCTRL.OSC20MCALIBA  bit masks and bit positions */
#define CLKCTRL_CAL20M_gm  0x7F  /* Calibration group mask. */
#define CLKCTRL_CAL20M_gp  0  /* Calibration group position. */
#define CLKCTRL_CAL20M0_bm  (1<<0)  /* Calibration bit 0 mask. */
#define CLKCTRL_CAL20M0_bp  0  /* Calibration bit 0 position. */
#define CLKCTRL_CAL20M1_bm  (1<<1)  /* Calibration bit 1 mask. */
#define CLKCTRL_CAL20M1_bp  1  /* Calibration bit 1 position. */
#define CLKCTRL_CAL20M2_bm  (1<<2)  /* Calibration bit 2 mask. */
#define CLKCTRL_CAL20M2_bp  2  /* Calibration bit 2 position. */
#define CLKCTRL_CAL20M3_bm  (1<<3)  /* Calibration bit 3 mask. */
#define CLKCTRL_CAL20M3_bp  3  /* Calibration bit 3 position. */
#define CLKCTRL_CAL20M4_bm  (1<<4)  /* Calibration bit 4 mask. */
#define CLKCTRL_CAL20M4_bp  4  /* Calibration bit 4 position. */
#define CLKCTRL_CAL20M5_bm  (1<<5)  /* Calibration bit 5 mask. */
#define CLKCTRL_CAL20M5_bp  5  /* Calibration bit 5 position. */
#define CLKCTRL_CAL20M6_bm  (1<<6)  /* Calibration bit 6 mask. */
#define CLKCTRL_CAL20M6_bp  6  /* Calibration bit 6 position. */

/* CLKCTRL.OSC20MCALIBB  bit masks and bit positions */
#define CLKCTRL_TEMPCAL20M_gm  0x0F  /* Oscillator temperature coefficient group mask. */
#define CLKCTRL_TEMPCAL20M_gp  0  /* Oscillator temperature coefficient group position. */
#define CLKCTRL_TEMPCAL20M0_bm  (1<<0)  /* Oscillator temperature coefficient bit 0 mask. */
#define CLKCTRL_TEMPCAL20M0_bp  0  /* Oscillator temperature coefficient bit 0 position. */
#define CLKCTRL_TEMPCAL20M1_bm  (1<<1)  /* Oscillator temperature coefficient bit 1 mask. */
#define CLKCTRL_TEMPCAL20M1_bp  1  /* Oscillator temperature coefficient bit 1 position. */
#define CLKCTRL_TEMPCAL20M2_bm  (1<<2)  /* Oscillator temperature coefficient bit 2 mask. */
#define CLKCTRL_TEMPCAL20M2_bp  2  /* Oscillator temperature coefficient bit 2 position. */
#define CLKCTRL_TEMPCAL20M3_bm  (1<<3)  /* Oscillator temperature coefficient bit 3 mask. */
#define CLKCTRL_TEMPCAL20M3_bp  3  /* Oscillator temperature coefficient bit 3 position. */
#define CLKCTRL_LOCK_bm  0x80  /* Lock bit mask. */
#define CLKCTRL_LOCK_bp  7  /* Lock bit position. */

/* CLKCTRL.OSC32KCTRLA  bit masks and bit positions */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSC32KCTRLA  bit masks and bit positions */
#define CLKCTRL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CLKCTRL_ENABLE_bp  0  /* Enable bit position. */
/* CLKCTRL_RUNSTDBY  is already defined. */
#define CLKCTRL_SEL_bm  0x04  /* Select bit mask. */
#define CLKCTRL_SEL_bp  2  /* Select bit position. */
#define CLKCTRL_CSUT_gm  0x30  /* Crystal startup time group mask. */
#define CLKCTRL_CSUT_gp  4  /* Crystal startup time group position. */
#define CLKCTRL_CSUT0_bm  (1<<4)  /* Crystal startup time bit 0 mask. */
#define CLKCTRL_CSUT0_bp  4  /* Crystal startup time bit 0 position. */
#define CLKCTRL_CSUT1_bm  (1<<5)  /* Crystal startup time bit 1 mask. */
#define CLKCTRL_CSUT1_bp  5  /* Crystal startup time bit 1 position. */

/* CPU - CPU */
/* CPU.CCP  bit masks and bit positions */
#define CPU_CCP_gm  0xFF  /* CCP signature group mask. */
#define CPU_CCP_gp  0  /* CCP signature group position. */
#define CPU_CCP0_bm  (1<<0)  /* CCP signature bit 0 mask. */
#define CPU_CCP0_bp  0  /* CCP signature bit 0 position. */
#define CPU_CCP1_bm  (1<<1)  /* CCP signature bit 1 mask. */
#define CPU_CCP1_bp  1  /* CCP signature bit 1 position. */
#define CPU_CCP2_bm  (1<<2)  /* CCP signature bit 2 mask. */
#define CPU_CCP2_bp  2  /* CCP signature bit 2 position. */
#define CPU_CCP3_bm  (1<<3)  /* CCP signature bit 3 mask. */
#define CPU_CCP3_bp  3  /* CCP signature bit 3 position. */
#define CPU_CCP4_bm  (1<<4)  /* CCP signature bit 4 mask. */
#define CPU_CCP4_bp  4  /* CCP signature bit 4 position. */
#define CPU_CCP5_bm  (1<<5)  /* CCP signature bit 5 mask. */
#define CPU_CCP5_bp  5  /* CCP signature bit 5 position. */
#define CPU_CCP6_bm  (1<<6)  /* CCP signature bit 6 mask. */
#define CPU_CCP6_bp  6  /* CCP signature bit 6 position. */
#define CPU_CCP7_bm  (1<<7)  /* CCP signature bit 7 mask. */
#define CPU_CCP7_bp  7  /* CCP signature bit 7 position. */



/* CPU.SREG  bit masks and bit positions */
#define CPU_C_bm  0x01  /* Carry Flag bit mask. */
#define CPU_C_bp  0  /* Carry Flag bit position. */
#define CPU_Z_bm  0x02  /* Zero Flag bit mask. */
#define CPU_Z_bp  1  /* Zero Flag bit position. */
#define CPU_N_bm  0x04  /* Negative Flag bit mask. */
#define CPU_N_bp  2  /* Negative Flag bit position. */
#define CPU_V_bm  0x08  /* Two's Complement Overflow Flag bit mask. */
#define CPU_V_bp  3  /* Two's Complement Overflow Flag bit position. */
#define CPU_S_bm  0x10  /* N Exclusive Or V Flag bit mask. */
#define CPU_S_bp  4  /* N Exclusive Or V Flag bit position. */
#define CPU_H_bm  0x20  /* Half Carry Flag bit mask. */
#define CPU_H_bp  5  /* Half Carry Flag bit position. */
#define CPU_T_bm  0x40  /* Transfer Bit bit mask. */
#define CPU_T_bp  6  /* Transfer Bit bit position. */
#define CPU_I_bm  0x80  /* Global Interrupt Enable Flag bit mask. */
#define CPU_I_bp  7  /* Global Interrupt Enable Flag bit position. */

/* CPUINT - Interrupt Controller */
/* CPUINT.CTRLA  bit masks and bit positions */
#define CPUINT_LVL0RR_bm  0x01  /* Round-robin Scheduling Enable bit mask. */
#define CPUINT_LVL0RR_bp  0  /* Round-robin Scheduling Enable bit position. */
#define CPUINT_CVT_bm  0x20  /* Compact Vector Table bit mask. */
#define CPUINT_CVT_bp  5  /* Compact Vector Table bit position. */
#define CPUINT_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define CPUINT_IVSEL_bp  6  /* Interrupt Vector Select bit position. */

/* CPUINT.STATUS  bit masks and bit positions */
#define CPUINT_LVL0EX_bm  0x01  /* Level 0 Interrupt Executing bit mask. */
#define CPUINT_LVL0EX_bp  0  /* Level 0 Interrupt Executing bit position. */
#define CPUINT_LVL1EX_bm  0x02  /* Level 1 Interrupt Executing bit mask. */
#define CPUINT_LVL1EX_bp  1  /* Level 1 Interrupt Executing bit position. */
#define CPUINT_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define CPUINT_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

/* CPUINT.LVL0PRI  bit masks and bit positions */
#define CPUINT_LVL0PRI_gm  0xFF  /* Interrupt Level Priority group mask. */
#define CPUINT_LVL0PRI_gp  0  /* Interrupt Level Priority group position. */
#define CPUINT_LVL0PRI0_bm  (1<<0)  /* Interrupt Level Priority bit 0 mask. */
#define CPUINT_LVL0PRI0_bp  0  /* Interrupt Level Priority bit 0 position. */
#define CPUINT_LVL0PRI1_bm  (1<<1)  /* Interrupt Level Priority bit 1 mask. */
#define CPUINT_LVL0PRI1_bp  1  /* Interrupt Level Priority bit 1 position. */
#define CPUINT_LVL0PRI2_bm  (1<<2)  /* Interrupt Level Priority bit 2 mask. */
#define CPUINT_LVL0PRI2_bp  2  /* Interrupt Level Priority bit 2 position. */
#define CPUINT_LVL0PRI3_bm  (1<<3)  /* Interrupt Level Priority bit 3 mask. */
#define CPUINT_LVL0PRI3_bp  3  /* Interrupt Level Priority bit 3 position. */
#define CPUINT_LVL0PRI4_bm  (1<<4)  /* Interrupt Level Priority bit 4 mask. */
#define CPUINT_LVL0PRI4_bp  4  /* Interrupt Level Priority bit 4 position. */
#define CPUINT_LVL0PRI5_bm  (1<<5)  /* Interrupt Level Priority bit 5 mask. */
#define CPUINT_LVL0PRI5_bp  5  /* Interrupt Level Priority bit 5 position. */
#define CPUINT_LVL0PRI6_bm  (1<<6)  /* Interrupt Level Priority bit 6 mask. */
#define CPUINT_LVL0PRI6_bp  6  /* Interrupt Level Priority bit 6 position. */
#define CPUINT_LVL0PRI7_bm  (1<<7)  /* Interrupt Level Priority bit 7 mask. */
#define CPUINT_LVL0PRI7_bp  7  /* Interrupt Level Priority bit 7 position. */

/* CPUINT.LVL1VEC  bit masks and bit positions */
#define CPUINT_LVL1VEC_gm  0xFF  /* Interrupt Vector with High Priority group mask. */
#define CPUINT_LVL1VEC_gp  0  /* Interrupt Vector with High Priority group position. */
#define CPUINT_LVL1VEC0_bm  (1<<0)  /* Interrupt Vector with High Priority bit 0 mask. */
#define CPUINT_LVL1VEC0_bp  0  /* Interrupt Vector with High Priority bit 0 position. */
#define CPUINT_LVL1VEC1_bm  (1<<1)  /* Interrupt Vector with High Priority bit 1 mask. */
#define CPUINT_LVL1VEC1_bp  1  /* Interrupt Vector with High Priority bit 1 position. */
#define CPUINT_LVL1VEC2_bm  (1<<2)  /* Interrupt Vector with High Priority bit 2 mask. */
#define CPUINT_LVL1VEC2_bp  2  /* Interrupt Vector with High Priority bit 2 position. */
#define CPUINT_LVL1VEC3_bm  (1<<3)  /* Interrupt Vector with High Priority bit 3 mask. */
#define CPUINT_LVL1VEC3_bp  3  /* Interrupt Vector with High Priority bit 3 position. */
#define CPUINT_LVL1VEC4_bm  (1<<4)  /* Interrupt Vector with High Priority bit 4 mask. */
#define CPUINT_LVL1VEC4_bp  4  /* Interrupt Vector with High Priority bit 4 position. */
#define CPUINT_LVL1VEC5_bm  (1<<5)  /* Interrupt Vector with High Priority bit 5 mask. */
#define CPUINT_LVL1VEC5_bp  5  /* Interrupt Vector with High Priority bit 5 position. */
#define CPUINT_LVL1VEC6_bm  (1<<6)  /* Interrupt Vector with High Priority bit 6 mask. */
#define CPUINT_LVL1VEC6_bp  6  /* Interrupt Vector with High Priority bit 6 position. */
#define CPUINT_LVL1VEC7_bm  (1<<7)  /* Interrupt Vector with High Priority bit 7 mask. */
#define CPUINT_LVL1VEC7_bp  7  /* Interrupt Vector with High Priority bit 7 position. */

/* CRCSCAN - CRCSCAN */
/* CRCSCAN.CTRLA  bit masks and bit positions */
#define CRCSCAN_ENABLE_bm  0x01  /* Enable CRC scan bit mask. */
#define CRCSCAN_ENABLE_bp  0  /* Enable CRC scan bit position. */
#define CRCSCAN_NMIEN_bm  0x02  /* Enable NMI Trigger bit mask. */
#define CRCSCAN_NMIEN_bp  1  /* Enable NMI Trigger bit position. */
#define CRCSCAN_RESET_bm  0x80  /* Reset CRC scan bit mask. */
#define CRCSCAN_RESET_bp  7  /* Reset CRC scan bit position. */

/* CRCSCAN.CTRLB  bit masks and bit positions */
#define CRCSCAN_SRC_gm  0x03  /* CRC Source group mask. */
#define CRCSCAN_SRC_gp  0  /* CRC Source group position. */
#define CRCSCAN_SRC0_bm  (1<<0)  /* CRC Source bit 0 mask. */
#define CRCSCAN_SRC0_bp  0  /* CRC Source bit 0 position. */
#define CRCSCAN_SRC1_bm  (1<<1)  /* CRC Source bit 1 mask. */
#define CRCSCAN_SRC1_bp  1  /* CRC Source bit 1 position. */
#define CRCSCAN_MODE_gm  0x30  /* CRC Flash Access Mode group mask. */
#define CRCSCAN_MODE_gp  4  /* CRC Flash Access Mode group position. */
#define CRCSCAN_MODE0_bm  (1<<4)  /* CRC Flash Access Mode bit 0 mask. */
#define CRCSCAN_MODE0_bp  4  /* CRC Flash Access Mode bit 0 position. */
#define CRCSCAN_MODE1_bm  (1<<5)  /* CRC Flash Access Mode bit 1 mask. */
#define CRCSCAN_MODE1_bp  5  /* CRC Flash Access Mode bit 1 position. */

/* CRCSCAN.STATUS  bit masks and bit positions */
#define CRCSCAN_BUSY_bm  0x01  /* CRC Busy bit mask. */
#define CRCSCAN_BUSY_bp  0  /* CRC Busy bit position. */
#define CRCSCAN_OK_bm  0x02  /* CRC Ok bit mask. */
#define CRCSCAN_OK_bp  1  /* CRC Ok bit position. */

/* EVSYS - Event System */
/* EVSYS.STROBE  bit masks and bit positions */
#define EVSYS_STROBE0_gm  0xFF  /* Software event on channels group mask. */
#define EVSYS_STROBE0_gp  0  /* Software event on channels group position. */
#define EVSYS_STROBE00_bm  (1<<0)  /* Software event on channels bit 0 mask. */
#define EVSYS_STROBE00_bp  0  /* Software event on channels bit 0 position. */
#define EVSYS_STROBE01_bm  (1<<1)  /* Software event on channels bit 1 mask. */
#define EVSYS_STROBE01_bp  1  /* Software event on channels bit 1 position. */
#define EVSYS_STROBE02_bm  (1<<2)  /* Software event on channels bit 2 mask. */
#define EVSYS_STROBE02_bp  2  /* Software event on channels bit 2 position. */
#define EVSYS_STROBE03_bm  (1<<3)  /* Software event on channels bit 3 mask. */
#define EVSYS_STROBE03_bp  3  /* Software event on channels bit 3 position. */
#define EVSYS_STROBE04_bm  (1<<4)  /* Software event on channels bit 4 mask. */
#define EVSYS_STROBE04_bp  4  /* Software event on channels bit 4 position. */
#define EVSYS_STROBE05_bm  (1<<5)  /* Software event on channels bit 5 mask. */
#define EVSYS_STROBE05_bp  5  /* Software event on channels bit 5 position. */
#define EVSYS_STROBE06_bm  (1<<6)  /* Software event on channels bit 6 mask. */
#define EVSYS_STROBE06_bp  6  /* Software event on channels bit 6 position. */
#define EVSYS_STROBE07_bm  (1<<7)  /* Software event on channels bit 7 mask. */
#define EVSYS_STROBE07_bp  7  /* Software event on channels bit 7 position. */

/* EVSYS.CHANNEL0  bit masks and bit positions */
#define EVSYS_GENERATOR_gm  0xFF  /* Generator selector group mask. */
#define EVSYS_GENERATOR_gp  0  /* Generator selector group position. */
#define EVSYS_GENERATOR0_bm  (1<<0)  /* Generator selector bit 0 mask. */
#define EVSYS_GENERATOR0_bp  0  /* Generator selector bit 0 position. */
#define EVSYS_GENERATOR1_bm  (1<<1)  /* Generator selector bit 1 mask. */
#define EVSYS_GENERATOR1_bp  1  /* Generator selector bit 1 position. */
#define EVSYS_GENERATOR2_bm  (1<<2)  /* Generator selector bit 2 mask. */
#define EVSYS_GENERATOR2_bp  2  /* Generator selector bit 2 position. */
#define EVSYS_GENERATOR3_bm  (1<<3)  /* Generator selector bit 3 mask. */
#define EVSYS_GENERATOR3_bp  3  /* Generator selector bit 3 position. */
#define EVSYS_GENERATOR4_bm  (1<<4)  /* Generator selector bit 4 mask. */
#define EVSYS_GENERATOR4_bp  4  /* Generator selector bit 4 position. */
#define EVSYS_GENERATOR5_bm  (1<<5)  /* Generator selector bit 5 mask. */
#define EVSYS_GENERATOR5_bp  5  /* Generator selector bit 5 position. */
#define EVSYS_GENERATOR6_bm  (1<<6)  /* Generator selector bit 6 mask. */
#define EVSYS_GENERATOR6_bp  6  /* Generator selector bit 6 position. */
#define EVSYS_GENERATOR7_bm  (1<<7)  /* Generator selector bit 7 mask. */
#define EVSYS_GENERATOR7_bp  7  /* Generator selector bit 7 position. */

/* EVSYS.CHANNEL1  bit masks and bit positions */
/* EVSYS_GENERATOR  is already defined. */

/* EVSYS.CHANNEL2  bit masks and bit positions */
/* EVSYS_GENERATOR  is already defined. */

/* EVSYS.CHANNEL3  bit masks and bit positions */
/* EVSYS_GENERATOR  is already defined. */

/* EVSYS.CHANNEL4  bit masks and bit positions */
/* EVSYS_GENERATOR  is already defined. */

/* EVSYS.CHANNEL5  bit masks and bit positions */
/* EVSYS_GENERATOR  is already defined. */

/* EVSYS.USERCCLLUT0A  bit masks and bit positions */
#define EVSYS_CHANNEL_gm  0xFF  /* Channel selector group mask. */
#define EVSYS_CHANNEL_gp  0  /* Channel selector group position. */
#define EVSYS_CHANNEL0_bm  (1<<0)  /* Channel selector bit 0 mask. */
#define EVSYS_CHANNEL0_bp  0  /* Channel selector bit 0 position. */
#define EVSYS_CHANNEL1_bm  (1<<1)  /* Channel selector bit 1 mask. */
#define EVSYS_CHANNEL1_bp  1  /* Channel selector bit 1 position. */
#define EVSYS_CHANNEL2_bm  (1<<2)  /* Channel selector bit 2 mask. */
#define EVSYS_CHANNEL2_bp  2  /* Channel selector bit 2 position. */
#define EVSYS_CHANNEL3_bm  (1<<3)  /* Channel selector bit 3 mask. */
#define EVSYS_CHANNEL3_bp  3  /* Channel selector bit 3 position. */
#define EVSYS_CHANNEL4_bm  (1<<4)  /* Channel selector bit 4 mask. */
#define EVSYS_CHANNEL4_bp  4  /* Channel selector bit 4 position. */
#define EVSYS_CHANNEL5_bm  (1<<5)  /* Channel selector bit 5 mask. */
#define EVSYS_CHANNEL5_bp  5  /* Channel selector bit 5 position. */
#define EVSYS_CHANNEL6_bm  (1<<6)  /* Channel selector bit 6 mask. */
#define EVSYS_CHANNEL6_bp  6  /* Channel selector bit 6 position. */
#define EVSYS_CHANNEL7_bm  (1<<7)  /* Channel selector bit 7 mask. */
#define EVSYS_CHANNEL7_bp  7  /* Channel selector bit 7 position. */

/* EVSYS.USERCCLLUT0B  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT1A  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT1B  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT2A  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT2B  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT3A  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT3B  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERADC0  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTA  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTB  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTC  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTD  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTE  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USEREVOUTF  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERUSART0  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERUSART1  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERUSART2  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERUSART3  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERTCA0  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERTCB0  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERTCB1  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERTCB2  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERTCB3  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* FUSE - Fuses */
/* FUSE.WDTCFG  bit masks and bit positions */
#define FUSE_PERIOD_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define FUSE_PERIOD_gp  0  /* Watchdog Timeout Period group position. */
#define FUSE_PERIOD0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define FUSE_PERIOD0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define FUSE_PERIOD1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define FUSE_PERIOD1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define FUSE_PERIOD2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define FUSE_PERIOD2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define FUSE_PERIOD3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define FUSE_PERIOD3_bp  3  /* Watchdog Timeout Period bit 3 position. */
#define FUSE_WINDOW_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define FUSE_WINDOW_gp  4  /* Watchdog Window Timeout Period group position. */
#define FUSE_WINDOW0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define FUSE_WINDOW0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define FUSE_WINDOW1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define FUSE_WINDOW1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define FUSE_WINDOW2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define FUSE_WINDOW2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define FUSE_WINDOW3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define FUSE_WINDOW3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

/* FUSE.BODCFG  bit masks and bit positions */
#define FUSE_SLEEP_gm  0x03  /* BOD Operation in Sleep Mode group mask. */
#define FUSE_SLEEP_gp  0  /* BOD Operation in Sleep Mode group position. */
#define FUSE_SLEEP0_bm  (1<<0)  /* BOD Operation in Sleep Mode bit 0 mask. */
#define FUSE_SLEEP0_bp  0  /* BOD Operation in Sleep Mode bit 0 position. */
#define FUSE_SLEEP1_bm  (1<<1)  /* BOD Operation in Sleep Mode bit 1 mask. */
#define FUSE_SLEEP1_bp  1  /* BOD Operation in Sleep Mode bit 1 position. */
#define FUSE_ACTIVE_gm  0x0C  /* BOD Operation in Active Mode group mask. */
#define FUSE_ACTIVE_gp  2  /* BOD Operation in Active Mode group position. */
#define FUSE_ACTIVE0_bm  (1<<2)  /* BOD Operation in Active Mode bit 0 mask. */
#define FUSE_ACTIVE0_bp  2  /* BOD Operation in Active Mode bit 0 position. */
#define FUSE_ACTIVE1_bm  (1<<3)  /* BOD Operation in Active Mode bit 1 mask. */
#define FUSE_ACTIVE1_bp  3  /* BOD Operation in Active Mode bit 1 position. */
#define FUSE_SAMPFREQ_bm  0x10  /* BOD Sample Frequency bit mask. */
#define FUSE_SAMPFREQ_bp  4  /* BOD Sample Frequency bit position. */
#define FUSE_LVL_gm  0xE0  /* BOD Level group mask. */
#define FUSE_LVL_gp  5  /* BOD Level group position. */
#define FUSE_LVL0_bm  (1<<5)  /* BOD Level bit 0 mask. */
#define FUSE_LVL0_bp  5  /* BOD Level bit 0 position. */
#define FUSE_LVL1_bm  (1<<6)  /* BOD Level bit 1 mask. */
#define FUSE_LVL1_bp  6  /* BOD Level bit 1 position. */
#define FUSE_LVL2_bm  (1<<7)  /* BOD Level bit 2 mask. */
#define FUSE_LVL2_bp  7  /* BOD Level bit 2 position. */

/* FUSE.OSCCFG  bit masks and bit positions */
#define FUSE_FREQSEL_gm  0x03  /* Frequency Select group mask. */
#define FUSE_FREQSEL_gp  0  /* Frequency Select group position. */
#define FUSE_FREQSEL0_bm  (1<<0)  /* Frequency Select bit 0 mask. */
#define FUSE_FREQSEL0_bp  0  /* Frequency Select bit 0 position. */
#define FUSE_FREQSEL1_bm  (1<<1)  /* Frequency Select bit 1 mask. */
#define FUSE_FREQSEL1_bp  1  /* Frequency Select bit 1 position. */
#define FUSE_OSCLOCK_bm  0x80  /* Oscillator Lock bit mask. */
#define FUSE_OSCLOCK_bp  7  /* Oscillator Lock bit position. */

/* FUSE.SYSCFG0  bit masks and bit positions */
#define FUSE_EESAVE_bm  0x01  /* EEPROM Save bit mask. */
#define FUSE_EESAVE_bp  0  /* EEPROM Save bit position. */
#define FUSE_RSTPINCFG_bm  0x08  /* Reset Pin Configuration bit mask. */
#define FUSE_RSTPINCFG_bp  3  /* Reset Pin Configuration bit position. */
#define FUSE_CRCSRC_gm  0xC0  /* CRC Source group mask. */
#define FUSE_CRCSRC_gp  6  /* CRC Source group position. */
#define FUSE_CRCSRC0_bm  (1<<6)  /* CRC Source bit 0 mask. */
#define FUSE_CRCSRC0_bp  6  /* CRC Source bit 0 position. */
#define FUSE_CRCSRC1_bm  (1<<7)  /* CRC Source bit 1 mask. */
#define FUSE_CRCSRC1_bp  7  /* CRC Source bit 1 position. */

/* FUSE.SYSCFG1  bit masks and bit positions */
#define FUSE_SUT_gm  0x07  /* Startup Time group mask. */
#define FUSE_SUT_gp  0  /* Startup Time group position. */
#define FUSE_SUT0_bm  (1<<0)  /* Startup Time bit 0 mask. */
#define FUSE_SUT0_bp  0  /* Startup Time bit 0 position. */
#define FUSE_SUT1_bm  (1<<1)  /* Startup Time bit 1 mask. */
#define FUSE_SUT1_bp  1  /* Startup Time bit 1 position. */
#define FUSE_SUT2_bm  (1<<2)  /* Startup Time bit 2 mask. */
#define FUSE_SUT2_bp  2  /* Startup Time bit 2 position. */







/* LOCKBIT - Lockbit */
/* LOCKBIT.LOCKBIT  bit masks and bit positions */
#define LOCKBIT_LB_gm  0xFF  /* Lock Bits group mask. */
#define LOCKBIT_LB_gp  0  /* Lock Bits group position. */
#define LOCKBIT_LB0_bm  (1<<0)  /* Lock Bits bit 0 mask. */
#define LOCKBIT_LB0_bp  0  /* Lock Bits bit 0 position. */
#define LOCKBIT_LB1_bm  (1<<1)  /* Lock Bits bit 1 mask. */
#define LOCKBIT_LB1_bp  1  /* Lock Bits bit 1 position. */
#define LOCKBIT_LB2_bm  (1<<2)  /* Lock Bits bit 2 mask. */
#define LOCKBIT_LB2_bp  2  /* Lock Bits bit 2 position. */
#define LOCKBIT_LB3_bm  (1<<3)  /* Lock Bits bit 3 mask. */
#define LOCKBIT_LB3_bp  3  /* Lock Bits bit 3 position. */
#define LOCKBIT_LB4_bm  (1<<4)  /* Lock Bits bit 4 mask. */
#define LOCKBIT_LB4_bp  4  /* Lock Bits bit 4 position. */
#define LOCKBIT_LB5_bm  (1<<5)  /* Lock Bits bit 5 mask. */
#define LOCKBIT_LB5_bp  5  /* Lock Bits bit 5 position. */
#define LOCKBIT_LB6_bm  (1<<6)  /* Lock Bits bit 6 mask. */
#define LOCKBIT_LB6_bp  6  /* Lock Bits bit 6 position. */
#define LOCKBIT_LB7_bm  (1<<7)  /* Lock Bits bit 7 mask. */
#define LOCKBIT_LB7_bp  7  /* Lock Bits bit 7 position. */

/* NVMCTRL - Non-volatile Memory Controller */
/* NVMCTRL.CTRLA  bit masks and bit positions */
#define NVMCTRL_CMD_gm  0x07  /* Command group mask. */
#define NVMCTRL_CMD_gp  0  /* Command group position. */
#define NVMCTRL_CMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVMCTRL_CMD0_bp  0  /* Command bit 0 position. */
#define NVMCTRL_CMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVMCTRL_CMD1_bp  1  /* Command bit 1 position. */
#define NVMCTRL_CMD2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVMCTRL_CMD2_bp  2  /* Command bit 2 position. */

/* NVMCTRL.CTRLB  bit masks and bit positions */
#define NVMCTRL_APCWP_bm  0x01  /* Application code write protect bit mask. */
#define NVMCTRL_APCWP_bp  0  /* Application code write protect bit position. */
#define NVMCTRL_BOOTLOCK_bm  0x02  /* Boot Lock bit mask. */
#define NVMCTRL_BOOTLOCK_bp  1  /* Boot Lock bit position. */

/* NVMCTRL.STATUS  bit masks and bit positions */
#define NVMCTRL_FBUSY_bm  0x01  /* Flash busy bit mask. */
#define NVMCTRL_FBUSY_bp  0  /* Flash busy bit position. */
#define NVMCTRL_EEBUSY_bm  0x02  /* EEPROM busy bit mask. */
#define NVMCTRL_EEBUSY_bp  1  /* EEPROM busy bit position. */
#define NVMCTRL_WRERROR_bm  0x04  /* Write error bit mask. */
#define NVMCTRL_WRERROR_bp  2  /* Write error bit position. */

/* NVMCTRL.INTCTRL  bit masks and bit positions */
#define NVMCTRL_EEREADY_bm  0x01  /* EEPROM Ready bit mask. */
#define NVMCTRL_EEREADY_bp  0  /* EEPROM Ready bit position. */

/* NVMCTRL.INTFLAGS  bit masks and bit positions */
/* NVMCTRL_EEREADY  is already defined. */












/* PORT - I/O Ports */
/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define PORT_INT_gp  0  /* Pin Interrupt group position. */
#define PORT_INT0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define PORT_INT0_bp  0  /* Pin Interrupt bit 0 position. */
#define PORT_INT1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define PORT_INT1_bp  1  /* Pin Interrupt bit 1 position. */
#define PORT_INT2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define PORT_INT2_bp  2  /* Pin Interrupt bit 2 position. */
#define PORT_INT3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define PORT_INT3_bp  3  /* Pin Interrupt bit 3 position. */
#define PORT_INT4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define PORT_INT4_bp  4  /* Pin Interrupt bit 4 position. */
#define PORT_INT5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define PORT_INT5_bp  5  /* Pin Interrupt bit 5 position. */
#define PORT_INT6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define PORT_INT6_bp  6  /* Pin Interrupt bit 6 position. */
#define PORT_INT7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define PORT_INT7_bp  7  /* Pin Interrupt bit 7 position. */

/* PORT.PORTCTRL  bit masks and bit positions */
#define PORT_SRL_bm  0x01  /* Slew Rate Limit Enable bit mask. */
#define PORT_SRL_bp  0  /* Slew Rate Limit Enable bit position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC2_bp  2  /* Input/Sense Configuration bit 2 position. */
#define PORT_PULLUPEN_bm  0x08  /* Pullup enable bit mask. */
#define PORT_PULLUPEN_bp  3  /* Pullup enable bit position. */
#define PORT_INVEN_bm  0x80  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  7  /* Inverted I/O Enable bit position. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORTMUX - Port Multiplexer */
/* PORTMUX.EVSYSROUTEA  bit masks and bit positions */
#define PORTMUX_EVOUT0_bm  0x01  /* Event Output 0 bit mask. */
#define PORTMUX_EVOUT0_bp  0  /* Event Output 0 bit position. */
#define PORTMUX_EVOUT1_bm  0x02  /* Event Output 1 bit mask. */
#define PORTMUX_EVOUT1_bp  1  /* Event Output 1 bit position. */
#define PORTMUX_EVOUT2_bm  0x04  /* Event Output 2 bit mask. */
#define PORTMUX_EVOUT2_bp  2  /* Event Output 2 bit position. */
#define PORTMUX_EVOUT3_bm  0x08  /* Event Output 3 bit mask. */
#define PORTMUX_EVOUT3_bp  3  /* Event Output 3 bit position. */
#define PORTMUX_EVOUT4_bm  0x10  /* Event Output 4 bit mask. */
#define PORTMUX_EVOUT4_bp  4  /* Event Output 4 bit position. */
#define PORTMUX_EVOUT5_bm  0x20  /* Event Output 5 bit mask. */
#define PORTMUX_EVOUT5_bp  5  /* Event Output 5 bit position. */

/* PORTMUX.CCLROUTEA  bit masks and bit positions */
#define PORTMUX_LUT0_bm  0x01  /* CCL LUT0 bit mask. */
#define PORTMUX_LUT0_bp  0  /* CCL LUT0 bit position. */
#define PORTMUX_LUT1_bm  0x02  /* CCL LUT1 bit mask. */
#define PORTMUX_LUT1_bp  1  /* CCL LUT1 bit position. */
#define PORTMUX_LUT2_bm  0x04  /* CCL LUT2 bit mask. */
#define PORTMUX_LUT2_bp  2  /* CCL LUT2 bit position. */
#define PORTMUX_LUT3_bm  0x08  /* CCL LUT3 bit mask. */
#define PORTMUX_LUT3_bp  3  /* CCL LUT3 bit position. */

/* PORTMUX.USARTROUTEA  bit masks and bit positions */
#define PORTMUX_USART0_gm  0x03  /* Port Multiplexer USART0 group mask. */
#define PORTMUX_USART0_gp  0  /* Port Multiplexer USART0 group position. */
#define PORTMUX_USART00_bm  (1<<0)  /* Port Multiplexer USART0 bit 0 mask. */
#define PORTMUX_USART00_bp  0  /* Port Multiplexer USART0 bit 0 position. */
#define PORTMUX_USART01_bm  (1<<1)  /* Port Multiplexer USART0 bit 1 mask. */
#define PORTMUX_USART01_bp  1  /* Port Multiplexer USART0 bit 1 position. */
#define PORTMUX_USART1_gm  0x0C  /* Port Multiplexer USART1 group mask. */
#define PORTMUX_USART1_gp  2  /* Port Multiplexer USART1 group position. */
#define PORTMUX_USART10_bm  (1<<2)  /* Port Multiplexer USART1 bit 0 mask. */
#define PORTMUX_USART10_bp  2  /* Port Multiplexer USART1 bit 0 position. */
#define PORTMUX_USART11_bm  (1<<3)  /* Port Multiplexer USART1 bit 1 mask. */
#define PORTMUX_USART11_bp  3  /* Port Multiplexer USART1 bit 1 position. */
#define PORTMUX_USART2_gm  0x30  /* Port Multiplexer USART2 group mask. */
#define PORTMUX_USART2_gp  4  /* Port Multiplexer USART2 group position. */
#define PORTMUX_USART20_bm  (1<<4)  /* Port Multiplexer USART2 bit 0 mask. */
#define PORTMUX_USART20_bp  4  /* Port Multiplexer USART2 bit 0 position. */
#define PORTMUX_USART21_bm  (1<<5)  /* Port Multiplexer USART2 bit 1 mask. */
#define PORTMUX_USART21_bp  5  /* Port Multiplexer USART2 bit 1 position. */
#define PORTMUX_USART3_gm  0xC0  /* Port Multiplexer USART3 group mask. */
#define PORTMUX_USART3_gp  6  /* Port Multiplexer USART3 group position. */
#define PORTMUX_USART30_bm  (1<<6)  /* Port Multiplexer USART3 bit 0 mask. */
#define PORTMUX_USART30_bp  6  /* Port Multiplexer USART3 bit 0 position. */
#define PORTMUX_USART31_bm  (1<<7)  /* Port Multiplexer USART3 bit 1 mask. */
#define PORTMUX_USART31_bp  7  /* Port Multiplexer USART3 bit 1 position. */

/* PORTMUX.TWISPIROUTEA  bit masks and bit positions */
#define PORTMUX_SPI0_gm  0x03  /* Port Multiplexer SPI0 group mask. */
#define PORTMUX_SPI0_gp  0  /* Port Multiplexer SPI0 group position. */
#define PORTMUX_SPI00_bm  (1<<0)  /* Port Multiplexer SPI0 bit 0 mask. */
#define PORTMUX_SPI00_bp  0  /* Port Multiplexer SPI0 bit 0 position. */
#define PORTMUX_SPI01_bm  (1<<1)  /* Port Multiplexer SPI0 bit 1 mask. */
#define PORTMUX_SPI01_bp  1  /* Port Multiplexer SPI0 bit 1 position. */
#define PORTMUX_TWI0_gm  0x30  /* Port Multiplexer TWI0 group mask. */
#define PORTMUX_TWI0_gp  4  /* Port Multiplexer TWI0 group position. */
#define PORTMUX_TWI00_bm  (1<<4)  /* Port Multiplexer TWI0 bit 0 mask. */
#define PORTMUX_TWI00_bp  4  /* Port Multiplexer TWI0 bit 0 position. */
#define PORTMUX_TWI01_bm  (1<<5)  /* Port Multiplexer TWI0 bit 1 mask. */
#define PORTMUX_TWI01_bp  5  /* Port Multiplexer TWI0 bit 1 position. */

/* PORTMUX.TCAROUTEA  bit masks and bit positions */
#define PORTMUX_TCA0_gm  0x07  /* Port Multiplexer TCA0 group mask. */
#define PORTMUX_TCA0_gp  0  /* Port Multiplexer TCA0 group position. */
#define PORTMUX_TCA00_bm  (1<<0)  /* Port Multiplexer TCA0 bit 0 mask. */
#define PORTMUX_TCA00_bp  0  /* Port Multiplexer TCA0 bit 0 position. */
#define PORTMUX_TCA01_bm  (1<<1)  /* Port Multiplexer TCA0 bit 1 mask. */
#define PORTMUX_TCA01_bp  1  /* Port Multiplexer TCA0 bit 1 position. */
#define PORTMUX_TCA02_bm  (1<<2)  /* Port Multiplexer TCA0 bit 2 mask. */
#define PORTMUX_TCA02_bp  2  /* Port Multiplexer TCA0 bit 2 position. */

/* PORTMUX.TCBROUTEA  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /* Port Multiplexer TCB0 bit mask. */
#define PORTMUX_TCB0_bp  0  /* Port Multiplexer TCB0 bit position. */
#define PORTMUX_TCB1_bm  0x02  /* Port Multiplexer TCB1 bit mask. */
#define PORTMUX_TCB1_bp  1  /* Port Multiplexer TCB1 bit position. */
#define PORTMUX_TCB2_bm  0x04  /* Port Multiplexer TCB2 bit mask. */
#define PORTMUX_TCB2_bp  2  /* Port Multiplexer TCB2 bit position. */
#define PORTMUX_TCB3_bm  0x08  /* Port Multiplexer TCB3 bit mask. */
#define PORTMUX_TCB3_bp  3  /* Port Multiplexer TCB3 bit position. */

/* RSTCTRL - Reset controller */
/* RSTCTRL.RSTFR  bit masks and bit positions */
#define RSTCTRL_PORF_bm  0x01  /* Power on Reset flag bit mask. */
#define RSTCTRL_PORF_bp  0  /* Power on Reset flag bit position. */
#define RSTCTRL_BORF_bm  0x02  /* Brown out detector Reset flag bit mask. */
#define RSTCTRL_BORF_bp  1  /* Brown out detector Reset flag bit position. */
#define RSTCTRL_EXTRF_bm  0x04  /* External Reset flag bit mask. */
#define RSTCTRL_EXTRF_bp  2  /* External Reset flag bit position. */
#define RSTCTRL_WDRF_bm  0x08  /* Watch dog Reset flag bit mask. */
#define RSTCTRL_WDRF_bp  3  /* Watch dog Reset flag bit position. */
#define RSTCTRL_SWRF_bm  0x10  /* Software Reset flag bit mask. */
#define RSTCTRL_SWRF_bp  4  /* Software Reset flag bit position. */
#define RSTCTRL_UPDIRF_bm  0x20  /* UPDI Reset flag bit mask. */
#define RSTCTRL_UPDIRF_bp  5  /* UPDI Reset flag bit position. */

/* RSTCTRL.SWRR  bit masks and bit positions */
#define RSTCTRL_SWRE_bm  0x01  /* Software reset enable bit mask. */
#define RSTCTRL_SWRE_bp  0  /* Software reset enable bit position. */

/* RTC - Real-Time Counter */
/* RTC.CTRLA  bit masks and bit positions */
#define RTC_RTCEN_bm  0x01  /* Enable bit mask. */
#define RTC_RTCEN_bp  0  /* Enable bit position. */
#define RTC_PRESCALER_gm  0x78  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  3  /* Prescaling Factor group position. */
#define RTC_PRESCALER0_bm  (1<<3)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER0_bp  3  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER1_bm  (1<<4)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER1_bp  4  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER2_bm  (1<<5)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER2_bp  5  /* Prescaling Factor bit 2 position. */
#define RTC_PRESCALER3_bm  (1<<6)  /* Prescaling Factor bit 3 mask. */
#define RTC_PRESCALER3_bp  6  /* Prescaling Factor bit 3 position. */
#define RTC_RUNSTDBY_bm  0x80  /* Run In Standby bit mask. */
#define RTC_RUNSTDBY_bp  7  /* Run In Standby bit position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_CTRLABUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLABUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */
#define RTC_CNTBUSY_bm  0x02  /* Count Synchronization Busy Flag bit mask. */
#define RTC_CNTBUSY_bp  1  /* Count Synchronization Busy Flag bit position. */
#define RTC_PERBUSY_bm  0x04  /* Period Synchronization Busy Flag bit mask. */
#define RTC_PERBUSY_bp  2  /* Period Synchronization Busy Flag bit position. */
#define RTC_CMPBUSY_bm  0x08  /* Comparator Synchronization Busy Flag bit mask. */
#define RTC_CMPBUSY_bp  3  /* Comparator Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_OVF_bm  0x01  /* Overflow Interrupt enable bit mask. */
#define RTC_OVF_bp  0  /* Overflow Interrupt enable bit position. */
#define RTC_CMP_bm  0x02  /* Compare Match Interrupt enable bit mask. */
#define RTC_CMP_bp  1  /* Compare Match Interrupt enable bit position. */

/* RTC.INTFLAGS  bit masks and bit positions */
/* RTC_OVF  is already defined. */
/* RTC_CMP  is already defined. */


/* RTC.DBGCTRL  bit masks and bit positions */
#define RTC_DBGRUN_bm  0x01  /* Run in debug bit mask. */
#define RTC_DBGRUN_bp  0  /* Run in debug bit position. */

/* RTC.CALIB  bit masks and bit positions */
#define RTC_ERROR_gm  0x7F  /* Error Correction Value group mask. */
#define RTC_ERROR_gp  0  /* Error Correction Value group position. */
#define RTC_ERROR0_bm  (1<<0)  /* Error Correction Value bit 0 mask. */
#define RTC_ERROR0_bp  0  /* Error Correction Value bit 0 position. */
#define RTC_ERROR1_bm  (1<<1)  /* Error Correction Value bit 1 mask. */
#define RTC_ERROR1_bp  1  /* Error Correction Value bit 1 position. */
#define RTC_ERROR2_bm  (1<<2)  /* Error Correction Value bit 2 mask. */
#define RTC_ERROR2_bp  2  /* Error Correction Value bit 2 position. */
#define RTC_ERROR3_bm  (1<<3)  /* Error Correction Value bit 3 mask. */
#define RTC_ERROR3_bp  3  /* Error Correction Value bit 3 position. */
#define RTC_ERROR4_bm  (1<<4)  /* Error Correction Value bit 4 mask. */
#define RTC_ERROR4_bp  4  /* Error Correction Value bit 4 position. */
#define RTC_ERROR5_bm  (1<<5)  /* Error Correction Value bit 5 mask. */
#define RTC_ERROR5_bp  5  /* Error Correction Value bit 5 position. */
#define RTC_ERROR6_bm  (1<<6)  /* Error Correction Value bit 6 mask. */
#define RTC_ERROR6_bp  6  /* Error Correction Value bit 6 position. */
#define RTC_SIGN_bm  0x80  /* Error Correction Sign Bit bit mask. */
#define RTC_SIGN_bp  7  /* Error Correction Sign Bit bit position. */

/* RTC.CLKSEL  bit masks and bit positions */
#define RTC_CLKSEL_gm  0x03  /* Clock Select group mask. */
#define RTC_CLKSEL_gp  0  /* Clock Select group position. */
#define RTC_CLKSEL0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define RTC_CLKSEL0_bp  0  /* Clock Select bit 0 position. */
#define RTC_CLKSEL1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define RTC_CLKSEL1_bp  1  /* Clock Select bit 1 position. */




/* RTC.PITCTRLA  bit masks and bit positions */
#define RTC_PITEN_bm  0x01  /* Enable bit mask. */
#define RTC_PITEN_bp  0  /* Enable bit position. */
#define RTC_PERIOD_gm  0x78  /* Period group mask. */
#define RTC_PERIOD_gp  3  /* Period group position. */
#define RTC_PERIOD0_bm  (1<<3)  /* Period bit 0 mask. */
#define RTC_PERIOD0_bp  3  /* Period bit 0 position. */
#define RTC_PERIOD1_bm  (1<<4)  /* Period bit 1 mask. */
#define RTC_PERIOD1_bp  4  /* Period bit 1 position. */
#define RTC_PERIOD2_bm  (1<<5)  /* Period bit 2 mask. */
#define RTC_PERIOD2_bp  5  /* Period bit 2 position. */
#define RTC_PERIOD3_bm  (1<<6)  /* Period bit 3 mask. */
#define RTC_PERIOD3_bp  6  /* Period bit 3 position. */

/* RTC.PITSTATUS  bit masks and bit positions */
#define RTC_CTRLBUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLBUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */

/* RTC.PITINTCTRL  bit masks and bit positions */
#define RTC_PI_bm  0x01  /* Periodic Interrupt bit mask. */
#define RTC_PI_bp  0  /* Periodic Interrupt bit position. */

/* RTC.PITINTFLAGS  bit masks and bit positions */
/* RTC_PI  is already defined. */

/* RTC.PITDBGCTRL  bit masks and bit positions */
/* RTC_DBGRUN  is already defined. */


























/* SLPCTRL - Sleep Controller */
/* SLPCTRL.CTRLA  bit masks and bit positions */
#define SLPCTRL_SEN_bm  0x01  /* Sleep enable bit mask. */
#define SLPCTRL_SEN_bp  0  /* Sleep enable bit position. */
#define SLPCTRL_SMODE_gm  0x06  /* Sleep mode group mask. */
#define SLPCTRL_SMODE_gp  1  /* Sleep mode group position. */
#define SLPCTRL_SMODE0_bm  (1<<1)  /* Sleep mode bit 0 mask. */
#define SLPCTRL_SMODE0_bp  1  /* Sleep mode bit 0 position. */
#define SLPCTRL_SMODE1_bm  (1<<2)  /* Sleep mode bit 1 mask. */
#define SLPCTRL_SMODE1_bp  2  /* Sleep mode bit 1 position. */

/* SPI - Serial Peripheral Interface */
/* SPI.CTRLA  bit masks and bit positions */
#define SPI_ENABLE_bm  0x01  /* Enable Module bit mask. */
#define SPI_ENABLE_bp  0  /* Enable Module bit position. */
#define SPI_PRESC_gm  0x06  /* Prescaler group mask. */
#define SPI_PRESC_gp  1  /* Prescaler group position. */
#define SPI_PRESC0_bm  (1<<1)  /* Prescaler bit 0 mask. */
#define SPI_PRESC0_bp  1  /* Prescaler bit 0 position. */
#define SPI_PRESC1_bm  (1<<2)  /* Prescaler bit 1 mask. */
#define SPI_PRESC1_bp  2  /* Prescaler bit 1 position. */
#define SPI_CLK2X_bm  0x10  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  4  /* Enable Double Speed bit position. */
#define SPI_MASTER_bm  0x20  /* Master Operation Enable bit mask. */
#define SPI_MASTER_bp  5  /* Master Operation Enable bit position. */
#define SPI_DORD_bm  0x40  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  6  /* Data Order Setting bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_MODE_gm  0x03  /* SPI Mode group mask. */
#define SPI_MODE_gp  0  /* SPI Mode group position. */
#define SPI_MODE0_bm  (1<<0)  /* SPI Mode bit 0 mask. */
#define SPI_MODE0_bp  0  /* SPI Mode bit 0 position. */
#define SPI_MODE1_bm  (1<<1)  /* SPI Mode bit 1 mask. */
#define SPI_MODE1_bp  1  /* SPI Mode bit 1 position. */
#define SPI_SSD_bm  0x04  /* Slave Select Disable bit mask. */
#define SPI_SSD_bp  2  /* Slave Select Disable bit position. */
#define SPI_BUFWR_bm  0x40  /* Buffer Write Mode bit mask. */
#define SPI_BUFWR_bp  6  /* Buffer Write Mode bit position. */
#define SPI_BUFEN_bm  0x80  /* Buffer Mode Enable bit mask. */
#define SPI_BUFEN_bp  7  /* Buffer Mode Enable bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_IE_bm  0x01  /* Interrupt Enable bit mask. */
#define SPI_IE_bp  0  /* Interrupt Enable bit position. */
#define SPI_SSIE_bm  0x10  /* Slave Select Trigger Interrupt Enable bit mask. */
#define SPI_SSIE_bp  4  /* Slave Select Trigger Interrupt Enable bit position. */
#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define SPI_TXCIE_bm  0x40  /* Transfer Complete Interrupt Enable bit mask. */
#define SPI_TXCIE_bp  6  /* Transfer Complete Interrupt Enable bit position. */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* SPI.INTFLAGS  bit masks and bit positions */
#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow bit position. */
#define SPI_SSIF_bm  0x10  /* Slave Select Trigger Interrupt Flag bit mask. */
#define SPI_SSIF_bp  4  /* Slave Select Trigger Interrupt Flag bit position. */
#define SPI_DREIF_bm  0x20  /* Data Register Empty Interrupt Flag bit mask. */
#define SPI_DREIF_bp  5  /* Data Register Empty Interrupt Flag bit position. */
#define SPI_TXCIF_bm  0x40  /* Transfer Complete Interrupt Flag bit mask. */
#define SPI_TXCIF_bp  6  /* Transfer Complete Interrupt Flag bit position. */
#define SPI_WRCOL_bm  0x40  /* Write Collision bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision bit position. */
#define SPI_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define SPI_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */
#define SPI_IF_bm  0x80  /* Interrupt Flag bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag bit position. */



/* SYSCFG - System Configuration Registers */
/* SYSCFG.EXTBRK  bit masks and bit positions */
#define SYSCFG_ENEXTBRK_bm  0x01  /* External break enable bit mask. */
#define SYSCFG_ENEXTBRK_bp  0  /* External break enable bit position. */


/* SYSCFG.OCDMS  bit masks and bit positions */
#define SYSCFG_OCDMR_bm  0x01  /* OCD Message Read bit mask. */
#define SYSCFG_OCDMR_bp  0  /* OCD Message Read bit position. */

/* TCA - 16-bit Timer/Counter Type A */
/* TCA_SINGLE.CTRLA  bit masks and bit positions */
#define TCA_SINGLE_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SINGLE_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SINGLE_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SINGLE_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SINGLE_CLKSEL0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SINGLE_CLKSEL0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SINGLE_CLKSEL1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SINGLE_CLKSEL1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SINGLE_CLKSEL2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SINGLE_CLKSEL2_bp  3  /* Clock Selection bit 2 position. */

/* TCA_SINGLE.CTRLB  bit masks and bit positions */
#define TCA_SINGLE_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TCA_SINGLE_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCA_SINGLE_WGMODE0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCA_SINGLE_WGMODE0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCA_SINGLE_WGMODE1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCA_SINGLE_WGMODE1_bp  1  /* Waveform generation mode bit 1 position. */
#define TCA_SINGLE_WGMODE2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TCA_SINGLE_WGMODE2_bp  2  /* Waveform generation mode bit 2 position. */
#define TCA_SINGLE_ALUPD_bm  0x08  /* Auto Lock Update bit mask. */
#define TCA_SINGLE_ALUPD_bp  3  /* Auto Lock Update bit position. */
#define TCA_SINGLE_CMP0EN_bm  0x10  /* Compare 0 Enable bit mask. */
#define TCA_SINGLE_CMP0EN_bp  4  /* Compare 0 Enable bit position. */
#define TCA_SINGLE_CMP1EN_bm  0x20  /* Compare 1 Enable bit mask. */
#define TCA_SINGLE_CMP1EN_bp  5  /* Compare 1 Enable bit position. */
#define TCA_SINGLE_CMP2EN_bm  0x40  /* Compare 2 Enable bit mask. */
#define TCA_SINGLE_CMP2EN_bp  6  /* Compare 2 Enable bit position. */

/* TCA_SINGLE.CTRLC  bit masks and bit positions */
#define TCA_SINGLE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */

/* TCA_SINGLE.CTRLD  bit masks and bit positions */
#define TCA_SINGLE_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SINGLE_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SINGLE.CTRLECLR  bit masks and bit positions */
#define TCA_SINGLE_DIR_bm  0x01  /* Direction bit mask. */
#define TCA_SINGLE_DIR_bp  0  /* Direction bit position. */
#define TCA_SINGLE_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TCA_SINGLE_LUPD_bp  1  /* Lock Update bit position. */
#define TCA_SINGLE_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SINGLE_CMD_gp  2  /* Command group position. */
#define TCA_SINGLE_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SINGLE_CMD0_bp  2  /* Command bit 0 position. */
#define TCA_SINGLE_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SINGLE_CMD1_bp  3  /* Command bit 1 position. */

/* TCA_SINGLE.CTRLESET  bit masks and bit positions */
/* TCA_SINGLE_DIR  is already defined. */
/* TCA_SINGLE_LUPD  is already defined. */
/* TCA_SINGLE_CMD  is already defined. */

/* TCA_SINGLE.CTRLFCLR  bit masks and bit positions */
#define TCA_SINGLE_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TCA_SINGLE_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TCA_SINGLE_CMP0BV_bm  0x02  /* Compare 0 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP0BV_bp  1  /* Compare 0 Buffer Valid bit position. */
#define TCA_SINGLE_CMP1BV_bm  0x04  /* Compare 1 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP1BV_bp  2  /* Compare 1 Buffer Valid bit position. */
#define TCA_SINGLE_CMP2BV_bm  0x08  /* Compare 2 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP2BV_bp  3  /* Compare 2 Buffer Valid bit position. */

/* TCA_SINGLE.CTRLFSET  bit masks and bit positions */
/* TCA_SINGLE_PERBV  is already defined. */
/* TCA_SINGLE_CMP0BV  is already defined. */
/* TCA_SINGLE_CMP1BV  is already defined. */
/* TCA_SINGLE_CMP2BV  is already defined. */

/* TCA_SINGLE.EVCTRL  bit masks and bit positions */
#define TCA_SINGLE_CNTEI_bm  0x01  /* Count on Event Input bit mask. */
#define TCA_SINGLE_CNTEI_bp  0  /* Count on Event Input bit position. */
#define TCA_SINGLE_EVACT_gm  0x06  /* Event Action group mask. */
#define TCA_SINGLE_EVACT_gp  1  /* Event Action group position. */
#define TCA_SINGLE_EVACT0_bm  (1<<1)  /* Event Action bit 0 mask. */
#define TCA_SINGLE_EVACT0_bp  1  /* Event Action bit 0 position. */
#define TCA_SINGLE_EVACT1_bm  (1<<2)  /* Event Action bit 1 mask. */
#define TCA_SINGLE_EVACT1_bp  2  /* Event Action bit 1 position. */

/* TCA_SINGLE.INTCTRL  bit masks and bit positions */
#define TCA_SINGLE_OVF_bm  0x01  /* Overflow Interrupt bit mask. */
#define TCA_SINGLE_OVF_bp  0  /* Overflow Interrupt bit position. */
#define TCA_SINGLE_CMP0_bm  0x10  /* Compare 0 Interrupt bit mask. */
#define TCA_SINGLE_CMP0_bp  4  /* Compare 0 Interrupt bit position. */
#define TCA_SINGLE_CMP1_bm  0x20  /* Compare 1 Interrupt bit mask. */
#define TCA_SINGLE_CMP1_bp  5  /* Compare 1 Interrupt bit position. */
#define TCA_SINGLE_CMP2_bm  0x40  /* Compare 2 Interrupt bit mask. */
#define TCA_SINGLE_CMP2_bp  6  /* Compare 2 Interrupt bit position. */

/* TCA_SINGLE.INTFLAGS  bit masks and bit positions */
/* TCA_SINGLE_OVF  is already defined. */
/* TCA_SINGLE_CMP0  is already defined. */
/* TCA_SINGLE_CMP1  is already defined. */
/* TCA_SINGLE_CMP2  is already defined. */

/* TCA_SINGLE.DBGCTRL  bit masks and bit positions */
#define TCA_SINGLE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SINGLE_DBGRUN_bp  0  /* Debug Run bit position. */











/* TCA_SPLIT.CTRLA  bit masks and bit positions */
#define TCA_SPLIT_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SPLIT_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SPLIT_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SPLIT_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SPLIT_CLKSEL0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SPLIT_CLKSEL0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SPLIT_CLKSEL1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SPLIT_CLKSEL1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SPLIT_CLKSEL2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SPLIT_CLKSEL2_bp  3  /* Clock Selection bit 2 position. */

/* TCA_SPLIT.CTRLB  bit masks and bit positions */
#define TCA_SPLIT_LCMP0EN_bm  0x01  /* Low Compare 0 Enable bit mask. */
#define TCA_SPLIT_LCMP0EN_bp  0  /* Low Compare 0 Enable bit position. */
#define TCA_SPLIT_LCMP1EN_bm  0x02  /* Low Compare 1 Enable bit mask. */
#define TCA_SPLIT_LCMP1EN_bp  1  /* Low Compare 1 Enable bit position. */
#define TCA_SPLIT_LCMP2EN_bm  0x04  /* Low Compare 2 Enable bit mask. */
#define TCA_SPLIT_LCMP2EN_bp  2  /* Low Compare 2 Enable bit position. */
#define TCA_SPLIT_HCMP0EN_bm  0x10  /* High Compare 0 Enable bit mask. */
#define TCA_SPLIT_HCMP0EN_bp  4  /* High Compare 0 Enable bit position. */
#define TCA_SPLIT_HCMP1EN_bm  0x20  /* High Compare 1 Enable bit mask. */
#define TCA_SPLIT_HCMP1EN_bp  5  /* High Compare 1 Enable bit position. */
#define TCA_SPLIT_HCMP2EN_bm  0x40  /* High Compare 2 Enable bit mask. */
#define TCA_SPLIT_HCMP2EN_bp  6  /* High Compare 2 Enable bit position. */

/* TCA_SPLIT.CTRLC  bit masks and bit positions */
#define TCA_SPLIT_LCMP0OV_bm  0x01  /* Low Compare 0 Output Value bit mask. */
#define TCA_SPLIT_LCMP0OV_bp  0  /* Low Compare 0 Output Value bit position. */
#define TCA_SPLIT_LCMP1OV_bm  0x02  /* Low Compare 1 Output Value bit mask. */
#define TCA_SPLIT_LCMP1OV_bp  1  /* Low Compare 1 Output Value bit position. */
#define TCA_SPLIT_LCMP2OV_bm  0x04  /* Low Compare 2 Output Value bit mask. */
#define TCA_SPLIT_LCMP2OV_bp  2  /* Low Compare 2 Output Value bit position. */
#define TCA_SPLIT_HCMP0OV_bm  0x10  /* High Compare 0 Output Value bit mask. */
#define TCA_SPLIT_HCMP0OV_bp  4  /* High Compare 0 Output Value bit position. */
#define TCA_SPLIT_HCMP1OV_bm  0x20  /* High Compare 1 Output Value bit mask. */
#define TCA_SPLIT_HCMP1OV_bp  5  /* High Compare 1 Output Value bit position. */
#define TCA_SPLIT_HCMP2OV_bm  0x40  /* High Compare 2 Output Value bit mask. */
#define TCA_SPLIT_HCMP2OV_bp  6  /* High Compare 2 Output Value bit position. */

/* TCA_SPLIT.CTRLD  bit masks and bit positions */
#define TCA_SPLIT_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SPLIT_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SPLIT.CTRLECLR  bit masks and bit positions */
#define TCA_SPLIT_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SPLIT_CMD_gp  2  /* Command group position. */
#define TCA_SPLIT_CMD0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SPLIT_CMD0_bp  2  /* Command bit 0 position. */
#define TCA_SPLIT_CMD1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SPLIT_CMD1_bp  3  /* Command bit 1 position. */

/* TCA_SPLIT.CTRLESET  bit masks and bit positions */
/* TCA_SPLIT_CMD  is already defined. */

/* TCA_SPLIT.INTCTRL  bit masks and bit positions */
#define TCA_SPLIT_LUNF_bm  0x01  /* Low Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_LUNF_bp  0  /* Low Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_HUNF_bm  0x02  /* High Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_HUNF_bp  1  /* High Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP0_bm  0x10  /* Low Compare 0 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP0_bp  4  /* Low Compare 0 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP1_bm  0x20  /* Low Compare 1 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP1_bp  5  /* Low Compare 1 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP2_bm  0x40  /* Low Compare 2 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP2_bp  6  /* Low Compare 2 Interrupt Enable bit position. */

/* TCA_SPLIT.INTFLAGS  bit masks and bit positions */
/* TCA_SPLIT_LUNF  is already defined. */
/* TCA_SPLIT_HUNF  is already defined. */
/* TCA_SPLIT_LCMP0  is already defined. */
/* TCA_SPLIT_LCMP1  is already defined. */
/* TCA_SPLIT_LCMP2  is already defined. */

/* TCA_SPLIT.DBGCTRL  bit masks and bit positions */
#define TCA_SPLIT_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SPLIT_DBGRUN_bp  0  /* Debug Run bit position. */











/* TCB - 16-bit Timer Type B */
/* TCB.CTRLA  bit masks and bit positions */
#define TCB_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCB_ENABLE_bp  0  /* Enable bit position. */
#define TCB_CLKSEL_gm  0x06  /* Clock Select group mask. */
#define TCB_CLKSEL_gp  1  /* Clock Select group position. */
#define TCB_CLKSEL0_bm  (1<<1)  /* Clock Select bit 0 mask. */
#define TCB_CLKSEL0_bp  1  /* Clock Select bit 0 position. */
#define TCB_CLKSEL1_bm  (1<<2)  /* Clock Select bit 1 mask. */
#define TCB_CLKSEL1_bp  2  /* Clock Select bit 1 position. */
#define TCB_SYNCUPD_bm  0x10  /* Synchronize Update bit mask. */
#define TCB_SYNCUPD_bp  4  /* Synchronize Update bit position. */
#define TCB_RUNSTDBY_bm  0x40  /* Run Standby bit mask. */
#define TCB_RUNSTDBY_bp  6  /* Run Standby bit position. */

/* TCB.CTRLB  bit masks and bit positions */
#define TCB_CNTMODE_gm  0x07  /* Timer Mode group mask. */
#define TCB_CNTMODE_gp  0  /* Timer Mode group position. */
#define TCB_CNTMODE0_bm  (1<<0)  /* Timer Mode bit 0 mask. */
#define TCB_CNTMODE0_bp  0  /* Timer Mode bit 0 position. */
#define TCB_CNTMODE1_bm  (1<<1)  /* Timer Mode bit 1 mask. */
#define TCB_CNTMODE1_bp  1  /* Timer Mode bit 1 position. */
#define TCB_CNTMODE2_bm  (1<<2)  /* Timer Mode bit 2 mask. */
#define TCB_CNTMODE2_bp  2  /* Timer Mode bit 2 position. */
#define TCB_CCMPEN_bm  0x10  /* Pin Output Enable bit mask. */
#define TCB_CCMPEN_bp  4  /* Pin Output Enable bit position. */
#define TCB_CCMPINIT_bm  0x20  /* Pin Initial State bit mask. */
#define TCB_CCMPINIT_bp  5  /* Pin Initial State bit position. */
#define TCB_ASYNC_bm  0x40  /* Asynchronous Enable bit mask. */
#define TCB_ASYNC_bp  6  /* Asynchronous Enable bit position. */

/* TCB.EVCTRL  bit masks and bit positions */
#define TCB_CAPTEI_bm  0x01  /* Event Input Enable bit mask. */
#define TCB_CAPTEI_bp  0  /* Event Input Enable bit position. */
#define TCB_EDGE_bm  0x10  /* Event Edge bit mask. */
#define TCB_EDGE_bp  4  /* Event Edge bit position. */
#define TCB_FILTER_bm  0x40  /* Input Capture Noise Cancellation Filter bit mask. */
#define TCB_FILTER_bp  6  /* Input Capture Noise Cancellation Filter bit position. */

/* TCB.INTCTRL  bit masks and bit positions */
#define TCB_CAPT_bm  0x01  /* Capture or Timeout bit mask. */
#define TCB_CAPT_bp  0  /* Capture or Timeout bit position. */

/* TCB.INTFLAGS  bit masks and bit positions */
/* TCB_CAPT  is already defined. */

/* TCB.STATUS  bit masks and bit positions */
#define TCB_RUN_bm  0x01  /* Run bit mask. */
#define TCB_RUN_bp  0  /* Run bit position. */

/* TCB.DBGCTRL  bit masks and bit positions */
#define TCB_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCB_DBGRUN_bp  0  /* Debug Run bit position. */




/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMPEN_bm  0x02  /* FM Plus Enable bit mask. */
#define TWI_FMPEN_bp  1  /* FM Plus Enable bit position. */
#define TWI_SDAHOLD_gm  0x0C  /* SDA Hold Time group mask. */
#define TWI_SDAHOLD_gp  2  /* SDA Hold Time group position. */
#define TWI_SDAHOLD0_bm  (1<<2)  /* SDA Hold Time bit 0 mask. */
#define TWI_SDAHOLD0_bp  2  /* SDA Hold Time bit 0 position. */
#define TWI_SDAHOLD1_bm  (1<<3)  /* SDA Hold Time bit 1 mask. */
#define TWI_SDAHOLD1_bp  3  /* SDA Hold Time bit 1 position. */
#define TWI_SDASETUP_bm  0x10  /* SDA Setup Time bit mask. */
#define TWI_SDASETUP_bp  4  /* SDA Setup Time bit position. */

/* TWI.DUALCTRL  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Dual Control Enable bit mask. */
#define TWI_ENABLE_bp  0  /* Dual Control Enable bit position. */
/* TWI_FMPEN  is already defined. */
/* TWI_SDAHOLD  is already defined. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
#define TWI_SMEN_bm  0x02  /* Smart Mode Enable bit mask. */
#define TWI_SMEN_bp  1  /* Smart Mode Enable bit position. */
#define TWI_TIMEOUT_gm  0x0C  /* Inactive Bus Timeout group mask. */
#define TWI_TIMEOUT_gp  2  /* Inactive Bus Timeout group position. */
#define TWI_TIMEOUT0_bm  (1<<2)  /* Inactive Bus Timeout bit 0 mask. */
#define TWI_TIMEOUT0_bp  2  /* Inactive Bus Timeout bit 0 position. */
#define TWI_TIMEOUT1_bm  (1<<3)  /* Inactive Bus Timeout bit 1 mask. */
#define TWI_TIMEOUT1_bp  3  /* Inactive Bus Timeout bit 1 position. */
#define TWI_QCEN_bm  0x10  /* Quick Command Enable bit mask. */
#define TWI_QCEN_bp  4  /* Quick Command Enable bit position. */
#define TWI_WIEN_bm  0x40  /* Write Interrupt Enable bit mask. */
#define TWI_WIEN_bp  6  /* Write Interrupt Enable bit position. */
#define TWI_RIEN_bm  0x80  /* Read Interrupt Enable bit mask. */
#define TWI_RIEN_bp  7  /* Read Interrupt Enable bit position. */

/* TWI.MCTRLB  bit masks and bit positions */
#define TWI_MCMD_gm  0x03  /* Command group mask. */
#define TWI_MCMD_gp  0  /* Command group position. */
#define TWI_MCMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MCMD0_bp  0  /* Command bit 0 position. */
#define TWI_MCMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MCMD1_bp  1  /* Command bit 1 position. */
#define TWI_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_ACKACT_bp  2  /* Acknowledge Action bit position. */
#define TWI_FLUSH_bm  0x08  /* Flush bit mask. */
#define TWI_FLUSH_bp  3  /* Flush bit position. */

/* TWI.MSTATUS  bit masks and bit positions */
#define TWI_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_BUSSTATE0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_BUSSTATE0_bp  0  /* Bus State bit 0 position. */
#define TWI_BUSSTATE1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_BUSSTATE1_bp  1  /* Bus State bit 1 position. */
#define TWI_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_ARBLOST_bp  3  /* Arbitration Lost bit position. */
#define TWI_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_WIF_bp  6  /* Write Interrupt Flag bit position. */
#define TWI_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_RIF_bp  7  /* Read Interrupt Flag bit position. */




/* TWI.SCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
/* TWI_SMEN  is already defined. */
#define TWI_PMEN_bm  0x04  /* Promiscuous Mode Enable bit mask. */
#define TWI_PMEN_bp  2  /* Promiscuous Mode Enable bit position. */
#define TWI_PIEN_bm  0x20  /* Stop Interrupt Enable bit mask. */
#define TWI_PIEN_bp  5  /* Stop Interrupt Enable bit position. */
#define TWI_APIEN_bm  0x40  /* Address/Stop Interrupt Enable bit mask. */
#define TWI_APIEN_bp  6  /* Address/Stop Interrupt Enable bit position. */
#define TWI_DIEN_bm  0x80  /* Data Interrupt Enable bit mask. */
#define TWI_DIEN_bp  7  /* Data Interrupt Enable bit position. */

/* TWI.SCTRLB  bit masks and bit positions */
#define TWI_SCMD_gm  0x03  /* Command group mask. */
#define TWI_SCMD_gp  0  /* Command group position. */
#define TWI_SCMD0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SCMD0_bp  0  /* Command bit 0 position. */
#define TWI_SCMD1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SCMD1_bp  1  /* Command bit 1 position. */
/* TWI_ACKACT  is already defined. */

/* TWI.SSTATUS  bit masks and bit positions */
#define TWI_AP_bm  0x01  /* Slave Address or Stop bit mask. */
#define TWI_AP_bp  0  /* Slave Address or Stop bit position. */
#define TWI_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_DIR_bp  1  /* Read/Write Direction bit position. */
/* TWI_BUSERR  is already defined. */
#define TWI_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_COLL_bp  3  /* Collision bit position. */
/* TWI_RXACK  is already defined. */
/* TWI_CLKHOLD  is already defined. */
#define TWI_APIF_bm  0x40  /* Address/Stop Interrupt Flag bit mask. */
#define TWI_APIF_bp  6  /* Address/Stop Interrupt Flag bit position. */
#define TWI_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_DIF_bp  7  /* Data Interrupt Flag bit position. */



/* TWI.SADDRMASK  bit masks and bit positions */
#define TWI_ADDREN_bm  0x01  /* Address Enable bit mask. */
#define TWI_ADDREN_bp  0  /* Address Enable bit position. */
#define TWI_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_ADDRMASK0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_ADDRMASK0_bp  1  /* Address Mask bit 0 position. */
#define TWI_ADDRMASK1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_ADDRMASK1_bp  2  /* Address Mask bit 1 position. */
#define TWI_ADDRMASK2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_ADDRMASK2_bp  3  /* Address Mask bit 2 position. */
#define TWI_ADDRMASK3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_ADDRMASK3_bp  4  /* Address Mask bit 3 position. */
#define TWI_ADDRMASK4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_ADDRMASK4_bp  5  /* Address Mask bit 4 position. */
#define TWI_ADDRMASK5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_ADDRMASK5_bp  6  /* Address Mask bit 5 position. */
#define TWI_ADDRMASK6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_ADDRMASK6_bp  7  /* Address Mask bit 6 position. */

/* USART - Universal Synchronous and Asynchronous Receiver and Transmitter */
/* USART.RXDATAL  bit masks and bit positions */
#define USART_DATA_gm  0xFF  /* RX Data group mask. */
#define USART_DATA_gp  0  /* RX Data group position. */
#define USART_DATA0_bm  (1<<0)  /* RX Data bit 0 mask. */
#define USART_DATA0_bp  0  /* RX Data bit 0 position. */
#define USART_DATA1_bm  (1<<1)  /* RX Data bit 1 mask. */
#define USART_DATA1_bp  1  /* RX Data bit 1 position. */
#define USART_DATA2_bm  (1<<2)  /* RX Data bit 2 mask. */
#define USART_DATA2_bp  2  /* RX Data bit 2 position. */
#define USART_DATA3_bm  (1<<3)  /* RX Data bit 3 mask. */
#define USART_DATA3_bp  3  /* RX Data bit 3 position. */
#define USART_DATA4_bm  (1<<4)  /* RX Data bit 4 mask. */
#define USART_DATA4_bp  4  /* RX Data bit 4 position. */
#define USART_DATA5_bm  (1<<5)  /* RX Data bit 5 mask. */
#define USART_DATA5_bp  5  /* RX Data bit 5 position. */
#define USART_DATA6_bm  (1<<6)  /* RX Data bit 6 mask. */
#define USART_DATA6_bp  6  /* RX Data bit 6 position. */
#define USART_DATA7_bm  (1<<7)  /* RX Data bit 7 mask. */
#define USART_DATA7_bp  7  /* RX Data bit 7 position. */

/* USART.RXDATAH  bit masks and bit positions */
#define USART_DATA8_bm  0x01  /* Receiver Data Register bit mask. */
#define USART_DATA8_bp  0  /* Receiver Data Register bit position. */
#define USART_PERR_bm  0x02  /* Parity Error bit mask. */
#define USART_PERR_bp  1  /* Parity Error bit position. */
#define USART_FERR_bm  0x04  /* Frame Error bit mask. */
#define USART_FERR_bp  2  /* Frame Error bit position. */
#define USART_BUFOVF_bm  0x40  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  6  /* Buffer Overflow bit position. */
#define USART_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */

/* USART.TXDATAL  bit masks and bit positions */
/* USART_DATA  is already defined. */

/* USART.TXDATAH  bit masks and bit positions */
/* USART_DATA8  is already defined. */

/* USART.STATUS  bit masks and bit positions */
#define USART_WFB_bm  0x01  /* Wait For Break bit mask. */
#define USART_WFB_bp  0  /* Wait For Break bit position. */
#define USART_BDF_bm  0x02  /* Break Detected Flag bit mask. */
#define USART_BDF_bp  1  /* Break Detected Flag bit position. */
#define USART_ISFIF_bm  0x08  /* Inconsistent Sync Field Interrupt Flag bit mask. */
#define USART_ISFIF_bp  3  /* Inconsistent Sync Field Interrupt Flag bit position. */
#define USART_RXSIF_bm  0x10  /* Receive Start Interrupt bit mask. */
#define USART_RXSIF_bp  4  /* Receive Start Interrupt bit position. */
#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */
#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */
/* USART_RXCIF  is already defined. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_RS485_gm  0x03  /* RS485 Mode internal transmitter group mask. */
#define USART_RS485_gp  0  /* RS485 Mode internal transmitter group position. */
#define USART_RS4850_bm  (1<<0)  /* RS485 Mode internal transmitter bit 0 mask. */
#define USART_RS4850_bp  0  /* RS485 Mode internal transmitter bit 0 position. */
#define USART_RS4851_bm  (1<<1)  /* RS485 Mode internal transmitter bit 1 mask. */
#define USART_RS4851_bp  1  /* RS485 Mode internal transmitter bit 1 position. */
#define USART_ABEIE_bm  0x04  /* Auto-baud Error Interrupt Enable bit mask. */
#define USART_ABEIE_bp  2  /* Auto-baud Error Interrupt Enable bit position. */
#define USART_LBME_bm  0x08  /* Loop-back Mode Enable bit mask. */
#define USART_LBME_bp  3  /* Loop-back Mode Enable bit position. */
#define USART_RXSIE_bm  0x10  /* Receiver Start Frame Interrupt Enable bit mask. */
#define USART_RXSIE_bp  4  /* Receiver Start Frame Interrupt Enable bit position. */
#define USART_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define USART_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define USART_TXCIE_bm  0x40  /* Transmit Complete Interrupt Enable bit mask. */
#define USART_TXCIE_bp  6  /* Transmit Complete Interrupt Enable bit position. */
#define USART_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define USART_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_MPCM_bm  0x01  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  0  /* Multi-processor Communication Mode bit position. */
#define USART_RXMODE_gm  0x06  /* Receiver Mode group mask. */
#define USART_RXMODE_gp  1  /* Receiver Mode group position. */
#define USART_RXMODE0_bm  (1<<1)  /* Receiver Mode bit 0 mask. */
#define USART_RXMODE0_bp  1  /* Receiver Mode bit 0 position. */
#define USART_RXMODE1_bm  (1<<2)  /* Receiver Mode bit 1 mask. */
#define USART_RXMODE1_bp  2  /* Receiver Mode bit 1 position. */
#define USART_ODME_bm  0x08  /* Open Drain Mode Enable bit mask. */
#define USART_ODME_bp  3  /* Open Drain Mode Enable bit position. */
#define USART_SFDEN_bm  0x10  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  4  /* Start Frame Detection Enable bit position. */
#define USART_TXEN_bm  0x40  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  6  /* Transmitter Enable bit position. */
#define USART_RXEN_bm  0x80  /* Reciever enable bit mask. */
#define USART_RXEN_bp  7  /* Reciever enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_UCPHA_bm  0x02  /* SPI Master Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Master Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Master Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Master Mode, Data Order bit position. */
#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE2_bp  2  /* Character Size bit 2 position. */
#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */
#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE1_bp  5  /* Parity Mode bit 1 position. */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE1_bp  7  /* Communication Mode bit 1 position. */


/* USART.CTRLD  bit masks and bit positions */
#define USART_ABW_gm  0xC0  /* Auto Baud Window group mask. */
#define USART_ABW_gp  6  /* Auto Baud Window group position. */
#define USART_ABW0_bm  (1<<6)  /* Auto Baud Window bit 0 mask. */
#define USART_ABW0_bp  6  /* Auto Baud Window bit 0 position. */
#define USART_ABW1_bm  (1<<7)  /* Auto Baud Window bit 1 mask. */
#define USART_ABW1_bp  7  /* Auto Baud Window bit 1 position. */

/* USART.DBGCTRL  bit masks and bit positions */
#define USART_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define USART_DBGRUN_bp  0  /* Debug Run bit position. */
#define USART_ABMBP_bm  0x80  /* Autobaud majority voter bypass bit mask. */
#define USART_ABMBP_bp  7  /* Autobaud majority voter bypass bit position. */

/* USART.EVCTRL  bit masks and bit positions */
#define USART_IREI_bm  0x01  /* IrDA Event Input Enable bit mask. */
#define USART_IREI_bp  0  /* IrDA Event Input Enable bit position. */

/* USART.TXPLCTRL  bit masks and bit positions */
#define USART_TXPL_gm  0xFF  /* Transmit pulse length group mask. */
#define USART_TXPL_gp  0  /* Transmit pulse length group position. */
#define USART_TXPL0_bm  (1<<0)  /* Transmit pulse length bit 0 mask. */
#define USART_TXPL0_bp  0  /* Transmit pulse length bit 0 position. */
#define USART_TXPL1_bm  (1<<1)  /* Transmit pulse length bit 1 mask. */
#define USART_TXPL1_bp  1  /* Transmit pulse length bit 1 position. */
#define USART_TXPL2_bm  (1<<2)  /* Transmit pulse length bit 2 mask. */
#define USART_TXPL2_bp  2  /* Transmit pulse length bit 2 position. */
#define USART_TXPL3_bm  (1<<3)  /* Transmit pulse length bit 3 mask. */
#define USART_TXPL3_bp  3  /* Transmit pulse length bit 3 position. */
#define USART_TXPL4_bm  (1<<4)  /* Transmit pulse length bit 4 mask. */
#define USART_TXPL4_bp  4  /* Transmit pulse length bit 4 position. */
#define USART_TXPL5_bm  (1<<5)  /* Transmit pulse length bit 5 mask. */
#define USART_TXPL5_bp  5  /* Transmit pulse length bit 5 position. */
#define USART_TXPL6_bm  (1<<6)  /* Transmit pulse length bit 6 mask. */
#define USART_TXPL6_bp  6  /* Transmit pulse length bit 6 position. */
#define USART_TXPL7_bm  (1<<7)  /* Transmit pulse length bit 7 mask. */
#define USART_TXPL7_bp  7  /* Transmit pulse length bit 7 position. */

/* USART.RXPLCTRL  bit masks and bit positions */
#define USART_RXPL_gm  0x7F  /* Receiver Pulse Lenght group mask. */
#define USART_RXPL_gp  0  /* Receiver Pulse Lenght group position. */
#define USART_RXPL0_bm  (1<<0)  /* Receiver Pulse Lenght bit 0 mask. */
#define USART_RXPL0_bp  0  /* Receiver Pulse Lenght bit 0 position. */
#define USART_RXPL1_bm  (1<<1)  /* Receiver Pulse Lenght bit 1 mask. */
#define USART_RXPL1_bp  1  /* Receiver Pulse Lenght bit 1 position. */
#define USART_RXPL2_bm  (1<<2)  /* Receiver Pulse Lenght bit 2 mask. */
#define USART_RXPL2_bp  2  /* Receiver Pulse Lenght bit 2 position. */
#define USART_RXPL3_bm  (1<<3)  /* Receiver Pulse Lenght bit 3 mask. */
#define USART_RXPL3_bp  3  /* Receiver Pulse Lenght bit 3 position. */
#define USART_RXPL4_bm  (1<<4)  /* Receiver Pulse Lenght bit 4 mask. */
#define USART_RXPL4_bp  4  /* Receiver Pulse Lenght bit 4 position. */
#define USART_RXPL5_bm  (1<<5)  /* Receiver Pulse Lenght bit 5 mask. */
#define USART_RXPL5_bp  5  /* Receiver Pulse Lenght bit 5 position. */
#define USART_RXPL6_bm  (1<<6)  /* Receiver Pulse Lenght bit 6 mask. */
#define USART_RXPL6_bp  6  /* Receiver Pulse Lenght bit 6 position. */




































































/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT_gm  0xFF  /* Pin Interrupt group mask. */
#define VPORT_INT_gp  0  /* Pin Interrupt group position. */
#define VPORT_INT0_bm  (1<<0)  /* Pin Interrupt bit 0 mask. */
#define VPORT_INT0_bp  0  /* Pin Interrupt bit 0 position. */
#define VPORT_INT1_bm  (1<<1)  /* Pin Interrupt bit 1 mask. */
#define VPORT_INT1_bp  1  /* Pin Interrupt bit 1 position. */
#define VPORT_INT2_bm  (1<<2)  /* Pin Interrupt bit 2 mask. */
#define VPORT_INT2_bp  2  /* Pin Interrupt bit 2 position. */
#define VPORT_INT3_bm  (1<<3)  /* Pin Interrupt bit 3 mask. */
#define VPORT_INT3_bp  3  /* Pin Interrupt bit 3 position. */
#define VPORT_INT4_bm  (1<<4)  /* Pin Interrupt bit 4 mask. */
#define VPORT_INT4_bp  4  /* Pin Interrupt bit 4 position. */
#define VPORT_INT5_bm  (1<<5)  /* Pin Interrupt bit 5 mask. */
#define VPORT_INT5_bp  5  /* Pin Interrupt bit 5 position. */
#define VPORT_INT6_bm  (1<<6)  /* Pin Interrupt bit 6 mask. */
#define VPORT_INT6_bp  6  /* Pin Interrupt bit 6 position. */
#define VPORT_INT7_bm  (1<<7)  /* Pin Interrupt bit 7 mask. */
#define VPORT_INT7_bp  7  /* Pin Interrupt bit 7 position. */

/* VREF - Voltage reference */
/* VREF.CTRLA  bit masks and bit positions */
#define VREF_AC0REFSEL_gm  0x07  /* AC0 reference select group mask. */
#define VREF_AC0REFSEL_gp  0  /* AC0 reference select group position. */
#define VREF_AC0REFSEL0_bm  (1<<0)  /* AC0 reference select bit 0 mask. */
#define VREF_AC0REFSEL0_bp  0  /* AC0 reference select bit 0 position. */
#define VREF_AC0REFSEL1_bm  (1<<1)  /* AC0 reference select bit 1 mask. */
#define VREF_AC0REFSEL1_bp  1  /* AC0 reference select bit 1 position. */
#define VREF_AC0REFSEL2_bm  (1<<2)  /* AC0 reference select bit 2 mask. */
#define VREF_AC0REFSEL2_bp  2  /* AC0 reference select bit 2 position. */
#define VREF_ADC0REFSEL_gm  0x70  /* ADC0 reference select group mask. */
#define VREF_ADC0REFSEL_gp  4  /* ADC0 reference select group position. */
#define VREF_ADC0REFSEL0_bm  (1<<4)  /* ADC0 reference select bit 0 mask. */
#define VREF_ADC0REFSEL0_bp  4  /* ADC0 reference select bit 0 position. */
#define VREF_ADC0REFSEL1_bm  (1<<5)  /* ADC0 reference select bit 1 mask. */
#define VREF_ADC0REFSEL1_bp  5  /* ADC0 reference select bit 1 position. */
#define VREF_ADC0REFSEL2_bm  (1<<6)  /* ADC0 reference select bit 2 mask. */
#define VREF_ADC0REFSEL2_bp  6  /* ADC0 reference select bit 2 position. */

/* VREF.CTRLB  bit masks and bit positions */
#define VREF_AC0REFEN_bm  0x01  /* AC0 DACREF reference enable bit mask. */
#define VREF_AC0REFEN_bp  0  /* AC0 DACREF reference enable bit position. */
#define VREF_ADC0REFEN_bm  0x02  /* ADC0 reference enable bit mask. */
#define VREF_ADC0REFEN_bp  1  /* ADC0 reference enable bit position. */

/* WDT - Watch-Dog Timer */
/* WDT.CTRLA  bit masks and bit positions */
#define WDT_PERIOD_gm  0x0F  /* Period group mask. */
#define WDT_PERIOD_gp  0  /* Period group position. */
#define WDT_PERIOD0_bm  (1<<0)  /* Period bit 0 mask. */
#define WDT_PERIOD0_bp  0  /* Period bit 0 position. */
#define WDT_PERIOD1_bm  (1<<1)  /* Period bit 1 mask. */
#define WDT_PERIOD1_bp  1  /* Period bit 1 position. */
#define WDT_PERIOD2_bm  (1<<2)  /* Period bit 2 mask. */
#define WDT_PERIOD2_bp  2  /* Period bit 2 position. */
#define WDT_PERIOD3_bm  (1<<3)  /* Period bit 3 mask. */
#define WDT_PERIOD3_bp  3  /* Period bit 3 position. */
#define WDT_WINDOW_gm  0xF0  /* Window group mask. */
#define WDT_WINDOW_gp  4  /* Window group position. */
#define WDT_WINDOW0_bm  (1<<4)  /* Window bit 0 mask. */
#define WDT_WINDOW0_bp  4  /* Window bit 0 position. */
#define WDT_WINDOW1_bm  (1<<5)  /* Window bit 1 mask. */
#define WDT_WINDOW1_bp  5  /* Window bit 1 position. */
#define WDT_WINDOW2_bm  (1<<6)  /* Window bit 2 mask. */
#define WDT_WINDOW2_bp  6  /* Window bit 2 position. */
#define WDT_WINDOW3_bm  (1<<7)  /* Window bit 3 mask. */
#define WDT_WINDOW3_bp  7  /* Window bit 3 position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Syncronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Syncronization busy bit position. */
#define WDT_LOCK_bm  0x80  /* Lock enable bit mask. */
#define WDT_LOCK_bp  7  /* Lock enable bit position. */



// Generic Port Pins

#define PIN0_bm 0x01
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04
#define PIN2_bp 2
#define PIN3_bm 0x08
#define PIN3_bp 3
#define PIN4_bm 0x10
#define PIN4_bp 4
#define PIN5_bm 0x20
#define PIN5_bp 5
#define PIN6_bm 0x40
#define PIN6_bp 6
#define PIN7_bm 0x80
#define PIN7_bp 7

/* ========== Interrupt Vector Definitions ========== */
/* Vector 0 is the reset vector */

/* CRCSCAN interrupt vectors */
#define CRCSCAN_NMI_vect_num  1
#define CRCSCAN_NMI_vect      _VECTOR(1)  /*  */

/* BOD interrupt vectors */
#define BOD_VLM_vect_num  2
#define BOD_VLM_vect      _VECTOR(2)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  3
#define RTC_CNT_vect      _VECTOR(3)  /*  */
#define RTC_PIT_vect_num  4
#define RTC_PIT_vect      _VECTOR(4)  /*  */

/* CCL interrupt vectors */
#define CCL_CCL_vect_num  5
#define CCL_CCL_vect      _VECTOR(5)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  6
#define PORTA_PORT_vect      _VECTOR(6)  /*  */

/* TCA0 interrupt vectors */
#define TCA0_LUNF_vect_num  7
#define TCA0_LUNF_vect      _VECTOR(7)  /*  */
#define TCA0_OVF_vect_num  7
#define TCA0_OVF_vect      _VECTOR(7)  /*  */
#define TCA0_HUNF_vect_num  8
#define TCA0_HUNF_vect      _VECTOR(8)  /*  */
#define TCA0_LCMP0_vect_num  9
#define TCA0_LCMP0_vect      _VECTOR(9)  /*  */
#define TCA0_CMP0_vect_num  9
#define TCA0_CMP0_vect      _VECTOR(9)  /*  */
#define TCA0_CMP1_vect_num  10
#define TCA0_CMP1_vect      _VECTOR(10)  /*  */
#define TCA0_LCMP1_vect_num  10
#define TCA0_LCMP1_vect      _VECTOR(10)  /*  */
#define TCA0_CMP2_vect_num  11
#define TCA0_CMP2_vect      _VECTOR(11)  /*  */
#define TCA0_LCMP2_vect_num  11
#define TCA0_LCMP2_vect      _VECTOR(11)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  12
#define TCB0_INT_vect      _VECTOR(12)  /*  */

/* TCB1 interrupt vectors */
#define TCB1_INT_vect_num  13
#define TCB1_INT_vect      _VECTOR(13)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIS_vect_num  14
#define TWI0_TWIS_vect      _VECTOR(14)  /*  */
#define TWI0_TWIM_vect_num  15
#define TWI0_TWIM_vect      _VECTOR(15)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  16
#define SPI0_INT_vect      _VECTOR(16)  /*  */

/* USART0 interrupt vectors */
#define USART0_RXC_vect_num  17
#define USART0_RXC_vect      _VECTOR(17)  /*  */
#define USART0_DRE_vect_num  18
#define USART0_DRE_vect      _VECTOR(18)  /*  */
#define USART0_TXC_vect_num  19
#define USART0_TXC_vect      _VECTOR(19)  /*  */

/* PORTD interrupt vectors */
#define PORTD_PORT_vect_num  20
#define PORTD_PORT_vect      _VECTOR(20)  /*  */

/* AC0 interrupt vectors */
#define AC0_AC_vect_num  21
#define AC0_AC_vect      _VECTOR(21)  /*  */

/* ADC0 interrupt vectors */
#define ADC0_RESRDY_vect_num  22
#define ADC0_RESRDY_vect      _VECTOR(22)  /*  */
#define ADC0_WCOMP_vect_num  23
#define ADC0_WCOMP_vect      _VECTOR(23)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  24
#define PORTC_PORT_vect      _VECTOR(24)  /*  */

/* TCB2 interrupt vectors */
#define TCB2_INT_vect_num  25
#define TCB2_INT_vect      _VECTOR(25)  /*  */

/* USART1 interrupt vectors */
#define USART1_RXC_vect_num  26
#define USART1_RXC_vect      _VECTOR(26)  /*  */
#define USART1_DRE_vect_num  27
#define USART1_DRE_vect      _VECTOR(27)  /*  */
#define USART1_TXC_vect_num  28
#define USART1_TXC_vect      _VECTOR(28)  /*  */

/* PORTF interrupt vectors */
#define PORTF_PORT_vect_num  29
#define PORTF_PORT_vect      _VECTOR(29)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_EE_vect_num  30
#define NVMCTRL_EE_vect      _VECTOR(30)  /*  */

/* USART2 interrupt vectors */
#define USART2_RXC_vect_num  31
#define USART2_RXC_vect      _VECTOR(31)  /*  */
#define USART2_DRE_vect_num  32
#define USART2_DRE_vect      _VECTOR(32)  /*  */
#define USART2_TXC_vect_num  33
#define USART2_TXC_vect      _VECTOR(33)  /*  */

/* PORTB interrupt vectors */
#define PORTB_PORT_vect_num  34
#define PORTB_PORT_vect      _VECTOR(34)  /*  */

/* PORTE interrupt vectors */
#define PORTE_PORT_vect_num  35
#define PORTE_PORT_vect      _VECTOR(35)  /*  */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (36 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (16384)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (16384U)
#endif
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define EEPROM_START     (0x1400)
#  define EEPROM_SIZE      (256)
#  define EEPROM_PAGE_SIZE (32)
#else
#  define EEPROM_START     (0x1400U)
#  define EEPROM_SIZE      (256U)
#  define EEPROM_PAGE_SIZE (32U)
#endif
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

/* Added MAPPED_EEPROM segment names for avr-libc */
#define MAPPED_EEPROM_START     (EEPROM_START)
#define MAPPED_EEPROM_SIZE      (EEPROM_SIZE)
#define MAPPED_EEPROM_PAGE_SIZE (EEPROM_PAGE_SIZE)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x1280)
#  define FUSES_SIZE      (10)
#  define FUSES_PAGE_SIZE (32)
#else
#  define FUSES_START     (0x1280U)
#  define FUSES_SIZE      (10U)
#  define FUSES_PAGE_SIZE (32U)
#endif
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x3800)
#  define INTERNAL_SRAM_SIZE      (2048)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x3800U)
#  define INTERNAL_SRAM_SIZE      (2048U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define IO_START     (0x0000)
#  define IO_SIZE      (4352)
#  define IO_PAGE_SIZE (0)
#else
#  define IO_START     (0x0000U)
#  define IO_SIZE      (4352U)
#  define IO_PAGE_SIZE (0U)
#endif
#define IO_END       (IO_START + IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define LOCKBITS_START     (0x128A)
#  define LOCKBITS_SIZE      (1)
#  define LOCKBITS_PAGE_SIZE (32)
#else
#  define LOCKBITS_START     (0x128AU)
#  define LOCKBITS_SIZE      (1U)
#  define LOCKBITS_PAGE_SIZE (32U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define MAPPED_PROGMEM_START     (0x4000)
#  define MAPPED_PROGMEM_SIZE      (16384)
#  define MAPPED_PROGMEM_PAGE_SIZE (64)
#else
#  define MAPPED_PROGMEM_START     (0x4000U)
#  define MAPPED_PROGMEM_SIZE      (16384U)
#  define MAPPED_PROGMEM_PAGE_SIZE (64U)
#endif
#define MAPPED_PROGMEM_END       (MAPPED_PROGMEM_START + MAPPED_PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x1103)
#  define PROD_SIGNATURES_SIZE      (61)
#  define PROD_SIGNATURES_PAGE_SIZE (64)
#else
#  define PROD_SIGNATURES_START     (0x1103U)
#  define PROD_SIGNATURES_SIZE      (61U)
#  define PROD_SIGNATURES_PAGE_SIZE (64U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x1100)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (64)
#else
#  define SIGNATURES_START     (0x1100U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (64U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x1300)
#  define USER_SIGNATURES_SIZE      (32)
#  define USER_SIGNATURES_PAGE_SIZE (32)
#else
#  define USER_SIGNATURES_START     (0x1300U)
#  define USER_SIGNATURES_SIZE      (32U)
#  define USER_SIGNATURES_PAGE_SIZE (32U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (16384)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (16384U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (16384)
#  define PROGMEM_PAGE_SIZE (64)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (16384U)
#  define PROGMEM_PAGE_SIZE (64U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE


/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 9

/* Fuse Byte 0 (WDTCFG) */
#define FUSE_PERIOD0  (unsigned char)~_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_PERIOD1  (unsigned char)~_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_PERIOD2  (unsigned char)~_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_PERIOD3  (unsigned char)~_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WINDOW0  (unsigned char)~_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WINDOW1  (unsigned char)~_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WINDOW2  (unsigned char)~_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WINDOW3  (unsigned char)~_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE0_DEFAULT  (0x0)
#define FUSE_WDTCFG_DEFAULT  (0x0)

/* Fuse Byte 1 (BODCFG) */
#define FUSE_SLEEP0  (unsigned char)~_BV(0)  /* BOD Operation in Sleep Mode Bit 0 */
#define FUSE_SLEEP1  (unsigned char)~_BV(1)  /* BOD Operation in Sleep Mode Bit 1 */
#define FUSE_ACTIVE0  (unsigned char)~_BV(2)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_ACTIVE1  (unsigned char)~_BV(3)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE_SAMPFREQ  (unsigned char)~_BV(4)  /* BOD Sample Frequency */
#define FUSE_LVL0  (unsigned char)~_BV(5)  /* BOD Level Bit 0 */
#define FUSE_LVL1  (unsigned char)~_BV(6)  /* BOD Level Bit 1 */
#define FUSE_LVL2  (unsigned char)~_BV(7)  /* BOD Level Bit 2 */
#define FUSE1_DEFAULT  (0x0)
#define FUSE_BODCFG_DEFAULT  (0x0)

/* Fuse Byte 2 (OSCCFG) */
#define FUSE_FREQSEL0  (unsigned char)~_BV(0)  /* Frequency Select Bit 0 */
#define FUSE_FREQSEL1  (unsigned char)~_BV(1)  /* Frequency Select Bit 1 */
#define FUSE_OSCLOCK  (unsigned char)~_BV(7)  /* Oscillator Lock */
#define FUSE2_DEFAULT  (0x2)
#define FUSE_OSCCFG_DEFAULT  (0x2)

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 Reserved */

/* Fuse Byte 5 (SYSCFG0) */
#define FUSE_EESAVE  (unsigned char)~_BV(0)  /* EEPROM Save */
#define FUSE_RSTPINCFG  (unsigned char)~_BV(3)  /* Reset Pin Configuration */
#define FUSE_CRCSRC0  (unsigned char)~_BV(6)  /* CRC Source Bit 0 */
#define FUSE_CRCSRC1  (unsigned char)~_BV(7)  /* CRC Source Bit 1 */
#define FUSE5_DEFAULT  (0xc4)
#define FUSE_SYSCFG0_DEFAULT  (0xc4)

/* Fuse Byte 6 (SYSCFG1) */
#define FUSE_SUT0  (unsigned char)~_BV(0)  /* Startup Time Bit 0 */
#define FUSE_SUT1  (unsigned char)~_BV(1)  /* Startup Time Bit 1 */
#define FUSE_SUT2  (unsigned char)~_BV(2)  /* Startup Time Bit 2 */
#define FUSE6_DEFAULT  (0x7)
#define FUSE_SYSCFG1_DEFAULT  (0x7)

/* Fuse Byte 7 (APPEND) */
#define FUSE7_DEFAULT  (0x0)
#define FUSE_APPEND_DEFAULT  (0x0)

/* Fuse Byte 8 (BOOTEND) */
#define FUSE8_DEFAULT  (0x0)
#define FUSE_BOOTEND_DEFAULT  (0x0)

/* ========== Lock Bits ========== */
#define __LOCK_BITS_EXIST

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x27


#endif /* #ifdef _AVR_ATMEGA1608_H_INCLUDED */

