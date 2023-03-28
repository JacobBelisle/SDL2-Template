#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "include/Entity.hpp";

Entity::Entity(double x, double y, SDL_Texture *texture)
:_x(x), _y(y), _texture(texture)
{
    _currentFrame.x = 0;
    _currentFrame.y = 0;
}