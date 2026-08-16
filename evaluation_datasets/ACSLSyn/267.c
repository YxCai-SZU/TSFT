/* Scenario: Validating and computing distance between two points within a bounded range.
   Data flow: 
   1. First, we validate that the input coordinates (x1,y1,x2,y2) are within valid range [1,100] 
      and that the coordinates are sorted and non-zero using func1 (the first snippet adapted).
   2. Then, we compute the Manhattan distance between the two points using func2.
   3. Finally, we check if the distance falls within a user-specified threshold range using func3.
   The core property: the final result correctly indicates whether the distance is within the threshold.
*/

#include <stdbool.h>

/* First function: validates that array elements are sorted, strictly increasing, 
   have at least two elements, and no element is zero. Adapted to take 4 integers. */
/*@
    predicate is_sorted_array(int a, int b, int c, int d) = 
        a <= b && b <= c && c <= d;
    
    predicate is_strictly_increasing_array(int a, int b, int c, int d) = 
        a < b && b < c && c < d;
    
    predicate has_at_least_two = true;
    
    predicate no_element_is_zero_array(int a, int b, int c, int d) = 
        a != 0 && b != 0 && c != 0 && d != 0;
*/

bool validate_inputs(int a, int b, int c, int d)
{
    //@ assert is_sorted_array(a, b, c, d);
    //@ assert is_strictly_increasing_array(a, b, c, d);
    //@ assert no_element_is_zero_array(a, b, c, d);
    return true;
}

/* Second function: compute Manhattan distance between (x1,y1) and (x2,y2) with values in [1,100] */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer abs_diff(integer x, integer y) =
        x >= y ? x - y : y - x;
    
    logic integer manhattan_distance(integer x1, integer y1, integer x2, integer y2) =
        abs_diff(x1, x2) + abs_diff(y1, y2);
*/

unsigned int compute_distance(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    unsigned int dx, dy, total;
    
    //@ assert valid_range(x1) && valid_range(y1) && valid_range(x2) && valid_range(y2);
    
    dx = (x1 > x2) ? (x1 - x2) : (x2 - x1);
    //@ assert dx == abs_diff(x1, x2);
    
    dy = (y1 > y2) ? (y1 - y2) : (y2 - y1);
    //@ assert dy == abs_diff(y1, y2);
    
    total = dx + dy;
    //@ assert total == manhattan_distance(x1, y1, x2, y2);
    
    return total;
}

/* Third function: check if a value is within a given range [low, high] */
/*@
    predicate in_range(integer low, integer high, integer x) =
        low <= x && x <= high;
    
    predicate result_condition(integer low, integer high, integer x, _Bool res) =
        res == 1 <==> in_range(low, high, x);
*/

_Bool check_in_range(unsigned int low, unsigned int high, unsigned int x)
{
    _Bool is_in_range = 0;
    
    //@ assert in_range(1, 10000, low);
    //@ assert in_range(1, 10000, high);
    //@ assert in_range(1, 10000, x);
    
    if (low <= x && x <= high) {
        is_in_range = 1;
    }
    
    //@ assert result_condition(low, high, x, is_in_range);
    return is_in_range;
}

/* Synthesized main function: validates inputs, computes distance, checks if distance is within threshold */
_Bool process_points(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,
                     unsigned int threshold_low, unsigned int threshold_high)
{
    bool valid = validate_inputs(x1, y1, x2, y2);
    //@ assert valid == true;
    
    unsigned int distance = compute_distance(x1, y1, x2, y2);
    //@ assert distance == manhattan_distance(x1, y1, x2, y2);
    
    _Bool result = check_in_range(threshold_low, threshold_high, distance);
    
    //@ assert result == 1 <==> in_range(threshold_low, threshold_high, distance);
    //@ assert result == 1 <==> (threshold_low <= distance && distance <= threshold_high);
    //@ assert result == 1 <==> (threshold_low <= manhattan_distance(x1, y1, x2, y2) && manhattan_distance(x1, y1, x2, y2) <= threshold_high);
    
    return result;
}
