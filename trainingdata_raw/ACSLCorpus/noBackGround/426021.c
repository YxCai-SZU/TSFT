#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 || \result == 2 || \result == 3;
*/
int func(int a, int b, int c)
{
    int max = 0;
    int mid = 0;
    int min = 0;
    int result = 0;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result >= 1 && result <= 3;
        return result;
    }
    else if (a == b || b == c || c == a)
    {
        result = 2;
        //@ assert result >= 1 && result <= 3;
        return result;
    }
    else
    {
        if (a > b)
        {
            if (a > c)
            {
                max = a;
            }
            else
            {
                max = c;
            }
        }
        else
        {
            if (b > c)
            {
                max = b;
            }
            else
            {
                max = c;
            }
        }

        if (a < b)
        {
            if (a < c)
            {
                min = a;
            }
            else
            {
                min = c;
            }
        }
        else
        {
            if (b < c)
            {
                min = b;
            }
            else
            {
                min = c;
            }
        }

        mid = a + b + c - max - min;

        //@ assert max >= min;
        //@ assert max >= mid;
        //@ assert min <= mid;

        if ((max - min) == 1)
        {
            //@ assert (max - min) == 1;
            result = 3;
        }
        else
        {
            //@ assert (max - min) != 1;
            result = 3;
        }

        //@ assert result >= 1 && result <= 3;
        return result;
    }
}
