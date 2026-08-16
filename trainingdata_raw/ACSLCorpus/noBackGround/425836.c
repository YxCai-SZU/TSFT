#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert ((n) * (n)) <= 10000;
    
    result = n * n;
    
    //@ assert result == ((n) * (n));
    
    return result;
}

int main(void)
{
    return 0;
}
