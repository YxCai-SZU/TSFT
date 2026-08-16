#include <stdint.h>

/*@
    predicate valid_input(integer n) =
        100 <= n && n <= 999;

    logic integer func_spec(integer n) =
        n / 111;

    lemma division_bounds:
        \forall integer n; valid_input(n) ==> 0 <= func_spec(n) <= 9;
*/

/*@
    requires valid_input(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 100 <= n && n <= 999;
    
    result = n / 111;
    
    //@ assert result == n / 111;
    return result;
}
