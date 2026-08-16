#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_product(integer a, integer b) = a * b;

    predicate product_in_range(integer a, integer b) =
        1 <= safe_product(a, b) <= 10000;

    lemma product_range_lemma:
        \forall integer a, b;
            valid_inputs(a, b) ==> product_in_range(a, b);
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == (a * b + 1) / 2;
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t c;
    uint64_t result;
    uint64_t count;
    uint64_t temp;

    //@ assert valid_inputs(a, b);
    //@ assert product_in_range(a, b);
    //@ assert 1 <= a * b <= 10000;

    c = a * b + 1;
    result = 0;
    count = 0;
    temp = c;

    /*@
        loop invariant 0 <= temp <= a * b + 1;
        loop invariant temp + 2 * count == a * b + 1;
        loop invariant count <= (a * b + 1) / 2;
        loop invariant product_in_range(a, b);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp + 2 * count == a * b + 1;
    }

    result = count;
    //@ assert result == (a * b + 1) / 2;
    return (int64_t)result;
}
