#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n < 256;

    logic integer tetrahedral_formula(integer n) =
        (n * (n + 1) * (n + 2)) / 6;

    lemma tetrahedral_ge_n:
        \forall integer n;
        is_valid_n(n) ==> tetrahedral_formula(n) >= n;

    lemma no_overflow1:
        \forall integer n;
        is_valid_n(n) ==> n + 1 < 257;

    lemma no_overflow2:
        \forall integer n;
        is_valid_n(n) ==> n * (n + 1) < 65536;

    lemma no_overflow3:
        \forall integer n;
        is_valid_n(n) ==> n * (n + 1) * (n + 2) < 16777216;
*/

/*@
    requires is_valid_n(n);
    ensures \result == tetrahedral_formula(n);
    ensures \result >= n;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    //@ assert n < 256;
    //@ assert n + 1 < 257;
    //@ assert n * (n + 1) < 65536;
    //@ assert n * (n + 1) * (n + 2) < 16777216;
    //@ assert (n * (n + 1) * (n + 2)) / 6 >= n;
    
    return (n * (n + 1) * (n + 2)) / 6;
}
