/*@
    predicate valid_input(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    predicate output_constraint(integer pies, integer a, integer p) =
        pies >= 0 && pies <= a * 3 + p;

    logic integer total_value(integer a, integer p) = a * 3 + p;

    lemma loop_invariant_maintained:
        \forall integer total, tmp, count;
        0 <= tmp && tmp <= total &&
        0 <= count && count <= total / 2 &&
        tmp == total - 2 * count &&
        tmp >= 2 ==>
        0 <= tmp - 2 && tmp - 2 <= total &&
        0 <= count + 1 && count + 1 <= total / 2 &&
        tmp - 2 == total - 2 * (count + 1);
*/

#include <stdint.h>

/*@
    requires valid_input(a, p);
    ensures output_constraint(\result, a, p);
*/
int64_t func(int64_t a, int64_t p)
{
    // Variable declarations at scope top
    int64_t total;
    int64_t pies;
    int64_t count;
    int64_t tmp;

    total = a * 3 + p;
    pies = 0;
    count = 0;
    tmp = total;

    /*@
        loop invariant 0 <= tmp && tmp <= total;
        loop invariant 0 <= count && count <= total / 2;
        loop invariant tmp == total - 2 * count;
        loop assigns tmp, count;
    */
    while (tmp >= 2)
    {
        //@ assert tmp >= 2;
        tmp -= 2;
        count += 1;
    }

    pies = count;
    //@ assert output_constraint(pies, a, p);
    return pies;
}
