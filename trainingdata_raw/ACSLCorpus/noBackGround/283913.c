#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
uint32_t func(uint32_t r)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;

    ans = 3 * r * r;
    return ans;
}

int main(void)
{
    return 0;
}
