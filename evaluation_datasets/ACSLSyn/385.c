#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* ========== First function: compute half + remainder ========== */
/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 1000000000;
    
    logic integer half_value(integer x) = x / 2;
    logic integer remainder_value(integer x) = x % 2;
    
    lemma half_remainder_relation: \forall integer x; 
        is_valid_range(x) ==> 
        x == 2 * half_value(x) + remainder_value(x);
        
    lemma remainder_bounds: \forall integer x; 
        is_valid_range(x) ==> 
        0 <= remainder_value(x) && remainder_value(x) <= 1;
*/

long func_half_remainder(long x) {
    long half = 0;
    long temp_x = x;
    
    while (temp_x >= 2) {
        temp_x -= 2;
        half += 1;
    }
    
    long remainder;
    if (temp_x == 1) {
        remainder = 1;
    } else {
        remainder = 0;
    }
    
    //@ assert remainder == 0 || remainder == 1;
    
    return half + remainder;
}

/* ========== Second function: check divisibility by 3 or 5 ========== */
/*@
    predicate is_divisible_by_3(integer x) = x % 3 == 0;
    predicate is_divisible_by_5(integer x) = x % 5 == 0;
    
    lemma mod_abs_3: \forall integer x; (x < 0 ==> (-x) % 3 == -(x % 3)) && (x >= 0 ==> x % 3 == x % 3);
    lemma mod_abs_5: \forall integer x; (x < 0 ==> (-x) % 5 == -(x % 5)) && (x >= 0 ==> x % 5 == x % 5);
*/

int func_divisible(int x) {
    int is_divisible_by_3 = 0;
    int is_divisible_by_5 = 0;
    int abs_x;
    
    abs_x = (x < 0) ? -x : x;
    
    while (abs_x >= 3) {
        //@ assert abs_x >= 3;
        abs_x -= 3;
    }
    
    if (abs_x == 0) {
        is_divisible_by_3 = 1;
    }
    
    abs_x = (x < 0) ? -x : x;
    
    while (abs_x >= 5) {
        //@ assert abs_x >= 5;
        abs_x -= 5;
    }
    
    if (abs_x == 0) {
        is_divisible_by_5 = 1;
    }
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 0 <= abs_x && abs_x <= 100;
    
    return is_divisible_by_3 || is_divisible_by_5;
}

/* ========== Third function: diff check ========== */
/*@
    predicate valid_vec(int *v, integer len) =
        len == 3 &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 100 &&
        1 <= v[2] <= 100;

    logic integer diff(integer a, integer b) = b - a;

    predicate result_condition(integer a, integer b, integer c) =
        c >= diff(a, b);
*/

bool func_diff_check(int *v) {
    int diff_val;
    bool result;

    diff_val = v[1] - v[0];

    if (diff_val > v[2]) {
        //@ assert diff_val > v[2];
        result = false;
    } else {
        //@ assert diff_val <= v[2];
        result = true;
    }

    return result;
}

/* ========== Fourth function: approximate circle circumference ========== */
/*@ predicate is_valid_range_circ(integer r) = 1 <= r <= 100; */

/*@ logic integer pi_approx_const = 314159265359; */
/*@ logic integer divisor_const = 100000000000; */

/*@
    lemma product_formula:
        \forall integer r; is_valid_range_circ(r) ==> 
        (2 * r) * pi_approx_const == 2 * r * pi_approx_const;
*/

void func_circumference(int64_t r, int64_t *result) {
    int64_t pi_approx;
    int64_t two_r;
    int64_t product;
    int64_t divisor;
    int64_t local_result;
    int64_t remainder;
    int64_t count;
    
    pi_approx = 314159265359;
    two_r = 2 * r;
    product = two_r * pi_approx;
    divisor = 100000000000;
    local_result = 0;
    remainder = product;
    count = 0;
    
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        count += 1;
    }
    
    local_result = count;
    *result = local_result;
}

/* ========== Synthesized function: CircleAreaProcessor ========== */

int64_t process_circle_data(int64_t r, int *v, int64_t *result) {
    int64_t circumference = 0;
    bool divisible_check;
    bool diff_check;
    int64_t half_remainder_val;
    
    divisible_check = func_divisible((int)r);
    
    diff_check = func_diff_check(v);
    
    half_remainder_val = func_half_remainder((long)r);
    
    func_circumference(r, &circumference);
    
    if (divisible_check && diff_check) {
        *result = circumference;
    } else {
        *result = 0;
    }
    
    //@ assert *result == 0 || *result == (2 * r * pi_approx_const) / divisor_const;
    
    return *result;
}
