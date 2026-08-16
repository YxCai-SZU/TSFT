#include <stdint.h>

/*@
    predicate is_valid_input(integer n) = 0 <= n && n <= 255;

    logic integer tetrahedral_formula(integer n) = 
        (n * (n + 1) * (n + 2)) / 6;

    lemma multiplication_bounds_1:
        \forall integer n; is_valid_input(n) ==> n * (n + 1) <= 255 * 256;

    lemma multiplication_bounds_2:
        \forall integer n; is_valid_input(n) ==> n * (n + 1) * (n + 2) <= 255 * 256 * 257;

    lemma division_bounds:
        \forall integer n; is_valid_input(n) ==> 
            (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;
*/

/*@
    requires is_valid_input(n);
    ensures \result == tetrahedral_formula(n);
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert is_valid_input(n);
    //@ assert n * (n + 1) <= 255 * 256;
    //@ assert n * (n + 1) * (n + 2) <= 255 * 256 * 257;
    //@ assert (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;

    ret = n * (n + 1) * (n + 2) / 6;
    //@ assert ret == tetrahedral_formula(n);
    return ret;
}
