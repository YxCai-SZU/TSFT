#include <stdint.h>

/*@
    predicate x_in_range(integer x) = 1 <= x <= 100;
    
    logic integer cubic_term(integer x) = x * x * x;
    logic integer quadratic_term(integer x) = 5 * x * x;
    logic integer linear_term(integer x) = 36 * x;
    
    lemma cubic_bound:
        \forall integer x; x_in_range(x) ==> 1 <= cubic_term(x) <= 1000000;
    
    lemma quadratic_bound:
        \forall integer x; x_in_range(x) ==> 5 <= quadratic_term(x) <= 50000;
    
    lemma linear_bound:
        \forall integer x; x_in_range(x) ==> 36 <= linear_term(x) <= 3600;
    
    lemma no_overflow:
        \forall integer x; x_in_range(x) ==> 
            cubic_term(x) + quadratic_term(x) <= 9223372036854775807 - linear_term(x);
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == x * x * x + 5 * x * x - 36 * x;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    //@ assert 1 <= x && x <= 100;
    
    //@ assert 1 <= x * x && x * x <= 10000;
    
    //@ assert 1 <= x * x * x && x * x * x <= 1000000;
    
    //@ assert 5 * x <= 500;
    
    //@ assert 5 * x * x <= 50000;
    
    //@ assert 36 * x <= 3600;
    
    //@ assert x * x * x + 5 * x * x <= 9223372036854775807 - 36 * x;
    
    //@ assert x * x * x + 5 * x * x - 36 * x <= 9223372036854775807;
    
    //@ assert x * x * x + 5 * x * x - 36 * x >= -9223372036854775808;
    
    return x * x * x + 5 * x * x - 36 * x;
}
