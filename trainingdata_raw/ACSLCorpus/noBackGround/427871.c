#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires a >= -100;
    requires b >= -100;
    requires a <= 100;
    requires b <= 100;
    requires ((a) * (b) <= 9223372036854775807);
    ensures \result == (a * b >= 0);
*/
bool func(long long a, long long b)
{
    bool result;
    long long product;
    
    //@ assert ((a) * (b) <= 9223372036854775807);
    product = a * b;
    result = (product >= 0);
    
    return result;
}
