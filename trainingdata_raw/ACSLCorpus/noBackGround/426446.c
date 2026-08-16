#include <limits.h>

/*@
    requires (3 <= (a) && (a) <= 20);
    requires (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert (3 <= (a) && (a) <= 20);
    //@ assert (3 <= (b) && (b) <= 20);

    if (a >= b + 1)
    {
        //@ assert 2 * a - 1 >= 2;
        //@ assert 2 * a - 1 == a + b || 2 * a - 1 == 2 * a - 1 || 2 * a - 1 == 2 * b - 1;
        result = a * 2 - 1;
    }
    else if (b >= a + 1)
    {
        //@ assert 2 * b - 1 >= 2;
        //@ assert 2 * b - 1 == a + b || 2 * b - 1 == 2 * a - 1 || 2 * b - 1 == 2 * b - 1;
        result = b * 2 - 1;
    }
    else
    {
        //@ assert a + b >= 2;
        //@ assert a + b == a + b || a + b == 2 * a - 1 || a + b == 2 * b - 1;
        result = a + b;
    }

    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 2;
    return result;
}
