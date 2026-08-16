#include <stdbool.h>

/*@
    requires (400 <= (x) && (x) <= 1999 && (x) != 1800);
    ensures (((\result) == 8 || (\result) == 7 || (\result) == 6 || (\result) == 5 || (\result) == 4) &&
        (\result) >= 4);
    assigns \nothing;
*/
int func(int x)
{
    unsigned int x_unsigned;
    int ans;
    
    //@ assert (400 <= (x) && (x) <= 1999 && (x) != 1800);
    
    if (x < 0)
    {
        x_unsigned = (unsigned int)(-x);
    }
    else
    {
        x_unsigned = (unsigned int)x;
    }
    
    //@ assert x_unsigned >= 400 && x_unsigned <= 1999;
    //@ assert x_unsigned != 1800;
    
    if (x_unsigned < 200)
    {
        ans = 8;
    }
    else if (x_unsigned < 400)
    {
        ans = 7;
    }
    else if (x_unsigned < 800)
    {
        ans = 6;
    }
    else if (x_unsigned < 1200)
    {
        ans = 5;
    }
    else
    {
        ans = 4;
    }
    
    //@ assert (((ans) == 8 || (ans) == 7 || (ans) == 6 || (ans) == 5 || (ans) == 4) &&         (ans) >= 4);
    return ans;
}
