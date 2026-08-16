#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer sum_val(integer a, integer b, integer h) = (a + b) * h;

    lemma sum_bound:
        \forall integer a, b, h;
        valid_params(a, b, h) ==> sum_val(a, b, h) <= 20000;

    lemma division_property:
        \forall integer a, b, h, s;
        valid_params(a, b, h) && s == sum_val(a, b, h) ==> s % 2 == 0;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    // Variable declarations at top of scope
    uint64_t sum;
    uint64_t res;
    uint64_t temp;
    uint64_t count;

    // Precondition checks (as assertions)
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= h && h <= 100;
    //@ assert h % 2 == 0;

    // Arithmetic safety verification
    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;

    sum = (a + b) * h;
    res = 0;
    temp = sum;
    count = 0;

    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant 1 <= h && h <= 100;
        loop invariant h % 2 == 0;
        loop invariant sum == (a + b) * h;
        loop invariant temp >= 0;
        loop invariant temp == sum - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= sum / 2;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == sum - 2 * count;
    }

    res = count;

    // Postcondition verification
    //@ assert res == (a + b) * h / 2;

    return res;
}
