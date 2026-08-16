#include <stdint.h>

/*@
    predicate a_le_b(integer a, integer b) = 0 <= a <= b <= 1000000000000000000;
    predicate x_valid(integer x) = 1 <= x <= 1000000000000000000;
    
    logic integer floor_div(integer n, integer d) = n / d;
    logic integer floor_mod(integer n, integer d) = n % d;
    
    lemma div_monotonic:
        \forall integer a, b, x;
        a_le_b(a, b) && x_valid(x) ==> floor_div(a, x) <= floor_div(b, x);
*/

/*@
    requires 0 <= a <= b <= 1000000000000000000;
    requires 1 <= x <= 1000000000000000000;
    ensures \result <= (b / x) - (a / x) + 1;
    ensures \result >= (b / x) - (a / x);
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t result;
    uint64_t temp_div_a;
    uint64_t temp_div_b;
    uint64_t temp_mod_a;
    
    //@ assert a_le_b(a, b);
    //@ assert x_valid(x);
    
    temp_div_a = a / x;
    temp_div_b = b / x;
    temp_mod_a = a % x;
    
    //@ assert temp_div_a <= temp_div_b;
    
    result = temp_div_b - temp_div_a;
    
    if (temp_mod_a == 0)
    {
        result = result + 1;
    }
    
    // Final verification of postconditions
    //@ assert result <= temp_div_b - temp_div_a + 1;
    //@ assert result >= temp_div_b - temp_div_a;
    
    return result;
}
