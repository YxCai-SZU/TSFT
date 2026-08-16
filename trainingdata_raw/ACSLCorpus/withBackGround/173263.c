#include <stdint.h>
/*@
    predicate is_valid_input(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) = y / 2;

    lemma half_y_lemma:
        \forall integer y;
        is_valid_input(100, y) ==> half_of(y) == y / 2;
*/

/*@
    requires is_valid_input(x, y);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t half_y;
    uint32_t count;
    uint32_t temp_y;
    uint32_t ans;

    //@ assert y % 2 == 0;
    
    count = 0;
    temp_y = y;
    
    /*@
        loop invariant 1 <= y <= 100;
        loop invariant 0 <= count <= y / 2;
        loop invariant temp_y == y - 2 * count;
        loop invariant y % 2 == 0;
        loop assigns count, temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        //@ assert temp_y >= 2;
        count += 1;
        temp_y -= 2;
        //@ assert temp_y == y - 2 * count;
    }
    
    half_y = count;
    //@ assert half_y == y / 2;
    
    ans = x + half_y;
    //@ assert ans == x + (y / 2);
    
    return ans;
}
