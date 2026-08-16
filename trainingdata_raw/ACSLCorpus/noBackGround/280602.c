#include <stdint.h>

/*@
    requires (1 <= (s) <= 100);
    ensures \result == ((s) * (s));
    assigns \nothing;
*/
uint64_t func(uint64_t s)
{
    // Variable declarations at top of scope
    uint64_t res;
    
    //@ assert (1 <= (s) <= 100);
    
    //@ assert ((s) * (s)) <= 10000;
    //@ assert ((s) * (s)) >= 1;
    
    res = s * s;
    
    //@ assert res == ((s) * (s));
    
    return res;
}

int main(void)
{
    return 0;
}
