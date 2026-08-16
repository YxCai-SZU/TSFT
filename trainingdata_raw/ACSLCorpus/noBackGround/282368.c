#include <stdint.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires k >= 1 && k <= a + b + c && k <= 2000000000;
    ensures \result <= k;
    ensures ((\result) >= 0);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t a_local = a;
    int64_t k_local = k;
    int64_t min_a_k;
    int64_t min_k_b;
    int64_t min_k_c;
    int64_t max_min_a_k;
    
    // First min operation
    //@ assert ((a_local) >= 0) && ((k_local) >= 0);
    if (a_local < k_local) {
        min_a_k = a_local;
    } else {
        min_a_k = k_local;
    }
    //@ assert min_a_k == (((a_local) < (k_local)) ? (a_local) : (k_local));
    //@ assert ((min_a_k) >= 0);
    
    k_local -= min_a_k;
    a_local -= min_a_k;
    //@ assert k_local >= 0 && a_local >= 0;
    
    // Second min operation
    //@ assert ((k_local) >= 0) && ((b) >= 0);
    if (k_local < b) {
        min_k_b = k_local;
    } else {
        min_k_b = b;
    }
    //@ assert min_k_b == (((k_local) < (b)) ? (k_local) : (b));
    //@ assert ((min_k_b) >= 0);
    
    k_local -= min_k_b;
    //@ assert k_local >= 0;
    
    // Third min operation
    //@ assert ((k_local) >= 0) && ((c) >= 0);
    if (k_local < c) {
        min_k_c = k_local;
    } else {
        min_k_c = c;
    }
    //@ assert min_k_c == (((k_local) < (c)) ? (k_local) : (c));
    //@ assert ((min_k_c) >= 0);
    
    k_local -= min_k_c;
    //@ assert k_local >= 0;
    
    // Max operation
    //@ assert ((min_a_k) >= 0) && ((k_local) >= 0);
    if (min_a_k > k_local) {
        max_min_a_k = min_a_k;
    } else {
        max_min_a_k = k_local;
    }
    //@ assert max_min_a_k == (((min_a_k) > (k_local)) ? (min_a_k) : (k_local));
    //@ assert ((max_min_a_k) >= 0);
    
    // Final calculation
    //@ assert min_a_k - max_min_a_k <= k_local;
    return min_a_k - max_min_a_k;
}
