# Wiring and Pin Connections

## DS18B20 to ESP32

| DS18B20 connection | ESP32 connection |
|---|---|
| VCC (commonly red) | 3V3 |
| GND (commonly black) | GND |
| DATA (commonly yellow) | GPIO 4 |

Wire colours may differ between manufacturers. Confirm the sensor's actual leadout before connecting power.

## Pull-up resistor

Connect one end of the **4.7 kΩ resistor** to the DATA line (GPIO 4) and the other end to **3V3**.

```text
ESP32 3V3 ─────┬──────── DS18B20 VCC
               │
             [4.7 kΩ]
               │
ESP32 GPIO 4 ──┴──────── DS18B20 DATA

ESP32 GND ────────────── DS18B20 GND
```

## Power and programming

Connect the ESP32 DevKit to a computer or suitable USB power source using its USB cable. The USB connection supplies power and is also used to upload firmware and view Serial Monitor output.

## Firmware pin setting

The sketch defines the One-Wire bus on GPIO 4:

```cpp
#define ONE_WIRE_BUS 4
```

Do not connect the sensor DATA wire to a different GPIO unless this definition is changed to match.
