#include <stdint.h>

/*@
    predicate valid_x(integer x) = 0 <= x <= 1000000000;

    logic integer total_value(integer five_hundred, integer five) =
        1000 * five_hundred + 5 * five;

    lemma division_property:
        \forall integer x, q, r;
        x >= 0 && q == x / 500 && r == x % 500 ==>
        x == 500 * q + r && 0 <= r < 500;

    lemma modulo_property:
        \forall integer x, q, r;
        x >= 0 && q == x / 5 && r == x % 5 ==>
        x == 5 * q + r && 0 <= r < 5;
*/

/*@
    requires valid_x(x);
    ensures \result >= 0;
    ensures \result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
*/
int64_t func(int64_t x)
{
    int64_t result;
    int64_t remaining_x;
    int64_t five_hundred_coins;
    int64_t five_coins;

    result = 0;
    remaining_x = x;
    five_hundred_coins = 0;

    /*@
        loop invariant 0 <= five_hundred_coins;
        loop invariant five_hundred_coins <= x / 500;
        loop invariant remaining_x == x - 500 * five_hundred_coins;
        loop invariant 0 <= remaining_x;
        loop assigns five_hundred_coins, remaining_x;
        loop variant remaining_x;
    */
    while (remaining_x >= 500)
    {
        //@ assert remaining_x >= 500;
        five_hundred_coins = five_hundred_coins + 1;
        remaining_x = remaining_x - 500;
    }

    five_coins = 0;

    /*@
        loop invariant 0 <= five_hundred_coins;
        loop invariant five_hundred_coins <= x / 500;
        loop invariant 0 <= five_coins;
        loop invariant five_coins <= (x - 500 * five_hundred_coins) / 5;
        loop invariant remaining_x == x - 500 * five_hundred_coins - 5 * five_coins;
        loop invariant 0 <= remaining_x;
        loop assigns five_coins, remaining_x;
        loop variant remaining_x;
    */
    while (remaining_x >= 5)
    {
        //@ assert remaining_x >= 5;
        five_coins = five_coins + 1;
        remaining_x = remaining_x - 5;
    }

    result = 1000 * five_hundred_coins + 5 * five_coins;

    //@ assert result == total_value(five_hundred_coins, five_coins);
    return result;
}
