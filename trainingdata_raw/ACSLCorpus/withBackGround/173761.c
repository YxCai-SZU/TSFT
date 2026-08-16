#include <stdint.h>

/*@
    predicate circumference_eq(integer r, integer pi, integer circ) =
        circ == 2 * r * pi;

    predicate division_invariant(integer circ, integer temp, integer divisor, integer count) =
        circ == (temp + divisor * count) &&
        count * divisor <= circ;

    logic integer compute_result(integer r, integer pi, integer divisor) =
        (2 * r * pi) / divisor;

    lemma result_correctness:
        \forall integer r, pi, divisor, result, temp;
        (1 <= r <= 100 && pi == 314159 && divisor == 100000 &&
         result * divisor + temp == 2 * r * pi && 0 <= temp < divisor) ==>
        result == compute_result(r, pi, divisor);
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * r * 314159) / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t count;

    pi = 314159;
    circumference = 2 * r * pi;
    result = 0;
    temp = circumference;
    divisor = 100000;
    count = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant circumference_eq(r, pi, circumference);
        loop invariant divisor == 100000;
        loop invariant division_invariant(circumference, temp, divisor, count);
        loop invariant temp >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        count += 1;
    }
    result = count;

    //@ assert result * 100000 + temp == 2 * r * pi;
    //@ assert 0 <= temp < divisor;
    return result;
}
