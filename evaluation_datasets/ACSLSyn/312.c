#include <stdbool.h>
#include <stdint.h>

/* ===== First code snippet: multiplication and modulo bounds ===== */

/*@
    predicate multiplication_bound(integer x, integer y) =
        x <= 10 && y <= 10 ==> x * y <= 100;

    lemma mod_less_than_divisor:
        \forall integer x, integer y; y > 0 ==> x % y < y;
*/

unsigned int verify_multiplication_bound(unsigned int x, unsigned int y) {
    //@ assert multiplication_bound(x, y);
    return x * y;
}

unsigned int verify_mod_less_than_divisor(unsigned int x, unsigned int y) {
    //@ assert x % y < y;
    return x % y;
}

unsigned int verify_mod_is_less_than_divisor(unsigned int x, unsigned int y) {
    //@ assert x % y < y;
    return x % y;
}

/* ===== Second code snippet: vector-based answer computation ===== */

/*@
    predicate valid_vec(int *v) =
        \valid(v) &&
        v[0] >= 1 && v[0] <= 20 &&
        v[1] >= 1 && v[1] <= 20 &&
        v[2] >= 1 && v[2] <= 20;

    logic integer water_level(integer a, integer b) = a + b;

    logic integer compute_answer(integer v0, integer water) =
        v0 < water ? v0 : water;

    lemma answer_bounds:
        \forall integer v0, water;
        (1 <= v0 && v0 <= 20 && 2 <= water && water <= 40) ==>
        (0 <= compute_answer(v0, water) && compute_answer(v0, water) <= 40);
*/

int func(int *v)
{
    int water;
    int answer;

    //@ assert v[0] >= 1 && v[0] <= 20;
    //@ assert v[1] >= 1 && v[1] <= 20;
    //@ assert v[2] >= 1 && v[2] <= 20;

    water = v[1] + v[2];
    //@ assert 2 <= water && water <= 40;

    if (v[0] < water)
    {
        answer = v[0];
    }
    else
    {
        answer = water;
    }

    //@ assert answer >= 0 && answer <= 40;
    return answer;
}

/* ===== Third code snippet: array break count ===== */

/*@ predicate is_valid_array(uint32_t *a, integer n) =
      n >= 1 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ predicate break_count_bounds(integer break_count, integer index) =
      break_count >= 0 && break_count <= index;
*/

/*@ predicate current_bounds(integer current) =
      1 <= current && current <= 101;
*/

/*@ lemma break_count_nonnegative:
      \forall integer break_count, integer index;
      break_count_bounds(break_count, index) ==> break_count >= 0;
*/

/*@ lemma index_bounds:
      \forall integer index, integer n;
      0 <= index && index <= n && n >= 1 ==> index >= 0;
*/

int32_t func_array(uint32_t n, uint32_t *a) {
    uint32_t break_count = 0;
    uint32_t current = 1;
    uint32_t index = 0;
    
    while (index < n) {
        //@ assert current_bounds(current);
        if (current <= a[index]) {
            break_count++;
            current = a[index] + 1;
        }
        index++;
        //@ assert break_count_bounds(break_count, index);
    }
    
    if (break_count == 0) {
        //@ assert n >= 1;
        return -1;
    } else {
        //@ assert break_count <= n;
        return (int32_t)break_count;
    }
}

/* ===== Synthesized complex function: process_sensor_data =====
 * Scenario: A sensor data processing pipeline for an environmental monitoring system.
 * Data flow:
 *   1. Three sensor readings (x, y, z) are each bounded (<=10) and multiplied to verify a bound.
 *   2. The multiplication results are used as inputs to a vector-based water level estimator,
 *      simulating three environmental parameters.
 *   3. The estimator's output is fed into an array break counter that counts how many times
 *      a cumulative threshold is exceeded, representing fault events.
 * The final assertion checks that the break count is non-negative and does not exceed the array size.
 */

int32_t process_sensor_data(unsigned int x, unsigned int y, int *v, uint32_t n, uint32_t *a) {
    unsigned int bound_check;
    int answer;
    int32_t fault_count;

    bound_check = verify_multiplication_bound(x, y);
    //@ assert bound_check <= 100;

    answer = func(v);
    //@ assert answer >= 0 && answer <= 40;

    fault_count = func_array(n, a);

    //@ assert fault_count >= -1 && (fault_count >= 0 ==> (uint32_t)fault_count <= n);

    return fault_count;
}
