#include <stdint.h>

/*@
    requires (0 <= (a) <= 10000 &&
        0 <= (b) <= 10000 &&
        0 <= (c) <= 10000 &&
        0 <= (d) <= 10000 &&
        1 <= (a) + (b) + (c) + (d));
    ensures \result <= a + b + c + d;
    ensures \result >= 0;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t min_val;
    uint64_t ans;
    uint64_t na;

    min_val = a;
    //@ assert min_val == a;
    
    if (b < min_val) {
        min_val = b;
    }
    //@ assert min_val <= a && min_val <= b;
    
    if (c < min_val) {
        min_val = c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    
    if (d < min_val) {
        min_val = d;
    }
    //@ assert min_val == (((a) <= (b) && (a) <= (c) && (a) <= (d)) ? (a) :         ((b) <= (a) && (b) <= (c) && (b) <= (d)) ? (b) :         ((c) <= (a) && (c) <= (b) && (c) <= (d)) ? (c) : (d));
    
    ans = 0;
    
    if (min_val != a) {
        ans += min_val;
    }
    //@ assert ans == (min_val != a ? min_val : 0);
    
    if (min_val != b) {
        ans += min_val;
    }
    //@ assert ans == (min_val != a ? min_val : 0) + (min_val != b ? min_val : 0);
    
    if (min_val != c) {
        ans += min_val;
    }
    //@ assert ans == (min_val != a ? min_val : 0) + (min_val != b ? min_val : 0) + (min_val != c ? min_val : 0);
    
    if (min_val != d) {
        ans += min_val;
    }
    //@ assert ans == (min_val != a ? min_val : 0) + (min_val != b ? min_val : 0) + (min_val != c ? min_val : 0) + (min_val != d ? min_val : 0);
    
    if (min_val == a) {
        na = b;
    } else if (min_val == b) {
        na = a;
    } else if (min_val == c) {
        na = d;
    } else {
        na = c;
    }
    //@ assert na == (min_val == a ? b : (min_val == b ? a : (min_val == c ? d : c)));
    
    ans += na;
    //@ assert ans <= a + b + c + d;
    
    return ans;
}
