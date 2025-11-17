#ifndef JDIMIPADAPTER_HPP
#define JDIMIPADAPTER_HPP
#include "JDI_MIP_Display.h"

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

#endif