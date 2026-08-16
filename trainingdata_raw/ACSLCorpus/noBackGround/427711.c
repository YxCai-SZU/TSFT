#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans = 0;
    size_t temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= ans <= ((n) / 3);
        loop invariant temp_n == n - 3 * ans;
        loop assigns ans, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        ans += 1;
        //@ assert temp_n == n - 3 * ans;
    }

    //@ assert ans == ((n) / 3);
    return ans;
}

int main(void)
{
    return 0;
}
