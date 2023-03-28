#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
private:
    SDL_Window *_window;
    SDL_Renderer* _renderer;
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* filePath);
    void cleanUp();
    void clear();
    void render(SDL_Texture* texture);
    void display();
};