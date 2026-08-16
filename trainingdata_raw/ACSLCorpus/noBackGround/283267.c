#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - 200 * (((n)) / 15));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t ans;
    int64_t cnt;
    int64_t temp_n;
    
    ans = n * 800;
    cnt = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= cnt <= ((n) / 15);
        loop invariant temp_n == n - 15 * cnt;
        loop invariant (1 <= (n) <= 100);
        loop assigns cnt, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        cnt = cnt + 1;
        temp_n = temp_n - 15;
    }
    
    //@ assert cnt == ((n) / 15);
    ans = ans - 200 * cnt;
    //@ assert ans == ((n) * 800 - 200 * (((n)) / 15));
    return ans;
}
