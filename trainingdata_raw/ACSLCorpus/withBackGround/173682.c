#include <stddef.h>

/*@
    predicate valid_input(integer x) = 1 <= x <= 100000;

    logic integer total_value(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma loop1_invariant_maintained:
        \forall integer x, temp_x, count;
        valid_input(x) && temp_x >= 0 && count >= 0 &&
        x == temp_x + count * 500 ==>
        (temp_x >= 500 ==> x == (temp_x - 500) + (count + 1) * 500);

    lemma loop2_invariant_maintained:
        \forall integer x, temp_x, count500, count5;
        valid_input(x) && temp_x >= 0 && count500 >= 0 && count5 >= 0 &&
        temp_x < 500 && x == temp_x + count500 * 500 + count5 * 5 ==>
        (temp_x >= 5 ==> x == (temp_x - 5) + count500 * 500 + (count5 + 1) * 5);
*/

/*@
    requires valid_input(x);
    ensures \result == total_value(x);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t result = 0;
    size_t temp_x = x;
    size_t five_hundred_count = 0;
    size_t five_count = 0;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant temp_x >= 0;
        loop invariant five_hundred_count >= 0;
        loop invariant x == temp_x + five_hundred_count * 500;
        loop assigns temp_x, five_hundred_count;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        five_hundred_count += 1;
        //@ assert x == temp_x + five_hundred_count * 500;
    }

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant temp_x >= 0;
        loop invariant five_hundred_count >= 0;
        loop invariant five_count >= 0;
        loop invariant x == temp_x + five_hundred_count * 500 + five_count * 5;
        loop invariant temp_x < 500;
        loop assigns temp_x, five_count;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        five_count += 1;
        //@ assert x == temp_x + five_hundred_count * 500 + five_count * 5;
    }

    result = five_hundred_count * 1000 + five_count * 5;
    //@ assert result == total_value(x);
    return result;
}
