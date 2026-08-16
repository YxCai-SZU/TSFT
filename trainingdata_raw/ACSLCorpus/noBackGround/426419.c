#include <limits.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == (((x) / 2) + 1);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int temp_x;
    int count;
    
    result = 0;
    temp_x = x;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x == x - 2 * count;
        loop invariant 0 <= count <= x / 2;
        loop invariant (1 <= (x) <= 100);
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
        count += 1;
    }
    
    result = count + 1;
    
    //@ assert result == (((x) / 2) + 1);
    
    return result;
}
