#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int64_t func(uint64_t n) {
    uint64_t mo = 1000000007;
    uint64_t i_unsigned;
    int64_t i_signed;
    uint64_t rem;
    
    //@ assert (1 <= (n) && (n) <= 1000000);
    
    i_unsigned = (n * 100 + 1000000006) % mo;
    
    //@ assert i_unsigned == (((n) * 100 + 1000000006) % (mo));
    
    if (i_unsigned > n * 100) {
        i_signed = (int64_t)(i_unsigned - mo);
    } else {
        i_signed = (int64_t)i_unsigned;
    }
    
    //@ assert -mo < i_signed && i_signed < mo;
    
    if (i_signed < 0) {
        rem = (uint64_t)(i_signed + (int64_t)mo);
    } else {
        rem = (uint64_t)i_signed;
    }
    
    rem = rem % mo;
    
    //@ assert 0 <= rem && rem < mo;
    
    if (rem == 0) {
        //@ assert rem == 0;
        return 1;
    } else {
        //@ assert rem != 0;
        return 0;
    }
}
