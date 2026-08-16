#include <stdint.h>
/*@
    predicate valid_x(integer x) = 1 <= x && x <= 1000000000000000;

    logic integer upper_bound(integer x) = 
        3 * (x / 11) + (x % 11 + 10) / 6;

    lemma division_bounds: \forall integer x; valid_x(x) ==> x / 11 <= x;
    lemma modulo_bounds: \forall integer x; valid_x(x) ==> x % 11 <= x;
    lemma addition_bounds: \forall integer x; valid_x(x) ==> x % 11 + 10 <= x + 10;
    lemma final_bound: \forall integer x; valid_x(x) ==> (x % 11 + 10) / 6 <= (x + 10) / 6;
*/

/*@
    requires valid_x(x);
    ensures \result <= upper_bound(x);
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    //@ assert x / 11 <= x;
    //@ assert x % 11 <= x;
    //@ assert x % 11 + 10 <= x + 10;
    //@ assert (x % 11 + 10) / 6 <= (x + 10) / 6;
    
    ans = 3 * (x / 11) + (x % 11 + 10) / 6;
    return ans;
}
