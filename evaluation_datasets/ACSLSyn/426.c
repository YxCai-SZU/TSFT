#include <stdbool.h>

/* ACSL predicates from original functions */
/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_medium(integer x) = 1 <= x <= 20;
    predicate valid_range(integer x) = 1 <= x && x <= 13;
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    predicate max_val(integer n, integer m) =
        (n % 2 == 0) ? (m == n / 2) : (m == n / 2 + 1);
*/

/*@
    logic integer calc_max(integer n) =
        (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
*/

/*@
    lemma max_lemma:
        \forall integer n;
            n >= 1 ==>
            calc_max(n) == n / 2 + n % 2;
    
    lemma range_lemma:
        \forall integer a, b; is_valid_range(a, b) ==> 1 <= a <= 100 && 1 <= b <= 100;
*/

/* Original function 1: multiplication with bounds check */
long func_mul(unsigned long a, unsigned long b)
{
    long a_i64;
    long b_i64;
    long result;

    a_i64 = (long)a;
    b_i64 = (long)b;

    if (a_i64 > 9 || b_i64 > 9)
    {
        result = -1;
    }
    else
    {
        //@ assert is_small(a_i64) && is_small(b_i64);
        //@ assert a_i64 * b_i64 <= 81;
        //@ assert a_i64 * b_i64 >= 1;
        result = a_i64 * b_i64;
    }

    return result;
}

/* Original function 2: check if k is within first half of n */
bool func_check_half(int n, int k)
{
    int max;
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    if (n % 2 == 0)
    {
        max = n / 2;
    }
    else
    {
        max = n / 2 + 1;
    }
    
    //@ assert max_val(n, max);
    //@ assert max == calc_max(n);
    //@ assert max == n / 2 + n % 2;
    
    if (k <= max)
    {
        //@ assert k <= n / 2 + n % 2;
        return true;
    }
    else
    {
        //@ assert k > n / 2 + n % 2;
        return false;
    }
}

/* Original function 3: triangle inequality check */
bool func_triangle(unsigned int* a) {
    bool result;
    
    //@ assert valid_range(a[0]);
    //@ assert valid_range(a[1]);
    //@ assert valid_range(a[2]);
    
    result = (a[0] + a[1] >= a[2] || 
              a[1] + a[2] >= a[0] || 
              a[2] + a[0] >= a[1]);
    
    return result;
}

/* Original function 4: range comparison */
bool func_range(unsigned int a, unsigned int b)
{
    bool ok = false;
    //@ assert is_valid_range(a, b);
    if (b >= a) {
        ok = true;
    }
    //@ assert ok == (b >= a);
    return ok;
}

/* 
 * Synthesized function: Smart Grid Resource Allocator
 * 
 * Real-world scenario: A smart grid resource allocator determines if a 
 * secondary power source (battery bank) can be allocated to a grid section.
 * The allocator processes sensor data to validate resource availability,
 * checks capacity constraints, verifies distribution feasibility, and 
 * ensures the allocation range is valid.
 *
 * Data flow:
 * 1. Validate battery capacity (small multiplication) - func_mul
 * 2. Check if load is within first half of available capacity - func_check_half
 * 3. Verify triangle inequality for three resource nodes - func_triangle
 * 4. Ensure allocation range is valid - func_range
 */

bool smart_grid_allocator(
    unsigned long capacity_a, 
    unsigned long capacity_b, 
    int load,
    unsigned int* nodes,
    unsigned int alloc_start,
    unsigned int alloc_end)
{
    bool result = false;
    long mult_result;
    bool half_check;
    bool triangle_check;
    bool range_check;
    
    mult_result = func_mul(capacity_a, capacity_b);
    
    half_check = func_check_half((int)capacity_a, load);
    
    triangle_check = func_triangle(nodes);
    
    range_check = func_range(alloc_start, alloc_end);
    
    if (mult_result != -1 && half_check && triangle_check && range_check) {
        result = true;
    }
    
    //@ assert result ==> (mult_result != -1 && half_check && triangle_check && range_check);
    
    return result;
}
