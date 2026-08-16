#include <limits.h>

/*@
    predicate valid_range(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    predicate ans_in_range(integer ans) =
        ans == 1000000000 || (0 <= ans && ans < 1000000000);
*/

/*@
    requires valid_range(X, Y);
    ensures ans_in_range(\result);
    assigns \nothing;
*/
int func(int X, int Y)
{
    int ans = 1000000000;
    int i = 1;
    int j;

    //@ ghost int old_i, old_j;

    /*@
        loop invariant 1 <= i <= X + 1;
        loop invariant valid_range(X, Y);
        loop invariant ans_in_range(ans);
        loop assigns i, j, ans;
        loop variant X - i + 1;
    */
    while (i <= X)
    {
        j = 1;

        /*@
            loop invariant 1 <= j <= Y + 1;
            loop invariant valid_range(X, Y);
            loop invariant 1 <= i <= X;
            loop invariant ans_in_range(ans);
            loop assigns j, ans;
            loop variant Y - j + 1;
        */
        while (j <= Y)
        {
            int k = (i < j) ? i : j;
            int l = X - i;
            int m = Y - j;
            int n = (l < m) ? l : m;
            int price;

            //@ assert i * 2 <= 410;
            //@ assert j * 2 <= 410;
            //@ assert k * 4 <= 820;
            //@ assert n * 4 <= 820;
            //@ assert i * 2 + j * 2 + k * 4 + n * 4 <= 1000000000;

            price = i * 2 + j * 2 + k * 4 + n * 4;
            ans = (ans < price) ? ans : price;

            j++;
        }

        i++;
    }

    return ans;
}
