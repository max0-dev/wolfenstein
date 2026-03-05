#include<include/Window.h>
#include<spdlog/spdlog.h>
Window::Window(const char* title, int width, int height) : mWindowSpecs({title, width, height}){
    SDL_Init(SDL_INIT_VIDEO);

    mWindow = SDL_CreateWindow(
        title,
        width,
        height,
        0
    );

    if(mWindow == nullptr){
        spdlog::error("Couldn't create a window");
        return;
    }

    mFBO = new FrameBuffer(mWindow, mWindowSpecs);

    Run();
}

void Window::Run(){
    mRunning = true;

    while (mRunning)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT){
                mRunning = false;
            }
        }
        
        mFBO->Lock();
        mFBO->Clear();

        // Call OnRender func on layer stack

        mFBO->Unlock();
        SDL_UpdateWindowSurface(mWindow);
    }
}

Window::~Window(){
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    delete mFBO;
}