#include <stdbool.h>
#include <stdint.h>

/* Predicate to check if a number is even */
/*@ predicate is_even(integer x) = x % 2 == 0; */

/* Function 1: checks if at least one input is even */
bool func1(const uint32_t input[2]) {
    uint32_t A;
    uint32_t B;
    
    A = input[0];
    B = input[1];
    
    //@ assert A <= 10000;
    //@ assert B <= 10000;
    
    return (A % 2 == 0) || (B % 2 == 0);
}

/* Predicate and logic for function 2 */
/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        a < b + c ? 0 : a - (b + c);
*/

/* Function 2: computes a resource allocation remainder */
int func2(int a, int b, int c)
{
    int result;
    //@ assert valid_range(a, b, c);
    //@ assert 1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;
    
    if (a < b + c) {
        result = 0;
    } else {
        result = a - (b + c);
    }
    
    //@ assert (a < b + c ==> result == 0) && (a >= b + c ==> result == a - (b + c));
    //@ assert result == compute_result(a, b, c);
    //@ assert result >= 0;
    //@ assert result <= a;
    
    return result;
}

/* 
 * Synthesized function: Resource allocation validator for a small embedded system.
 * 
 * Scenario: A memory-constrained device manages up to 20 resource blocks.
 * The function checks if two consecutive allocation requests (input[0] and input[1]) 
 * have at least one request that is even (aligned to word boundaries), 
 * and computes the leftover resource after satisfying a combined demand.
 * 
 * Data flow:
 * - input[0] and input[1] are the two allocation request sizes (<= 10000 each).
 * - a is the total available resource blocks (1..20).
 * - b and c are the request indices (1..a, 1..20) used to compute the combined demand.
 * 
 * The synthesized function verifies that if the first request is even, 
 * then the leftover resource (after subtracting combined demand) is non-negative 
 * and does not exceed the total available resource.
 */

int synthesized_func(const uint32_t input[2], int a, int b, int c)
{
    bool even_flag = func1(input);
    
    int leftover = func2(a, b, c);
    
    //@ assert (is_even(input[0]) ==> (leftover >= 0 && leftover <= a));
    
    return leftover;
}
