#ifndef SH1107ADAPTER_HPP
#define SH1107ADAPTER_HPP
#include "Adafruit_SH110X.h"
#include "XeonEngine.h"
class SH1107Adapter : public IAdapter {
public:
    explicit SH1107Adapter(Adafruit_SH1107& gfx) : IAdapter(gfx) {}
    void postRender() override {
        static_cast<Adafruit_SH1107&>(this->gfx).display();
    }
    void preRender() override {
        static_cast<Adafruit_SH1107&>(this->gfx).clearDisplay();
    }

};

#endif