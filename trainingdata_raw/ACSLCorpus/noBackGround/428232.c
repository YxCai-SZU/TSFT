#include <stdint.h>

/*@
    requires 0 <= x <= 8;
    requires 0 <= y <= 8;
    ensures \result == x * y;
    ensures \result <= 64;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans;

    //@ assert (0 <= (x) <= 8 && 0 <= (y) <= 8);
    //@ assert 0 <= x * y <= 64;
    ans = x * y;
    //@ assert ans == x * y;
    //@ assert ans <= 64;
    return ans;
}

int main()
{
    return 0;
}
