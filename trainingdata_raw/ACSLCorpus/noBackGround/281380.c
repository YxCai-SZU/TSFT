#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a > b);
    assigns \nothing;
*/
bool func(long long a, long long b)
{
    long long precision;
    long long diff;
    
    precision = 10000;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    //@ assert 1 <= a * precision <= 100 * precision;
    //@ assert 1 <= b * precision <= 100 * precision;
    
    diff = a * precision - b * precision;
    
    //@ assert diff == ((a) * 10000) - ((b) * 10000);
    
    return diff > 0;
}
