#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000);
    ensures \result == x / 3 || \result == x / 3 + 1;
    ensures \result >= 0;
*/
int64_t func(int64_t x)
{
    int64_t result;
    int64_t temp_x;
    int64_t count;
    
    result = 0;
    temp_x = x;
    count = 0;
    
    /*@
        loop invariant 1 <= x && x <= 1000;
        loop invariant temp_x >= 0;
        loop invariant count >= 0;
        loop invariant x == temp_x + 3 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        count += 1;
    }
    
    if (temp_x != 0)
    {
        result = count + 1;
    }
    else
    {
        result = count;
    }
    
    //@ assert result == x / 3 || result == x / 3 + 1;
    //@ assert result >= 0;
    
    return result;
}
