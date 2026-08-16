#include <stdbool.h>

/*@
    predicate are_equal(integer a, integer b) = a == b;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result <==> (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;
    
    //@ assert n == m <==> (n == m);
    
    result = (n == m);
    return result;
}
