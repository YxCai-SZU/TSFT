#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50 &&
        1 <= (c) && (c) <= 50 &&
        1 <= (k) && (k) <= 50);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int res;
    int rst;

    res = 0;
    rst = k;

    //@ assert (1 <= (a) && (a) <= 50 &&         1 <= (b) && (b) <= 50 &&         1 <= (c) && (c) <= 50 &&         1 <= (k) && (k) <= 50);
    
    if (rst >= a)
    {
        res += a;
        rst -= a;
    }
    else
    {
        res += rst;
        rst = 0;
    }
    
    //@ assert res >= 0 && res <= a;
    
    if (rst >= b)
    {
        rst -= b;
    }
    else
    {
        rst = 0;
    }
    
    //@ assert rst >= 0;
    
    if (rst >= c)
    {
        res -= c;
        rst -= c;
    }
    else
    {
        res -= rst;
        rst = 0;
    }
    
    //@ assert res >= -c;
    //@ assert res <= a;
    
    return res;
}
