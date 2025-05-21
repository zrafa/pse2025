#include <iostream>
#include "joypad.hpp"
#include "render.hpp"
#include "driver.hpp"
#include "state.hpp"

//#include <SDL3/SDL_timer.h>

int main(int argc, char** argv)
{
    joypad joypad0;
    render render0;
    driver driver0;
    state_t state;

    std::cout << "Press A to start calibration...\n"; 
    while(not joypad0.pulsed())
        ;
    
    std::cout << "Press A at minimum distance...\n";
    while(not joypad0.pulsed())
        ;
    driver0.set_minimum(joypad0.sensor());
    
    std::cout << "Press A at maximun distance...\n";
    while(not joypad0.pulsed())
        ;
    driver0.set_maximum(joypad0.sensor());

    std::cout << "Starting Game...\n";

    while(render0.is_open())
    {
        render0.update(state);
        if(joypad0.pulsed())
            std::cout << "Pulsed!... Tier: \n";// << (int)driver0.pitch(joypad0.sensor()) << "\n";
    
        int target = (7-driver0.pitch(joypad0.sensor()))*32;
        if(target > state.player.y)
            state.player.y+=4;
        else if(target < state.player.y)
            state.player.y-=4;
    }

    return 0;
}