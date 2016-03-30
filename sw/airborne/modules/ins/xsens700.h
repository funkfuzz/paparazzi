/*
 * Copyright (C) 2010 ENAC
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/** @file modules/ins/xsens_700.h
 * Parser for the Xsens protocol.
 */

#ifndef XSENS700_H
#define XSENS700_H

#include "std.h"
#include "math/pprz_algebra_float.h"
#include "math/pprz_geodetic_float.h"
#include "math/pprz_geodetic_int.h"

#if USE_GPS_XSENS
#include "subsystems/gps.h"
#endif

struct XsensTime {
  int8_t hour;
  int8_t min;
  int8_t sec;
  int32_t nanosec;
  int16_t year;
  int8_t month;
  int8_t day;
};

struct Xsens {
  struct XsensTime time;
  uint16_t time_stamp;

  struct FloatRates gyro;
  struct FloatVect3 accel;
  struct FloatVect3 mag;

  struct LlaCoor_f lla_f;
  struct FloatVect3 vel;  ///< NED velocity in m/s

  struct FloatQuat quat;
  struct FloatEulers euler;

  volatile bool_t msg_received;
  volatile bool_t new_attitude;

  bool_t gyro_available;
  bool_t accel_available;
  bool_t mag_available;

#if USE_GPS_XSENS
  struct GpsState gps;
  bool_t gps_available;
#endif
};

extern struct Xsens xsens700;

extern void xsens700_init(void);
extern void xsens700_periodic(void);
extern void parse_xsens700_msg(void);

#endif /* XSENS700_H */
