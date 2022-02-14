/*
 * FpDevice - A fingerprint reader device
 * Copyright (C) 2021 Marco Trevisan <marco.trevisan@canonical.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#pragma once

#include "tod/tod-macros.h"

typedef struct _FpDevice FpDevice;

typedef enum {
  FP_DEVICE_TYPE_TODV1_90_1_VIRTUAL,
  FP_DEVICE_TYPE_TODV1_90_1_USB,
} FpDeviceTypeTODV1_90_1;

typedef enum {
  FP_DEVICE_TYPE_TODV1_92_0_VIRTUAL,
  FP_DEVICE_TYPE_TODV1_92_0_USB,
  FP_DEVICE_TYPE_TODV1_92_0_UDEV,
} FpDeviceTypeTODV1_92_0;

typedef enum {
  FP_SCAN_TYPE_TODV1_90_1_SWIPE,
  FP_SCAN_TYPE_TODV1_90_1_PRESS,
} FpScanTypeTODV1_90_1;

typedef enum {
  FP_DEVICE_RETRY_TODV1_90_1_GENERAL,
  FP_DEVICE_RETRY_TODV1_90_1_TOO_SHORT,
  FP_DEVICE_RETRY_TODV1_90_1_CENTER_FINGER,
  FP_DEVICE_RETRY_TODV1_90_1_REMOVE_FINGER,
} FpDeviceRetryTODV1_90_1;

typedef enum {
  FP_DEVICE_ERROR_TODV1_90_1_GENERAL,
  FP_DEVICE_ERROR_TODV1_90_1_NOT_SUPPORTED,
  FP_DEVICE_ERROR_TODV1_90_1_NOT_OPEN,
  FP_DEVICE_ERROR_TODV1_90_1_ALREADY_OPEN,
  FP_DEVICE_ERROR_TODV1_90_1_BUSY,
  FP_DEVICE_ERROR_TODV1_90_1_PROTO,
  FP_DEVICE_ERROR_TODV1_90_1_DATA_INVALID,
  FP_DEVICE_ERROR_TODV1_90_1_DATA_NOT_FOUND,
  FP_DEVICE_ERROR_TODV1_90_1_DATA_FULL,
} FpDeviceErrorTODV1_90_1;

typedef enum {
  FP_DEVICE_ERROR_TODV1_90_3_GENERAL,
  FP_DEVICE_ERROR_TODV1_90_3_NOT_SUPPORTED,
  FP_DEVICE_ERROR_TODV1_90_3_NOT_OPEN,
  FP_DEVICE_ERROR_TODV1_90_3_ALREADY_OPEN,
  FP_DEVICE_ERROR_TODV1_90_3_BUSY,
  FP_DEVICE_ERROR_TODV1_90_3_PROTO,
  FP_DEVICE_ERROR_TODV1_90_3_DATA_INVALID,
  FP_DEVICE_ERROR_TODV1_90_3_DATA_NOT_FOUND,
  FP_DEVICE_ERROR_TODV1_90_3_DATA_FULL,
  FP_DEVICE_ERROR_TODV1_90_3_DATA_DUPLICATE,
} FpDeviceErrorTODV1_90_3;

typedef enum {
  FP_DEVICE_ERROR_TODV1_90_4_GENERAL,
  FP_DEVICE_ERROR_TODV1_90_4_NOT_SUPPORTED,
  FP_DEVICE_ERROR_TODV1_90_4_NOT_OPEN,
  FP_DEVICE_ERROR_TODV1_90_4_ALREADY_OPEN,
  FP_DEVICE_ERROR_TODV1_90_4_BUSY,
  FP_DEVICE_ERROR_TODV1_90_4_PROTO,
  FP_DEVICE_ERROR_TODV1_90_4_DATA_INVALID,
  FP_DEVICE_ERROR_TODV1_90_4_DATA_NOT_FOUND,
  FP_DEVICE_ERROR_TODV1_90_4_DATA_FULL,
  FP_DEVICE_ERROR_TODV1_90_4_DATA_DUPLICATE,
  /* Leave some room to add more DATA related errors */
  FP_DEVICE_ERROR_TODV1_90_4_REMOVED = 0x100,
} FpDeviceErrorTODV1_90_4;

typedef enum /*< flags >*/ {
  FP_DEVICE_FEATURE_TODV1_92_0_NONE = 0,
  FP_DEVICE_FEATURE_TODV1_92_0_CAPTURE = 1 << 0,
  FP_DEVICE_FEATURE_TODV1_92_0_IDENTIFY = 1 << 1,
  FP_DEVICE_FEATURE_TODV1_92_0_VERIFY = 1 << 2,
  FP_DEVICE_FEATURE_TODV1_92_0_STORAGE = 1 << 3,
  FP_DEVICE_FEATURE_TODV1_92_0_STORAGE_LIST = 1 << 4,
  FP_DEVICE_FEATURE_TODV1_92_0_STORAGE_DELETE = 1 << 5,
  FP_DEVICE_FEATURE_TODV1_92_0_STORAGE_CLEAR = 1 << 6,
  FP_DEVICE_FEATURE_TODV1_92_0_DUPLICATES_CHECK = 1 << 7,
} FpDeviceFeatureTODV1_92_0;

typedef enum /*< flags >*/ {
  FP_DEVICE_FEATURE_TODV1_94_0_NONE = 0,
  FP_DEVICE_FEATURE_TODV1_94_0_CAPTURE = 1 << 0,
  FP_DEVICE_FEATURE_TODV1_94_0_IDENTIFY = 1 << 1,
  FP_DEVICE_FEATURE_TODV1_94_0_VERIFY = 1 << 2,
  FP_DEVICE_FEATURE_TODV1_94_0_STORAGE = 1 << 3,
  FP_DEVICE_FEATURE_TODV1_94_0_STORAGE_LIST = 1 << 4,
  FP_DEVICE_FEATURE_TODV1_94_0_STORAGE_DELETE = 1 << 5,
  FP_DEVICE_FEATURE_TODV1_94_0_STORAGE_CLEAR = 1 << 6,
  FP_DEVICE_FEATURE_TODV1_94_0_DUPLICATES_CHECK = 1 << 7,
  FP_DEVICE_FEATURE_TODV1_94_0_ALWAYS_ON = 1 << 8,
} FpDeviceFeatureTODV1_94_0;

typedef enum {
  FP_DEVICE_ERROR_TODV1_94_0_GENERAL,
  FP_DEVICE_ERROR_TODV1_94_0_NOT_SUPPORTED,
  FP_DEVICE_ERROR_TODV1_94_0_NOT_OPEN,
  FP_DEVICE_ERROR_TODV1_94_0_ALREADY_OPEN,
  FP_DEVICE_ERROR_TODV1_94_0_BUSY,
  FP_DEVICE_ERROR_TODV1_94_0_PROTO,
  FP_DEVICE_ERROR_TODV1_94_0_DATA_INVALID,
  FP_DEVICE_ERROR_TODV1_94_0_DATA_NOT_FOUND,
  FP_DEVICE_ERROR_TODV1_94_0_DATA_FULL,
  FP_DEVICE_ERROR_TODV1_94_0_DATA_DUPLICATE,
  /* Leave some room to add more DATA related errors */
  FP_DEVICE_ERROR_TODV1_94_0_REMOVED = 0x100,
  FP_DEVICE_ERROR_TODV1_94_0_TOO_HOT,
} FpDeviceErrorTODV1_94_0;

typedef enum {
  FP_TEMPERATURE_TODV1_94_0_COLD,
  FP_TEMPERATURE_TODV1_94_0_WARM,
  FP_TEMPERATURE_TODV1_94_0_HOT,
} FpTemperatureTODV1_94_0;
