#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int ans = 0;
    int temp_n = n;

    /*@
        loop invariant (0 <= (temp_n) <= (n) &&
        0 <= (ans) <= (((n)) / 3) &&
        (temp_n) == (n) - 3 * (ans));
        loop assigns temp_n, ans;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n == n - 3 * ans;
        temp_n -= 3;
        ans += 1;
    }

    //@ assert ans == ((n) / 3);
    return ans;
}
