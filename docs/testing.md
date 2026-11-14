# Testing Checklist and Observations

## Test setup

- ESP32 DevKit powered through USB.
- DS18B20 waterproof temperature sensor connected to GPIO 4, 3V3 and GND.
- 4.7 kΩ pull-up resistor between GPIO 4 and 3V3.
- ESP32 connected to a Wi-Fi network.
- Mobile phone connected to the same network.

## Testing checklist

| Test | Procedure | Expected result | Status / observation |
|---|---|---|---|
| Board programming | Upload the sketch from Arduino IDE | Upload completes | Reported successful by project owner |
| Sensor initialization | Start the board with sensor connected | Sensor library initializes | Demonstrated by successful temperature display |
| Wi-Fi connection | Enter valid 2.4 GHz network credentials | Serial Monitor reports Wi-Fi connected | Passed; IP address was printed |
| IP assignment | Read Serial Monitor | ESP32 prints a local IP address | Observed: 10.20.220.204 during one session |
| Browser access | Open the IP address on a phone on the same Wi-Fi | Temperature page loads | Reported successful |
| Temperature reading | Observe the displayed value | Numeric temperature in °C | Observed: 27.56 °C during one session |
| Periodic update | Leave browser page open | Page refreshes every five seconds | Implemented by HTML meta refresh |
| Calibration | Compare against a reference and configure offset | Corrected value shifts by configured offset | Offset code present; independent calibration accuracy not yet verified |

## Recorded demonstration observations

- IP address during one successful session: `10.20.220.204`.
- Temperature displayed during one session: `27.56 °C`.

These are historical observations from the project owner's test session. DHCP addresses can change, and temperature depends on the environment. They are not guaranteed fixed outputs.

## Additional validation recommended

- Compare readings with a trusted reference thermometer at several temperatures.
- Repeat readings after thermal stabilization.
- Test behaviour with the sensor disconnected.
- Test behaviour when Wi-Fi is unavailable or credentials are incorrect.
- Measure supply voltage and current in active and idle operation before making low-power performance claims.
