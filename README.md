# Temperature-Humidity-Control-System
# Project Overview
This project is a complete environment monitoring and control system built using an Arduino Uno and a DHT11 sensor.
It measures real-time temperature and humidity, displays them on an LCD, and automatically controls a fan (via relay) and an alarm buzzer based on user-defined setpoints.
The entire system is designed and tested in Proteus.

# Key Features
 Real-time temperature & humidity monitoring
 LCD display (16×2) output
 Adjustable temperature setpoint (Potentiometer RV2)
 Adjustable humidity setpoint (Potentiometer RV3)
 Automatic fan control using relay
 Buzzer alarm for critical conditions
 Fully simulated in Proteus

# Working Principle
1. The DHT11 sensor continuously reads environmental data.
2. The Arduino Uno processes this data.
3. Two potentiometers allow real-time adjustment of:
4. Temperature setpoint
5. Humidity setpoint
6. The LCD displays:
7. Current Temperature (T)
8. Current Humidity (H)
9. Temperature Setpoint (TS)
10. Humidity Setpoint (HS)
11. If: Temperature > Setpoint → Relay ON → Fan ON
12. If: Temperature or Humidity exceeds critical limit → Buzzer ON
13. Otherwise: System remains in normal monitoring mode

# Circuit Diagram
<img width="1235" height="863" alt="Circuit" src="https://github.com/user-attachments/assets/40c5fb5c-ee1d-492f-99e1-f8c0fdb1ede8" />

# Simulation Preview 
<img width="1211" height="849" alt="Simulation" src="https://github.com/user-attachments/assets/43aa0fee-a70a-4678-a294-a7c91da77299" />


# Code Logic 
1. Reads temperature & humidity using DHT11
2. Reads analog values from potentiometers
3. Converts them into setpoints using map()
4. Displays all values on LCD
5. Compares real values with setpoints
6. Controls: Relay (fan) & Buzzer (alarm)

# Applications
1. Smart room climate control
2. Greenhouse automation
3. Server room monitoring
4. Industrial environment control
5. Home automation systems

## 🛠️ How to Run

1. Open the project in Proteus
2. Load the HEX file into Arduino
3. Run simulation
4. Adjust potentiometers to change setpoints
   
# Conclusion
This project demonstrates a complete embedded control system combining sensing, processing, display, and actuation. With real-time adjustable setpoints and safety alarms, it closely resembles practical industrial temperature control systems.
