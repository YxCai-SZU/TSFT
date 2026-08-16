#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result >= 0;
    ensures \result * 3 <= n;
    ensures n < (\result + 1) * 3;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t ans;
    int64_t temp_n;
    int64_t count;

    ans = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n <= 1000;
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 3;
        loop invariant temp_n == n - 3 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n = temp_n - 3;
        count = count + 1;
        //@ assert temp_n == n - 3 * count;
    }

    ans = count;
    //@ assert ans >= 0;
    //@ assert ans * 3 <= n;
    //@ assert n < (ans + 1) * 3;
    return ans;
}
