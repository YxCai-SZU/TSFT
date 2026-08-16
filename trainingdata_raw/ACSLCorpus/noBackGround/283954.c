#include <stdint.h>

/*@
    requires x <= 5 && y <= 10;
    ensures \result <= 50;
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert ((x) <= 5 && (y) <= 10);
    //@ assert 0 <= x && x <= 5 && 0 <= y && y <= 10;
    //@ assert x * y <= 50;

    result = x * y;
    return result;
}

int main()
{
    return 0;
}
