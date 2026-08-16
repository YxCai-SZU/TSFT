#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
uint32_t func(uint32_t r)
{
    // Variable declarations at top of scope
    uint32_t res;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    res = 3 * r * r;
    
    //@ assert res == (3 * (r) * (r));
    return res;
}

int main()
{
    return 0;
}
