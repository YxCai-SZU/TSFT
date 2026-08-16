#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    int product;
    bool result;

    //@ assert (1 <= (t) <= 10000);
    //@ assert (1 <= (s) <= 10000);
    //@ assert ((t) * (s)) <= 10000 * 10000;

    product = t * s;
    //@ assert product == ((t) * (s));
    
    result = (product >= d);
    //@ assert result == (((t) * (s)) >= d);
    
    return result;
}
