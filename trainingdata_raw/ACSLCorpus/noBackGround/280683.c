#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == ((((n) - 1) * (n)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t result;
    
    //@ assert (1 <= (n) <= 1000000000);
    
    if (n == 1)
    {
        result = 0;
        //@ assert result == ((((n) - 1) * (n)) / 2);
        return result;
    }
    
    //@ assert n > 1 && n <= 1000000000;
    //@ assert n - 1 >= 0;
    
    //@ assert multiplication_bound: (n - 1) * n <= 1000000000 * 1000000000;
    //@ assert division_bound: ((n - 1) * n) / 2 <= 1000000000 * 1000000000 / 2;
    
    result = ((n - 1) * n) / 2;
    //@ assert result == ((((n) - 1) * (n)) / 2);
    
    return result;
}
