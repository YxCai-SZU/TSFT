#include <stddef.h>
/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer div_500(integer x) = x / 500;
    logic integer mod_500(integer x) = x % 500;
    logic integer div_5_mod_500(integer x) = (x % 500) / 5;
    logic integer expected_result(integer x) =
        div_500(x) * 1000 + div_5_mod_500(x) * 5;

    lemma count_500_bound:
        \forall integer x, count_500;
        is_valid_x(x) && 0 <= count_500 <= div_500(x) ==>
            count_500 <= div_500(x);
    lemma count_5_bound:
        \forall integer x, count_500, count_5;
        is_valid_x(x) && 0 <= count_5 <= div_5_mod_500(x) ==>
            count_5 <= div_5_mod_500(x);
    lemma result_correct:
        \forall integer x, count_500, count_5;
        is_valid_x(x) && count_500 == div_500(x) && count_5 == div_5_mod_500(x) ==>
            count_500 * 1000 + count_5 * 5 == expected_result(x);
*/

/*@
    requires is_valid_x(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t result = 0;
    size_t remaining = x;
    size_t count_500 = 0;
    size_t count_5 = 0;

    /*@
        loop invariant is_valid_x(x);
        loop invariant 0 <= count_500 <= div_500(x);
        loop invariant remaining == x - 500 * count_500;
        loop invariant result == 0;
        loop invariant count_5 == 0;
        loop assigns remaining, count_500;
        loop variant remaining;
    */
    while (remaining >= 500)
    {
        remaining -= 500;
        count_500 += 1;
        //@ assert count_500 <= div_500(x);
    }

    /*@
        loop invariant is_valid_x(x);
        loop invariant 0 <= count_5 <= div_5_mod_500(x);
        loop invariant remaining == x - 500 * count_500 - 5 * count_5;
        loop invariant result == 0;
        loop invariant count_500 <= div_500(x);
        loop assigns remaining, count_5;
        loop variant remaining;
    */
    while (remaining >= 5)
    {
        remaining -= 5;
        count_5 += 1;
        //@ assert count_5 <= div_5_mod_500(x);
    }

    result = count_500 * 1000 + count_5 * 5;
    //@ assert count_500 == div_500(x);
    //@ assert count_5 == div_5_mod_500(x);
    //@ assert result == expected_result(x);

    return result;
}
