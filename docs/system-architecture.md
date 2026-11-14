# System Architecture

## Overview

The prototype is organized into three functional modules connected in sequence.

### Module 1 — Temperature Sensing

**Hardware:** DS18B20 waterproof digital temperature sensor and 4.7 kΩ pull-up resistor.

The DS18B20 measures temperature and communicates its digital result to the ESP32 using the One-Wire protocol. The pull-up resistor is connected between the data line and 3.3 V.

### Module 2 — Processing and Digital Calibration

**Hardware:** ESP32 DevKit.

The ESP32 initializes the sensor, requests a temperature conversion, reads the result and applies a configurable software offset. The same controller manages the Wi-Fi connection and HTTP server.

### Module 3 — Wireless Communication and Display

**Hardware/software:** ESP32 Wi-Fi interface, HTTP server and a mobile browser.

The ESP32 joins the configured Wi-Fi network and prints its DHCP-assigned IP address to Serial Monitor. A phone connected to the same network opens that IP address in a browser. The server returns an HTML page containing the calibrated temperature.

## Data path

```text
DS18B20
   | One-Wire digital temperature data
   v
ESP32 — read, process and apply calibration offset
   | Wi-Fi / HTTP
   v
Mobile browser — display temperature
```

## Power path

In the demonstrated setup, the ESP32 is powered through its USB connection. The sensor is supplied from the ESP32 3.3 V pin.

## Scope and terminology

The project title refers to an ultra-low-power CMOS temperature-sensing concept. The current demonstrator uses a commercial DS18B20 sensor and an ESP32 DevKit; it does not contain a custom CMOS sensor IC. No measured current profile or quantified ultra-low-power result is currently available. Such claims require separate power measurements and, if required by the project specification, CMOS circuit-level design and characterization.
