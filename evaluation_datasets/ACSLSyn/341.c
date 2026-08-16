/* ============================================================
   Scenario: Traffic Flow Monitoring System - Intersection State Validator
   
   A traffic monitoring system collects data from three sensors at an intersection:
   - Sensor A: vehicle count modulo 1000 (1..10000 raw count)
   - Sensor B: three-component vector (speed, occupancy, headway) with ranges
   - Sensor C: equality check between two normalized traffic parameters
   
   The synthesized function validates the overall intersection state by:
   1. Computing the corrected modulo count from Sensor A
   2. Computing a safety metric from Sensor B's vector
   3. Checking parameter consistency between two sensors
   
   The final assertion verifies that the output state satisfies the invariant:
   the computed safety metric is positive and bounded by the headway value.
   ============================================================ */

#include <stdbool.h>

/* ============================================================
   Function 1: Compute corrected modulo count
   ============================================================ */
/*@
    predicate is_mod_result(integer n, integer r) =
        1 <= n <= 10000 &&
        r == (1000 - n % 1000) % 1000 &&
        0 <= r < 1000;
*/

unsigned int compute_mod_count(unsigned int n)
{
    unsigned int result;
    //@ assert 1 <= n <= 10000;
    result = (1000 - n % 1000) % 1000;
    //@ assert is_mod_result(n, result);
    return result;
}

/* ============================================================
   Function 2: Compute safety metric from sensor vector
   ============================================================ */
/*@ predicate is_valid_vector(int *v, integer len) =
      len == 3 &&
      1 <= v[0] && v[0] <= 100 &&
      1 <= v[1] && v[1] <= 100 &&
      1 <= v[2] && v[2] <= 200;
*/

/*@ logic integer min_val(integer x, integer y) =
      (x < y) ? x : y;
*/

/*@ logic integer compute_result(integer x, integer y, integer z) =
      z - (x + y - min_val(x, y));
*/

/*@ lemma result_nonnegative:
      \forall integer x, y, z;
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        1 <= z <= 200 &&
        compute_result(x, y, z) >= 0 ==>
        compute_result(x, y, z) <= z;
*/

int compute_safety_metric(int *v)
{
    int x;
    int y;
    int z;
    int min_val;
    int result;

    //@ assert is_valid_vector(v, 3);
    x = v[0];
    y = v[1];
    z = v[2];

    //@ assert 1 <= x && x <= 100 && 1 <= y && y <= 100 && 1 <= z && z <= 200;

    if (x < y) {
        min_val = x;
    } else {
        min_val = y;
    }
    //@ assert min_val == min_val(x, y);

    result = z - (x + y - min_val);

    if (result < 0) {
        //@ assert result < 0;
        return 0;
    } else {
        //@ assert result >= 0;
        //@ assert result <= z;
        return result;
    }
}

/* ============================================================
   Function 3: Check parameter equality
   ============================================================ */
/*@
    predicate equal(integer n, integer m) = n == m;
*/

bool check_equality(int n, int m)
{
    bool properties_equal;
    int x;
    int y;
    int diff;

    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;

    if (n < 10 && m < 10) {
        properties_equal = (n == m);
    } else {
        if (n > m) {
            x = n;
            y = m;
        } else {
            x = m;
            y = n;
        }
        diff = x - y;
        properties_equal = (diff == 0);
    }

    //@ assert properties_equal == (n == m);
    return properties_equal;
}

/* ============================================================
   Synthesized Function: validate_intersection_state
   
   This function processes data from three sensors to validate
   the intersection state. The data flow:
   1. Raw count from sensor A (1..10000) -> corrected modulo count
   2. Vector from sensor B (speed, occupancy, headway) -> safety metric
   3. Two normalized parameters from sensors A and C -> consistency check
   
   The final assertion verifies that the safety metric is positive
   and bounded by the headway, ensuring safe intersection operation.
   ============================================================ */

int validate_intersection_state(unsigned int raw_count, int *sensor_vector, int param_a, int param_b)
{
    unsigned int corrected_count;
    int safety_metric;
    bool params_equal;
    
    /* Step 1: Compute corrected modulo count from sensor A */
    corrected_count = compute_mod_count(raw_count);
    
    /* Step 2: Compute safety metric from sensor vector */
    safety_metric = compute_safety_metric(sensor_vector);
    
    /* Step 3: Check parameter consistency */
    params_equal = check_equality(param_a, param_b);
    
    /* Core property: The safety metric must be positive and bounded by headway
       This is a high-level invariant ensuring safe intersection operation */
    //@ assert safety_metric >= 0 && safety_metric <= sensor_vector[2];
    
    return safety_metric;
}
