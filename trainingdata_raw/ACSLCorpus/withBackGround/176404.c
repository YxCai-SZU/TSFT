#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;

    logic integer scaled_pi(integer r) = 2 * r * 314159;

    lemma result_bound:
        \forall integer r, integer scale;
        is_valid_range(r) && scale == 100000 ==>
        scaled_pi(r) / scale == 2 * r * 314159 / 100000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == 2 * r * 314159 / 100000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t scale;
    int64_t result;
    int64_t temp;

    pi = 314159;
    scale = 100000;

    result = 0;
    temp = 2 * r * pi;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant result * scale + temp == 2 * r * pi;
        loop invariant temp >= 0;
        loop invariant result <= 2 * r * 314159 / 100000;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert result * scale + temp == 2 * r * pi;
        result += 1;
        temp -= scale;
        //@ assert result * scale + temp == 2 * r * pi;
    }

    //@ assert result == 2 * r * 314159 / 100000;
    return result;
}
