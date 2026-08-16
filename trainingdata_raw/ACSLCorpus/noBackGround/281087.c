#include <stddef.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures \result == ((n) / 2 + (n) % 2);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    size_t temp_n;
    size_t count;

    ans = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop invariant (1 <= (n) <= 100000);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }

    //@ assert temp_n == 0 || temp_n == 1;
    
    if (temp_n == 1)
    {
        ans = count + 1;
    }
    else
    {
        ans = count;
    }

    //@ assert ans == ((n) / 2 + (n) % 2);
    return ans;
}
