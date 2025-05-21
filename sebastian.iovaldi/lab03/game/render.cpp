#include <SDL3/SDL_render.h>
#include <SDL3/SDL_main.h>
#include "state.hpp"
#include "render.hpp"

render::render()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer("Game", 384, 256, 0, &window, &renderer);
    SDL_SetRenderVSync(renderer, 1);
}

render::~render()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void render::update(const state_t& state) const
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect box = {state.player.x, state.player.y, TILE_SIZE, TILE_SIZE};
    SDL_FRect fbox;
    SDL_RectToFRect(&box, &fbox); 
    SDL_RenderFillRect(renderer, &fbox);
    SDL_RenderPresent(renderer);
}

bool render::is_open() const 
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
        if(event.window.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
            return false;
    return true;
}