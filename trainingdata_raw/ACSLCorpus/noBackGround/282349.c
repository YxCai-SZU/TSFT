#include <limits.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (m) % 2 == 0);
    ensures \result == n + ((m) / 2);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result = n;
    int temp_m = m;
    int quotient = 0;
    int remainder = 0;
    int abs_m = (temp_m < 0) ? -temp_m : temp_m;

    /*@
        loop invariant 0 <= abs_m <= 100;
        loop invariant quotient >= 0;
        loop invariant abs_m == temp_m - 2 * quotient;
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (m) % 2 == 0);
        loop assigns abs_m, quotient;
        loop variant abs_m;
    */
    while (abs_m >= 2)
    {
        abs_m -= 2;
        quotient += 1;
    }
    remainder = abs_m;

    if (temp_m < 0)
    {
        quotient = -quotient;
    }

    result += quotient;

    //@ assert quotient == ((m) / 2);
    //@ assert result == n + ((m) / 2);

    return result;
}
