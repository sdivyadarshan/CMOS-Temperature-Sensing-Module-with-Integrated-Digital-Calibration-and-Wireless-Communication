# Algorithm and Working Logic

## Three-module sequence

1. **Sensing module:** The ESP32 requests a temperature conversion from the DS18B20 over the One-Wire bus.
2. **Processing and calibration module:** The firmware reads the sensor result and adds the configured software offset.
3. **Wireless communication and display module:** The ESP32 serves an HTML page over Wi-Fi. A mobile browser displays the value.

## Algorithm

```text
START
  |
Initialize Serial Monitor
  |
Initialize DS18B20 sensor
  |
Connect ESP32 to configured Wi-Fi
  |
Print assigned IP address
  |
Start HTTP server on port 80
  |
Wait for browser client
  |
Request temperature conversion
  |
Read temperature from DS18B20
  |
Add calibration offset
  |
Send temperature in HTML response
  |
Close client connection
  |
Repeat
```

## Calibration calculation

The firmware applies an additive digital correction:

`Calibrated temperature = Measured temperature + Offset`

The current source initializes `offset` to `0.0`. To determine an offset, compare the sensor against a suitable reference thermometer under the same conditions:

`Offset = Reference temperature - Sensor temperature`

Example: if the reference is 28.00 °C and the sensor reads 27.56 °C, the calculated offset is +0.44 °C. This is an example calculation, not a calibration certificate or proof of accuracy.

## Update behaviour

The HTML page includes a five-second browser refresh. Each new HTTP request causes the ESP32 to request a new sensor conversion and send a new reading. This is periodic, near-real-time monitoring rather than continuous streaming.
