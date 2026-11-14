# Design Decisions

## 1. ESP32 DevKit as controller

The ESP32 was selected because it combines a microcontroller platform with integrated Wi-Fi. This allows sensor acquisition, offset calculation and local wireless display without a separate Wi-Fi module.

## 2. DS18B20 digital temperature sensor

The DS18B20 was selected for direct digital temperature output over a One-Wire interface. This avoids adding a separate external analog-to-digital converter for this sensor interface.

## 3. GPIO 4 for the One-Wire data bus

The firmware assigns GPIO 4 to the sensor data line using `ONE_WIRE_BUS`. The physical wiring and firmware definition must remain consistent.

## 4. 4.7 kΩ pull-up resistor

A pull-up resistor is used between the One-Wire data line and 3.3 V to provide the required bus pull-up.

## 5. Software offset calibration

A simple additive offset was chosen because it is easy to understand, implement and demonstrate. The offset must be determined by comparison with a reference thermometer; the default value in the submitted sketch is 0.0 °C.

## 6. Local HTTP server

The ESP32 hosts a basic HTTP server on port 80. This avoids requiring a separate cloud service or dedicated mobile application. The phone must be on the same Wi-Fi network as the ESP32.

## 7. Five-second browser refresh

A five-second HTML refresh interval was used to provide periodic readings without implementing a more complex streaming protocol.

## Known limitations and future improvements

- The Wi-Fi connection loop waits indefinitely if the configured network is unavailable.
- The firmware does not currently validate disconnected-sensor error values.
- The browser refresh is periodic and not push-based streaming.
- The prototype has not been characterized for power consumption.
- A custom CMOS temperature sensor has not been designed or fabricated.
- Future revisions could add connection timeout handling, sensor fault reporting, measured power modes and a more responsive dashboard.
