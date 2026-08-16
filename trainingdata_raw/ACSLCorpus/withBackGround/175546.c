#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    
    logic integer min(integer x, integer y) = (x < y) ? x : y;
    
    lemma cnt_non_negative:
        \forall integer a, b, c, k, cnt, rst, min_a, min_b, min_c;
        non_negative(a) && non_negative(b) && non_negative(c) && 
        k >= 1 && k <= a + b + c && k <= 2 * 9223372036854775807 / 3 &&
        min_a == min(a, k) && 
        rst == k - min_a &&
        min_b == min(b, rst) &&
        rst == k - min_a - min_b &&
        min_c == min(c, rst) &&
        rst == k - min_a - min_b - min_c &&
        cnt == min_a - rst ==>
        non_negative(cnt);
*/

/*@
    requires 0 <= a && 0 <= b && 0 <= c;
    requires 1 <= k && k <= a + b + c;
    requires k <= 2 * 9223372036854775807 / 3;
    ensures \result <= k && \result >= 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k) {
    int64_t cnt;
    int64_t rst;
    int64_t min_val_a;
    int64_t min_val_b;
    int64_t min_val_c;
    
    cnt = 0;
    rst = k;
    
    //@ assert non_negative(cnt) && non_negative(rst);
    
    min_val_a = (a < rst) ? a : rst;
    rst = rst - min_val_a;
    cnt = cnt + min_val_a;
    
    //@ assert non_negative(min_val_a) && non_negative(rst) && non_negative(cnt);
    
    min_val_b = (b < rst) ? b : rst;
    rst = rst - min_val_b;
    
    //@ assert non_negative(min_val_b) && non_negative(rst);
    
    min_val_c = (c < rst) ? c : rst;
    rst = rst - min_val_c;
    cnt = cnt - rst;
    
    //@ assert cnt >= 0;
    
    return cnt;
}
