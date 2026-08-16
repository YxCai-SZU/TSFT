#include <stdint.h>

/*@
    predicate x_in_range(integer x) = 1 <= x <= 100000;
    
    logic integer total_value(integer x) = 
        1000 * (x / 500) + 5 * ((x % 500) / 5);
*/

/*@
    requires x_in_range(x);
    ensures \result == total_value(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp_x;
    uint32_t five_hundred_coins;
    uint32_t five_coins;
    
    result = 0;
    temp_x = x;
    five_hundred_coins = 0;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_x;
        loop invariant 0 <= five_hundred_coins;
        loop invariant x == temp_x + 500 * five_hundred_coins;
        loop invariant five_hundred_coins <= x / 500;
        loop assigns temp_x, five_hundred_coins;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        five_hundred_coins += 1;
    }
    
    five_coins = 0;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_x;
        loop invariant 0 <= five_coins;
        loop invariant x == temp_x + 500 * five_hundred_coins + 5 * five_coins;
        loop invariant five_hundred_coins <= x / 500;
        loop invariant five_coins <= (x % 500) / 5;
        loop assigns temp_x, five_coins;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        five_coins += 1;
    }
    
    result += five_hundred_coins * 1000;
    result += five_coins * 5;
    
    //@ assert result == total_value(x);
    return result;
}

/*@
    lemma loop_property: 
        \forall integer x; x_in_range(x) ==> total_value(x) == 1000 * (x / 500) + 5 * ((x % 500) / 5);
*/
