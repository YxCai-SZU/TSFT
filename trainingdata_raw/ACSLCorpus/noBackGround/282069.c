#include <limits.h>
#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100000 &&
        1 <= (k) <= (n) - 1 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= INT_MAX;
*/
int func(int n, int k, int *a)
{
    int ans = INT_MAX;
    int i = k;

    //@ assert 0 <= ans <= INT_MAX;

    /*@
        loop invariant k <= i <= n;
        loop invariant 0 <= ans <= INT_MAX;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        int tmp = 0;
        int j = 0;

        /*@
            loop invariant 0 <= j <= i;
            loop invariant 0 <= tmp <= j;
            loop assigns j, tmp;
            loop variant i - j;
        */
        while (j < i)
        {
            tmp += (a[j] & 1) == 1 ? 1 : 0;
            j++;
        }

        ans = ans < tmp ? ans : tmp;
        i++;
    }

    return ans;
}
