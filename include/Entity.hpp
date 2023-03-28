#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
private:
    double _x, _y;
    SDL_Rect _currentFrame;
    SDL_Texture* _texture;

public:
    Entity(double x, double y, SDL_Texture* texture);
};