#include <stdbool.h>

/*@ predicate is_nonnegative(integer x) = x >= 0; */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a - b * 2 || \result == 0;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int c;
    int res;

    c = a - b * 2;
    
    if (c < 0)
    {
        //@ assert c < 0;
        res = 0;
    }
    else
    {
        //@ assert c >= 0;
        res = c;
    }

    //@ assert res == a - b * 2 || res == 0;
    //@ assert is_nonnegative(res);
    return res;
}
