#include <limits.h>

/*@
    requires ((x) >= 1 && (x) <= 100 &&
        (y) >= 1 && (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
long func(long x, long y)
{
    long half_y;
    
    //@ assert y >= 0;
    
    {
        long count = 0;
        long temp_y = y;
        
        /*@
            loop invariant temp_y >= 0;
            loop invariant count >= 0;
            loop invariant temp_y + 2 * count == y;
            loop assigns temp_y, count;
            loop variant temp_y;
        */
        while (temp_y >= 2)
        {
            temp_y -= 2;
            count += 1;
        }
        
        half_y = count;
    }
    
    //@ assert half_y >= 0 && half_y <= 50;
    //@ assert half_y == y / 2;
    
    //@ assert x >= 1 && x <= 100;
    //@ assert INT_MIN <= x + half_y <= INT_MAX;
    
    return x + half_y;
}

int main()
{
    return 0;
}
