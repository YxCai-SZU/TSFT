#include <limits.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (m) % 2 == 0);
    ensures \result == n + (m / 2);
    assigns \nothing;
*/
int func(int n, int m)
{
    int half_m;
    int count;
    int temp_m;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= 100 &&         (m) % 2 == 0);
    
    if (m >= 0)
    {
        count = 0;
        temp_m = m;
        /*@
            loop invariant 0 <= temp_m <= m;
            loop invariant 0 <= count <= m / 2;
            loop invariant temp_m == m - 2 * count;
            loop assigns temp_m, count;
            loop variant temp_m;
        */
        while (temp_m >= 2)
        {
            temp_m -= 2;
            count += 1;
        }
        half_m = count;
    }
    else
    {
        count = 0;
        temp_m = m;
        /*@
            loop invariant m <= temp_m <= 0;
            loop invariant 0 <= count <= m / 2;
            loop invariant temp_m == m - 2 * count;
            loop assigns temp_m, count;
            loop variant -temp_m;
        */
        while (temp_m <= -2)
        {
            temp_m += 2;
            count -= 1;
        }
        half_m = count;
    }
    
    //@ assert half_m == m / 2;
    
    int ans = n + half_m;
    
    //@ assert ans == n + (m / 2);
    
    return ans;
}
