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
    int half_m = 0;
    int temp_m = m;

    /*@
        loop invariant 0 <= temp_m <= m;
        loop invariant half_m >= 0;
        loop invariant temp_m == m - 2 * half_m;
        loop invariant half_m <= ((m) / 2);
        loop assigns temp_m, half_m;
        loop variant temp_m;
    */
    while (temp_m >= 2)
    {
        //@ assert temp_m >= 2;
        temp_m -= 2;
        half_m += 1;
    }

    //@ assert half_m == ((m) / 2);
    int result = n + half_m;
    return result;
}
