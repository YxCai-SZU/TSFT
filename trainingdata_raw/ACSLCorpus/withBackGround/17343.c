#include <stdint.h>

/*@
    predicate k_in_range(integer k) = 1 <= k <= 200;

    logic integer half_of(integer k) = k / 2;
    logic integer mod_of(integer k) = k % 2;

    lemma half_mod_relation: \forall integer k; k_in_range(k) ==> 
        k == 2 * half_of(k) + mod_of(k);
*/

/*@
    requires k_in_range(k);
    ensures \result == 800 * k - half_of(k) * 100 - mod_of(k) * 100;
*/
int64_t func(uint32_t k) {
    uint32_t half_k;
    uint32_t remainder;
    int64_t ans;
    
    // Division by 2 using loop
    if (k >= 2) {
        uint32_t half = 0;
        uint32_t temp_k = k;
        
        /*@
            loop invariant 0 <= temp_k <= k;
            loop invariant half == (k - temp_k) / 2;
            loop invariant temp_k + 2 * half == k;
            loop assigns half, temp_k;
            loop variant temp_k;
        */
        while (temp_k >= 2) {
            half += 1;
            temp_k -= 2;
        }
        half_k = half;
    } else {
        half_k = 0;
    }
    
    //@ assert half_k == k / 2;
    
    // Modulo by 2 using loop
    if (k > 0) {
        uint32_t temp_k = k;
        
        /*@
            loop invariant 0 <= temp_k <= k;
            loop invariant temp_k % 2 == k % 2;
            loop assigns temp_k;
            loop variant temp_k;
        */
        while (temp_k >= 2) {
            temp_k -= 2;
        }
        remainder = (temp_k == 1) ? 1 : 0;
    } else {
        remainder = 0;
    }
    
    //@ assert remainder == k % 2;
    
    ans = 800 * (int64_t)k - 100 * (int64_t)half_k - (int64_t)remainder * 100;
    
    //@ assert ans == 800 * k - (k / 2) * 100 - (k % 2) * 100;
    
    return ans;
}

int main() {
    return 0;
}
