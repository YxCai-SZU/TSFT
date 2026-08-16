#include <stdbool.h>

/*@
    predicate in_range(integer n, integer m) =
        1 <= n <= 10000 && 1 <= m <= 10000;
    
    logic integer product(integer n, integer m) = n * m;
    
    predicate is_even_product(integer n, integer m) =
        product(n, m) % 2 == 0;
*/

/*@
    requires in_range(n, m);
    ensures \result == (product(n, m) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int prod;
    
    //@ assert 1 <= n <= 10000;
    
    //@ assert 1 <= m <= 10000;
    
    //@ assert product(n, m) <= 10000 * 10000;
    
    prod = n * m;
    
    if (prod % 2 == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (product(n, m) % 2 == 0);
    return result;
}
