# HID Report Macros

The C header file "HID_Report.h" provides preprocessor macros which allows to write HID Reports a notation which looks similar to the notation used in HID Report Standard [1].
The usage tables defined in [2] are partly defined in the header file.

## Example

The macros allows to write the keybord example shown in section E.6 of [1] as:

``` c
static const uint8_t hid_example_E6[] = {
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
```

## References 

[1] Device Class Definition for Human Interface Devices (HID) (6/27/01) Version 1.11 (https://usb.org/document-library/device-class-definition-hid-111)

[2] HID Usage Tables (10/28/2004) Version 1.12 (https://usb.org/document-library/hid-usage-tables-112)
