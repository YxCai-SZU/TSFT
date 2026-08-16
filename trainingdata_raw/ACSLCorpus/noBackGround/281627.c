#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
*/
int func(int a, int p)
{
    // Variable declarations at scope top
    int sum;
    int ans;
    bool is_negative;

    //@ assert 0 <= a * 3 <= 300;
    //@ assert 0 <= a * 3 + p <= 400;

    sum = a * 3 + p;
    ans = 0;
    is_negative = false;

    if (sum < 0)
    {
        sum = -sum;
        is_negative = true;
    }

    /*@
        loop invariant 0 <= sum <= 400;
        loop invariant 0 <= ans <= 200;
        loop invariant sum >= 0;
        loop invariant ans >= 0;
        loop invariant sum <= a * 3 + p;
        loop invariant ans <= (a * 3 + p - sum) / 2;
        loop assigns sum, ans;
        loop variant sum;
    */
    while (sum >= 2)
    {
        sum -= 2;
        ans += 1;
    }

    if (is_negative)
    {
        ans = -ans;
    }

    return ans;
}
