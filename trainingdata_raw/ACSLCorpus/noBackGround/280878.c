#include <limits.h>

/*@
    requires (0 <= (a) <= 23 && 0 <= (b) <= 59);
    requires (0 <= (c) <= 23 && 0 <= (d) <= 59);
    requires (0 <= (e) <= 10000);
    ensures \result >= 0;
    ensures \result <= 10000 + 23 * 60 + 59;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int t0;
    int t1;
    int result;
    int tmp;
    
    t0 = a * 60 + b;
    t1 = c * 60 + d;
    
    //@ assert t0 >= 0 && t0 <= 23 * 60 + 59;
    //@ assert t1 >= 0 && t1 <= 23 * 60 + 59;
    
    if (t0 < t1)
    {
        result = t1 - t0;
        //@ assert result >= 0;
    }
    else
    {
        result = 24 * 60 - t0 + t1;
        //@ assert result >= 0;
    }
    
    //@ assert result <= 10000 + 23 * 60 + 59;
    
    tmp = result;
    if (tmp < e)
    {
        result = tmp;
        //@ assert result >= 0;
    }
    else
    {
        result = e;
        //@ assert result >= 0;
    }
    
    //@ assert result <= 10000 + 23 * 60 + 59;
    return result;
}
