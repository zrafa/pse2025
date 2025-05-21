#include <SDL3/SDL_events.h>

void process_key(uint8_t* keys, int bit, bool pressed)
{
    *keys = pressed ? *keys | (1 << bit) : *keys & ~(1 << bit); 
}

bool input_update(uint8_t* keys)
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.window.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
            return false;
    
        if(event.type==SDL_EVENT_KEY_DOWN | event.type==SDL_EVENT_KEY_UP)
        {
            switch (event.key.key)
            {
                case SDLK_Q: process_key(keys, 0, event.key.down); break;
                case SDLK_W: process_key(keys, 1, event.key.down); break;
                case SDLK_E: process_key(keys, 2, event.key.down); break;
                case SDLK_R: process_key(keys, 3, event.key.down); break;
                case SDLK_T: process_key(keys, 4, event.key.down); break;
                case SDLK_Y: process_key(keys, 5, event.key.down); break;
                case SDLK_U: process_key(keys, 6, event.key.down); break;
            }
        }
    }
    return true;
}

