#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == n/2 + 1 || \result == n/2;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t temp_n;
    int64_t count;
    int64_t remainder;

    if (n > 0)
    {
        result = 0;
        temp_n = n;
        count = 0;

        /*@
            loop invariant 1 <= n <= 1000000000;
            loop invariant 0 <= temp_n <= n;
            loop invariant temp_n == n - 2 * count;
            loop invariant 0 <= count <= n/2;
            loop assigns temp_n, count;
        */
        while (temp_n > 1)
        {
            //@ assert temp_n > 1;
            temp_n -= 2;
            count += 1;
        }

        result = count;
        remainder = n % 2;

        if (remainder == 1)
        {
            result += 1;
        }

        return result;
    }
    else
    {
        return 0;
    }
}
