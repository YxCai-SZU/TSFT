#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (k <= ((n) / 2 + (n) % 2));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    unsigned int ans = 0;
    unsigned int temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= ans <= n / 2;
        loop invariant temp_n + 2 * ans == n;
        loop assigns temp_n, ans;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        ans += 1;
    }

    if (temp_n == 1)
    {
        //@ assert temp_n == 1;
        ans += 1;
    }

    //@ assert ans == ((n) / 2 + (n) % 2);
    return k <= ans;
}
