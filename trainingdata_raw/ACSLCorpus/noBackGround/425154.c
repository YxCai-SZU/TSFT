#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == n / 500 * 1000 + (n % 500 / 5) * 5;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result = 0;
    size_t temp_n = n;
    size_t count_500 = 0;
    size_t count_5 = 0;
    
    //@ assert (1 <= (n) && (n) <= 100000);
    
    /*@
        loop invariant 0 <= count_500 <= n / 500;
        loop invariant temp_n == n - 500 * count_500;
        loop invariant temp_n >= 0;
        loop assigns temp_n, count_500;
        loop variant temp_n;
    */
    while (temp_n >= 500)
    {
        //@ assert temp_n >= 500;
        temp_n -= 500;
        count_500 += 1;
        //@ assert temp_n == n - 500 * count_500;
    }
    
    //@ assert temp_n == n % 500;
    
    /*@
        loop invariant 0 <= count_5 <= (n % 500) / 5;
        loop invariant temp_n == (n % 500) - 5 * count_5;
        loop invariant temp_n >= 0;
        loop assigns temp_n, count_5;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert temp_n >= 5;
        temp_n -= 5;
        count_5 += 1;
        //@ assert temp_n == (n % 500) - 5 * count_5;
    }
    
    result = count_500 * 1000 + count_5 * 5;
    
    //@ assert result == n / 500 * 1000 + (n % 500 / 5) * 5;
    
    return result;
}
