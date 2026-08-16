#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t sum;
    uint64_t result;
    uint64_t count;
    uint64_t temp_sum;
    
    //@ assert n >= 1 && n <= 100;
    
    sum = n * (n + 1);
    result = 0;
    count = 0;
    temp_sum = sum;
    
    //@ assert sum == n * (n + 1);
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant sum == n * (n + 1);
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant count <= 50 * 101;
        loop assigns count, temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum == sum - 2 * count;
    }
    
    result = count;
    //@ assert result == ((n) * ((n) + 1) / 2);
    return result;
}
