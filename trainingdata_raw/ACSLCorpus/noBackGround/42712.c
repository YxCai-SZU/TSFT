#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        1 <= (d) <= 100);
    ensures \result == ((c) == 0 ? (a) + (b) + 1 : (a) + (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t ans;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (c) <= 100 &&         1 <= (d) <= 100);

    if (c == 0)
    {
        ans = a + b + 1;
        //@ assert ans == a + b + 1;
    }
    else
    {
        ans = a + b;
        //@ assert ans == a + b;
    }

    //@ assert ans == ((c) == 0 ? (a) + (b) + 1 : (a) + (b));
    return ans;
}
