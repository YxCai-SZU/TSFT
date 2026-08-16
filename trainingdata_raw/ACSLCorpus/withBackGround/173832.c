#include <stdint.h>

/*@
    predicate A_bounds(integer A) = 0 <= A <= 100;
    predicate P_bounds(integer P) = 0 <= P <= 100;
    
    logic integer compute_result(integer A, integer P) = (A * 3 + P) / 2;
    
    lemma result_bounds:
        \forall integer A, P; A_bounds(A) && P_bounds(P) ==> 
        compute_result(A, P) <= (300 + 100) / 2;
*/

/*@
    requires 0 <= A <= 100;
    requires 0 <= P <= 100;
    ensures \result == (A * 3 + P) / 2;
    ensures \result <= (300 + 100) / 2;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    // Variable declarations at scope top
    uint32_t ans;
    
    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;
    
    ans = (A * 3 + P) / 2;
    
    //@ assert ans == (A * 3 + P) / 2;
    //@ assert ans <= (300 + 100) / 2;
    
    return ans;
}
