#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000;
    
    logic integer compute_change(integer n) =
        n % 1000 == 0 ? 0 : 1000 - n % 1000;
    
    lemma change_less_than_1000: 
        \forall integer n; is_valid_n(n) ==> compute_change(n) < 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result < 1000;
    ensures n % 1000 == 0 ==> \result == 0;
    ensures n % 1000 != 0 ==> \result == 1000 - n % 1000;
*/
size_t func(size_t n) {
    size_t change;
    
    if (n % 1000 == 0) {
        change = 0;
        //@ assert change == 0;
    } else {
        size_t r = n % 1000;
        change = 1000 - r;
        //@ assert change < 1000;
    }
    
    return change;
}
