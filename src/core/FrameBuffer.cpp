#include<include/FrameBuffer.h>

FrameBuffer::FrameBuffer(SDL_Window* window, WindowSpecs specs) : mOwningWindow(window), mWindowSpecs(specs){
    mSurface = SDL_GetWindowSurface(mOwningWindow);
    mPixels = (uint32_t*)mSurface->pixels;


}