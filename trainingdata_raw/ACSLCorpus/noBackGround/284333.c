#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) == (c)) ==> \result == 3;
    ensures (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((a) == (c) && (c) != (b))) ==> \result == 2;
    ensures ((a) != (b) && (b) != (c) && (a) != (c)) ==> \result == 1;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100;

    if (a == b && b == c)
    {
        //@ assert ((a) == (b) && (b) == (c));
        result = 3;
    }
    else if (a == b || b == c || a == c)
    {
        //@ assert a == b || b == c || a == c;
        //@ assert (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((a) == (c) && (c) != (b)));
        result = 2;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
        result = 1;
    }

    return result;
}
