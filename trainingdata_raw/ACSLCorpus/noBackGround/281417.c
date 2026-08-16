#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    uint64_t temp_x;
    uint64_t five_hundreds;
    uint64_t five;

    ans = 0;
    temp_x = x;
    five_hundreds = x / 500;
    temp_x = temp_x - five_hundreds * 500;
    five = temp_x / 5;
    ans = five_hundreds * 1000 + five * 5;

    //@ assert five_hundreds == x / 500;
    //@ assert temp_x == x - five_hundreds * 500;
    //@ assert five == temp_x / 5;
    //@ assert ans == five_hundreds * 1000 + five * 5;
    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return ans;
}
