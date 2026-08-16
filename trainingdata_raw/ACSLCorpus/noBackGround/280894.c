#include <limits.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires ((y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y;
    
    if (y >= 0)
    {
        int count = 0;
        int temp_y = y;
        
        /*@
            loop invariant 0 <= temp_y <= y;
            loop invariant count <= ((y) / 2);
            loop invariant ((y) % 2 == 0);
            loop invariant temp_y == y - 2 * count;
            loop assigns count, temp_y;
            loop variant temp_y;
        */
        while (temp_y >= 2)
        {
            //@ assert temp_y >= 2;
            count += 1;
            temp_y -= 2;
        }
        half_y = count;
    }
    else
    {
        int count = 0;
        int temp_y = y;
        
        /*@
            loop invariant y <= temp_y <= 0;
            loop invariant count >= ((y) / 2);
            loop invariant ((y) % 2 == 0);
            loop invariant temp_y == y - 2 * count;
            loop assigns count, temp_y;
            loop variant -temp_y;
        */
        while (temp_y <= -2)
        {
            //@ assert temp_y <= -2;
            count -= 1;
            temp_y += 2;
        }
        half_y = count;
    }
    
    //@ assert half_y == ((y) / 2);
    //@ assert x >= 1 && x <= 100;
    //@ assert ((y) % 2 == 0);
    
    return x + half_y;
}
