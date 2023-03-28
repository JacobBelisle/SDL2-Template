#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height)
    : _window(nullptr), _renderer(nullptr)
{
    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (_window == nullptr)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(_renderer, filePath);

    if (texture == nullptr)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(_window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(_renderer);
}

void RenderWindow::render(SDL_Texture *texture)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Rect dst;
    dst.x = 400;
    dst.y = 200;
    dst.w = 32 * 4;
    dst.h = 32 * 4;

    SDL_RenderCopy(_renderer, texture, &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(_renderer);
}