#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert ((a) + (b)) <= 200;
    //@ assert ((a) + (c)) <= 200;
    //@ assert ((b) + (c)) <= 200;

    if (a + b == c)
    {
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return true;
    }
    else if (a + c == b)
    {
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return true;
    }
    else if (b + c == a)
    {
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return true;
    }
    else
    {
        return false;
    }
}
