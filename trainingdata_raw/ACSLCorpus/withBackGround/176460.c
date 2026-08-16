#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer mod(integer a, integer b) = a % b;

    lemma mod_bounds:
        \forall integer N, M;
            valid_range(N) && valid_range(M) ==>
            0 <= mod(N, M) <= 100;
*/

/*@
    requires valid_range(N) && valid_range(M);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> N % M == 0;
    ensures \result == 1 ==> N % M != 0;
*/
int32_t func(uint32_t N, uint32_t M)
{
    // Variable declarations
    uint32_t n_mod_m;
    int32_t is_divisible;

    //@ assert valid_range(N) && valid_range(M);
    //@ assert 0 <= N % M <= 100;

    n_mod_m = N % M;

    if (n_mod_m == 0)
    {
        is_divisible = 0;
    }
    else
    {
        is_divisible = 1;
    }

    //@ assert is_divisible == 0 || is_divisible == 1;
    //@ assert is_divisible == 0 ==> N % M == 0;
    //@ assert is_divisible == 1 ==> N % M != 0;

    return is_divisible;
}
