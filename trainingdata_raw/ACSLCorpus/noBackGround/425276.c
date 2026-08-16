#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int m = 0;
    int diff1 = 0;
    int diff2 = 0;
    int diff3 = 0;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    diff1 = (a - b < 0) ? -(a - b) : (a - b);
    diff2 = (b - c < 0) ? -(b - c) : (b - c);
    diff3 = (c - a < 0) ? -(c - a) : (c - a);

    if (diff1 == 0 && diff2 == 0)
    {
        m = 3;
        //@ assert m == 3;
    }
    else if (diff1 == 0 || diff2 == 0 || diff3 == 0)
    {
        m = 2;
        //@ assert m == 2;
    }
    else
    {
        m = 1;
        //@ assert m == 1;
    }

    //@ assert m >= 1 && m <= 3;
    return m;
}
