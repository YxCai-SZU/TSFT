#include <stdint.h>


uint32_t func(uint32_t x)
{
    uint32_t number;
    uint32_t result;
    uint32_t five_hundreds;
    uint32_t five;

    number = x;
    result = 0;

    five_hundreds = number / 500;
    result = result + five_hundreds * 1000;
    number = number % 500;

    //@ assert (0 <= (number) < 500);
    //@ assert (0 <= (number / 5) <= 100);
    //@ assert (0 <= ((number / 5) * 5) <= 500);

    five = number / 5;
    result = result + five * 5;
    number = number % 5;

    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return result;
}
