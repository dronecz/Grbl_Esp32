/*
    midtbot.h
    Part of Grbl_ESP32

    Pin assignments for the Buildlog.net midtbot
    https://github.com/bdring/midTbot_esp32

    2018    - Bart Dring
    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "MIDTBOT"

#define SPINDLE_TYPE    SPINDLE_TYPE_NONE

#define X_STEP_PIN      GPIO_NUM_12
#define Y_STEP_PIN      GPIO_NUM_14

#define X_DIRECTION_PIN GPIO_NUM_26
#define Y_DIRECTION_PIN GPIO_NUM_25

#ifndef COREXY // maybe set in config.h
    #define COREXY
#endif

#define STEPPERS_DISABLE_PIN GPIO_NUM_13

#define X_LIMIT_PIN     GPIO_NUM_2
#define Y_LIMIT_PIN     GPIO_NUM_4
#define LIMIT_MASK      B11

#define USE_SERVO_AXES

#define SERVO_Z_PIN             GPIO_NUM_27
#define SERVO_Z_RANGE_MIN       0.0
#define SERVO_Z_RANGE_MAX       5.0
#define SERVO_Z_HOMING_TYPE     SERVO_HOMING_TARGET // during homing it will instantly move to a target value
#define SERVO_Z_HOME_POS        SERVO_Z_RANGE_MAX // move to max during homing
#define SERVO_Z_MPOS            false   // will not use mpos, uses work coordinates

#ifndef IGNORE_CONTROL_PINS // maybe set in config.h
    #define IGNORE_CONTROL_PINS
#endif

// redefine some stuff from config.h
#ifdef HOMING_CYCLE_0
    #undef HOMING_CYCLE_0
#endif

#define HOMING_CYCLE_0 (1<<Y_AXIS)

#ifdef HOMING_CYCLE_1
    #undef HOMING_CYCLE_1
#endif

#define HOMING_CYCLE_1 (1<<X_AXIS)

#ifdef HOMING_CYCLE_2
    #undef HOMING_CYCLE_2
#endif

#define SERVO_PEN_PIN           GPIO_NUM_27

// defaults
#define DEFAULT_STEP_PULSE_MICROSECONDS 3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME  255 // stay on

#define DEFAULT_STEPPING_INVERT_MASK    0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   2 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 1

#define DEFAULT_JUNCTION_DEVIATION  0.01 // mm
#define DEFAULT_ARC_TOLERANCE       0.002 // mm
#define DEFAULT_REPORT_INCHES       0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 0  // false

#define DEFAULT_HOMING_ENABLE           1
#define DEFAULT_HOMING_DIR_MASK         1
#define DEFAULT_HOMING_FEED_RATE        200.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          3.0 // mm

#define DEFAULT_X_STEPS_PER_MM 200.0
#define DEFAULT_Y_STEPS_PER_MM 100.0
#define DEFAULT_Z_STEPS_PER_MM 100.0 // This is percent in servo mode

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 5000.0 // mm/min

#define DEFAULT_X_ACCELERATION (200.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Y_ACCELERATION (200.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Z_ACCELERATION (100.0*60*60)

#define DEFAULT_X_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 100.0 // This is percent in servo mode
