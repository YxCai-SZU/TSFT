#include <stdint.h>

/*@
    predicate valid_range(integer a) = -100 <= a && a <= 100;
    logic integer square(integer a) = a * a;
    lemma square_bounds: \forall integer a; valid_range(a) ==> -10000 <= square(a) <= 10000;
*/

/*@
    requires valid_range(a);
    ensures \result == square(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    
    //@ assert valid_range(a);
    //@ assert -10000 <= a * a <= 10000;
    
    result = a * a;
    
    //@ assert result == square(a);
    return result;
}
