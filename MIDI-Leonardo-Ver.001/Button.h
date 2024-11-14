#pragma once
#include <Arduino.h>

enum BUTTON_STATE {
  DOWN = 0,
  UP = 1
};

class Button {
private:
  int pin;
  int state;
  void (*callback)(int, int);

public:
  Button(int _pin, void (*_callback)(int, int)) {
    pin = _pin;
    state = 0;
    callback = _callback;
  }

  void check() {
    int currstate = digitalRead(pin);
    if (state == currstate)
      return;
    state = currstate;
    if (state == HIGH)
      return callback(pin, BUTTON_STATE::DOWN);
    if (state == LOW)
      return callback(pin, BUTTON_STATE::UP);
  };

  int getPin() {
    return pin;
  }
};