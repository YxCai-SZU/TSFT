#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (n / k == 0);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long k)
{
    // Variable declarations at scope top
    bool result;
    unsigned long quotient;

    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);
    
    //@ assert n / k <= 100;
    
    quotient = n / k;
    result = (quotient == 0);
    
    //@ assert result == (n / k == 0);
    return result;
}
