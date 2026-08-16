#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        2 <= k <= n <= 100000;

    predicate valid_array(integer n, uint64_t *a) =
        \valid(a + (0 .. n-1)) &&
        (\forall integer i; 0 <= i < n ==> 1 <= a[i] <= n) &&
        (\forall integer i, j; 0 <= i < j < n ==> a[i] != a[j]);

    logic integer compute_result(integer n, integer k) =
        (n - 1) % (k - 1) == 0 ?
        (n - 1) / (k - 1) :
        (n - 1) / (k - 1) + 1;

    lemma result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==>
        compute_result(n, k) >= (n - 1) / (k - 1) &&
        compute_result(n, k) <= (n - 1) / (k - 1) + 1;
*/

/*@
    requires valid_params(n, k);
    requires valid_array(n, a);
    ensures \result == compute_result(n, k);
*/
uint64_t func(uint64_t n, uint64_t k, uint64_t *a)
{
    uint64_t result;
    
    //@ assert valid_params(n, k);
    
    if ((n - 1) % (k - 1) == 0)
    {
        result = (n - 1) / (k - 1);
    }
    else
    {
        result = (n - 1) / (k - 1) + 1;
    }
    
    //@ assert result == compute_result(n, k);
    
    return result;
}
