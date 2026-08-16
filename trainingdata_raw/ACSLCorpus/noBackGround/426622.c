#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t n_div_15;
    int64_t temp_n;
    
    n_div_15 = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant n_div_15 >= 0;
        loop invariant temp_n == n - 15 * n_div_15;
        loop assigns temp_n, n_div_15;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        n_div_15 += 1;
    }
    
    //@ assert n_div_15 * 15 + temp_n == n;
    
    return n * 800 - n_div_15 * 200;
}
