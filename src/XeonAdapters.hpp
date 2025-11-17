//
// Created by LithiumFish on 2025/9/29.
//

#ifndef XEONADAPTERS_H
#define XEONADAPTERS_H
#include <Adafruit_SSD1306.h>
#include <Adafruit_SSD1327.h>
#include <JDI_MIP_Display.h>

#include "XeonEngine.h"
#include "U8GFX.hpp"

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

class SSD1327Adapter: public IAdapter {
public:
    explicit SSD1327Adapter(Adafruit_SSD1327& display): IAdapter(display) {}
    void postRender() override {
        static_cast<Adafruit_SSD1327&>(this->gfx).display();
    }
    void preRender() override {
        static_cast<Adafruit_SSD1327&>(this->gfx).clearDisplay();
    }
};

class JdiMipAdapter: public IAdapter {
public:
    explicit JdiMipAdapter(JDI_MIP_Display& display): IAdapter(display) {}
    uint8_t background = 0;
    void postRender() override {
        static_cast<JDI_MIP_Display&>(this->gfx).refresh();
    }
    void preRender() override {
        this->gfx.fillScreen(background);
    }
};

class U8GFXAdapter: public IAdapter {
public:
    explicit U8GFXAdapter(U8GFX& g8): IAdapter(g8) {}
    void postRender() override {
        static_cast<U8GFX&>(this->gfx).display();
    }
    void preRender() override {
        static_cast<U8GFX&>(this->gfx).clear();
    }
};
#endif //XEONADAPTERS_H