#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer scaled_value(integer x) = (x / 100) * 100;
    
    lemma scaled_value_bound: \forall integer x; is_valid_range(x) ==> 
        (x / 100) <= 1000 && scaled_value(x) <= 100000;
*/

/*@
    requires is_valid_range(x);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> scaled_value(x) <= x;
    ensures \result == 0 ==> scaled_value(x) > x;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at scope top
    uint64_t n;
    
    //@ assert is_valid_range(x);
    
    //@ assert (x / 100) <= 1000;
    //@ assert (x / 100) * 100 <= 100000;
    
    n = (x / 100) * 100;
    
    if (n <= x) {
        return 1;
    } else {
        return 0;
    }
}
