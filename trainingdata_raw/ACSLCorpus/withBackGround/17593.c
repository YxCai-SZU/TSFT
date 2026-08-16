#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        2 <= k && k <= n && n <= 1000000000;
*/

/*@
    logic integer func_spec(integer n, integer k) =
        n <= k ? n - 1 : (n - 1) - (k - 1);
*/

/*@
    lemma func_lemma:
        \forall integer n, integer k;
        valid_params(n, k) ==>
        func_spec(n, k) <= n - 1 &&
        (func_spec(n, k) == n - 1 || (n - 1 - func_spec(n, k)) >= (k - 1));
*/

/*@
    requires valid_params(n, k);
    ensures \result <= n - 1;
    ensures \result == n - 1 || (n - 1 - \result) >= (k - 1);
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t result;
    uint64_t x;
    uint64_t y;
    uint64_t ans;
    
    if (n <= k) {
        result = n - 1;
        //@ assert result == n - 1;
        return result;
    } else {
        x = n - 1;
        y = k - 1;
        
        //@ assert x >= y;
        //@ assert x - y <= n - 1;
        
        ans = (x > y) ? (x - y) : 0;
        result = ans;
        
        //@ assert result == func_spec(n, k);
        return result;
    }
}
