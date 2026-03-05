#pragma once

#include<SDL3/SDL.h>
#include<include/WindowSpecs.h>

class FrameBuffer{
private:
    SDL_Window* mOwningWindow;
    SDL_Surface* mSurface;
    uint32_t* mPixels;
    WindowSpecs mWindowSpecs;
public:
    FrameBuffer(SDL_Window* window, WindowSpecs specs);
    void Lock(){
        SDL_LockSurface(mSurface);
    }
    void Unlock(){
        SDL_UnlockSurface(mSurface);
    }
    void Clear(){
        memset(mPixels, 0, sizeof(uint32_t) * mWindowSpecs.width * mWindowSpecs.height);
    }
};