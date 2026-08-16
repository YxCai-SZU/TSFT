#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

/* ============================================================
   Function 1: Compute (x*y) - (x+y) + 1 for valid ranges
   ============================================================ */
/*@
    predicate valid_range(integer v) = 2 <= v <= 100;

    logic integer target_result(integer x, integer y) = (x * y) - (x + y) + 1;

    lemma no_overflow_xy:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> x * y <= 10000;

    lemma result_consistent:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> target_result(x, y) == (x * y) - (x + y) + 1;
*/

int func1(int x, int y)
{
    unsigned int x_unsigned;
    unsigned int y_unsigned;
    unsigned int xy_unsigned;
    int xy;
    int x_plus_y;
    int result;

    if (x < 0)
    {
        //@ assert x >= -100;
        x_unsigned = (unsigned int)(-x);
    }
    else
    {
        x_unsigned = (unsigned int)x;
    }

    if (y < 0)
    {
        //@ assert y >= -100;
        y_unsigned = (unsigned int)(-y);
    }
    else
    {
        y_unsigned = (unsigned int)y;
    }

    //@ assert x_unsigned <= 100;
    //@ assert y_unsigned <= 100;
    //@ assert x_unsigned * y_unsigned <= 10000;

    xy_unsigned = x_unsigned * y_unsigned;

    if ((x < 0) != (y < 0))
    {
        xy = -(int)xy_unsigned;
    }
    else
    {
        xy = (int)xy_unsigned;
    }

    x_plus_y = x + y;
    result = xy - x_plus_y + 1;

    //@ assert result == target_result(x, y);
    return result;
}

/* ============================================================
   Function 2: Check if time * speed >= distance
   ============================================================ */
/*@
    predicate distance_in_range(integer d) = 1 <= d && d <= 10000;
    predicate time_in_range(integer t) = 1 <= t && t <= 10000;
    predicate speed_in_range(integer s) = 1 <= s && s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        time_in_range(t) && speed_in_range(s) ==>
        1 <= product(t, s) && product(t, s) <= 10000 * 10000;
*/

int func2(int d, int t, int s)
{
    int distance = d;
    int time = t;
    int speed = s;

    //@ assert 1 <= time && time <= 10000;
    //@ assert 1 <= speed && speed <= 10000;
    //@ assert 1 <= time * speed && time * speed <= 10000 * 10000;

    if (time * speed >= distance) {
        return 1;
    } else {
        return 0;
    }
}

/* ============================================================
   Function 3: Count elements where index+1 < value
   ============================================================ */
/*@ predicate valid_array(integer n, int* arr) =
      n > 0 && n <= 100 &&
      \valid(arr + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 100;
*/




int func3(size_t n, int* numbers) {
    size_t count = 0;
    size_t index = 0;
    
    //@ assert valid_array(n, numbers);
    
    while (index < n) {
        int num = numbers[index];
        
        //@ assert 1 <= num && num <= 100;
        
        if (index + 1 < (size_t)num) {
            count++;
        }
        
        index++;
    }
    
    //@ assert count <= n;
    //@ assert count >= 0;
    
    return (int)count;
}

/* ============================================================
   Synthesized Function: Process a batch of "distance-time-speed" records
   and return the number of records that can be covered.
   
   Real-world scenario: In a logistics planning system, we have a set of
   delivery routes. For each route, we have:
     - A coverage requirement (distance d) that must be met
     - Available time (t) and speed (s) resources
     - A priority index (x,y) used to compute a "feasibility score"
   
   The function filters routes where:
     1. The feasibility score (computed by func1) is positive
     2. The time*speed product is sufficient to cover the distance (func2)
   
   Then, among those feasible routes, it counts how many have a "tight"
   schedule (index+1 < route_id, where route_id is the value from the array).
   
   The final assertion states that the result count is bounded by the number
   of feasible routes, which is itself bounded by the array size.
   ============================================================ */

/*@
    predicate feasible_route(integer x, integer y, integer d, integer t, integer s) =
        valid_range(x) && valid_range(y) &&
        distance_in_range(d) && time_in_range(t) && speed_in_range(s) &&
        target_result(x, y) > 0 &&
        t * s >= d;
    
    predicate tight_condition(integer idx, integer val) =
        idx + 1 < val;
    
    lemma feasible_implies_valid:
        \forall integer x, y, d, t, s;
            feasible_route(x, y, d, t, s) ==>
            (valid_range(x) && valid_range(y) &&
             distance_in_range(d) && time_in_range(t) && speed_in_range(s));
*/

int process_routes(
    size_t n,
    int* numbers,
    int* x_arr,
    int* y_arr,
    int* d_arr,
    int* t_arr,
    int* s_arr
) {
    size_t feasible_count = 0;
    size_t tight_count = 0;
    size_t i = 0;
    
    //@ assert n > 0 && n <= 100;
    
    while (i < n) {
        int x = x_arr[i];
        int y = y_arr[i];
        int d = d_arr[i];
        int t = t_arr[i];
        int s = s_arr[i];
        int num = numbers[i];
        
        //@ assert valid_range(x) && valid_range(y);
        int score = func1(x, y);
        //@ assert score == target_result(x, y);
        
        //@ assert distance_in_range(d) && time_in_range(t) && speed_in_range(s);
        int can_cover = func2(d, t, s);
        //@ assert can_cover == (t * s >= d);
        
        if (score > 0 && can_cover == 1) {
            feasible_count++;
            
            //@ assert 1 <= num && num <= 100;
            if (i + 1 < (size_t)num) {
                tight_count++;
            }
        }
        
        i++;
    }
    
    //@ assert tight_count <= feasible_count && feasible_count <= n;
    //@ assert tight_count >= 0;
    
    //@ assert tight_count <= n && tight_count >= 0;
    
    return (int)tight_count;
}
