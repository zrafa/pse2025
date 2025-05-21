#pragma once

#include <SDL3/SDL_rect.h>
#include <cstdint>

struct player_t
{
    int x { 0 };
    int y { 0 };
};

struct state_t
{
    int scene { 0 };
    player_t player{};
    std::uint8_t tier = 0;
};