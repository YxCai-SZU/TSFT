#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_res(integer n) =
        n % 1000 == 0 ? 0 : 1000 - n % 1000;

    lemma res_properties:
        \forall integer n;
        is_valid_n(n) ==>
        compute_res(n) < 1000 &&
        compute_res(n) >= 0 &&
        (compute_res(n) == 1000 - n % 1000 || compute_res(n) == 0);
*/

/*@
    requires is_valid_n(n);
    ensures \result < 1000;
    ensures \result >= 0;
    ensures \result == 1000 - n % 1000 || \result == 0;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    size_t res;

    //@ assert is_valid_n(n);
    
    ans = (n / 1000 + (n % 1000 != 0 ? 1 : 0)) * 1000;
    
    //@ assert ans >= 1000;
    //@ assert ans <= n + 1000;
    
    res = ans - n;
    
    //@ assert res == compute_res(n);
    return res;
}
