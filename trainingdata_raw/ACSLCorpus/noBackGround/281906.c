#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max = 0;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);

    if (a == b && b == c)
    {
        max = a + b + c;
        //@ assert max >= 0;
    }
    else if (a == b)
    {
        max = a + b + 1;
        //@ assert max >= 0;
    }
    else if (a == c)
    {
        max = a + c + 1;
        //@ assert max >= 0;
    }
    else if (b == c)
    {
        max = b + c + 1;
        //@ assert max >= 0;
    }
    else
    {
        max = a + b;
        //@ assert max >= 0;
    }

    return max;
}
