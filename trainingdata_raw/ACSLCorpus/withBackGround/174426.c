#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100000;

    logic integer five_hundreds_part(integer x) = (x / 500) * 1000;
    logic integer fives_part(integer x) = (x % 500 / 5) * 5;
    logic integer total_result(integer x) = five_hundreds_part(x) + fives_part(x);

    lemma division_property: \forall integer x; x >= 0 ==> x / 500 * 500 <= x < (x / 500 + 1) * 500;
    lemma modulo_property: \forall integer x; x >= 0 ==> 0 <= x % 500 < 500;
*/

/*@
    requires valid_range(x);
    ensures \result == total_result(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t ans = 0;
    int64_t temp_x = x;
    int64_t five_hundreds_num = 0;
    int64_t five_num = 0;

    //@ assert valid_range(x);
    //@ assert temp_x == x;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant five_hundreds_num >= 0;
        loop invariant five_hundreds_num == (x - temp_x) / 500;
        loop invariant temp_x == x - five_hundreds_num * 500;
        loop invariant five_hundreds_num <= x / 500;
        loop assigns temp_x, five_hundreds_num;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        five_hundreds_num += 1;
        //@ assert temp_x == x - five_hundreds_num * 500;
    }

    //@ assert temp_x == x % 500;
    //@ assert 0 <= temp_x < 500;

    /*@
        loop invariant 0 <= temp_x <= x % 500;
        loop invariant five_num >= 0;
        loop invariant five_num == (x % 500 - temp_x) / 5;
        loop invariant temp_x == x % 500 - five_num * 5;
        loop invariant five_num <= (x % 500) / 5;
        loop assigns temp_x, five_num;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        five_num += 1;
        //@ assert temp_x == x % 500 - five_num * 5;
    }

    //@ assert temp_x == x % 500 % 5;
    //@ assert 0 <= temp_x < 5;

    ans = five_hundreds_num * 1000 + five_num * 5;

    //@ assert five_hundreds_num == x / 500;
    //@ assert five_num == (x % 500) / 5;
    //@ assert ans == (x / 500) * 1000 + (x % 500 / 5) * 5;
    //@ assert ans == total_result(x);

    return ans;
}
