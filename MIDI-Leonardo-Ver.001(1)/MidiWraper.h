#pragma once
#include <MIDIUSB.h>
#include <Arduino.h>

void MidiNoteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = { 0x09, 0x90 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOn);
}

void MidiNoteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = { 0x08, 0x80 | channel, pitch, velocity };
  MidiUSB.sendMIDI(noteOff);
}

void MidiControlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = { 0x0B, 0xB0 | channel, control, value };
  MidiUSB.sendMIDI(event);
}

void MidiPitchBend(byte channel, int value) {
  midiEventPacket_t event = { 0x0E, 0xE0 | channel, value & 0x7F, value >> 7 & 0x7F };
  MidiUSB.sendMIDI(event);
}