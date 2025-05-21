#include <SDL3/SDL_render.h>

#define KEY_GAP 12
#define KEY_WIDTH 20
#define KEY_HEIGHT 50

SDL_Window* window;
SDL_Renderer* render;
SDL_FRect rect_keys[7];

void render_init()
{
    for(int i=0; i<7; i++)
        rect_keys[i] = (SDL_FRect){KEY_GAP+(KEY_GAP+KEY_WIDTH)*i, KEY_GAP, KEY_WIDTH, KEY_HEIGHT};

    SDL_CreateWindowAndRenderer("Piano", 240, 160, 0, &window, &render);
}

void render_update(uint8_t keys)
{
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderFillRects(render, rect_keys, 7);

    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);

    for(int i=0; i<7; i++)
        if((keys>>i) & 1)
            SDL_RenderFillRect(render, &rect_keys[i]);

    SDL_RenderPresent(render);
}

void render_close()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}