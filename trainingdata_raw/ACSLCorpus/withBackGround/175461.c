/*@
    predicate is_less_than_max_div_5(integer x) = x < 4294967295 / 5;
    predicate is_less_than_max_div_2(integer x) = x < 4294967295 / 2;
    predicate is_less_than_max_div_3(integer x) = x < 4294967295 / 3;
    predicate is_less_than_max_div_4(integer x) = x < 4294967295 / 4;
    
    lemma multiplication_bounds: 
        \forall integer x; 
        is_less_than_max_div_5(x) ==> 
        is_less_than_max_div_2(x) && 
        is_less_than_max_div_3(x) && 
        is_less_than_max_div_4(x);
*/

#include <stdint.h>

/*@
    requires x1 < 4294967295 / 5;
    ensures \result == 5 * x1;
    assigns \nothing;
*/
uint32_t pentuple(uint32_t x1)
{
    // Variable declarations at the top
    uint32_t x2;
    uint32_t x3;
    uint32_t x4;
    uint32_t result;
    
    //@ assert x1 < 4294967295 / 5;
    
    //@ assert x1 * 2 < 4294967295;
    x2 = x1 + x1;
    
    //@ assert x1 * 3 < 4294967295;
    x3 = x2 + x1;
    
    //@ assert x1 * 4 < 4294967295;
    x4 = x3 + x1;
    
    //@ assert x1 * 5 < 4294967295;
    result = x4 + x1;
    
    return result;
}

int main()
{
    return 0;
}
