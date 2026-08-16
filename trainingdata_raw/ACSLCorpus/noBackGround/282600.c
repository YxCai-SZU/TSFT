#include <stdint.h>

/*@
    requires 1 <= N <= 1000;
    ensures \result >= 0;
    ensures \result <= N / 3;
    ensures \result <= N / 3 + 1;
    assigns \nothing;
*/
int64_t func(int64_t N)
{
    int64_t ans = 0;
    int64_t temp = N;

    /*@
        loop invariant 0 <= ans;
        loop invariant ans <= N / 3;
        loop invariant ans <= N / 3 + 1;
        loop invariant temp >= 0;
        loop invariant temp == N - 3 * ans;
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        //@ assert temp >= 3;
        temp -= 3;
        ans += 1;
        //@ assert temp == N - 3 * ans;
    }

    //@ assert (0 <= (ans) && (ans) <= (N) / 3 && (ans) <= (N) / 3 + 1);
    return ans;
}
