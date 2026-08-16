#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 100;
    
    logic integer scaled_cost(integer x) = x * 800;
    logic integer division_part(integer x) = x / 15;
    logic integer scaled_discount(integer x) = division_part(x) * 200;
    logic integer final_result(integer x) = scaled_cost(x) - scaled_discount(x);
    
    lemma scaled_cost_bounds: \forall integer x; is_valid_input(x) ==> scaled_cost(x) <= 80000;
    lemma scaled_discount_bounds: \forall integer x; is_valid_input(x) ==> scaled_discount(x) <= 20000;
    lemma result_correctness: \forall integer x; is_valid_input(x) ==> final_result(x) == x * 800 - (x / 15) * 200;
*/

/*@
    requires is_valid_input(x);
    ensures \result == final_result(x);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t x_scaled;
    uint32_t division;
    uint32_t discount_scaled;
    int32_t result;
    
    x_scaled = x * 800;
    division = x / 15;
    discount_scaled = division * 200;
    
    //@ assert x_scaled <= 80000;
    //@ assert discount_scaled <= 20000;
    
    result = (int32_t)(x_scaled - discount_scaled);
    
    //@ assert result == final_result(x);
    
    return result;
}
