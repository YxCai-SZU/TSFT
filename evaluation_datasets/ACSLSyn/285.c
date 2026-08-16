#include <stdbool.h>
#include <stddef.h>

/* ========== Original Function 1 (adapted) ========== */
/*@
    predicate is_last_digit_nine(integer n) = n % 10 == 9;
    predicate is_n_greater_than_or_equal_to_90(integer n) = n >= 90;
*/

bool check_special(unsigned long n)
{
    unsigned int n_unsigned;
    unsigned int last_digit;
    bool is_last_digit_nine;
    bool is_n_greater_than_or_equal_to_90;
    bool result;
    
    n_unsigned = (unsigned int)n;
    last_digit = n_unsigned % 10;
    is_last_digit_nine = (last_digit == 9);
    is_n_greater_than_or_equal_to_90 = (n >= 90);
    
    //@ assert is_last_digit_nine == (n % 10 == 9);
    //@ assert is_n_greater_than_or_equal_to_90 == (n >= 90);
    
    result = is_last_digit_nine || is_n_greater_than_or_equal_to_90;
    return result;
}

/* ========== Original Function 2 (adapted) ========== */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 20 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 20;

    logic integer min_val(integer a, integer b, integer c) =
        (a <= b && a <= c) ? a :
        (b <= a && b <= c) ? b : c;

    logic integer max_val(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a :
        (b >= a && b >= c) ? b : c;
*/

long compute_score(long a, long b, long c) {
    long min_val;
    long max_val;
    long sum;
    bool is_even;
    long temp_sum;
    long ans;

    min_val = a;
    max_val = a;

    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    //@ assert min_val == min_val(a, b, c);

    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    //@ assert max_val == max_val(a, b, c);

    sum = min_val + max_val;
    //@ assert sum == min_val(a, b, c) + max_val(a, b, c);

    is_even = true;
    temp_sum = sum;

    while (temp_sum >= 2) {
        temp_sum -= 2;
    }

    if (temp_sum != 0) {
        is_even = false;
    }

    if (is_even) {
        ans = max_val * 2 - 1;
    } else {
        ans = sum;
    }

    //@ assert ans >= 0 && ans <= 40;
    return ans;
}

/* ========== Original Function 3 (adapted) ========== */
/*@ predicate all_odd_or_multiple_of_6_or_10(unsigned long long *a, integer len, integer i) =
       \forall integer j; 0 <= j < i ==> 
           (a[j] % 2 != 0) || (a[j] % 6 == 0) || (a[j] % 10 == 0);
*/

/*@ predicate valid_range(unsigned long long *a, integer len) =
       \forall integer k; 0 <= k < len ==> 1 <= a[k] && a[k] <= 1000;
*/

bool check_array_property(unsigned long long *a, size_t len) {
    size_t i = 0;
    
    while (i < len) {
        unsigned long long ai = a[i];
        
        //@ assert 1 <= ai && ai <= 1000;
        
        if (ai % 2 == 0 && ai % 6 != 0 && ai % 10 != 0) {
            return false;
        }
        
        i++;
    }
    return true;
}

/* ========== Synthesized Function ========== */
/*@
    predicate valid_student_ids(integer a, integer b, integer c) =
        1 <= a && a <= 20 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 20;

    predicate valid_scores(unsigned long long *scores, integer len) =
        \forall integer k; 0 <= k < len ==> 1 <= scores[k] && scores[k] <= 1000;
*/

long process_student_data(
    unsigned long long *scores,
    size_t len,
    unsigned long *student_ids,
    long *sids1,
    long *sids2,
    long *sids3
) {
    size_t i = 0;
    long total_score = 0;
    
    while (i < len) {
        bool special_flag = check_special(student_ids[i]);
        long computed_score = compute_score(sids1[i], sids2[i], sids3[i]);
        
        if (special_flag) {
            total_score += computed_score;
        }
        
        i++;
    }
    
    //@ assert total_score >= 0;
    return total_score;
}
