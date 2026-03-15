//  RC Macro Pad  Jonas März 2026
//  Only for test purpose   


#include "BTkb.h"       
#include "OLED.h"      
#include "display.h

#define JOY_H 35
#define JOY_V 34
#define JOY_BTN 33

#define BTN1 16  // Zurück
#define BTN2 4   // Play/Pause 
#define BTN3 5   // Vorwärts
#define BTN4 17  // Taskmanager
#define BTN5 23  // Win L
#define BTN6 25  // Sleep

BleKeyboard kb("RC Macro", "Jonas", 100);
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

bool btn_states[6] = {0};
bool joy_states[5] = {0};  // up down left right enter

void setup() {
  Serial.begin(115200);
  
  pinMode(JOY_BTN, INPUT_PULLUP);
  pinMode(BTN1, INPUT_PULLUP); pinMode(BTN2, INPUT_PULLUP); 
  pinMode(BTN3, INPUT_PULLUP); pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP); pinMode(BTN6, INPUT_PULLUP);
  
  Wire.begin(21, 22);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED kaputt :(");
  }
  
  boot_screen();
  kb.begin();
}

void loop() {
  if(kb.isConnected()) {
    joystick_stuff();
    button_stuff();
     show_status(true);
  } else {
    show_status(false);
  }
  delay(30);
}

void joystick_stuff() {
  int h = analogRead(JOY_H);
  int v = analogRead(JOY_V);
  
  // Rechts/Links - einfache Zahlen statt fancy map()
    if(h < 1600 && !joy_states[2]) {  // links 
    kb.write(KEY_LEFT_ARROW);
    joy_states[2] = true;
  } else if(h > 2500 && !joy_states[3]) {  // rechts
     kb.write(KEY_RIGHT_ARROW);
      joy_states[3] = true;
  } else if(h > 1600 && h < 2500) {
      joy_states[2] = joy_states[3] = false;
  }
  
  // Hoch Runter
  if(v < 1600 && !joy_states[0]) {
    kb.write(KEY_UP_ARROW);
      joy_states[0] = true;
  } else if(v > 2500 && !joy_states[1]) {
    kb.write(KEY_DOWN_ARROW);
    joy_states[1] = true;
  } else if(v > 1600 && v < 2500) {
    joy_states[0] = joy_states[1] = false;
  }
  
  // Enter wenn gedrückt
  if(!digitalRead(JOY_BTN) && joy_states[4] == false) {
     kb.write(KEY_RETURN);
    joy_states[4] = true;
  } else if(digitalRead(JOY_BTN)) {
    joy_states[4] = false;
  }
}

void button_stuff() {
  if(btn_pressed(BTN1)) kb.write(KEY_MEDIA_PREVIOUS_TRACK);
   if(btn_pressed(BTN2)) kb.write(KEY_MEDIA_PLAY_PAUSE);
  if(btn_pressed(BTN3)) kb.write(KEY_MEDIA_NEXT_TRACK);
  
  if(btn_pressed(BTN4)) {  // Taskmanagr
    kb.press(KEY_LEFT_CTRL);
     kb.press(KEY_LEFT_SHIFT);
     kb.write(KEY_DELETE);
     kb.releaseAll();
  }
  
  if(btn_pressed(BTN5)) {  // Lock
     kb.press(KEY_LEFT_GUI);
     kb.write('l');
    kb.releaseAll();
  }
  
  if(btn_pressed(BTN6)) {  // Sleep
    kb.press(KEY_LEFT_GUI);
    kb.write('x'); delay(200);
    kb.releaseAll();
     kb.write('u'); delay(150);
    kb.write('s');
  }
}

bool btn_pressed(int pin) {
  static bool last[6] = {1,1,1,1,1,1};
  int idx = 0;
   if(pin == BTN1) idx=0;
    else if(pin == BTN2) idx=1;
    else if(pin == BTN3) idx=2;
    else if(pin == BTN4) idx=3;
    else if(pin == BTN5) idx=4;
    else idx=5;
   
  bool now = !digitalRead(pin);
  if(now && !last[idx]) {
    last[idx] = true;
     return true;
  }
  last[idx] = now;
   return false;
}

void show_status(bool connected) {
  oled.clearDisplay();
  
  if(connected) {
    oled.setTextSize(2);
    oled.setCursor(25, 15);
    oled.print("ONLINE");
    oled.setTextSize(1);
    oled.setCursor(10, 45);
    oled.print("Joystick Pfeile OK");
  } else {
     oled.setTextSize(2);
      oled.setCursor(15, 20);
       oled.print("OFFLINE");
        oled.setTextSize(1);
         oled.setCursor(20, 45);
          oled.print("BT verbinden...");
  }
  oled.display();
}

void boot_screen() {
  oled.clearDisplay();
   oled.setTextSize(2);
    oled.setCursor(15, 15);
     oled.print("RC MACRO");
      oled.setTextSize(1);
       oled.setCursor(25, 40);
        oled.print("Jonas - 2026");
          oled.display();
            delay(1800);
}