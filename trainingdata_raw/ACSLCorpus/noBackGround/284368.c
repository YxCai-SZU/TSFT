#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result >= 0;
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
int64_t func(int64_t N)
{
    int64_t ans;
    int64_t temp_N;
    int64_t count;

    ans = 0;
    temp_N = N;
    count = 0;

    /*@
        loop invariant 1 <= N <= 1000;
        loop invariant temp_N >= 0;
        loop invariant N == temp_N + 3 * count;
        loop invariant count >= 0;
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        //@ assert temp_N >= 3;
        temp_N = temp_N - 3;
        count = count + 1;
        //@ assert N == temp_N + 3 * count;
    }

    ans = count;
    //@ assert ans >= 0;
    //@ assert ans == ((N) / 3);
    return ans;
}
