#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ========== ORIGINAL FUNCTION 1 (adapted for scenario) ========== */

/*@
    predicate valid_array(unsigned long long n, unsigned long long *h) =
        n > 0 &&
        \forall integer i; 0 <= i < n ==> h[i] > 0 && h[i] <= 1000000000;
*/

/*@
    logic integer max_attempt_bound(integer index) = index;
    logic integer current_attempt_bound(integer index) = index;
*/

/*@
    lemma bounds_lemma:
        \forall integer index; index >= 0 ==>
            max_attempt_bound(index) >= 0 &&
            current_attempt_bound(index) >= 0;
*/

unsigned long long compute_max_increasing_sequence(unsigned long long n, unsigned long long *h) {
    unsigned long long index = 0;
    unsigned long long max_attempt = 0;
    unsigned long long current_attempt = 0;
    
    while (index < n) {
        bool breaked = false;
        unsigned long long i = 0;
        
        while (i < index) {
            //@ assert 0 <= i < n;
            //@ assert 0 <= index < n;
            if (h[i] > h[index]) {
                breaked = true;
                break;
            }
            i++;
        }
        
        if (!breaked) {
            current_attempt++;
        }
        
        if (current_attempt > max_attempt) {
            max_attempt = current_attempt;
        }
        
        index++;
    }
    
    //@ assert 0 <= max_attempt <= n;
    return max_attempt;
}

/* ========== ORIGINAL FUNCTION 2 (adapted for scenario) ========== */

/*@ predicate exists_at_index{L}(int *arr, integer len, int value, integer i) =
    (0 <= i < len) && (arr[i] == value);
*/

/*@ predicate value_in_array{L}(int *arr, integer len, int value) =
    \exists integer i; exists_at_index{L}(arr, len, value, i);
*/

/*@ lemma not_found_in_prefix{L}:
    \forall int *arr, integer len, int value, integer prefix_len;
    (\forall integer j; 0 <= j < prefix_len ==> arr[j] != value) ==>
    !value_in_array{L}(arr, prefix_len, value);
*/

bool contains_value(const int *arr, size_t len, int value) {
    size_t i = 0;
    
    while (i < len) {
        //@ assert i < len;
        if (arr[i] == value) {
            //@ assert exists_at_index{Here}(arr, len, value, i);
            return true;
        }
        //@ assert arr[i] != value;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] != value;
    return false;
}

/* ========== ORIGINAL FUNCTION 3 (adapted for scenario) ========== */

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;
*/

/*@
    logic integer compute_n(integer x) = x / 100;
    logic integer compute_remained(integer x) = x % 100;
    logic integer compute_b(integer n, integer remained) = n * 5 + (remained / 5);
*/

/*@
    lemma division_bound: \forall integer x; is_valid_x(x) ==> x / 100 + x % 100 <= 100000;
    lemma modulo_bound: \forall integer x; is_valid_x(x) ==> x % 100 <= 100;
    lemma b_bound: \forall integer n, remained; 0 <= n && 0 <= remained <= 100 ==> 
                   compute_b(n, remained) <= n * 5 + remained / 5;
*/

int32_t compute_config_flag(uint32_t x) {
    uint32_t n;
    uint32_t remained;
    uint32_t a;
    uint32_t b;
    
    //@ assert x / 100 + x % 100 <= 100000;
    //@ assert x % 100 <= 100;
    
    n = x / 100;
    remained = x % 100;
    a = remained;
    b = n * 5 + (remained / 5);
    
    //@ assert b <= n * 5 + remained / 5;
    
    if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

/* ========== ORIGINAL FUNCTION 4 (adapted for scenario) ========== */

/*@
    predicate half_mod2_even(integer n, integer half) =
        (half % 2) == 0;

    logic integer compute_half(integer n) = n / 2;

    lemma half_range: \forall integer n; 1 <= n <= 100 ==> 0 <= compute_half(n) <= 50;
*/

_Bool check_half_even(int n)
{
    int half;
    _Bool is_even;
    int temp;

    half = n / 2;
    is_even = 1;
    temp = half;

    while (temp >= 2)
    {
        temp -= 2;
    }

    //@ assert temp == 0 || temp == 1;
    if (temp != 0)
    {
        is_even = 0;
    }

    //@ assert is_even == (half % 2 == 0);
    return is_even;
}

/* ========== SYNTHESIZED FUNCTION ========== */

/* 
 * Scenario: Configuration Validation System
 * 
 * This function validates a system configuration by:
 * 1. Checking if the maximum increasing sequence length in a data array meets a threshold
 * 2. Verifying the data array contains a specific configuration key
 * 3. Computing a configuration flag from a parameter
 * 4. Checking if a configuration parameter's half value is even
 * 
 * The combined property ensures that when the configuration is valid,
 * the maximum increasing sequence length is consistent with the configuration mode.
 */

int validate_configuration(unsigned long long n, unsigned long long *h, 
                           int config_param, uint32_t config_x,
                           const int *config_keys, size_t keys_len)
{
    unsigned long long max_seq_len;
    bool has_config_key;
    int32_t config_flag;
    _Bool half_is_even;
    unsigned long long threshold;
    
    max_seq_len = compute_max_increasing_sequence(n, h);
    //@ assert 0 <= max_seq_len <= n;
    
    has_config_key = contains_value(config_keys, keys_len, config_param);
    //@ assert has_config_key <==> value_in_array{Here}(config_keys, keys_len, config_param);
    
    config_flag = compute_config_flag(config_x);
    //@ assert config_flag == 0 || config_flag == 1;
    
    half_is_even = check_half_even(config_param);
    //@ assert half_is_even == (compute_half(config_param) % 2 == 0);
    
    if (has_config_key && config_flag == 1) {
        threshold = n / 2;
    } else {
        threshold = 0;
    }
    
    if (max_seq_len >= threshold && half_is_even) {
        //@ assert max_seq_len >= threshold && half_is_even;
        return 1;
    } else {
        return 0;
    }
}
