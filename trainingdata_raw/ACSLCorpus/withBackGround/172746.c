#include <stdint.h>

/*@
    predicate triangular_formula(integer n, integer ret) =
        ret == n * (n + 1) / 2;

    lemma triangular_bound:
        \forall integer n; 0 <= n <= 65535 ==> n * (n + 1) / 2 <= 2147483647;
*/

/*@
    requires n <= 65535;
    ensures \result == n * (n + 1) / 2;
    ensures \result <= 2147483647;
    assigns \nothing;
*/
uint32_t triangular_num(uint32_t n)
{
    //@ assert n >= 0;
    //@ assert n <= 65535;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    return n * (n + 1) / 2;
}
