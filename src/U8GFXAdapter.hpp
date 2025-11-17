#ifndef U8GFXADAPTER_HPP
#define U8GFXADAPTER_HPP
#include "U8GFX.hpp"
#include "XeonEngine.h"

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

#endif