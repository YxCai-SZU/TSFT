#include <stdint.h>

/*@
    predicate valid_range(integer l) = 1 <= l <= 1000;

    logic integer cube(integer l) = l * l * l;

    lemma cube_bounds:
        \forall integer l; valid_range(l) ==> cube(l) <= 1000000000;

    lemma division_property:
        \forall integer l, integer result, integer temp;
        valid_range(l) && temp == cube(l) - result * 27 && temp >= 0 ==>
        (result == cube(l) / 27 <==> temp < 27);
*/

/*@
    requires valid_range(l);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    // Variable declarations at scope top
    int64_t result = 0;
    int64_t temp_result;
    int64_t divisor = 27;

    //@ assert valid_range(l);
    //@ assert cube(l) <= 1000000000;

    temp_result = l * l * l;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant temp_result >= 0;
        loop invariant result >= 0;
        loop invariant temp_result == cube(l) - result * divisor;
        loop assigns temp_result, result;
        loop variant temp_result;
    */
    while (temp_result >= divisor)
    {
        temp_result -= divisor;
        result += 1;
    }

    //@ assert temp_result == cube(l) - result * divisor;
    //@ assert temp_result < divisor;
    //@ assert result == cube(l) / divisor;

    return result;
}
