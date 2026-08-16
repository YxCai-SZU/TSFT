#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_k(integer x, integer k) = 0 <= x && x <= k;
*/

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires k >= 1 && k <= a + b + c && k <= 2000000000;
    ensures \result >= 0;
    ensures \result <= k;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans;
    int32_t rst;
    
    ans = 0;
    rst = k;
    
    //@ assert non_negative(ans);
    //@ assert within_k(rst, k);
    
    ans += (a < rst) ? a : rst;
    //@ assert non_negative(ans);
    
    rst -= (a < rst) ? a : rst;
    //@ assert non_negative(rst);
    
    rst -= (b < rst) ? b : rst;
    //@ assert non_negative(rst);
    
    ans -= (rst < 0) ? -rst : 0;
    //@ assert non_negative(ans);
    
    //@ assert ans <= k;
    
    return ans;
}
