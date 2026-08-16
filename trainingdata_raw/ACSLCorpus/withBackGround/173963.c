#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 65535;
    
    logic integer triangular_num(integer n) = n * (n + 1) / 2;
    
    lemma arithmetic_bounds: 
        \forall integer n; is_valid_n(n) ==> n + 1 <= 65536;
    
    lemma product_bounds: 
        \forall integer n; is_valid_n(n) ==> n * (n + 1) <= 4294967295;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_num(n);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n + 1 <= 65536;
    
    //@ assert n * (n + 1) <= 4294967295;
    
    return n * (n + 1) / 2;
}
