#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10000);
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    ensures \result == (a * x <= b);
*/
bool func(long long x, long long a, long long b)
{
    // Variable declarations at top of scope
    long long product;
    bool result;
    
    //@ assert (1 <= (x) <= 10000);
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    
    //@ assert ((a) * (x)) <= 100000000;
    product = a * x;
    
    //@ assert product == ((a) * (x));
    result = (product <= b);
    
    //@ assert result == (((a) * (x)) <= b);
    return result;
}
