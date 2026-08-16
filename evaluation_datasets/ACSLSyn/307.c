#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* First function: score calculation */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        1 <= m <= n &&
        m <= 5;

    logic integer lower_bound(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    logic integer upper_bound(integer n, integer m) =
        100 * (n - m) + 1900 * m * 2;

    lemma ret_ge_lower_bound:
        \forall integer n, m, ret;
        valid_params(n, m) &&
        ret == (n < m ?
                100 * (n - m) + 1900 * m :
                100 * (n - m) + 1900 * m + 100 * (m - 1))
        ==> ret >= lower_bound(n, m);

    lemma ret_le_upper_bound:
        \forall integer n, m, ret;
        valid_params(n, m) &&
        ret == (n < m ?
                100 * (n - m) + 1900 * m :
                100 * (n - m) + 1900 * m + 100 * (m - 1)) &&
        ret >= lower_bound(n, m)
        ==> ret <= upper_bound(n, m);
*/

int32_t score_func(uint32_t n, uint32_t m) {
    int32_t ret;
    
    //@ assert valid_params(n, m);
    
    if (n < m) {
        ret = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    } else {
        ret = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m + 100 * ((int32_t)m - 1);
    }
    
    //@ assert ret >= 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    //@ assert ret <= 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m * 2;
    
    return ret;
}

/* Second function: position calculation */
/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100000;
    predicate valid_pair(integer n, integer v) = 
        valid_range(n) && 1 <= v && v <= n;
*/

/*@
    logic integer func_result(integer n, integer v) = n - v + 1;
*/

bool is_even(unsigned int n);

unsigned int input();

unsigned int pos_func(unsigned int n, unsigned int v)
{
    //@ assert valid_pair(n, v);
    unsigned int result = n - v + 1;
    //@ assert result == func_result(n, v);
    return result;
}

/* Third function: array validation */
/*@ predicate all_positive(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

bool validate_array(int *arr, size_t len) {
    //@ assert all_positive(arr, len);
    return true;
}

/* Synthesized function: process game scores and validate positions */
bool process_game_data(uint32_t n, uint32_t m, unsigned int v, int *scores, size_t len) {
    int32_t score = score_func(n, m);
    
    unsigned int pos = pos_func(n, v);
    
    bool valid = validate_array(scores, len);
    
    //@ assert score >= lower_bound(n, m) && score <= upper_bound(n, m) && pos == func_result(n, v) && valid == true;
    //@ assert (score >= 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m) && (score <= 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m * 2) && (pos == n - v + 1);
    
    return valid;
}
