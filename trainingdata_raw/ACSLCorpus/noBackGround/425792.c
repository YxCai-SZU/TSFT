#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    unsigned long quotient;
    unsigned long remainder;
    bool result;
    
    quotient = n / 500;
    
    //@ assert 0 <= quotient * 500 <= 10000 * 500;
    
    remainder = n - quotient * 500;
    result = (remainder <= a);
    
    //@ assert result == (n % 500 <= a);
    
    return result;
}
