#pragma once

#include <cstdint>
#include <thread>
#include <atomic>

class joypad
{

public:

    joypad();
    ~joypad();

    bool pulsed();
    std::uint8_t sensor() const;

private:

    std::uint8_t recv() const;
    std::atomic<std::uint8_t> code_m { 0 };
    const int port;
    std::atomic<bool> running { true };
    std::thread process;
};