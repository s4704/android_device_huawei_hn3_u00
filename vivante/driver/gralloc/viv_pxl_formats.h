/*

 * Copyright (C) 2016 Android For Marvell Project <ctx.xda@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.

 */

#ifndef VIV_PIXEL_FORMATS_H_INCLUDED
#define VIV_PIXEL_FORMATS_H_INCLUDED

 	/* Define Vivante Pixel Formats */
#define    HAL_PIXEL_FORMAT_YCbCr_422_SP        0x10 // NV16
#define    HAL_PIXEL_FORMAT_YCrCb_420_SP        0x11 // NV21
#define    HAL_PIXEL_FORMAT_YCbCr_422_I         0x14 // YUY2
#define    HAL_PIXEL_FORMAT_YCbCr_420_I         0x15
#define    HAL_PIXEL_FORMAT_CbYCrY_420_I        0x17
#define    HAL_PIXEL_FORMAT_YCbCr_422_P         0x100
#define    HAL_PIXEL_FORMAT_YCbCr_420_P         0x101 // I420
#define    HAL_PIXEL_FORMAT_CbYCrY_422_I        0x102 // UYVY
#define    HAL_PIXEL_FORMAT_YCbCr_420_SP        0x103 // NV12
#define    HAL_PIXEL_FORMAT_YCrCb_422_SP        0x23 // NV61
#define    HAL_PIXEL_FORMAT_YV12                0x32315659 // YCrCb 4:2:0 Planar

#endif // VIV_PIXEL_FORMATS_H_INCLUDED