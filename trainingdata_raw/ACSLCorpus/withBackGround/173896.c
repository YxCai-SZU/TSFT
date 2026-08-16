#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer min(integer x, integer y) =
        x < y ? x : y;

    lemma cnt_bound:
        \forall integer a, b, c, k, cnt, k_flag, min_a, min_b, min_c;
        valid_params(a, b, c, k) ==>
        min_a == min(a, k) ==>
        min_b == min(b, k - min_a) ==>
        min_c == min(c, k - min_a - min_b) ==>
        cnt == min_a - (k - min_a - min_b - min_c) ==>
        cnt <= a + b + c;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t cnt;
    int32_t k_flag;
    int32_t min_a;
    int32_t min_b;
    int32_t min_c;

    cnt = 0;
    k_flag = k;

    //@ assert valid_params(a, b, c, k);
    
    min_a = a < k_flag ? a : k_flag;
    cnt += min_a;
    k_flag -= min_a;
    
    //@ assert cnt == min_a && k_flag == k - min_a;
    
    min_b = b < k_flag ? b : k_flag;
    k_flag -= min_b;
    
    //@ assert k_flag == k - min_a - min_b;
    
    min_c = c < k_flag ? c : k_flag;
    k_flag -= min_c;
    
    //@ assert k_flag == k - min_a - min_b - min_c;
    
    cnt -= k_flag;
    
    //@ assert cnt == min_a - (k - min_a - min_b - min_c);
    //@ assert cnt <= a + b + c;
    
    return cnt;
}
