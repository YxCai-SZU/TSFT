#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> 
            (((n) % 2 == 0) && n / 2 < k) || 
            (((n) % 2 == 1) && n / 2 + 1 <= k);
*/
bool func(int n, int k) {
    unsigned int n_unsigned;
    unsigned int k_unsigned;
    unsigned int half_n;
    
    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
    k_unsigned = (k < 0) ? (unsigned int)(-k) : (unsigned int)k;
    
    half_n = n_unsigned / 2;
    
    if (n_unsigned % 2 == 0) {
        if (half_n < k_unsigned) {
            //@ assert n_unsigned % 2 == 0 && half_n < k_unsigned;
            return true;
        } else {
            //@ assert !(n_unsigned % 2 == 0 && half_n < k_unsigned);
            return false;
        }
    } else {
        if (half_n + 1 <= k_unsigned) {
            //@ assert n_unsigned % 2 == 1 && half_n + 1 <= k_unsigned;
            return true;
        } else {
            //@ assert !(n_unsigned % 2 == 1 && half_n + 1 <= k_unsigned);
            return false;
        }
    }
}
