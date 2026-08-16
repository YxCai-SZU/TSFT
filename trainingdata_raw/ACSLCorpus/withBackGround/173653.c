#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer inner_expr(integer a) = 1 + a + a * a;
    
    logic integer func_result(integer a) = a * inner_expr(a);
*/

/*@
    requires is_valid_a(a);
    ensures \result == func_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t res;
    
    //@ assert is_valid_a(a);
    
    //@ assert inner_expr(a) <= 1 + 10 + 10 * 10;
    //@ assert inner_expr(a) >= 1;
    //@ assert a * inner_expr(a) <= 10 * (1 + 10 + 10 * 10);
    //@ assert a * inner_expr(a) >= 1 * 1;
    
    res = a * (1 + a + a * a);
    
    //@ assert res == func_result(a);
    return res;
}
