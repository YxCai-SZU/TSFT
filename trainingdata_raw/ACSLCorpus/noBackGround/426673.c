#include <stdint.h>

/*@
    requires ((a) < 1000000);
    requires ((b) < 1000000);
    ensures \result == a * b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t result;
    
    //@ assert a * b < 1000000000000000;
    
    result = a * b;
    
    //@ assert result == a * b;
    
    return result;
}

int main(void)
{
    return 0;
}
