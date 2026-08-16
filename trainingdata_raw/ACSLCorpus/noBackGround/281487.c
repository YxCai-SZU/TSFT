#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (((n) / (k)) * ((k) - 1) + ((n) % (k)));
    assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t k) {
    uint64_t n_div_k;
    uint64_t n_mod_k;
    int64_t term1;
    int64_t term2;
    int64_t ans;
    
    n_div_k = n / k;
    n_mod_k = n % k;
    
    //@ assert 0 <= k - 1 <= 99;
    
    //@ assert n_div_k * (k - 1) <= 100 * 99;
    
    term1 = (int64_t)n_div_k * ((int64_t)k - 1);
    
    //@ assert n_mod_k <= 100;
    
    term2 = (int64_t)n_mod_k;
    
    //@ assert (n_div_k * (k - 1) + n_mod_k) <= 100 * 99 + 100;
    
    ans = term1 + term2;
    
    //@ assert ans == (((n) / (k)) * ((k) - 1) + ((n) % (k)));
    
    return ans;
}
