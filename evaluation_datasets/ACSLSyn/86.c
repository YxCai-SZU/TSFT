#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from first function */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;

    logic integer compute_result(integer a) = a + a * a + a * a * a;

    lemma result_bound: \forall integer a; a_in_range(a) ==> compute_result(a) <= 1110;
*/

/* ACSL predicate from second function */
/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/* First underlying function: polynomial computation */
int32_t func_poly(uint32_t a)
{
    uint32_t result;
    uint32_t i;

    //@ assert a_in_range(a);
    //@ assert compute_result(a) <= 1110;

    result = a + a * a + a * a * a;

    i = 0;
    while (i < a)
    {
        i = i + 1;
    }

    return (int32_t)result;
}

/* Second underlying function: range-based difference */
int func_diff(int numbers[2]) {
    int result = 0;
    int temp = 0;
    
    //@ assert is_valid_range(numbers[0]);
    //@ assert is_valid_range(numbers[1]);
    //@ assert 0 <= numbers[1] * 2 <= 200;
    //@ assert numbers[0] - numbers[1] * 2 <= 100;
    
    temp = numbers[0] - numbers[1] * 2;
    
    if (temp > 0) {
        result = temp;
    }
    
    //@ assert result >= 0;
    //@ assert result == numbers[0] - numbers[1] * 2 || result == 0;
    return result;
}

/* Synthesized function: Data validation and transformation pipeline
   Scenario: Process a pair of values where first value (a) is used to compute
   a polynomial, and the result is used as input to a range-based validation
   and difference operation, simulating a pipeline like packet header processing
   where one field encodes a parameter that feeds into another field validation.
*/
int process_pipeline(uint32_t a, int numbers[2]) {
    int32_t poly_result;
    int diff_result;
    
    poly_result = func_poly(a);
    
    diff_result = func_diff(numbers);
    
    /* High-level property: The pipeline preserves non-negativity and
       the diff result is either the positive difference or zero,
       independent of the polynomial computation (which is used for
       other processing stages not shown here). */
    //@ assert diff_result >= 0 && (diff_result == numbers[0] - numbers[1] * 2 || diff_result == 0);
    
    return diff_result;
}
