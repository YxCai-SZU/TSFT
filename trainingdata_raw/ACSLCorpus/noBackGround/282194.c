#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == true <==> (((a) == 5 && (b) == 5 && (c) == 7) ||
        ((a) == 5 && (b) == 7 && (c) == 5) ||
        ((a) == 7 && (b) == 5 && (c) == 5));
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    if (a == 5)
    {
        if (b == 5)
        {
            if (c == 7)
            {
                //@ assert a == 5 && b == 5 && c == 7;
                result = true;
            }
            else
            {
                result = false;
            }
        }
        else if (b == 7)
        {
            if (c == 5)
            {
                //@ assert a == 5 && b == 7 && c == 5;
                result = true;
            }
            else
            {
                result = false;
            }
        }
        else
        {
            result = false;
        }
    }
    else if (a == 7)
    {
        if (b == 5)
        {
            if (c == 5)
            {
                //@ assert a == 7 && b == 5 && c == 5;
                result = true;
            }
            else
            {
                result = false;
            }
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }

    return result;
}
