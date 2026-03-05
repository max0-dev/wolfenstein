#pragma once
#include<SDL3/SDL.h>
#include<include/WindowSpecs.h>
#include<include/FrameBuffer.h>

class Window{
private:
    SDL_Window* mWindow;
    SDL_Surface* mSurface;
    bool mRunning;
    WindowSpecs mWindowSpecs;
    FrameBuffer* mFBO;

    void Run();
public:
    Window(const char* title, int width, int height);
    ~Window();
};