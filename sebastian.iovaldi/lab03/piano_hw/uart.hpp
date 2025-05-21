#pragma once

#include <cstdint>

struct uart 
{
    uint8_t status_control_a;
    uint8_t status_control_b;
    uint8_t status_control_c;
    uint8_t reserved;
    uint8_t baud_rate_low;
    uint8_t baud_rate_high;
    uint8_t data_es;    

    void rtx(bool on);
};