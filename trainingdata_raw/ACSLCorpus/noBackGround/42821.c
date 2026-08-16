#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == (a == 5 || b == 5 || c == 5);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool five = false;

    //@ assert a >= 1 && a <= 10;
    //@ assert b >= 1 && b <= 10;
    //@ assert c >= 1 && c <= 10;

    if (a == 5)
    {
        five = true;
        //@ assert ((a) == 5);
    }

    if (b == 5)
    {
        five = true;
        //@ assert ((b) == 5);
    }

    if (c == 5)
    {
        five = true;
        //@ assert ((c) == 5);
    }

    //@ assert five == (a == 5 || b == 5 || c == 5);
    return five;
}
