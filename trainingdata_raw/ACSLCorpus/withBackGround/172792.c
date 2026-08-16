#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    logic integer square_times_three(integer a) = a * a * 3;
    lemma no_overflow: \forall integer a; a_in_range(a) ==> square_times_three(a) <= 30000;
*/

/*@
    requires a_in_range(a);
    ensures \result == square_times_three(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t result;
    //@ assert a_in_range(a);
    //@ assert square_times_three(a) <= 30000;
    result = a * a * 3;
    //@ assert result == square_times_three(a);
    return result;
}
