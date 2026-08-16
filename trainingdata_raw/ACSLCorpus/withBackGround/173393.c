#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer mod_100(integer n) = n % 100;

    // Verification lemmas
    lemma mod_range: \forall integer n; is_valid_n(n) ==> 0 <= mod_100(n) && mod_100(n) < 100;
    lemma case_analysis: \forall integer n; is_valid_n(n) ==> 
        (mod_100(n) < 10) || 
        (10 <= mod_100(n) && mod_100(n) < 500) || 
        (500 <= mod_100(n) && mod_100(n) < 1000) || 
        (mod_100(n) >= 1000);
*/

/*@
    requires is_valid_n(n);
    ensures (mod_100(n) < 10) ==> \result == 0;
    ensures (mod_100(n) < 500 && mod_100(n) >= 10) ==> \result == 500;
    ensures (mod_100(n) < 1000 && mod_100(n) >= 500) ==> \result == 1000;
    ensures (mod_100(n) >= 1000) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t result;
    uint32_t mod_val;
    
    //@ assert is_valid_n(n);
    mod_val = n % 100;
    
    //@ assert 0 <= mod_val && mod_val < 100;
    
    if (mod_val < 10) {
        //@ assert mod_val < 10;
        result = 0;
    } else if (mod_val < 500) {
        //@ assert mod_val >= 10 && mod_val < 500;
        result = 500;
    } else if (mod_val < 1000) {
        //@ assert mod_val >= 500 && mod_val < 1000;
        result = 1000;
    } else {
        //@ assert mod_val >= 1000;
        result = 0;
    }
    
    return result;
}
