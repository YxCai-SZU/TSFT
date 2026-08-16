#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bounds:
        \forall integer n; 1 <= n <= 100 ==> 0 <= square(n) <= 10000;
*/

/*@
    requires is_valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 0 <= n * n <= 10000;
    //@ assert 0 <= a <= n * n;
    
    result = n * n - a;
    return result;
}
