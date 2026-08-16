#include <stdint.h>

/*@
    predicate is_valid_input(integer n) = 0 <= n && n <= 1000;

    logic integer tetrahedral_formula(integer n) = (n * (n + 1) * (n + 2)) / 6;

    lemma tetrahedral_ge_n:
        \forall integer n; 0 <= n && n <= 1000 ==> tetrahedral_formula(n) >= n;
*/

/*@
    requires is_valid_input(n);
    ensures \result == tetrahedral_formula(n);
    ensures \result >= n;
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    // Variable declarations at the top
    uint32_t ret;

    //@ assert n <= 1000;
    //@ assert n * (n + 1) <= 1000 * (1000 + 1);
    //@ assert n * (n + 1) * (n + 2) <= 1000 * 1001 * 1002;
    //@ assert n * (n + 1) * (n + 2) / 6 <= (1000 * 1001 * 1002) / 6;
    //@ assert n * (n + 1) * (n + 2) / 6 >= n;

    ret = n * (n + 1) * (n + 2) / 6;
    return ret;
}
