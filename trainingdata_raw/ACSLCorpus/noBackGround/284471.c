#include <stdbool.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
    ensures \result == ((A) * 3 + (P)) / 2;
*/
int func(int A, int P)
{
    int sum;
    int ans;
    bool is_even;

    sum = A * 3 + P;
    ans = 0;
    is_even = true;

    /*@
        loop invariant 0 <= sum <= ((A) * 3 + (P));
        loop invariant 0 <= ans <= ((A) * 3 + (P)) / 2;
        loop invariant sum == ((A) * 3 + (P)) - 2 * ans;
        loop invariant (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
        loop assigns sum, ans;
    */
    while (sum >= 2)
    {
        //@ assert sum >= 2;
        sum -= 2;
        ans += 1;
    }

    if (sum == 1)
    {
        is_even = false;
    }

    if (is_even)
    {
        //@ assert ans == ((A) * 3 + (P)) / 2;
        return ans;
    }
    else
    {
        //@ assert ans == ((A) * 3 + (P)) / 2;
        return ans;
    }
}
