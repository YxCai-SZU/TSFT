#include <stddef.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t result;
    size_t remainder;
    
    //@ assert (1 <= (x) <= 100000 ==>         0 <= (x) % 500 <= 500);
    
    result = 1000 * (x / 500);
    remainder = x % 500;
    
    //@ assert 0 <= remainder && remainder <= 500;
    //@ assert 0 <= (x % 500) && (x % 500) <= 500;
    
    result += 5 * (remainder / 5);
    
    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
    
    return result;
}
