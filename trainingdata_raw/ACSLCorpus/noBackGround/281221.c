#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures ((\result) == true <==> ((n) % 100 <= 5 * ((n) / 100) && (n) % 100 >= ((n) / 100)));
    assigns \nothing;
 */
bool func(unsigned int n)
{
    unsigned int count = 0;
    unsigned int temp_n = n;
    unsigned int div = 0;
    unsigned int modu = 0;

    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 100;
        loop invariant temp_n == n - 100 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
     */
    while (temp_n >= 100)
    {
        temp_n -= 100;
        count += 1;
    }

    div = count;
    modu = temp_n;

    //@ assert div == n / 100;
    //@ assert modu == n % 100;

    if (modu <= 5 * div && modu >= div)
    {
        return true;
    }
    else
    {
        return false;
    }
}
