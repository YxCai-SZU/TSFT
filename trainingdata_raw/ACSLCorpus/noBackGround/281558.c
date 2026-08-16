#include <stdint.h>

/*@ requires 0 <= e <= 100;
    requires 0 <= k <= 100;
    ensures \result >= 0;
    ensures \result <= e;
    assigns \nothing; */
int64_t count_tasty_cookies(int64_t e, int64_t k) {
    int64_t min_e_k;
    
    if (e < k) {
        min_e_k = e;
        //@ assert ((e) < (k));
    } else {
        min_e_k = k;
        //@ assert ((e) >= (k));
    }
    
    //@ assert min_e_k == (((e) < (k)) ? (e) : (k));
    //@ assert 0 <= min_e_k <= e;
    
    return e - min_e_k;
}
