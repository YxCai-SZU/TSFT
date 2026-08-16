#include <stdint.h>

/*@
    predicate valid_input(integer n) = 0 <= n <= 255;

    logic integer tetrahedral_formula(integer n) =
        (n * (n + 1) * (n + 2)) / 6;

    lemma product_bound1:
        \forall integer n; valid_input(n) ==> n * (n + 1) <= 255 * 256;

    lemma product_bound2:
        \forall integer n; valid_input(n) ==> n * (n + 1) * (n + 2) <= 255 * 256 * 257;

    lemma division_bound:
        \forall integer n; valid_input(n) ==> (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;

    lemma product_identity:
        \forall integer n; valid_input(n) ==> n * (n + 1) * (n + 2) == n * (n + 1) * (n + 2);
*/

/*@
    requires 0 <= n <= 255;
    ensures \result == tetrahedral_formula(n);
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    //@ assert valid_input(n);
    //@ assert n * (n + 1) <= 255 * 256;
    //@ assert n * (n + 1) * (n + 2) <= 255 * 256 * 257;
    //@ assert (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;
    //@ assert n * (n + 1) * (n + 2) == n * (n + 1) * (n + 2);
    
    return (n * (n + 1) * (n + 2)) / 6;
}
