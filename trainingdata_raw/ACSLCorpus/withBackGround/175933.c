#include <stdint.h>

/*@
    predicate is_valid_input(integer n, integer k) =
        1 <= n && n <= 1000000000000 &&
        1 <= k && k <= 1000000000000;

    logic integer mod_result(integer n, integer k) =
        n % k;

    lemma mod_properties:
        \forall integer n, k;
        is_valid_input(n, k) ==>
        (mod_result(n, k) == 0 ==> n % k == 0) &&
        (mod_result(n, k) != 0 ==> n % k != 0);
*/

/*@
    requires is_valid_input(N, K);
    ensures \result <= 1;
    ensures \result >= 0;
    ensures \result == 1 ==> N % K == 0;
    ensures \result == 0 ==> N % K != 0;
*/
uint64_t func(uint64_t N, uint64_t K)
{
    //@ assert N > 0 && N <= 1000000000000;
    //@ assert K > 0 && K <= 1000000000000;
    
    if (N % K == 0)
    {
        //@ assert N % K == 0;
        return 1;
    }
    else
    {
        //@ assert N % K != 0;
        return 0;
    }
}
