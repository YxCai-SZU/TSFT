#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - ((((n)) / 15) * 200));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    int64_t temp_n;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 15;
        loop invariant count >= 0;
        loop invariant result == n * 800;
        loop invariant temp_n == n - count * 15;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - count * 15;
    }
    
    result = result - count * 200;
    //@ assert result == n * 800 - count * 200;
    return result;
}
