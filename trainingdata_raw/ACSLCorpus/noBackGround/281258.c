#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 800 * n - 200 * (n / 15);
*/
int32_t func(uint32_t n)
{
    int32_t ans;
    int32_t temp;
    int32_t count;
    
    //@ assert (1 <= (n) && (n) <= 100);
    ans = 800 * (int32_t)n;
    temp = (int32_t)n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp <= (int32_t)n;
        loop invariant 0 <= count <= (int32_t)n / 15;
        loop invariant temp == (int32_t)n - 15 * count;
        loop invariant ans == 800 * (int32_t)n;
        loop assigns temp, count;
    */
    while (temp >= 15)
    {
        int32_t old_temp = temp;
        //@ assert temp >= 15;
        temp -= 15;
        count += 1;
        //@ assert temp == old_temp - 15;
    }
    
    //@ assert count == (int32_t)n / 15;
    ans -= 200 * count;
    
    //@ assert ans >= 800 * (int32_t)n - 200 * ((int32_t)n / 15);
    return ans;
}
