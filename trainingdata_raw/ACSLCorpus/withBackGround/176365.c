#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;
    logic integer square(integer a) = a * a;
    lemma square_bound: \forall integer a; is_valid_range(a) ==> square(a) <= 10000;
*/

/*@
    requires is_valid_range(a);
    ensures \result == square(a);
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert is_valid_range(a);
    //@ assert square(a) <= 10000;
    
    result = a * a;
    
    //@ assert result == square(a);
    return result;
}
