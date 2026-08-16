/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 179;
    
    logic integer division_count(integer x, integer temp_x) = (x - temp_x) / 2;
    
    lemma division_loop_invariant_maintained:
        \forall integer x, temp_x, count;
        x_in_range(x) ==>
        0 <= temp_x && temp_x <= x ==>
        temp_x == x - 2 * count ==>
        0 <= count && count <= x / 2 ==>
        count == division_count(x, temp_x);
    
    logic integer remainder_value(integer x, integer rem) = x - 2 * ((x - rem) / 2);
    
    lemma modulo_loop_invariant_maintained:
        \forall integer x, remainder;
        x_in_range(x) ==>
        0 <= remainder && remainder <= x ==>
        remainder == remainder_value(x, remainder) ==>
        0 <= (x - remainder) / 2 && (x - remainder) / 2 <= x / 2;
*/

#include <stdint.h>

/*@
    requires 1 <= x && x <= 179;
    ensures \result == (x / 2 + x % 2);
*/
int32_t func(int32_t x)
{
    int32_t res = 0;
    int32_t temp_x = x;
    int32_t count = 0;
    
    // Manual division by 2
    /*@
        loop invariant 1 <= x && x <= 179;
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant temp_x == x - 2 * count;
        loop invariant 0 <= count && count <= x / 2;
        loop invariant count == (x - temp_x) / 2;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        //@ assert temp_x >= 2;
        temp_x -= 2;
        count += 1;
    }
    
    int32_t remainder = x;
    
    // Manual modulo by 2
    /*@
        loop invariant 1 <= x && x <= 179;
        loop invariant 0 <= remainder && remainder <= x;
        loop invariant remainder == x - 2 * ((x - remainder) / 2);
        loop invariant 0 <= (x - remainder) / 2 && (x - remainder) / 2 <= x / 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        remainder -= 2;
    }
    
    res = count + remainder;
    //@ assert res == (x / 2 + x % 2);
    return res;
}
