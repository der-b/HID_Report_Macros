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
 * This is the HID Report example for a Keyboard from section E.10 of [1].
 */
static const uint8_t hid_keyboard_example_E6[] = {
        0x05, 0x01, // Usage Page (Generic Desktop)
	0x09, 0x02, // Usage (Mouse)
	0xa1, 0x01, // Collection (Application)
	0x09, 0x01, //   Usage(Pointer)
	0xa1, 0x00, //   Collection(Physical)
	0x05, 0x09, //     Usage Page (Buttons)
	0x19, 0x01, //     Usage Minimum (01)
	0x29, 0x03, //     Usage Maximum (03)
	0x15, 0x00, //     Logical Minimum (0)
	0x25, 0x01, //     Logical Maximum (1)
	0x95, 0x03, //     Report Count (3)
	0x75, 0x01, //     Report Size (1)
	0x81, 0x02, //     Input (Data, Variable, Absolute)
	0x95, 0x01, //     Report Count (1)
	0x75, 0x05, //     Report Size (5)
	0x81, 0x01, //     Input (Constant)
	0x05, 0x01, //     Usage Page (Generic Desktop)
	0x09, 0x30, //     Usage (X)
	0x09, 0x31, //     Usage (Y)
	0x15, 0x81, //     Logical Minimum (-127)
	0x25, 0x7f, //     Logical Maximum (127)
	0x75, 0x08, //     Report Size (8)
	0x95, 0x02, //     Report Count (2)
	0x81, 0x06, //     Input (Data, Variable, Relative)
	0xc0,       //   End Collection
	0xc0        // End COllection
};


/*
 * This is the HID Report example for a Keyboard from section E.10 of [1] using the macros 
 * defined in "HID_Report.h".
 */
static const uint8_t copy[] = {
	USAGE_PAGE (GENERIC_DESKTOP_CONTROLS),
	USAGE (MOUSE),
	COLLECTION (APPLICATION),
	  USAGE (POINTER),
	  COLLECTION (PHYSICAL),
	  	USAGE_PAGE (BUTTON),
		USAGE_MINIMUM (01),
		USAGE_MAXIMUM (03),
		LOGICAL_MINIMUM (0),
		LOGICAL_MAXIMUM (1),
		REPORT_COUNT (3),
		REPORT_SIZE (1),
		INPUT (DATA | VARIABLE | ABSOLUTE),
		REPORT_COUNT (1),
		REPORT_SIZE (5),
		INPUT (CONSTANT),
		USAGE_PAGE (GENERIC_DESKTOP_CONTROLS),
		USAGE (X),
		USAGE (Y),
		LOGICAL_MINIMUM (-127),
		LOGICAL_MAXIMUM (127),
		REPORT_SIZE (8),
		REPORT_COUNT (2),
		INPUT (DATA | VARIABLE | RELATIVE),
	END_COLLECTION,
END_COLLECTION
};

int main(int argc, char **argv)
{
	return compare(hid_keyboard_example_E6, sizeof(hid_keyboard_example_E6),copy, sizeof(copy));
}

