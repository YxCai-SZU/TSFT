#include <stdbool.h>
#include <stdint.h>

/* ACSL specifications for the three underlying functions */

/*@
    predicate is_mod_zero(integer x) = x % 3 == 0;
    logic integer mod_three(integer x) = x - ((x / 3) * 3);
*/

bool mod_check(unsigned int a, unsigned int b)
{
    unsigned int a_u32;
    unsigned int b_u32;
    unsigned int a_mod_3;
    unsigned int b_mod_3;
    unsigned int sum_mod_3;
    bool result;

    a_u32 = a;
    b_u32 = b;

    a_mod_3 = a_u32 - ((a_u32 / 3) * 3);
    //@ assert a_mod_3 == mod_three(a_u32);

    b_mod_3 = b_u32 - ((b_u32 / 3) * 3);
    //@ assert b_mod_3 == mod_three(b_u32);

    sum_mod_3 = (a_u32 + b_u32) - (((a_u32 + b_u32) / 3) * 3);
    //@ assert sum_mod_3 == mod_three(a_u32 + b_u32);

    result = (a_mod_3 == 0) || (b_mod_3 == 0) || (sum_mod_3 == 0);
    //@ assert result == (mod_three(a_u32) == 0 || mod_three(b_u32) == 0 || mod_three(a_u32 + b_u32) == 0);

    return result;
}

/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_bound: \forall integer r; valid_range(r) ==> square(r) <= 10000;
    lemma func_postcondition: \forall integer r, integer res; valid_range(r) && res == square(r) ==> res == square(r);
*/

int square_func(int r)
{
    int result;
    result = r;
    //@ assert valid_range(r);
    if (r != 0)
    {
        //@ assert square(r) <= 10000;
        result = r * r;
    }
    //@ assert result == square(r);
    return result;
}

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer safe_division(integer a, integer b) =
        b == 0 ? -1 : a / b;

    lemma division_bounds:
        \forall integer a, b;
            valid_inputs(a, b) ==> 0 <= safe_division(a, b) <= 10000;
*/

int32_t division_func(uint32_t a, uint32_t b)
{
    uint64_t result_u64;
    int32_t result;

    //@ assert valid_inputs(a, b);
    
    if (b == 0) {
        result = -1;
        //@ assert result == -1;
        return result;
    }

    //@ assert 1 <= b <= 10000;
    result_u64 = (uint64_t)a / (uint64_t)b;
    
    //@ assert 0 <= result_u64 <= 10000;
    result = (int32_t)result_u64;
    
    //@ assert result == a / b;
    return result;
}

/*
 * Real-world scenario: Resource allocation validator
 * 
 * In a resource allocation system, we need to check if a resource request (size)
 * can be granted based on available resources (capacity). The process involves:
 * 1. Checking if the request size and capacity are both multiples of 3 (alignment requirement)
 * 2. Computing the squared capacity to ensure it's within limits
 * 3. Dividing the request by a base unit to get the number of units needed
 *
 * The final assertion verifies that the allocation decision is consistent:
 * - If either value is a multiple of 3, the allocation is valid
 * - The squared capacity must be at least as large as the division result
 */

bool resource_allocator(unsigned int request, unsigned int capacity, uint32_t base_unit)
{
    bool alignment_ok;
    int squared_capacity;
    int32_t units_needed;
    bool result;

    alignment_ok = mod_check(request, capacity);
    //@ assert alignment_ok == (mod_three(request) == 0 || mod_three(capacity) == 0 || mod_three(request + capacity) == 0);

    squared_capacity = square_func(capacity);
    //@ assert squared_capacity == square(capacity);

    units_needed = division_func(request, base_unit);
    //@ assert units_needed == safe_division(request, base_unit);

    if (alignment_ok && squared_capacity >= units_needed) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (alignment_ok && squared_capacity >= units_needed);

    return result;
}
