#include <stdint.h>

/*@
    predicate valid_params(integer N, integer a, integer b) =
        1 <= N && N <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer max_product(integer N, integer a) = N * a;

    lemma product_bound: \forall integer N, integer a;
        valid_params(N, a, 0) ==> max_product(N, a) <= 1000;
*/

/*@
    requires valid_params(N, a, b);
    ensures \result >= 0;
    ensures \result <= max_product(N, a);
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert valid_params(N, a, b);
    //@ assert max_product(N, a) <= 1000;

    if (N * a < b)
    {
        ans = N * a;
    }
    else
    {
        ans = b;
    }

    //@ assert ans <= max_product(N, a);
    //@ assert ans >= 0;

    return ans;
}
