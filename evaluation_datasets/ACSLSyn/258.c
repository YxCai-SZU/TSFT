#include <stdbool.h>
#include <stdint.h>

/* ========== Original function 1 (adapted for counting odd numbers in even positions) ========== */
/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

int func1(unsigned int n, const long long *a) {
    int count = 0;
    unsigned int num = 0;
    unsigned int index = 0;
    
    while (num < n && index < n) {
        long long value = a[index];
        if (num % 2 == 0) {
            if ((unsigned int)value % 2 != 0) {
                count += 1;
            }
        }
        num += 1;
        index += 1;
    }
    //@ assert count >= 0 && count <= (int)n;
    return count;
}

/* ========== Original function 2 (unchanged) ========== */
/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 100 && 1 <= m && m <= n;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1) + m;

    lemma no_underflow: \forall integer n, integer m; valid_range(n, m) ==> n - 1 >= 0 && m - 1 >= 0;
    lemma product_nonnegative: \forall integer n, integer m; valid_range(n, m) ==> (n - 1) * (m - 1) >= 0;
    lemma product_bound: \forall integer n, integer m; valid_range(n, m) ==> (n - 1) * (m - 1) <= 99 * 99;
*/

long func2(long n, long m) {
    long result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    //@ assert n - 1 >= 0;
    //@ assert m - 1 >= 0;
    //@ assert (n - 1) * (m - 1) >= 0;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1) + m;
    //@ assert result >= 1 && result <= 10000;
    return result;
}

/* ========== Original function 3 (unchanged) ========== */
/*@ predicate vector_len_eq_two(int *v, integer len) =
    len == 2;
*/

/*@ predicate element0_nonnegative(int *v, integer len) =
    len > 0 ==> v[0] >= 0;
*/

/*@ predicate element1_upper_bound(int *v, integer len) =
    len > 1 ==> v[1] <= 1000000000;
*/

/*@ predicate result_condition(int *v, integer len, bool res) =
    len == 2 ==> (res == (v[0] <= v[1]));
*/

bool func3(int *v, int len)
{
    bool res;

    //@ assert vector_len_eq_two(v, len);
    //@ assert element0_nonnegative(v, len);
    //@ assert element1_upper_bound(v, len);
    //@ assert v[0] >= 0 && v[1] <= 1000000000;

    res = (v[0] <= v[1]);
    //@ assert res == (v[0] <= v[1]);
    return res;
}

/* ========== Synthesized function: process_input_data ========== */
/*
 * Real-world scenario: Process input data from a sensor array.
 * The sensor array produces values a[0..n-1] (1 <= value <= 1000000).
 * We count odd values at even positions (func1), use that count to compute
 * a derived parameter (func2), and then validate the result against
 * a threshold vector (func3).
 * Data flow: count_odd_even -> func1, derived_param -> func2(count_odd_even, n),
 *            threshold_check -> func3(threshold_vector, 2)
 */

int process_input_data(unsigned int n, const long long *a, int *threshold)
{
    int count_odd_even;
    long derived_param;
    bool threshold_check;
    int result;

    count_odd_even = func1(n, a);
    //@ assert count_odd_even >= 0 && count_odd_even <= (int)n;

    if (count_odd_even >= 1 && count_odd_even <= 100 && n >= 1 && n <= 100 && count_odd_even <= (int)n) {
        derived_param = func2((long)n, (long)count_odd_even);
        //@ assert derived_param == compute_result((long)n, (long)count_odd_even);
    } else {
        derived_param = 0;
    }

    threshold_check = func3(threshold, 2);
    //@ assert threshold_check == (threshold[0] <= threshold[1]);

    if (threshold_check && count_odd_even >= 1 && count_odd_even <= 100 && n >= 1 && n <= 100 && count_odd_even <= (int)n) {
        //@ assert derived_param >= 1 && derived_param <= 10000;
        result = 1;
    } else {
        result = 0;
    }

    //@ assert (result == 1) <==> (threshold_check == true && count_odd_even >= 1 && count_odd_even <= 100 && n >= 1 && n <= 100 && count_odd_even <= (int)n);
    return result;
}
