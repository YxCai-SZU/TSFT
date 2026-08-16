#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

/* ============================================================
   Original functions (with their ACSL specifications)
   ============================================================ */

/* --- Function 1: compute count of 100-unit steps --- */
/*@
    predicate valid_x(integer x) = 101 <= x <= 1000000000000000000;
    predicate valid_temp_x(integer x, integer temp_x) = 
        0 <= temp_x <= x - 100;
    predicate valid_count(integer x, integer temp_x, integer count) = 
        0 <= count <= (x - 100 - temp_x) / 100;
    predicate temp_x_relation(integer x, integer temp_x, integer count) = 
        temp_x == x - 100 - 100 * count;
*/

uint64_t step_count(uint64_t x) {
    uint64_t result;
    uint64_t temp_x;
    uint64_t count;
    
    result = 0;
    temp_x = x - 100;
    count = 0;
    
    while (temp_x >= 100) {
        //@ assert temp_x >= 100;
        count += 1;
        temp_x -= 100;
    }
    
    result = count;
    return result;
}

/* --- Function 2: bitwise OR identity --- */
/*@
    predicate is_valid_input(integer x) = x == 5 || x == 7;
    logic integer bitwise_or_zero(integer x) = x | 0;
    lemma or_identity_property: \forall integer x; is_valid_input(x) ==> bitwise_or_zero(x) == x;
    lemma result_range: \forall integer x; is_valid_input(x) ==> (bitwise_or_zero(x) == 5 || bitwise_or_zero(x) == 7);
*/

uint32_t test_or_identity(uint32_t x) {
    uint32_t result;
    
    //@ assert x == 5 || x == 7;
    //@ assert (x & 0) == 0;
    //@ assert (x | 0) == x;
    //@ assert x == 5 || x == 7;
    
    result = x | 0;
    
    //@ assert result == 5 || result == 7;
    
    return result;
}

/* --- Function 3: time difference with threshold --- */
/*@
    predicate time_in_range(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;
    
    predicate valid_interval(integer h1, integer m1, integer h2, integer m2) =
        h1 < h2 || (h1 == h2 && m1 <= m2);
    
    logic integer time_difference(integer h1, integer m1, integer h2, integer m2) =
        60 * (h2 - h1) + m2 - m1;
*/

int time_diff_threshold(int h1, int m1, int h2, int m2, int k)
{
    int ans;
    int temp;
    
    //@ assert 60 * (h2 - h1) + m2 - m1 - k <= 60 * 23 + 59;
    temp = 60 * (h2 - h1) + m2 - m1 - k;
    
    //@ assert temp >= 0 - 1439;
    ans = temp < 0 ? 0 : temp;
    
    return ans;
}

/* --- Function 4: array comparison scoring --- */
/*@ predicate valid_range(integer n) = 1 <= n <= 200000;
    predicate valid_array(int *arr, integer n) = 
        \valid(arr + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 200000;
    predicate answer_bounds(integer ans, integer idx) = 
        ans >= 0 && ans <= idx * 3;
*/

long array_score(long n, int *a, int *b) {
    long answer = 0;
    size_t index = 0;
    
    while (index < (size_t)n) {
        int a_value = a[index];
        int b_value = b[index];
        
        //@ assert 1 <= a_value <= 200000;
        //@ assert 1 <= b_value <= 200000;
        
        if (a_value == b_value) {
            answer += 1;
        } else if (a_value < b_value) {
            answer += 2;
        } else {
            answer += 3;
        }
        index++;
        
        //@ assert answer_bounds(answer, index);
    }
    return answer;
}

/* ============================================================
   Synthesized function: traffic light pattern analyzer
   Scenario: Analyze traffic light timing patterns from sensor data.
   Data flow:
     1. step_count: compute number of 100ms intervals in a cycle period
     2. test_or_identity: validate sensor status flags (must be 5 or 7)
     3. time_diff_threshold: compute adjusted time difference between two events
     4. array_score: compare two arrays of sensor readings and compute score
   The synthesized function combines these to analyze a traffic light cycle.
   ============================================================ */

/*@
    predicate valid_cycle_analysis(integer steps, integer flag, integer time_gap, integer score) =
        steps >= 0 && (flag == 5 || flag == 7) && time_gap >= 0 && score >= 0;
*/

struct cycle_result {
    uint64_t steps;
    uint32_t flag;
    int time_gap;
    long score;
};

struct cycle_result analyze_traffic_cycle(uint64_t cycle_period_ms, uint32_t sensor_flag,
                        int h1, int m1, int h2, int m2, int k,
                        long n, int *a, int *b)
{
    struct cycle_result result;
    
    uint64_t steps = step_count(cycle_period_ms);
    //@ assert steps <= cycle_period_ms - 100;
    
    uint32_t flag = test_or_identity(sensor_flag);
    //@ assert flag == 5 || flag == 7;
    
    int time_gap = time_diff_threshold(h1, m1, h2, m2, k);
    //@ assert time_gap >= 0;
    
    long score = array_score(n, a, b);
    //@ assert score >= 0;
    
    result.steps = steps;
    result.flag = flag;
    result.time_gap = time_gap;
    result.score = score;
    
    //@ assert valid_cycle_analysis(result.steps, result.flag, result.time_gap, result.score);
    
    return result;
}
