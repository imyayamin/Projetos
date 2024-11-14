#pragma once
#include <Arduino.h>

template <typename T>
class ObjectSet {
private:
  T** objs;
  int length;

public:
  ObjectSet()
    : objs(nullptr), length(0) {}

  ~ObjectSet() {
    // Libera a memória dos objetos e o array de ponteiros
    for (int i = 0; i < length; i++) {
      delete objs[i];
    }
    delete[] objs;
  }

  void add(T* obj) {
    T** new_objs = new T*[length + 1];
    for (int i = 0; i < length; i++)
      new_objs[i] = objs[i];
    new_objs[length] = obj;
    delete[] objs;
    objs = new_objs;
    length++;
  }

  void walk(void (*callback)(T*)) {
    for (int i = 0; i < length; i++)
      callback(objs[i]);
  }

  int size() const {
    return length;
  }

  T* get(int index) const {
    return (index >= 0 && index < length) ? objs[index] : nullptr;
  }
};
