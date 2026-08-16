#include <stddef.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 10000;
    
    logic integer ceiling_div_1000(integer n) = (n + 999) / 1000;
    
    lemma num_bounds:
        \forall integer n; valid_range(n) ==> 
            1 <= ceiling_div_1000(n) <= 11;
    
    lemma lower_bound:
        \forall integer n; valid_range(n) ==> 
            ceiling_div_1000(n) * 1000 >= 1000;
    
    lemma upper_bound:
        \forall integer n; valid_range(n) ==> 
            ceiling_div_1000(n) * 1000 <= 11000;
*/

/*@
    requires valid_range(n);
    ensures \result == ceiling_div_1000(n) * 1000 - n;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t num;
    size_t result;
    
    //@ assert valid_range(n);
    
    num = (n + 999) / 1000;
    
    //@ assert num == ceiling_div_1000(n);
    
    //@ assert 1 <= num && num <= 11;
    
    //@ assert num * 1000 <= 11000;
    
    //@ assert num * 1000 >= 1000;
    
    result = num * 1000 - n;
    
    //@ assert result == ceiling_div_1000(n) * 1000 - n;
    
    return result;
}
