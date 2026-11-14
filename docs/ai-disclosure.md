# Contribution and AI Disclosure

## Project owner contributions

The project owner reports having:
- Selected and assembled the ESP32 and DS18B20 hardware prototype.
- Connected the sensor, pull-up resistor and ESP32 wiring.
- Installed and configured the Arduino development environment and ESP32 board support.
- Uploaded the firmware to the ESP32.
- Configured Wi-Fi credentials on the device.
- Verified that the ESP32 connected to Wi-Fi and printed an IP address.
- Opened the ESP32-hosted page from a mobile browser on the same network.
- Observed a displayed temperature reading of 27.56 °C during a test session.

## AI-assisted work

AI assistance was used for:
- Explaining the One-Wire sensor interface and ESP32 Wi-Fi web-server workflow.
- Helping structure and comment the Arduino sketch.
- Explaining the additive software calibration approach.
- Preparing repository documentation, architecture descriptions, testing templates and the block diagram.

## Verification and responsibility

The physical assembly and test observations are attributed to the project owner as reported. AI-generated explanations and documentation should be reviewed by the project owner before academic submission. The repository does not claim that AI independently assembled, measured, calibrated or validated the hardware.

The current prototype should be described accurately: it demonstrates a DS18B20/ESP32 temperature-monitoring system with software offset correction and Wi-Fi display. It does not yet demonstrate a custom CMOS sensor or experimentally verified ultra-low-power operation.
