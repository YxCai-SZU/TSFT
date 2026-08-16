#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
    ensures \result == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    if (a == b && b == c)
    {
        ans = 1;
        //@ assert ((a) == (b) && (b) == (c));
    }
    else if (a != b && b != c && a != c)
    {
        ans = 3;
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
    }
    else
    {
        ans = 2;
        //@ assert (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
    }

    //@ assert ans == 1 || ans == 2 || ans == 3;
    return ans;
}
