#include <stddef.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 1000000000;
*/

/*@
    logic integer compute_result(integer n) = (n - 1) / 2 + 1;
*/

/*@
    lemma result_property:
        \forall integer n; valid_range(n) ==> compute_result(n) == (n - 1) / 2 + 1;
*/

/*@
    requires valid_range(n);
    ensures \result == compute_result(n);
    ensures \result == (n - 1) / 2 + 1;
*/
size_t func(size_t n)
{
    size_t result;
    
    //@ assert valid_range(n);
    result = (n - 1) / 2 + 1;
    //@ assert result == compute_result(n);
    return result;
}
