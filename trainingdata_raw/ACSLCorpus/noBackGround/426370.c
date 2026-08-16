#include <limits.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
  ensures \result >= 1 && \result <= 3;
  assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min;
    min = a;

    if (b < min)
    {
        min = b;
    }

    if (c < min)
    {
        min = c;
    }

    //@ assert min == a || min == b || min == c;

    if (min == a)
    {
        if (b == c)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if (min == b)
    {
        if (a == c)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (a == b)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
