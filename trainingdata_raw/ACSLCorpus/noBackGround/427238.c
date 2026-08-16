#include <stdint.h>

/*@
    requires ((x) > 0) && ((y) > 0);
    requires ((x) <= 0xFFFFFFFF) && ((y) <= 0xFFFFFFFF);
    ensures \result == ((x) | (y));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert ((x) & (y)) == ((y) & (x));
    return x | y;
}

int main()
{
    return 0;
}
