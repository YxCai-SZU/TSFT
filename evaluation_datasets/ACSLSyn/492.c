#include <stddef.h>
#include <stdint.h>

/* First function: compute some combinatorial value from n,m */
/*@
    predicate is_valid_input(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer min_val(integer n, integer m) =
        n < m ? n : m;

    logic integer left_n(integer n, integer m) =
        n - min_val(n, m);

    logic integer left_m(integer n, integer m) =
        m - min_val(n, m);

    logic integer ans_value(integer n, integer m) =
        min_val(n, m) +
        (left_n(n, m) / 2 * 2) +
        (left_m(n, m) > 0 ? ((left_m(n, m) - 1) / 2 * 2 + 1) : 0);

    lemma ans_bounded: \forall integer n, m;
        is_valid_input(n, m) ==> ans_value(n, m) <= n + m;
*/

size_t func1(size_t n, size_t m)
{
    size_t ans = 0;
    size_t min_val = 0;
    size_t left_n = 0;
    size_t left_m = 0;
    
    //@ assert 1 <= n && 1 <= m;
    
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    
    //@ assert min_val <= n && min_val <= m;
    ans += min_val;
    
    //@ assert n >= min_val;
    left_n = n - min_val;
    
    //@ assert m >= min_val;
    left_m = m - min_val;
    
    //@ assert left_n <= n;
    //@ assert left_m <= m;
    
    if (left_m > 0) {
        //@ assert left_m - 1 <= m;
        ans += left_n / 2 * 2 + (left_m - 1) / 2 * 2 + 1;
    } else {
        ans += left_n / 2 * 2;
    }
    
    //@ assert ans <= n + m;
    return ans;
}

/* Second function: check if a or b or a+b is divisible by 3 */
/*@
    predicate is_mod_zero(integer x) = x % 3 == 0;
    predicate condition_holds(integer a, integer b) =
        is_mod_zero(a) || is_mod_zero(b) || is_mod_zero(a + b);
*/

int32_t func2(uint32_t a, uint32_t b) {
    int32_t ans;
    uint32_t a_mod_3;
    uint32_t b_mod_3;
    uint32_t sum_mod_3;

    ans = 1;
    a_mod_3 = a % 3;
    b_mod_3 = b % 3;
    sum_mod_3 = (a + b) % 3;

    if (a_mod_3 != 0 && b_mod_3 != 0 && sum_mod_3 != 0) {
        ans = 0;
    }

    //@ assert ans == 0 || ans == 1;
    //@ assert ans == 1 ==> condition_holds(a, b);
    //@ assert ans == 0 ==> !condition_holds(a, b);

    return ans;
}

/* Third function: compute interior angle sum of N-gon */
/*@
    predicate valid_N(integer N) = 3 <= N <= 100;

    logic integer func_spec(integer N) = 180 * (N - 2);

    lemma func_lemma: \forall integer N; valid_N(N) ==> func_spec(N) == 180 * (N - 2);
*/

int32_t func3(uint32_t N)
{
    int32_t result;
    int32_t temp;

    //@ assert valid_N(N);
    temp = (int32_t)N - 2;
    //@ assert temp == N - 2;
    result = 180 * temp;
    //@ assert result == 180 * (N - 2);
    return result;
}

/* Fourth function: compute minimal time difference between two times */
/*@
    predicate valid_time_vector(int32_t *arr, integer len) =
        len == 4 &&
        0 <= arr[0] && arr[0] < 24 &&
        0 <= arr[1] && arr[1] < 60 &&
        0 <= arr[2] && arr[2] < 24 &&
        0 <= arr[3] && arr[3] < 60;

    logic integer time_minutes(integer hours, integer minutes) = hours * 60 + minutes;

    logic integer time_difference(integer a, integer b) = (a > b) ? (a - b) : (b - a);

    lemma difference_bound:
        \forall integer a, b, max;
        (0 <= a && a <= max && 0 <= b && b <= max) ==> 
        time_difference(a, b) <= max;
*/

int32_t func4(int32_t *v)
{
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t result;

    a = v[0] * 60 + v[1];
    b = v[2] * 60 + v[3];

    //@ assert 0 <= a && a < 24 * 60;
    //@ assert 0 <= b && b < 24 * 60;

    if (a > b) {
        c = a - b;
    } else {
        c = b - a;
    }

    //@ assert c == time_difference(a, b);
    //@ assert c <= 24 * 60;

    if (c > 24 * 60 - c) {
        result = 24 * 60 - c;
    } else {
        result = c;
    }

    //@ assert 0 <= result && result <= 24 * 60;
    return result;
}

/* 
 * Synthesized function: 
 * Scenario: A geometry puzzle game where you need to compute a score based on:
 * - The number of sides of a polygon (N)
 * - Two resource counts (n, m)
 * - Two time-based coordinates (start and end times)
 * - Two validation numbers (a, b)
 * 
 * The function computes a "puzzle score" that combines these elements.
 * The core invariant: the final score is non-negative and bounded by the sum of all inputs.
 */

int64_t puzzle_score(size_t n, size_t m, uint32_t a, uint32_t b, uint32_t N, int32_t *v)
{
    int64_t total_score = 0;
    
    size_t base_score = func1(n, m);
    //@ assert base_score <= n + m;
    total_score += (int64_t)base_score;
    
    int32_t bonus_flag = func2(a, b);
    //@ assert bonus_flag == 0 || bonus_flag == 1;
    //@ assert bonus_flag == 1 ==> condition_holds(a, b);
    
    int32_t angle_sum = func3(N);
    //@ assert angle_sum == 180 * (N - 2);
    
    int32_t time_penalty = func4(v);
    //@ assert 0 <= time_penalty && time_penalty <= 24 * 60;
    
    if (bonus_flag == 1) {
        total_score += (int64_t)angle_sum;
    }
    total_score += (int64_t)time_penalty;
    
    //@ assert total_score >= 0;
    //@ assert total_score <= n + m + 180 * (N - 2) + 24 * 60;
    
    return total_score;
}
