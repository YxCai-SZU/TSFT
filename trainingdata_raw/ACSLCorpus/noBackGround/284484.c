#include <stdint.h>

/*@
    requires A >= 0 && B >= 0 && C >= 0;
    requires 1 <= K <= A + B + C;
    ensures \result <= K;
    ensures \result >= 0;
*/
int32_t func(int32_t A, int32_t B, int32_t C, int32_t K)
{
    int32_t ans;
    int32_t rst;
    
    ans = 0;
    rst = K;
    
    //@ assert ((ans) >= 0);
    //@ assert (1 <= (rst) <= (A + B + C));
    
    ans += (A < rst) ? A : rst;
    //@ assert ans <= K;
    
    rst -= (A < rst) ? A : rst;
    //@ assert rst >= 0;
    
    rst -= (B < rst) ? B : rst;
    //@ assert rst >= 0;
    
    ans -= (rst < 0) ? -rst : 0;
    //@ assert ans >= 0;
    
    return ans;
}
