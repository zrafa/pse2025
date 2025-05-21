#pragma once

#include <cstdint>

class driver
{
public:

    driver() = default;

    constexpr void set_minimum(std::uint8_t x)  { minimum = x; }
    constexpr void set_maximum(std::uint8_t x)  { maximum = x; }
    constexpr void set_tiers(std::uint8_t t)    { tiers = t;   }
    std::int8_t pitch(std::uint8_t d) const;

private:

    std::uint8_t minimum { 0xff };
    std::uint8_t maximum { 0xff };
    std::uint8_t tiers { 8 };
};