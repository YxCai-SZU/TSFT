#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    ans = c - a + b;

    //@ assert -20 <= ans <= 40;

    /*@
        loop invariant ans == c - a + b;
        loop assigns \nothing;
    */
    while (0) { }

    if (ans > 0)
    {
        //@ assert ans >= 0 && ans <= c;
        return ans;
    }
    else
    {
        return 0;
    }
}
