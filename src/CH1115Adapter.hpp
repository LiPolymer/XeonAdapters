#ifndef CH1115ADAPTERS_H
#define CH1115ADAPTERS_H

#include "ER_OLEDM1_CH1115.hpp"
#include "XeonEngine.h"

class CH1115Adapter : public IAdapter {
public:
    explicit CH1115Adapter(ERMCH1115& display) : IAdapter(display) {}

    void postRender() override {
        static_cast<ERMCH1115&>(this->gfx).OLEDupdate();
    }
    bool isFirst = true;
    void preRender() override {
        this->gfx.fillScreen(0);
    }
};

#endif