#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) == (c)) ==> \result == a;
    ensures ((a) != (b) || (b) != (c)) ==> \result == b;
*/
int func(int a, int b, int c)
{
    int ans;

    if (a == b)
    {
        ans = a;
    }
    else
    {
        ans = b;
    }

    //@ assert ((a) == (b) && (b) == (c)) ==> ans == a;
    //@ assert ((a) != (b) || (b) != (c)) ==> ans == b;

    return ans;
}
