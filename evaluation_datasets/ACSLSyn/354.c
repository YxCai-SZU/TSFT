#include <stdint.h>
#include <stdbool.h>

/* Predicates from first snippet */
/*@ predicate is_valid_N(integer N) = 1 <= N && N <= 1000000; */

/* Predicates from second snippet */
/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    logic integer polygon_sum(integer n) = (n - 2) * 180;
    lemma sum_bounds: \forall integer n; valid_n(n) ==> 180 <= polygon_sum(n) <= 17640;
*/

/* Predicates from third snippet */
/*@
predicate gt(integer a, integer b) = a > b;
predicate ge(integer a, integer b) = a >= b;
predicate le(integer a, integer b) = a <= b;
predicate eq(integer a, integer b) = a == b;

lemma calc_example_5: \forall integer x, y; x > y ==> x - y > 0;
lemma calc_example_6: \forall integer x, y; x >= y ==> x - y >= 0;
lemma calc_example_7: \forall integer x, y; x <= y ==> x - y <= 0;
lemma calc_example_8: \forall integer x, y; x == y ==> x - y == 0;
*/

/* Predicates from fourth snippet */
/*@ predicate is_even(integer n) = n % 2 == 0; */

/* First original function - checks if N is 2019 or divisible by 2019 */
int func1(int32_t N)
{
    int32_t result;
    uint32_t N_unsigned;
    
    if (N == 2019)
    {
        return 1;
    }
    else
    {
        if (N < 0)
        {
            N_unsigned = (uint32_t)(-N);
        }
        else
        {
            N_unsigned = (uint32_t)N;
        }
        
        result = (int32_t)(N_unsigned % 2019);
        
        if (result == 0)
        {
            return 0;
        }
        else
        {
            //@ assert N != 2019;
            return 0;
        }
    }
}

/* Second original function - calculates polygon interior angle sum */
int32_t func2(uint32_t n)
{
    int32_t result;
    
    //@ assert valid_n(n);
    //@ assert 1 <= n - 2 && n - 2 <= 98;
    //@ assert polygon_sum(n) <= 17640;
    
    result = (int32_t)((n - 2) * 180);
    
    //@ assert result == polygon_sum(n);
    return result;
}

/* Third original functions - comparison verification */
bool verify_example_5(int x, int y) {
    //@ assert x - y > 0;
    return true;
}

bool verify_example_6(int x, int y) {
    //@ assert x - y >= 0;
    return true;
}

bool verify_example_7(int x, int y) {
    //@ assert x - y <= 0;
    return true;
}

bool verify_example_8(int x, int y) {
    //@ assert x - y == 0;
    return true;
}

/* Fourth original function - calculates a*3 + b/2 */
unsigned int func4(unsigned int a, unsigned int b)
{
    unsigned int ans;
    
    //@ assert a * 3 <= 300;
    //@ assert b / 2 <= 50;
    //@ assert a * 3 + b / 2 <= 350;
    
    ans = a * 3 + b / 2;
    return ans;
}

/* 
 * Real-world scenario: Polygon property verification system
 * This function processes polygon data to verify geometric properties.
 * It takes a polygon ID, number of sides, and two comparison values,
 * then computes a combined property index.
 * 
 * Control flow:
 * 1. Validate polygon ID using func1 (ensures ID is meaningful)
 * 2. Calculate polygon interior angle sum using func2
 * 3. Verify comparison relationships using verify_example functions
 * 4. Compute final property index using func4
 * 
 * High-level property: The output property index is bounded and 
 * represents a valid polygon configuration
 */
unsigned int process_polygon_properties(int32_t polygon_id, uint32_t num_sides, 
                                        unsigned int val_a, unsigned int val_b,
                                        int val_x, int val_y)
{
    int32_t check_result;
    int32_t angle_sum;
    bool comp_check1;
    bool comp_check2;
    unsigned int property_index;
    
    check_result = func1(polygon_id);
    
    angle_sum = func2(num_sides);
    
    comp_check1 = verify_example_5(val_x, val_y);
    comp_check2 = verify_example_6(val_a, val_b);
    
    property_index = func4(val_a, val_b);
    
    //@ assert property_index <= 350 && property_index >= 0;
    return property_index;
}
