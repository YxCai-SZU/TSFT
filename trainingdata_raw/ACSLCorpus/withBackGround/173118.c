#include <stdint.h>
/*@
    predicate valid_k(integer k) = 1 <= k && k <= 1000000000;

    logic integer func_spec(integer k) =
        ((k - 1) / 2 + 1) / 2;

    lemma func_lemma:
        \forall integer k; valid_k(k) ==> 0 <= func_spec(k) && func_spec(k) <= k;
*/

/*@
    requires valid_k(k);
    ensures \result == func_spec(k);
    assigns \nothing;
*/
uint64_t func(uint64_t k)
{
    // Variable declarations at top of scope
    uint64_t ans;

    //@ assert 1 <= k && k <= 1000000000;
    //@ assert k - 1 <= 18446744073709551615ULL;
    //@ assert (k - 1) / 2 <= 9223372036854775807ULL;
    //@ assert (k - 1) / 2 + 1 <= 9223372036854775808ULL;
    //@ assert ((k - 1) / 2 + 1) / 2 <= 4611686018427387904ULL;

    ans = ((k - 1) / 2 + 1) / 2;
    //@ assert ans == func_spec(k);
    return ans;
}
