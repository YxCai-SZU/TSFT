#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from the first code snippet */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    
    logic integer max(integer x, integer y) = x > y ? x : y;
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma ans_bounds:
        \forall integer a, b, c, ans;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        ans == min(max(c + (a <= b ? a : b), c), c) ==>
        ans <= c && ans >= 0;
*/

int func(int a, int b, int c)
{
    int ans;
    
    if (a <= b) {
        ans = c + a;
    } else {
        ans = c + b;
    }
    
    if (ans > c) {
    } else {
        ans = c;
    }
    
    if (ans < c) {
    } else {
        ans = c;
    }
    
    //@ assert ans <= c;
    //@ assert ans >= 0;
    
    return ans;
}

/* ACSL predicates and lemmas from the second code snippet */
/*@
    predicate in_range(integer x, integer low, integer high) =
        low <= x && x <= high;
*/

/*@
    logic integer triple_val(integer x) = 3 * x;
*/

/*@
    logic integer square_val(integer x) = x * x;
*/

int triple(int x)
{
    //@ assert in_range(x, -1000, 1000);
    return x + x + x;
}

int square(int x)
{
    //@ assert in_range(x, -46340, 46340);
    //@ assert in_range(x * x, -46340 * 46340, 46340 * 46340);
    return x * x;
}

int call_triple_or_square(int x, int use_triple)
{
    int ret;
    //@ assert in_range(x, -1000, 1000);
    if (use_triple) {
        ret = triple(x);
    } else {
        ret = square(x);
    }
    return ret;
}

/* ACSL predicates and lemmas from the third code snippet */
/*@ predicate valid_range_n(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_x(integer x) = 1 <= x && x <= 10000; */
/*@ predicate valid_number(integer num) = 1 <= num && num <= 100; */
/*@ predicate valid_array(int32_t *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

/*@ lemma sum_bound: 
      \forall integer i, integer n, integer sum; 
      0 <= i <= n && sum <= i * 100 ==> sum <= n * 100; */

int32_t func_count(int32_t n, int32_t x, int32_t *numbers) {
    int32_t count;
    int32_t sum;
    int32_t i;
    
    count = 0;
    sum = 0;
    i = 0;
    
    while (i < n) {
        sum += numbers[i];
        
        if (sum <= x) {
            count += 1;
        }
        
        i += 1;
        
        //@ assert sum <= x + i * 100;
    }
    
    return count;
}

/* ACSL predicates and lemmas from the fourth code snippet */
/*@
    predicate square_in_range(integer x) = 0 <= x <= 46340;
    predicate sum_in_range(integer x, integer y) = 0 <= x < 128 && 0 <= y < 128;
*/

/*@
    logic integer square_logic(integer x) = x * x;
    logic integer sum_squares(integer x, integer y) = square_logic(x) + square_logic(y);
*/

/*@
    lemma square_bound: \forall integer x; square_in_range(x) ==> square_logic(x) <= 46340 * 46340;
    lemma sum_bound_sq: \forall integer x, y; sum_in_range(x, y) ==> sum_squares(x, y) < 128 * 128 + 128 * 128;
*/

uint32_t square_uint(uint32_t x) {
    //@ assert square_in_range(x);
    //@ assert square_logic(x) <= 46340 * 46340;
    return x * x;
}

uint32_t sum_of_squares(uint32_t x, uint32_t y) {
    //@ assert sum_in_range(x, y);
    //@ assert sum_squares(x, y) < 128 * 128 + 128 * 128;
    return x * x + y * y;
}

/* Synthesized function: process_sensor_data
 * Real-world scenario: Process sensor data from a monitoring system.
 * The function takes sensor readings (a, b, c), a scaling factor (x), an array of additional readings (numbers), 
 * and coordinates (coord_x, coord_y) to compute a combined result.
 * Data flow:
 * 1. Use func to compute a bounded value from sensor readings a, b, c.
 * 2. Use call_triple_or_square to scale the result using the scaling factor x.
 * 3. Use func_count to count how many prefix sums of numbers array are within a threshold.
 * 4. Use sum_of_squares to combine the coordinates into a single value.
 * The final result is a tuple (first two elements) and a count, ensuring the combined output satisfies an invariant.
 */
int32_t process_sensor_data(int a, int b, int c, int x, int32_t n, int32_t x_threshold, int32_t *numbers, uint32_t coord_x, uint32_t coord_y) {
    int func_result;
    int scaled_result;
    int32_t count_result;
    uint32_t sum_sq_result;
    int32_t final_result;
    
    func_result = func(a, b, c);
    //@ assert func_result <= c && func_result >= 0;
    
    if (x > 0) {
        scaled_result = call_triple_or_square(func_result, 1);
        //@ assert scaled_result == triple_val(func_result);
    } else {
        scaled_result = call_triple_or_square(func_result, 0);
        //@ assert scaled_result == square_val(func_result);
    }
    
    count_result = func_count(n, x_threshold, numbers);
    //@ assert 0 <= count_result <= n + 1;
    
    sum_sq_result = sum_of_squares(coord_x, coord_y);
    //@ assert sum_sq_result == sum_squares(coord_x, coord_y);
    
    final_result = (int32_t)(scaled_result + count_result + (int32_t)sum_sq_result);
    
    //@ assert final_result >= 0;  // High-level property: output is non-negative
    return final_result;
}
