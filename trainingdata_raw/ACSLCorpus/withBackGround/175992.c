#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;
    
    logic integer calculate_sum(integer r, integer g, integer b) = 
        r * 100 + g * 10 + b;
    
    lemma sum_nonnegative: 
        \forall integer r, g, b; 
        valid_range(r) && valid_range(g) && valid_range(b) ==> 
        calculate_sum(r, g, b) >= 0;
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (calculate_sum(r, g, b) % 4 == 0);
*/
bool func(int r, int g, int b) {
    int sum;
    bool is_divisible;
    int abs_sum;
    int remainder;
    
    //@ assert valid_range(r) && valid_range(g) && valid_range(b);
    
    sum = r * 100 + g * 10 + b;
    is_divisible = false;
    abs_sum = sum;
    
    //@ assert calculate_sum(r, g, b) == sum;
    //@ assert sum >= 0;
    
    //@ assert abs_sum == sum;
    
    remainder = abs_sum;
    
    /*@
        loop invariant 0 <= remainder <= abs_sum;
        loop invariant remainder % 4 == abs_sum % 4;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 4) {
        remainder -= 4;
    }
    
    if (remainder == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible == (abs_sum % 4 == 0);
    //@ assert abs_sum % 4 == calculate_sum(r, g, b) % 4;
    
    return is_divisible;
}
