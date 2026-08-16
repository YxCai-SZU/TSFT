#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_even_pred(integer n) = n % 2 == 0;
*/

/*@
    requires n <= 4294967295;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even(uint32_t n)
{
    bool ret;
    //@ ghost uint32_t n_spec = n;
    
    ret = (n % 2 == 0);
    
    //@ assert ret == (n_spec % 2 == 0);
    return ret;
}

/*@
    logic integer perimeter_polygon_logic(integer s, integer l) = s * l;
    
    lemma perimeter_no_overflow:
        \forall integer s, integer l;
            s > 2 && s <= 4294967295 / l && l > 0 && l <= 4294967295 ==> 
            s * l <= 4294967295;
*/

/*@
    requires s > 2;
    requires s <= 4294967295 / l;
    requires l > 0;
    requires l <= 4294967295;
    ensures \result == s * l;
    assigns \nothing;
*/
uint32_t perimeter_polygon(uint32_t s, uint32_t l)
{
    uint32_t ret;
    //@ ghost uint32_t s_spec = s;
    //@ ghost uint32_t l_spec = l;
    
    //@ assert s_spec * l_spec <= 4294967295;
    
    ret = s * l;
    
    //@ assert ret == s_spec * l_spec;
    return ret;
}
