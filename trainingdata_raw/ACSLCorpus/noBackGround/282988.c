#include <stdint.h>

/*@
    requires ((a) <= 100 && (b) <= 100 && (c) <= 100 && (k) <= (a) + (b) + (c));
    ensures \result >= -1 * (int)c;
    ensures \result <= 1 * (int)a;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    uint32_t a_cnt;
    uint32_t k_cnt;
    uint32_t b_cnt;
    uint32_t c_cnt;
    int32_t ans;
    
    //@ assert a <= 100 && b <= 100 && c <= 100 && k <= a + b + c;
    
    a_cnt = (a < k) ? a : k;
    //@ assert k >= a_cnt;
    
    k_cnt = k - a_cnt;
    b_cnt = (b > k_cnt) ? k_cnt : b;
    k_cnt = k_cnt - b_cnt;
    c_cnt = (c > k_cnt) ? k_cnt : c;
    
    ans = (int32_t)a_cnt - (int32_t)c_cnt;
    
    //@ assert ans >= -1 * (int)c;
    //@ assert ans <= 1 * (int)a;
    
    return ans;
}
