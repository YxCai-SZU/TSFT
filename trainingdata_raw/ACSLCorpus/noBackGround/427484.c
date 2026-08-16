#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (n / 2) - (n / 2) / 2 - 1;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t temp_n;
    int64_t count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n + 2 * count == n;
        loop invariant (1 <= (n) <= 1000000);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    result = count;
    
    count = 0;
    temp_n = result;
    
    /*@
        loop invariant 0 <= temp_n <= result;
        loop invariant temp_n + 2 * count == result;
        loop invariant (1 <= (n) <= 1000000);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    //@ assert count == result / 2;
    result -= count + 1;
    
    //@ assert result == (n / 2) - (n / 2) / 2 - 1;
    return result;
}
