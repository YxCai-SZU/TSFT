#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 800 * n - 200 * (n / 15);
*/
int32_t func(int32_t n)
{
    int32_t result;
    int32_t count;
    int32_t temp_n;
    
    result = 800 * n;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= count && count <= n / 15;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15) {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - 15 * count;
    }
    
    result = result - 200 * count;
    //@ assert result == 800 * n - 200 * count;
    return result;
}
