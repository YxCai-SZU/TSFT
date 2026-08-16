#include <stdint.h>

/*@
    requires (0 <= (x) && (x) < 10);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t res;
    
    //@ assert 0 <= x && x < 10;
    
    res = x * x;
    
    //@ assert res == ((x) * (x));
    
    return res;
}

int main()
{
    return 0;
}
