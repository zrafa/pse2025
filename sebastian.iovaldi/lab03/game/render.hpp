#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct state_t;

class render
{
public:
    render();
    ~render();

    bool is_open() const;
    void update(const state_t& state) const;

private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    static const int TILE_SIZE { 32 }; 
};