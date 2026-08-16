#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;
    
    logic integer product(integer n, integer m) = n * m;
    
    lemma product_range:
        \forall integer n, m;
        valid_range(n, m) ==> 1 <= product(n, m) <= 10000;
*/

/*@
    requires valid_range(n, m);
    ensures \result == product(n, m);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    //@ assert valid_range(n, m);
    
    //@ assert 1 <= product(n, m) <= 10000;
    
    int32_t result;
    result = n * m;
    
    //@ assert result == product(n, m);
    
    return result;
}
