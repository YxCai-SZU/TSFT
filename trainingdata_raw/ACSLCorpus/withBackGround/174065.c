#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 0 <= x <= 1000000000;

    logic integer five_hundreds_value(integer fh) = fh * 1000;
    logic integer fives_value(integer f) = f * 5;

    lemma division_property:
        \forall integer x, fh, rem;
        0 <= x && fh >= 0 && rem == x - 500 * fh ==>
        (0 <= rem < 500 ==> fh == x / 500);
*/

/*@
    requires is_valid_x(x);
    ensures \result == (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t five_hundreds = 0;
    int64_t fives = 0;

    //@ ghost int64_t original_x = x;

    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant five_hundreds >= 0;
        loop invariant temp_x == original_x - 500 * five_hundreds;
        loop assigns temp_x, five_hundreds;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        five_hundreds += 1;
        temp_x -= 500;
        //@ assert temp_x == original_x - 500 * five_hundreds;
    }

    result += five_hundreds * 1000;

    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant five_hundreds >= 0;
        loop invariant fives >= 0;
        loop invariant temp_x == original_x - 500 * five_hundreds - 5 * fives;
        loop assigns temp_x, fives;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        fives += 1;
        temp_x -= 5;
        //@ assert temp_x == original_x - 500 * five_hundreds - 5 * fives;
    }

    result += fives * 5;

    //@ assert result == five_hundreds * 1000 + fives * 5;
    //@ assert five_hundreds == original_x / 500;
    //@ assert fives == (original_x % 500) / 5;
    return result;
}
