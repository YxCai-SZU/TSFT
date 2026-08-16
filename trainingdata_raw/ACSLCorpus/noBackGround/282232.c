#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (1000 * (((n) / 1000) + 1) - (n));
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;

    result = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= temp_n;
        loop invariant 0 <= count;
        loop invariant n == temp_n + 1000 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        count += 1;
    }

    result = 1000 * (count + 1) - n;

    //@ assert count == n / 1000;
    //@ assert temp_n == n % 1000;
    //@ assert result == 1000 * (count + 1) - n;
    //@ assert result == (1000 * (((n) / 1000) + 1) - (n));

    return result;
}
