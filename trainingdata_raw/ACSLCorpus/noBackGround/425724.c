#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(long n)
{
    long temp;
    long count;
    bool is_odd;
    int result;

    temp = n;
    count = 0;
    is_odd = false;

    /*@
        loop invariant (1 <= (n) && (n) <= 100000);
        loop invariant temp >= 0;
        loop invariant temp == n - 2 * count;
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }

    if (temp == 1)
    {
        is_odd = true;
    }

    //@ assert count >= 0;

    if (((count + (is_odd ? 1 : 0)) & 1) == 1)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
