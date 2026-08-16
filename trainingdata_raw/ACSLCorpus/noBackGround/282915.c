#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (a) != (c)) ==> \result == c;
    ensures ((a) == (c) && (a) != (b)) ==> \result == b;
    ensures ((b) == (c) && (a) != (b)) ==> \result == a;
*/
long func(long a, long b, long c)
{
    long ans;

    if (a == b)
    {
        ans = c;
        //@ assert ((a) == (b) && (a) != (c)) ==> ans == c;
    }
    else if (a == c)
    {
        ans = b;
        //@ assert ((a) == (c) && (a) != (b)) ==> ans == b;
    }
    else
    {
        ans = a;
        //@ assert ((b) == (c) && (a) != (b)) ==> ans == a;
    }

    return ans;
}
