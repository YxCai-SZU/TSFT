#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int b_minus_a;
    int c_minus_b;
    int b_minus_a_new;
    int c_minus_b_new;
    bool result;

    b_minus_a = b - a;
    c_minus_b = c - b;

    if (b_minus_a < 0)
    {
        b_minus_a_new = -b_minus_a;
        if (c_minus_b < 0)
        {
            c_minus_b_new = -c_minus_b;
            //@ assert b_minus_a_new == c_minus_b_new ==> ((b) - (a) == (c) - (b));
            result = (b_minus_a_new == c_minus_b_new);
            return result;
        }
        else
        {
            result = false;
            return result;
        }
    }
    else
    {
        if (c_minus_b < 0)
        {
            result = false;
            return result;
        }
        else
        {
            //@ assert b_minus_a == c_minus_b ==> ((b) - (a) == (c) - (b));
            result = (b_minus_a == c_minus_b);
            return result;
        }
    }
}
