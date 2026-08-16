#include <stdint.h>

/*@
    requires ((x) < 0x100000000);
    ensures \result == ((x) ^ 0);
    ensures \result == x;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert x < 0x100000000;
    
    result = x ^ 0;
    
    //@ assert result == x;
    
    return result;
}

int main()
{
    return 0;
}
