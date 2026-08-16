#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result == (((a) + (b)) * (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert a + b <= 200;
    //@ assert (a + b) * c <= 20000;

    ans = (a + b) * c;
    return ans;
}

int main()
{
    return 0;
}
