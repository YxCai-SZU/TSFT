#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - 200 * ((n) / 15));
*/
int64_t func(uint64_t n)
{
    int64_t result;
    uint64_t temp_n;
    uint64_t count;
    
    //@ assert (1 <= (n) <= 100);
    result = (int64_t)n * 800;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 15;
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - 15 * count;
    }
    
    //@ assert temp_n == n - 15 * count;
    result = result - (int64_t)count * 200;
    
    //@ assert result == ((n) * 800 - 200 * ((n) / 15));
    return result;
}
