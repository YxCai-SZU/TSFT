#include <stdbool.h>
#include <limits.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
int func(int a, int p)
{
    int sum;
    int ans;
    bool is_even;

    sum = a * 3 + p;
    ans = 0;
    is_even = true;

    /*@
        loop invariant sum >= 0;
        loop invariant sum <= ((a) * 3 + (p));
        loop invariant ans >= 0;
        loop invariant ans <= ((a) * 3 + (p)) / 2;
        loop invariant sum + 2 * ans == ((a) * 3 + (p));
        loop invariant (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
        loop assigns sum, ans;
    */
    while (sum >= 2)
    {
        sum -= 2;
        ans += 1;
    }

    if (sum == 1)
    {
        is_even = false;
    }

    if (is_even)
    {
        //@ assert ans >= 0;
        return ans;
    }
    else
    {
        //@ assert ans < INT_MAX - 1;
        return ans + 1;
    }
}
