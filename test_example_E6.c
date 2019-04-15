/* Copyright 2019 Bernd Lehmann
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <stdint.h>
#include "HID_Report.h"
#include "_test_helper.h"

/*
 * References:
 * [1] Device Class Definition for Human Interface Devices (HID) (6/27/01) Version 1.11
 * [2] HID Usage Tables (10/28/2004) Version 1.12
 */


/*
 * This is the HID Report example for a Keyboard from section E.6 of [1].
 */
static const uint8_t hid_keyboard_example_E6[] = {
        0x05, 0x01, // Usage Page (Generic Desktop)
        0x09, 0x06, // Usage (Keyboard)
        0xa1, 0x01, // Collection (Application)
        0x05, 0x07, //   Usage Page (Keyboard/Keypad)
        0x19, 0xe0, //   Usage Minimum (224)
        0x29, 0xe7, //   Usage Maximum (231)
        0x15, 0x00, //   Logical Minimum (0)
        0x25, 0x01, //   Logical Maximum (1)
        0x75, 0x01, //   Report Size (1)
        0x95, 0x08, //   Report Count (8)
        0x81, 0x02, //   Input (Data, Variable, Absolute)
        0x95, 0x01, //   Report Count (1)
        0x75, 0x08, //   Report Size (8)
        0x81, 0x01, //   Input (Constant)
	0x95, 0x05, //   Report Count (5)
	0x75, 0x01, //   Report Size (1)
	0x05, 0x08, //   Usage Page (Page# for LEDs)
	0x19, 0x01, //   Usage Minimum (1)
	0x29, 0x05, //   Usage Maximum (5)
	0x91, 0x02, //   Output (Data, Variable, Absolute)
	0x95, 0x01, //   Report Count (1)
	0x75, 0x03, //   Report Size (3)
	0x91, 0x01, //   Output (Constatnt)
        0x95, 0x06, //   Report Count (6)
        0x75, 0x08, //   Report Size (8)
        0x15, 0x00, //   Logical Minimum (0)
        0x25, 0x65, //   Logical Maximum (101)
        0x05, 0x07, //   Usage Page (Keyboard/Keypad)
        0x19, 0x00, //   Usage Minimum (0)
        0x29, 0x65, //   Usage Maximum (101)
        0x81, 0x00, //   Input (Data, Array)
        0xc0,       // End Collection
};


/*
 * This is the HID Report example for a Keyboard from section E.6 of [1] using the macros 
 * defined in "HID_Report.h".
 */
static const uint8_t copy[] = {
	USAGE_PAGE (GENERIC_DESKTOP_CONTROLS),
	USAGE (KEYBOARD),
	COLLECTION (APPLICATION),
	  USAGE_PAGE (KEYBOARD_KEYPAD),
	  USAGE_MINIMUM (224),
	  USAGE_MAXIMUM (231),
	  LOGICAL_MINIMUM (0),
	  LOGICAL_MAXIMUM (1),
	  REPORT_SIZE (1),
	  REPORT_COUNT (8),
	  INPUT (DATA | VARIABLE | ABSOLUTE),
	  REPORT_COUNT (1),
	  REPORT_SIZE (8),
	  INPUT (CONSTANT),
	  REPORT_COUNT (5),
	  REPORT_SIZE (1),
	  USAGE_PAGE (LEDS),
	  USAGE_MINIMUM (1),
	  USAGE_MAXIMUM (5),
	  OUTPUT (DATA | VARIABLE | ABSOLUTE),
	  REPORT_COUNT (1),
	  REPORT_SIZE (3),
	  OUTPUT (CONSTANT),
	  REPORT_COUNT (6),
	  REPORT_SIZE (8),
	  LOGICAL_MINIMUM (0),
	  LOGICAL_MAXIMUM (101),
	  USAGE_PAGE (KEYBOARD_KEYPAD),
	  USAGE_MINIMUM (0),
	  USAGE_MAXIMUM (101),
	  INPUT (DATA | ARRAY),
	END_COLLECTION
};

int main(int argc, char **argv)
{
	return compare(hid_keyboard_example_E6, sizeof(hid_keyboard_example_E6),copy, sizeof(copy));
}

