#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from the first function */
/*@
    predicate is_valid_range(integer n) = 100 <= n && n <= 999;

    logic integer next_multiple(integer n) = ((n / 111) + 1) * 111;

    lemma next_multiple_properties:
        \forall integer n; is_valid_range(n) ==>
            next_multiple(n) >= n &&
            next_multiple(n) % 111 == 0 &&
            next_multiple(n) / 111 > n / 111;
*/

uint64_t func1(uint64_t n)
{
    uint64_t num;
    uint64_t den;
    uint64_t result;

    //@ assert is_valid_range(n);
    num = n / 111;
    den = 111;
    result = (num + 1) * den;

    //@ assert result >= n;
    //@ assert result % 111 == 0;
    //@ assert result / 111 > n / 111;

    return result;
}

/* ACSL predicates and lemmas from the second function */
/*@
    predicate valid_params2(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;

    lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

int func2(unsigned int n, unsigned int a)
{
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;

    result = (int)(n * n - a);
    return result;
}

/* ACSL predicates and lemmas from the third function */
/*@ predicate valid_params3(integer n, integer m, integer len_a) =
      1 <= m <= n <= 100 &&
      m <= len_a <= n;
*/

/*@ predicate valid_array(int *a, integer len_a) =
      \forall integer k; 0 <= k < len_a ==> 1 <= a[k] <= 1000;
*/

/*@ predicate vec_eq{L}(int *v, int *a, integer i) =
      \forall integer j; 0 <= j < i ==> v[j] == a[j];
*/

/*@ lemma bounds_preserved:
      \forall integer n, m, len_a;
      valid_params3(n, m, len_a) ==> len_a <= n;
*/

size_t func3(size_t n, size_t m, int *a, size_t len_a) {
    int v[100];
    size_t i = 0;
    size_t v_len = 0;

    while (i < len_a) {
        v[i] = a[i];
        //@ assert v[i] == a[i];
        v_len = i + 1;
        i++;
    }

    size_t result = 0;
    size_t index = 0;

    while (index < v_len) {
        int x = v[index];
        if (x <= 500) {
            result++;
        }
        index++;
    }

    if (result >= m) {
        //@ assert result >= m;
        return n - result;
    } else {
        size_t diff = m - result;
        size_t ans = 0;
        i = 0;

        while (i < v_len) {
            int x = v[i];
            if (x > 500) {
                if (diff > 0) {
                    diff--;
                    ans++;
                } else {
                    break;
                }
            }
            i++;
        }
        //@ assert ans <= n;
        return ans;
    }
}

/* Synthesized function: process_sensor_data
 * Real-world scenario: A sensor data processing system that reads a sensor ID (3-digit number),
 * computes a derived parameter from calibration data, and filters sensor readings.
 * Data flow:
 *   1. func1: Takes a sensor ID (100-999) and computes the next multiple of 111 as a reference value.
 *   2. func2: Uses the reference value (mod 100 to fit constraints) and a calibration constant to compute a threshold.
 *   3. func3: Filters an array of sensor readings using n (sensor count), m (minimum valid readings), and the array.
 * The final result is the number of valid readings after filtering, ensuring it is within bounds.
 */
size_t process_sensor_data(uint64_t sensor_id, unsigned int n, unsigned int calib_const,
                           size_t m, int *a, size_t len_a)
{
    uint64_t ref_val;
    int threshold;
    size_t result;

    ref_val = func1(sensor_id);
    //@ assert ref_val % 111 == 0;

    //@ assert ref_val % 111 == 0;
    threshold = func2(n, calib_const);
    //@ assert threshold == (int)(n * n - calib_const);

    result = func3(n, m, a, len_a);
    //@ assert 0 <= result <= n;

    //@ assert 0 <= result <= n;
    return result;
}
