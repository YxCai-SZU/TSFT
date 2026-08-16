#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) == (c)) ==> \result == 3;
    ensures (((a) == (b) && (b) != (c)) ||
        ((a) != (b) && (b) == (c)) ||
        ((a) == (c) && (b) != (c))) ==> \result == 2;
    ensures ((a) != (b) && (b) != (c) && (a) != (c)) ==> \result == 0;
*/
int func(int a, int b, int c)
{
    int result = 0;

    if (a == b && b == c)
    {
        result = 3;
    }
    else if (a == b || b == c || a == c)
    {
        result = 2;
    }
    else
    {
        result = 0;
    }

    //@ assert ((a) == (b) && (b) == (c)) ==> result == 3;
    //@ assert (((a) == (b) && (b) != (c)) ||         ((a) != (b) && (b) == (c)) ||         ((a) == (c) && (b) != (c))) ==> result == 2;
    //@ assert ((a) != (b) && (b) != (c) && (a) != (c)) ==> result == 0;

    return result;
}
