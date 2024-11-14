#include "./ButtonSet.h";
#include "./MidiWraper.h";

int notes[] = { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71 };
int firstPin = 2;
int lastPin = 13;

void callbackButton(int pin, int status) {
  int note = notes[pin - firstPin];
  int speed = 64;
  String log = "PIN: " + String(pin) + "; STATUS" + (status == BUTTON_STATE::DOWN ? "down" : "up") + "; NOTE: " + String(note);
  Serial.println(log);

  if (status == BUTTON_STATE::DOWN) {
    MidiNoteOn(0, note, speed);
    MidiUSB.flush();
    return;
  }

  MidiNoteOff(0, note, speed);
  MidiUSB.flush();
}

ButtonSet bts = ButtonSet();

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  bts.add(A0, callbackButton);
  for (int i = firstPin; i <= lastPin; i++)
    bts.add(i, callbackButton);
}

void loop() {
  bts.check();
}


// ==========================================================================================================================================================================================================
// // Maneira 03 - Set de Botões
//
// #include "./ButtonSet.h";
//
// void callbackDummy(int pin, int status) {
//   Serial.print("PIN: ");
//   Serial.print(pin);
//   Serial.print(" STATUS: ");
//   Serial.println(status == BUTTON_STATE::DOWN ? "down" : "up");
// }
//
// ButtonSet bts = ButtonSet();
//
// void setup() {
//   Serial.begin(9600);
//   while (!Serial) {}
//   bts.add(A0, callbackDummy);
//   bts.add(2, callbackDummy);
//   bts.add(3, callbackDummy);
//   bts.add(4, callbackDummy);
//   bts.add(5, callbackDummy);
//   bts.add(6, callbackDummy);
//   bts.add(7, callbackDummy);
//   bts.add(8, callbackDummy);
//   bts.add(9, callbackDummy);
//   bts.add(10, callbackDummy);
//   bts.add(11, callbackDummy);
//   bts.add(12, callbackDummy);
//   bts.add(13, callbackDummy);
// }
//
// void loop() {
//   bts.check();
// }
//
// ==========================================================================================================================================================================================================
// // Maneira 02 - Set de Objetos
//
// #include <Arduino.h>
// #include "Button.h"
// #include "ObjectSet.h"  // Certifique-se de que o arquivo ObjectSet.h esteja incluído
//
// ObjectSet<Button> buttonSet;
//
// void callbackDummy(int pin, int status) {
//   Serial.print("PIN: ");
//   Serial.print(pin);
//   Serial.print(" STATUS: ");
//   Serial.println(status == BUTTON_STATE::DOWN ? "down" : "up");
// }
//
// void buttonCheckCallback(Button* btn) {
//   btn->check();
// }
//
// void setup() {
//   buttonSet.add(new Button(A0, callbackDummy));
//   buttonSet.add(new Button(2, callbackDummy));
//   buttonSet.add(new Button(3, callbackDummy));
//   buttonSet.add(new Button(4, callbackDummy));
//   buttonSet.add(new Button(5, callbackDummy));
//   buttonSet.add(new Button(6, callbackDummy));
//   buttonSet.add(new Button(7, callbackDummy));
//   buttonSet.add(new Button(8, callbackDummy));
//   buttonSet.add(new Button(9, callbackDummy));
//   buttonSet.add(new Button(10, callbackDummy));
//   buttonSet.add(new Button(11, callbackDummy));
//   buttonSet.add(new Button(13, callbackDummy));
// }
//
// void loop() {
//   buttonSet.walk(buttonCheckCallback);
// }
//
// ==========================================================================================================================================================================================================
// // Maneira 01 - "Manual"
//
// #include "./Button.h";
//
// void callbackDummy(int pin, int status) {
//   Serial.print("PIN: ");
//   Serial.print(pin);
//   Serial.print(" STATUS: ");
//   Serial.println(status == BUTTON_STATE::DOWN ? "down" : "up");
// }
//
// int basePin = 2;
//
// Button bts[] = {
//   Button(A0, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy),
//   Button(basePin++, callbackDummy)
// };
//
// int btsLength = sizeof(bts) / sizeof(bts[0]);
//
// void setup() {
//   Serial.begin(9600);
//   while (!Serial) {}
// }
//
// void loop() {
//   for (int i = 0; i < btsLength; i++) {
//     bts[i].check();
//   }
// }
//
// ==========================================================================================================================================================================================================