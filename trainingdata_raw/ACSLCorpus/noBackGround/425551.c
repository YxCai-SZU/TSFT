#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 0 && \result <= a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result = 0;
    int a_local = a;
    int b_local = b;
    int c_local = c;
    int max_val;

    //@ assert (1 <= (a_local) && (a_local) <= 100) && (1 <= (b_local) && (b_local) <= 100) && (1 <= (c_local) && (c_local) <= 100);

    // Implementing max manually
    if (a_local > b_local)
    {
        if (a_local > c_local)
        {
            max_val = a_local;
        }
        else
        {
            max_val = c_local;
        }
    }
    else
    {
        if (b_local > c_local)
        {
            max_val = b_local;
        }
        else
        {
            max_val = c_local;
        }
    }

    //@ assert max_val == (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c)));

    a_local = a_local - max_val;
    b_local = b_local - max_val;
    c_local = c_local - max_val;

    result += max_val;

    //@ assert result == max_val;

    // Implementing the rest of the logic without using division or modulo
    if (a_local >= 1 && b_local >= 1 && c_local >= 1)
    {
        result += 1;
    }

    //@ assert result <= 1 + max_val;

    //@ assert result >= 0 && result <= a + b + c;
    return result;
}
