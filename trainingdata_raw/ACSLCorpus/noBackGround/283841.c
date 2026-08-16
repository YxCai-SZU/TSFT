#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    //@ assert n > 0;
    //@ assert n <= 1000000000;
    
    result = (n - 1) / 2;
    
    //@ assert result == (((n) - 1) / 2);
    
    return result;
}

int main()
{
    return 0;
}
