/*@
    predicate is_valid_input(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer compute_result(integer a, integer p) =
        3 * a + p;

    logic integer compute_pies(integer a, integer p) =
        compute_result(a, p) / 2;

    lemma pies_correctness:
        \forall integer a, p;
        is_valid_input(a, p) ==> compute_pies(a, p) == (3 * a + p) / 2;
*/

#include <stddef.h>

/*@
    requires 0 <= a <= 100 && 0 <= p <= 100;
    ensures \result == (3 * a + p) / 2;
*/
size_t func(size_t a, size_t p)
{
    size_t result;
    size_t pies = 0;
    size_t temp;

    //@ assert 0 <= a <= 100 && 0 <= p <= 100;
    result = 3 * a + p;
    temp = result;

    /*@
        loop invariant 0 <= temp <= result;
        loop invariant 0 <= pies <= result / 2;
        loop invariant temp + 2 * pies == result;
        loop assigns temp, pies;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        pies += 1;
        //@ assert temp + 2 * pies == result;
    }

    //@ assert pies == (3 * a + p) / 2;
    return pies;
}
