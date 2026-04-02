# RC Macro Controller

## Description

This project is a custom macro controller with a joystick, based on an ESP32.
It is designed as a mix between a macro pad and an RC controller. The current version focuses on the hardware (PCB, inputs, and display), while wireless functionality is planned for a future version.

You can use the controller by connecting it via USB. The buttons and joystick can be programmed to send inputs, for example as a macro pad or for testing control inputs. In the future, it is intended to control an RC car wirelessly.

I made this project to learn PCB design and gain more experience with microcontrollers. I also wanted to build something more interactive than a basic macro pad, which is why I added a joystick and an OLED display.

---

## Pictures

### 3D Model
<img width="1969" height="1088" alt="Macro3Dview" src="https://github.com/user-attachments/assets/1a1f6ba6-d6d5-4388-bdfc-95301f5d8249" />


### PCB
<img width="1817" height="846" alt="PCB" src="https://github.com/user-attachments/assets/6a353b41-9ec7-4b2e-a59e-847e765d91da" />

### Schematic
<img width="1590" height="1090" alt="MacroSchematic" src="https://github.com/user-attachments/assets/92d4080a-77fb-4b86-af10-0800f0c7437b" />

## Case
<img width="479" height="343" alt="joystick case" src="https://github.com/user-attachments/assets/8d304416-fe95-4f21-8f73-929856b8bb2b" />


---

## Bill of Materials 

| Item                             | Description                         | Source     | Link                                                 | Quantity | Unit Price (€) | Total (€) |
| -------------------------------- | ----------------------------------- | ---------- | ---------------------------------------------------- | -------- | -------------- | --------- |
| Tactile Push Button (6x6mm)      | Small tactile buttons for PCB input | AliExpress | https://de.aliexpress.com/item/1005006998132061.html | 6        | 2.79 (per 10)  | 2.79      |
| Thumb Joystick Module            | 2-axis analog joystick with button  | AliExpress | https://de.aliexpress.com/item/1005009942094855.html | 1        | 1.59           | 1.59      |
| OLED Display 0.91" (SSD1306 I2C) | 128x32 OLED display                 | AliExpress | https://de.aliexpress.com/item/1005006365884520.html | 1        | 1.65           | 1.65      |
| Custom PCB                       | Self-designed PCB                   | JLCPCB     | —                                                    | 1        | —              | —         |
| ESP32 Dev Board                  | Microcontroller (already owned)     | —          | —                                                    | 1        | —              | —         |
| SK6812 MINI-E LEDs               | Addressable RGB LEDs                | AliExpress | https://de.aliexpress.com/item/1005008308801366.html | 6        | 0.90 (per 20)  | 1.77      |

---

## Total Cost

Approx. 23€ (excluding ESP32 and PCB)

---

## Notes

This is my first PCB project, so it’s probably not perfect.
I learned how to design schematics and PCBs in KiCad, and how to work with the ESP32 and I2C devices.

Feedback and suggestions for improvement are appreciated.
