#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 1000000000 &&
        1 <= k <= n;

    logic integer compute_result(integer n, integer k) =
        n - k + 1;

    lemma result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==>
        1 <= compute_result(n, k) <= 1000000000;
*/

/*@
    requires valid_params(n, k);
    ensures \result == compute_result(n, k);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t ans;
    
    //@ assert 1 <= n <= 1000000000;
    //@ assert 1 <= k <= n;
    
    //@ assert n - k + 1 >= 1;
    //@ assert n - k + 1 <= 1000000000;
    
    ans = n - k + 1;
    
    //@ assert ans == compute_result(n, k);
    return ans;
}

#ifdef TEST
#include <stdio.h>
int main()
{
    int64_t n = 10;
    int64_t k = 3;
    int64_t result = func(n, k);
    printf("%lld\n", (long long)result);
    return 0;
}
#endif
