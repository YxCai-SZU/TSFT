#include <stdint.h>
#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1);
    requires ((k) <= (a) + (b) + (c) && (a) + (b) + (c) <= INT64_MAX);
    ensures \result <= a + b + c;
    ensures \result >= k - b - c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k) {
    int64_t min_a_k;
    int64_t remain_k;
    int64_t min_remain_b;
    int64_t neg_res;
    int64_t result;
    
    //@ assert a >= 0 && b >= 0 && c >= 0 && k >= 1;
    
    min_a_k = a < k ? a : k;
    //@ assert min_a_k <= a;
    
    remain_k = k - min_a_k;
    //@ assert remain_k >= 0;
    
    min_remain_b = remain_k < b ? remain_k : b;
    //@ assert min_remain_b <= b;
    
    neg_res = min_remain_b - remain_k;
    //@ assert neg_res <= 0;
    
    result = min_a_k - neg_res;
    //@ assert result <= a + b + c;
    
    return result;
}
