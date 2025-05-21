#include "driver.hpp"

std::int8_t driver::pitch(std::uint8_t d) const 
{
    std::uint8_t delta = (maximum - minimum) / tiers;
    std::int8_t tier = (d - minimum) / delta;

    if(tier < 0)
        tier = 0;
    else if (tier >= tiers)
            tier = tiers - 1;

    return tier;
}