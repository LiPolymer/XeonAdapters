#ifndef SSD1306ADAPTER_HPP
#define SSD1306ADAPTER_HPP
#include "Adafruit_SSD1306.h"
#include "XeonEngine.h"

class SSD1306Adapter : public IAdapter {
public:
    explicit SSD1306Adapter(Adafruit_SSD1306& display) : IAdapter(display) {}

    void postRender() override {
        static_cast<Adafruit_SSD1306&>(this->gfx).display();
    }
    void preRender() override {
        static_cast<Adafruit_SSD1306&>(this->gfx).clearDisplay();
    }
};

#endif