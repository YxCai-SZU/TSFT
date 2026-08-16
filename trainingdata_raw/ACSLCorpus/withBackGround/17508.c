#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 100;
    
    logic integer compute_result(integer x) = (x * x) + (3 * x) + 2;
    
    lemma square_bound: \forall integer x; 1 <= x <= 100 ==> x * x <= 10000;
    lemma linear_bound: \forall integer x; 1 <= x <= 100 ==> 3 * x <= 300;
    lemma sum_bound: \forall integer x; 1 <= x <= 100 ==> (x * x) + (3 * x) <= 10300;
    lemma final_bound: \forall integer x; 1 <= x <= 100 ==> (x * x) + (3 * x) + 2 <= 10302;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert 1 <= x && x <= 100;
    //@ assert x * x <= 10000;
    //@ assert 3 * x <= 300;
    //@ assert (x * x) + (3 * x) <= 10300;
    //@ assert (x * x) + (3 * x) + 2 <= 10302;
    
    result = (x * x) + (3 * x) + 2;
    return result;
}
