#pragma once
#include <Arduino.h>
#include "./Button.h"

class ButtonSet {
private:
  struct Pair {
    Button *button;
    Pair *next;
  };

  Pair *head;
  Pair *current;

public:
  ButtonSet()
    : head(nullptr), current(nullptr) {}

  void add(int pin, void (*_callback)(int, int)) {
    Pair *new_pair = new Pair;
    new_pair->button = new Button(pin, _callback);
    new_pair->next = nullptr;
    if (head == nullptr) {
      head = new_pair;
      current = head;
      return;
    }
    current->next = new_pair;
    current = new_pair;
  }

  void check() {
    Pair *p = head;
    while (p != nullptr) {
      p->button->check();
      p = p->next;
    }
  }
};