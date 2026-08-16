#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n && n < 1000;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bounds: \forall integer n; is_valid_n(n) ==> 
        square(n) >= n && square(n) < 1000000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    ensures \result >= n;
    assigns \nothing;
*/
uint32_t find_square_num(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t ret;
    
    //@ assert is_valid_n(n);
    
    //@ assert square(n) < 1000000;
    //@ assert square(n) >= n;
    
    ret = n * n;
    
    //@ assert ret == square(n);
    //@ assert ret >= n;
    
    return ret;
}
