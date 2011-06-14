/*
 * settings.h - system untime settings
 * Part of TinyG project
 *
 * Copyright (c) 2011 Alden S. Hart Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 */
/* Note: The values in this file are the default settings that are loaded
 * 		 into a virgin EEPROM, and can be changed using the config commands.
 *		 After initial load the EEPROM values (or changed values) are used.
 *
 *		 System and hardware settings that you shouldn't need to change 
 *		 are in system.h  Application settings that also shouldn't need 
 *		 to be changed are in tinyg.h
 */

#ifndef settings_h
#define settings_h

/*
 * SYSTEM SETTINGS - for initial load of EEPROM values
 */
/* general machine settings */

/*	Angular jerk thresholds set that ranges over which different path 
	control modes are in effect. Angular jerk of 0.0 is no jerk - i.e. 
 	a straight line. Max jerk is 1.0 for a 180 degree turn. A 90 degree 
	turn is 0.707... If the jerk is above the upper threshold the path
	control mode will be degraded to exact_stop mode. If between the upper 
	and lower if will be degraded to exact_path mode. If below the lower 
	threshold the path control mode will not be affected - i.e. can 
	operate in full continuous mode.
 */

//#define MAX_LINEAR_JERK 5000000	//   5,000,000 mm/(min^3)
//#define MAX_LINEAR_JERK 1000000	//  10,000,000 mm/(min^3)
//#define MAX_LINEAR_JERK 25000000	//  25,000,000 mm/(min^3)
#define MAX_LINEAR_JERK 50000000	//  50,000,000 mm/(min^3)
//#define MAX_LINEAR_JERK 100000000	// 100,000,000 mm/(min^3)

#define ANGULAR_JERK_UPPER_THRESHOLD 0.70	// above which it's exact stop
#define ANGULAR_JERK_LOWER_THRESHOLD 0.30	// below which it's continuous
#define ENABLE_ACCEL 1						// 1 to enable
//#define ENABLE_ACCEL 0

#define MAX_VELOCITY 1500			// ++++ THIS NEEDS TO BE A COMPUTED VALUE

/* Gcode power-on defaults */

#define GCODE_PLANE	CANON_PLANE_XY
#define GCODE_UNITS UNITS_MM
#define GCODE_PATH_CONTROL PATH_CONTINUOUS
//#define GCODE_PATH_CONTROL PATH_EXACT_PATH
//#define GCODE_PATH_CONTROL PATH_EXACT_STOP
#define GCODE_TOOL 1
#define GCODE_FEED_RATE 300			// mm/min
#define GCODE_SPINDLE_SPEED 1500	// rpm

/* axis mapping and modes */

#define X_AXIS_MAP 0				// standard axis mappings (off by one)
#define Y_AXIS_MAP 1
#define Z_AXIS_MAP 2
#define A_AXIS_MAP 3

/* Axis mode settings
 *
 *	0 = disabled - useful for dry runs
 *	1 = independent mode - axis runs independent and coordinated
 *	2 = slaved mode - see each axis for what this means
 *	3 = uncoordinated mode - axis is not included in coordinated motion
 */
#define X_AXIS_MODE 1	// slaved mode is not meaningful
#define Y_AXIS_MODE 1	// slaved mode is not meaningful
#define Z_AXIS_MODE 1	// slaved mode is not meaningful
#define A_AXIS_MODE 1	// slaved mode slaves to linear travel
#define B_AXIS_MODE 0	// slaved mode slaves to linear travel
#define C_AXIS_MODE 0	// slaved mode slaves to linear travel
#define U_AXIS_MODE 2	// independent mode unsupported - slave slaves to X
#define V_AXIS_MODE 2	// independent mode unsupported - slave slaves to Y
#define W_AXIS_MODE 2	// independent mode unsupported - slave slaves to Z

/* motor settings */

#define STEP_ANGLE 1.8			// 1.8 degrees is typical
//#define STEP_ANGLE 0.9				// 0.9 in some cases
#define MICROSTEP_MODE 8			// Choose one of: 8, 4, 2, 1

/* robot dimensions */

#define X_TRAVEL 200				// total travel in X in mm
#define Y_TRAVEL 200
#define Z_TRAVEL 200
#define A_TRAVEL 200

#define A_RADIUS RADIAN				// makes mm/min = degrees/min on conversion
#define B_RADIUS RADIAN
#define C_RADIUS RADIAN

/* homing cycle settings */

//#define HOMING_MODE TRUE			// set TRUE for power-on-homing
#define HOMING_MODE FALSE			// set TRUE for power-on-homing
#define HOMING_SEEK_RATE 500		// mm/min
#define HOMING_CLOSE_RATE 5			// mm/min
#define HOMING_BACKOFF 10			// mm

#define X_HOMING_ENABLE 1			// 1=enabled for that axis
#define Y_HOMING_ENABLE 1
#define Z_HOMING_ENABLE 1
#define A_HOMING_ENABLE 1

/* machine profiles - chose one: */

//#define __LEADSCREW_20				// 1/4" 20 leadscrew table - Riley special
#define __LEADSCREW_10			// 10 TPI leadscrew table - std threading
//#define __MAKERBOT				// Makerbot settings

// Profile for 1/4-20 hardware leadscrew // Note: POLARITY is [0,1,0,0]
#ifdef __LEADSCREW_20
#define SEEK_STEPS 500
#define FEED_STEPS 500
#define TRAVEL_PER_REV 1.27
#endif

// Profile for 10 TPI  leadscrew machines
#ifdef __LEADSCREW_10
#define SEEK_STEPS 2500
#define FEED_STEPS 2000
//#define SEEK_STEPS 500
//#define FEED_STEPS 500
#define TRAVEL_PER_REV 2.54
#endif

// Makerbot profile					// Note: POLARITY is [0,0,1,1]
#ifdef __MAKERBOT
#define SEEK_STEPS 500
#define FEED_STEPS 500
#define TRAVEL_PER_REV 33			// must set Z to 1.27 (or something)
#define HOMING_OFFSET -50
#endif

/*
 * DERIVED VALUES (from above) - shouldn't need changing but can be overtyped
 */

#define X_SEEK_STEPS SEEK_STEPS // max whole steps per second for G0 motion
#define Y_SEEK_STEPS SEEK_STEPS // (motor parameter)
#define Z_SEEK_STEPS SEEK_STEPS
#define A_SEEK_STEPS SEEK_STEPS

#define X_FEED_STEPS FEED_STEPS // max whole steps per sec for feed motion
#define Y_FEED_STEPS FEED_STEPS // (motor parameter)
#define Z_FEED_STEPS FEED_STEPS
#define A_FEED_STEPS FEED_STEPS

#define X_STEP_ANGLE STEP_ANGLE			// degrees per whole step
#define Y_STEP_ANGLE STEP_ANGLE 		// (motor parameter)
#define Z_STEP_ANGLE STEP_ANGLE
#define A_STEP_ANGLE STEP_ANGLE

#define X_MICROSTEPS MICROSTEP_MODE	// microstep mode 
#define Y_MICROSTEPS MICROSTEP_MODE	// (stepper driver configuration parameter)
#define Z_MICROSTEPS MICROSTEP_MODE
#define A_MICROSTEPS MICROSTEP_MODE

#define X_POLARITY 0					// motor direction polarity
#define Y_POLARITY 0
#define Z_POLARITY 0
#define A_POLARITY 0

#define X_POWER_MODE TRUE				// 1=low power idle enabled 
#define Y_POWER_MODE TRUE				// (robot parameter)
#define Z_POWER_MODE TRUE
#define A_POWER_MODE TRUE

#define X_LIMIT_MODE TRUE				// 1=limit switches present and enabled
#define Y_LIMIT_MODE TRUE				// (robot parameter)
#define Z_LIMIT_MODE TRUE
#define A_LIMIT_MODE TRUE

#define X_TRAVEL_PER_REV TRAVEL_PER_REV	// typ. set by leadscrews or cogwheels
#define Y_TRAVEL_PER_REV TRAVEL_PER_REV	// (robot parameter)
#define Z_TRAVEL_PER_REV TRAVEL_PER_REV
#define A_TRAVEL_PER_REV TRAVEL_PER_REV	// degrees moved per motor revolution

#define X_TRAVEL_MAX X_TRAVEL			// full excursion from min to max 
#define Y_TRAVEL_MAX Y_TRAVEL			// (robot parameter)
#define Z_TRAVEL_MAX Z_TRAVEL
#define A_TRAVEL_MAX A_TRAVEL			// -1 is no limit (typ for rotary axis)

#define X_TRAVEL_WARN X_TRAVEL			// full excursion from min to max 
#define Y_TRAVEL_WARN Y_TRAVEL
#define Z_TRAVEL_WARN Z_TRAVEL
#define A_TRAVEL_WARN -1				// -1 is no limit (typ for rotary axis)

#define X_HOMING_OFFSET -(X_TRAVEL/2) 	// offset to zero from axis minimum
#define Y_HOMING_OFFSET -(Y_TRAVEL/2)
#define Z_HOMING_OFFSET -(Z_TRAVEL/2)
#define A_HOMING_OFFSET -(A_TRAVEL/2)

#define X_HOMING_SEEK_RATE HOMING_SEEK_RATE
#define Y_HOMING_SEEK_RATE HOMING_SEEK_RATE
#define Z_HOMING_SEEK_RATE HOMING_SEEK_RATE
#define A_HOMING_SEEK_RATE HOMING_SEEK_RATE

#define X_HOMING_CLOSE_RATE HOMING_CLOSE_RATE
#define Y_HOMING_CLOSE_RATE HOMING_CLOSE_RATE
#define Z_HOMING_CLOSE_RATE HOMING_CLOSE_RATE
#define A_HOMING_CLOSE_RATE HOMING_CLOSE_RATE

#define X_HOMING_BACKOFF HOMING_BACKOFF
#define Y_HOMING_BACKOFF HOMING_BACKOFF
#define Z_HOMING_BACKOFF HOMING_BACKOFF
#define A_HOMING_BACKOFF HOMING_BACKOFF

#endif