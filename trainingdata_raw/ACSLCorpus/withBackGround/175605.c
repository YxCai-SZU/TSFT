#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n <= 2957;
    
    logic integer triangular_num(integer n) = n * (n + 1) / 2;
    
    lemma triangular_bound: \forall integer n; is_valid_n(n) ==> triangular_num(n) <= 2957 * 2958 / 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_num(n);
    ensures \result <= triangular_num(n);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations
    uint32_t ret;
    
    // Precondition assertions
    //@ assert n <= 2957;
    //@ assert n + 1 <= 2958;
    
    //@ assert n * (n + 1) <= 2957 * 2958;
    
    // Main computation
    ret = n * (n + 1) / 2;
    
    // Postcondition verification
    //@ assert ret == triangular_num(n);
    //@ assert ret <= triangular_num(n);
    
    return ret;
}
