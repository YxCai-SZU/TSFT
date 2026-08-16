#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) / 2 + (n) % 2);
    assigns \nothing;
*/
int func(int n)
{
    int half = 0;
    int temp_n = n;
    bool is_even = true;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant half <= n / 2;
        loop invariant temp_n == n - 2 * half;
        loop assigns half, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        half += 1;
        temp_n -= 2;
    }

    if (temp_n == 1)
    {
        is_even = false;
    }

    if (is_even)
    {
        //@ assert half == n / 2;
        return half;
    }
    else
    {
        //@ assert half + 1 == n / 2 + n % 2;
        return half + 1;
    }
}
