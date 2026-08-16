#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures (\result == 1) ==> ((a) == (b) && (b) == (c));
    ensures (\result == 2) ==> (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
    ensures (\result == 3) ==> ((a) != (b) && (b) != (c) && (a) != (c));
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int result;

    if (a == b && b == c)
    {
        //@ assert ((a) == (b) && (b) == (c));
        result = 1;
    }
    else if (a == b || b == c || a == c)
    {
        //@ assert (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
        result = 2;
    }
    else
    {
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
        result = 3;
    }

    return result;
}
