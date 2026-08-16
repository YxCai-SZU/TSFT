#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (c) != (a) && (c) != (b)) ||
        ((b) == (c) && (a) != (b) && (a) != (c)) ||
        ((c) == (a) && (b) != (c) && (b) != (a)));
    assigns \nothing;
 */
bool func(long a, long b, long c)
{
    long counter = 0;

    //@ assert 0 <= counter <= 3;

    if (a == b)
    {
        counter += 1;
        //@ assert 0 <= counter <= 3;
    }

    if (b == c)
    {
        counter += 1;
        //@ assert 0 <= counter <= 3;
    }

    if (c == a)
    {
        counter += 1;
        //@ assert 0 <= counter <= 3;
    }

    //@ assert 0 <= counter <= 3;
    return counter == 1;
}
