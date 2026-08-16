#include <stdint.h>
#include <stdbool.h>

/* First function: compute adjusted value */
/*@
    predicate valid_inputs(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100;

    logic integer compute_result(integer A, integer B) =
        (A - B * 2) >= 0 ? (A - B * 2) : 0;

    lemma result_property:
        \forall integer A, B;
        valid_inputs(A, B) ==>
        (compute_result(A, B) == A - B * 2 || compute_result(A, B) == 0) &&
        compute_result(A, B) >= 0;
*/

uint32_t func1(uint32_t A, uint32_t B)
{
    int32_t ans;
    int32_t tmp;

    tmp = (int32_t)A - (int32_t)B * 2;
    ans = tmp;

    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans == compute_result(A, B);

    return (uint32_t)ans;
}

/* Second function: check if safe division result meets threshold */
/*@
    predicate in_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_div(integer a) =
        (a - 1) / 3;

    lemma div_bound: \forall integer a; 1 <= a <= 100 ==> 0 <= safe_div(a) <= 33;
*/

bool func2(unsigned int a, unsigned int b)
{
    bool result;
    unsigned int temp_a;
    unsigned int temp_b;
    
    temp_a = a;
    temp_b = b;
    
    result = ((temp_a - 1) / 3 >= temp_b - 1);
    
    //@ assert result == (safe_div(a) >= b - 1);
    
    return result;
}

/* Synthesized function: Resource allocation validator */
/*@
    predicate valid_allocation(integer A, integer B) =
        valid_inputs(A, B) && in_range(A, B) &&
        ((A - B * 2) >= 0 ==> ((A - B * 2) > 0 ? ((A - 1) / 3 >= B - 1) : true));

    logic integer adjusted_value(integer A, integer B) = compute_result(A, B);
    logic boolean allocation_possible(integer A, integer B) = 
        (adjusted_value(A, B) > 0) ? (safe_div(A) >= B - 1) : true;
*/

bool synthesized_func(uint32_t A, uint32_t B)
{
    uint32_t adjusted;
    bool sufficient;
    
    adjusted = func1(A, B);
    
    if (adjusted > 0)
    {
        sufficient = func2(A, B);
    }
    else
    {
        sufficient = true;
    }
    
    return sufficient;
}
