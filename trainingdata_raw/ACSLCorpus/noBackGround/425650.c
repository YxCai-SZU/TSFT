#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (a * b == c * d);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) * (b) <= 10000);
    //@ assert (1 <= (c) * (d) <= 10000);
    
    result = (a * b == c * d);
    return result;
}
