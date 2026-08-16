#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == (x % 3 == 0 || x % 5 == 0);
    assigns \nothing;
*/
bool func(int x)
{
    bool result = false;
    int temp_x = x;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 3 == x % 3;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        temp_x -= 3;
    }

    //@ assert temp_x == x % 3;
    
    if (temp_x == 0)
    {
        result = true;
    }
    else
    {
        temp_x = x;
        
        /*@
            loop invariant 1 <= x <= 100;
            loop invariant 0 <= temp_x <= x;
            loop invariant temp_x % 5 == x % 5;
            loop assigns temp_x;
            loop variant temp_x;
        */
        while (temp_x >= 5)
        {
            temp_x -= 5;
        }

        //@ assert temp_x == x % 5;
        
        if (temp_x == 0)
        {
            result = true;
        }
    }

    //@ assert result == (x % 3 == 0 || x % 5 == 0);
    return result;
}
