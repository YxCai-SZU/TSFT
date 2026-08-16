#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 2) - 1);
    assigns \nothing;
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
        loop invariant 1 <= x && x <= 1000000000;
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant 0 <= count && count <= x/2;
        loop invariant temp_x == x - 2*count;
        loop invariant count <= x/2;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        //@ assert temp_x >= 2;
        temp_x = temp_x - 2;
        count = count + 1;
    }
    
    result = count;
    //@ assert result == x/2;
    result = result - 1;
    
    //@ assert result == (x/2) - 1;
    return result;
}
