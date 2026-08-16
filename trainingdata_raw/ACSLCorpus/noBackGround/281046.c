#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t ans;
    uint64_t temp_N;
    
    ans = 0;
    temp_N = N;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= ans <= ((N) / 3);
        loop invariant N == temp_N + 3 * ans;
        loop invariant (1 <= (N) <= 1000);
        loop assigns ans, temp_N;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        //@ assert temp_N >= 3;
        temp_N = temp_N - 3;
        ans = ans + 1;
    }
    
    //@ assert temp_N >= 0;
    //@ assert N == temp_N + 3 * ans;
    //@ assert 0 <= 3 * ans <= 3 * ((N) / 3);
    
    return ans;
}
