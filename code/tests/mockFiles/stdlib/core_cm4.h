/**************************************************************************//**
 * @file     core_cm4.h
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File
 * @version  V5.00
 * @date     13. September 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if   defined ( __ICCARM__ )
 #pragma system_include         /* treat file as system include file for MISRA check */
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header   /* treat file as system include file */
#endif

#ifndef __CORE_CM4_H_GENERIC
#define __CORE_CM4_H_GENERIC

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#define     __IO    volatile             /*!< Defines 'read / write' permissions */

#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM4_H_DEPENDANT */

//#endif /* __CMSIS_GENERIC */

