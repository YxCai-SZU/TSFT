#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 0 <= a && a <= 100;
    predicate is_valid_b(integer b) = 0 <= b && b <= 100;
    
    logic integer func_result(integer a, integer b) = 
        a <= 2 * b ? 0 : a - 2 * b;
    
    lemma func_result_bound: 
        \forall integer a, b; 
        is_valid_a(a) && is_valid_b(b) ==> 
        func_result(a, b) <= a;
    
    lemma func_result_cases: 
        \forall integer a, b; 
        is_valid_a(a) && is_valid_b(b) ==> 
        func_result(a, b) == 0 || func_result(a, b) == a - 2 * b;
*/

/*@
    requires is_valid_a(a) && is_valid_b(b);
    ensures \result <= a;
    ensures \result == 0 || \result == a - 2 * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    if (a <= 2 * b)
    {
        //@ assert a <= 2 * b;
        result = 0;
    }
    else
    {
        //@ assert a > 2 * b;
        result = a - 2 * b;
    }
    
    //@ assert result <= a;
    //@ assert result == 0 || result == a - 2 * b;
    
    return result;
}

int main()
{
    return 0;
}
