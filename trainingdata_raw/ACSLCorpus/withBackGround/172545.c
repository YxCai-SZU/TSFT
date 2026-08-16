#include <stdbool.h>

/*@ predicate is_even(integer x) = (x % 2) == 0; */

/*@
    requires 3 <= a && a <= 20;
    requires 3 <= b && b <= 20;
    ensures \result == a * 2 || \result == b * 2 || 
            \result == a * 2 + 1 || \result == b * 2 + 1;
*/
int func(int a, int b)
{
    bool a_even;
    bool b_even;
    int result;

    a_even = (a & 1) == 0;
    b_even = (b & 1) == 0;

    if (a_even && b_even)
    {
        //@ assert a * 2 == a * 2 || a * 2 == b * 2 || a * 2 == a * 2 + 1 || a * 2 == b * 2 + 1;
        result = a * 2;
    }
    else if (a_even)
    {
        //@ assert a * 2 + 1 == a * 2 || a * 2 + 1 == b * 2 || a * 2 + 1 == a * 2 + 1 || a * 2 + 1 == b * 2 + 1;
        result = a * 2 + 1;
    }
    else if (b_even)
    {
        //@ assert b * 2 + 1 == a * 2 || b * 2 + 1 == b * 2 || b * 2 + 1 == a * 2 + 1 || b * 2 + 1 == b * 2 + 1;
        result = b * 2 + 1;
    }
    else
    {
        //@ assert b * 2 == a * 2 || b * 2 == b * 2 || b * 2 == a * 2 + 1 || b * 2 == b * 2 + 1;
        result = b * 2;
    }

    return result;
}
