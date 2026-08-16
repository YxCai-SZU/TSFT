#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= x <= 10000;
    requires \valid(lengths + (0 .. n-1));
    requires (\forall integer j; 0 <= j < (n) ==> 1 <= (lengths)[j] <= 100);
    ensures \result >= 1;
    ensures \result <= n + 1;
*/
int func(int n, int x, int *lengths)
{
    int ans;
    int d;
    int i;

    ans = 1;
    d = 0;
    i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        (\forall integer j; 0 <= j < ((n)) ==> 1 <= ((lengths))[j] <= 100) &&
        0 <= (d) <= (x) &&
        1 <= (ans) <= (i) + 1);
        loop assigns i, d, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        int l;

        l = lengths[i];
        d = d + l;

        //@ assert d >= 0;

        if (d > x)
        {
            break;
        }

        ans = ans + 1;
        i = i + 1;

        //@ assert ans >= 1;
    }

    //@ assert ans >= 1;
    //@ assert ans <= n + 1;

    return ans;
}
