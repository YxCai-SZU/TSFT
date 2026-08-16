#include <stdbool.h>

/*@ requires ((a) > -2147483648 && (a) < 2147483647) && ((b) > -2147483648 && (b) < 2147483647) && ((c) > -2147483648 && (c) < 2147483647);
    ensures \result == true <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    if (a < b)
    {
        //@ assert ((b) > -2147483648 && (b) < 2147483647);
        //@ assert ((c) > -2147483648 && (c) < 2147483647);
        //@ assert b - a >= 0;

        if (b < c)
        {
            //@ assert ((a) < (b) && (b) < (c));
            result = true;
        }
        else
        {
            //@ assert !((a) < (b) && (b) < (c));
            result = false;
        }
    }
    else
    {
        //@ assert !((a) < (b) && (b) < (c));
        result = false;
    }

    return result;
}
