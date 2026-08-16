#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a <= 10000;

    logic integer compute_result(integer a) =
        (1000 - (a % 1000)) % 1000;

    lemma result_bound: \forall integer a; is_valid_a(a) ==> compute_result(a) <= 1000;
*/

/*@
    requires is_valid_a(a);
    assigns \nothing;
    ensures \result <= 1000;
    ensures \result == compute_result(a);
*/
uint64_t func(uint64_t a)
{
    uint64_t result;
    
    //@ assert a % 1000 <= 999;
    //@ assert 1000 - (a % 1000) <= 1000;
    //@ assert (1000 - (a % 1000)) % 1000 <= 999;
    
    result = (1000 - a % 1000) % 1000;
    
    //@ assert result == compute_result(a);
    
    return result;
}
