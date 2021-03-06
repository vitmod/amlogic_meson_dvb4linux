/*
 * Airoha AV201x tuner driver
 *
 * Copyright (C) 2020 Availink, Inc. (opensource@availink.com)
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef AV201X_AVL_DRV_H
#define AV201X_AVL_DRV_H

#include "AVL_Tuner.h"

#ifdef AVL_CPLUSPLUS
extern "C"
{
#endif

  ///////////////////////////////////////////////////////
  typedef unsigned char UINT8;

  typedef short AVL_int16;
  typedef unsigned short UINT16;

  typedef int INT32;
  typedef unsigned int UINT32;

  //////////////////////////////////////////////////////////
  //-----------------------------------------------------------------------------
  // Types and Enum definition
  //-----------------------------------------------------------------------------

  typedef enum _e_AV201X_IQMODE
  {
    e_AV201X_IQ_DIFF = 0,
    e_AV201X_IQ_SIG
  } e_AV201X_IQMODE;

  typedef enum _e_AV201X_BBGAIN
  {
    e_AV201X_BBG_0DB = 0,
    e_AV201X_BBG_1p5DB,
    e_AV201X_BBG_3DB,
    e_AV201X_BBG_4p5DB,
    e_AV201X_BBG_6DB,
    e_AV201X_BBG_7p5DB,
    e_AV201X_BBG_9DB,
    e_AV201X_BBG_10p5DB,
    e_AV201X_BBG_12DB
  } e_AV201X_BBGAIN;

  typedef enum _e_AV201X_LOOPTHROUGH
  {
    e_AV201X_LOOP_OFF = 0,
    e_AV201X_LOOP_ON
  } e_AV201X_LOOPTHROUGH;

  typedef enum _e_AV201X_XTAL_Freq
  {
    e_AV201X_XTAL_Freq_25Mhz = 25000,
    e_AV201X_XTAL_Freq_27Mhz = 27000,
    e_AV201X_XTAL_Freq_30p4Mhz = 30400,
    e_AV201X_XTAL_Freq_4Mhz = 4000,
    e_AV201X_XTAL_Freq_50Mhz = 50000,
    e_AV201X_XTAL_Freq_10Mhz = 10000,
    e_AV201X_XTAL_Freq_10p11Mhz = 10111,
    e_AV201X_XTAL_Freq_15Mhz = 15000,
    e_AV201X_XTAL_Freq_16Mhz = 16000,
    e_AV201X_XTAL_Freq_30Mhz = 30000,
    e_AV201X_XTAL_Freq_Other
  } e_AV201X_XTAL_Freq;

  typedef enum _e_AV201X_Model
  {
    e_AV201X_Model_AV2011 = 0,
    e_AV201X_Model_AV2012 = 1,
    e_AV201X_Model_AV2018 = 2
  } e_AV201X_Model;

  typedef struct _s_AV201X_Params
  {
    unsigned char u1UseDefaults;
    e_AV201X_XTAL_Freq eXTAL_Freq;
    e_AV201X_IQMODE eIQmode;
    e_AV201X_BBGAIN eBBG;
    e_AV201X_LOOPTHROUGH eLoopTh;
    unsigned char u1FT;
  } s_AV201X_Params;

//-----------------------------------------------------------------------------
//Default_Definition
//-----------------------------------------------------------------------------
#define AV201X_FILTER_BANDWIDTH_MAX 40
#define AV201X_FILTER_BANDWIDTH_MIN 4
#define AV201X_FIX_LPF_MIN 9.3
#define AV201X_DEFAULT_USE_DEFAULTS 1
#define AV201X_DEFALUT_XTAL_FREQ e_AV201X_XTAL_Freq_27Mhz
#define AV201X_DEFALUT_IQ_MODE e_AV201X_IQ_SIG
#define AV201X_DEFALUT_BB_GAIN e_AV201X_BBG_1p5DB
#define AV201X_DEFAULT_LOOP_THROUGH e_AV201X_LOOP_OFF
#define AV201X_DEFAULT_FT_STATE 0x6
#define AV201X_DEFAULT_TUNER_MODEL e_AV201X_Model_AV2018

#define AV201X_R0 0x00
#define AV201X_R1 0x01
#define AV201X_R2 0x02
#define AV201X_R3 0x03
#define AV201X_R4 0x04
#define AV201X_R5 0x05
#define AV201X_R6 0x06
#define AV201X_R7 0x07
#define AV201X_R8 0x08
#define AV201X_R9 0x09
#define AV201X_RA 0x0A
#define AV201X_RB 0x0B
#define AV201X_RC 0x0C
#define AV201X_RD 0x0D
#define AV201X_RE 0x0E
#define AV201X_RF 0x0F
#define AV201X_RF_PD 0x80
#define AV201X_RF_CLR 0x40
#define AV201X_RF_P0 0x20

/**********************************************************************************/
/* Register Bits */
/**********************************************************************************/
#define AV201X_R11_PLL_LOCK 0x01
#define AV201X_R11_LPF_LOCK 0x02

  extern e_AV201X_Model g_eAV201X_TunerModel;

  AVL_uint32 AV201X_Initialize(struct AVL_Tuner *pTuner);
  AVL_uint32 AV201X_GetLockStatus(struct AVL_Tuner *pTuner);
  AVL_uint32 AV201X_Lock(struct AVL_Tuner *pTuner);
  AVL_uint32 AV201X_GetMaxLPF(struct AVL_Tuner *pTuner, AVL_uint32 *puiMaxLPFHz);
  AVL_uint32 AV201X_GetMinLPF(struct AVL_Tuner *pTuner, AVL_uint32 *puiMinLPFHz);

  void AV201X_Time_DELAY_MS(UINT32 ms);
  AVL_uint32 AV201X_I2C_write(struct AVL_Tuner *pTuner, UINT8 reg_start, UINT8 *buff, UINT8 len);
  AVL_uint32 AV201X_I2C_read(struct AVL_Tuner *pTuner, UINT8 addr, UINT8 *data);

#ifdef AVL_CPLUSPLUS
}
#endif

#endif
