#pragma once

#include <Def/Def.hpp>
#include <Hardware/ExtendedInputOutput/ExtendedInputOutput.hpp>

template <uint8_t N>
class LEDs {
  public:
    LEDs(const PinList<N> &ledPins) : ledPins(ledPins) {}

    void begin() const {
        for (const pin_t &pin : ledPins)
            ExtIO::pinMode(pin, OUTPUT);
    }

    void displayRange(uint8_t startOn, uint8_t startOff) const {
        for (uint8_t pin = 0; pin < startOn; pin++)
            ExtIO::digitalWrite(ledPins[pin], LOW);
        for (uint8_t pin = startOn; pin < startOff; pin++)
            ExtIO::digitalWrite(ledPins[pin], HIGH);
        for (uint8_t pin = startOff; pin < N; pin++)
            ExtIO::digitalWrite(ledPins[pin], LOW);
    }

    void displayDot(uint8_t led) const { displayRange(led, led + 1); }

    void clear() const {
        for (uint8_t pin = 0; pin < N; pin++)
            ExtIO::digitalWrite(ledPins[pin], LOW);
    }

  private:
    const PinList<N> ledPins;
};