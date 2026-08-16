#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures ((\result) == (((a)) + ((b)) + 10 * ((c))) ||
        (\result) == (((a)) + ((c)) + 10 * ((b))) ||
        (\result) == (((b)) + ((c)) + 10 * ((a))));
*/
int func(int a, int b, int c)
{
    int max;
    int result;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);

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

    //@ assert max == a || max == b || max == c;
    //@ assert (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c))) == max;

    result = a + b + c;
    //@ assert result == a + b + c;

    result += max * 9;
    //@ assert result == a + b + c + max * 9;

    //@ assert ((result) == (((a)) + ((b)) + 10 * ((c))) ||         (result) == (((a)) + ((c)) + 10 * ((b))) ||         (result) == (((b)) + ((c)) + 10 * ((a))));

    return result;
}
