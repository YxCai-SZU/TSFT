#include <stdint.h>
#include <stdbool.h>

/* ===== func1: computes abs_diff(a,c) + b + d ===== */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate c_in_range(integer c) = 1 <= c <= 10000;
    predicate d_in_range(integer d) = 1 <= d <= 10000;
    
    logic integer abs_diff(integer a, integer c) = 
        a > c ? a - c : c - a;
    
    lemma abs_diff_nonneg: 
        \forall integer a, c; abs_diff(a, c) >= 0;
    
    lemma abs_diff_bound: 
        \forall integer a, c; 
        1 <= a <= 10000 && 1 <= c <= 10000 ==> 
        abs_diff(a, c) <= 9999;
    
    lemma result_formula: 
        \forall integer a, b, c, d, result;
        a_in_range(a) && b_in_range(b) && 
        c_in_range(c) && d_in_range(d) && 
        result == abs_diff(a, c) + b + d ==> 
        result >= 0;
*/

int64_t func1(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    //@ assert a >= c || c >= a;
    //@ assert (a > c ? a - c : c - a) >= 0;
    //@ assert (a > c ? a - c : c - a) <= 9999;
    
    //@ assert (a > c ? a - c : c - a) + b >= b;
    //@ assert (a > c ? a - c : c - a) + b <= 10000 + b;
    
    //@ assert (a > c ? a - c : c - a) + b + d >= d;
    //@ assert (a > c ? a - c : c - a) + b + d <= 10000 + b + d;
    
    result = (a > c ? a - c : c - a) + b + d;
    
    //@ assert result == abs_diff(a, c) + b + d;
    //@ assert result >= 0;
    
    return result;
}

/* ===== func2: checks if input is 3, 5, or 7 ===== */
/*@ predicate is_valid_input(integer n) = 1 <= n && n <= 9; */

bool func2(int input[1]) {
    int n;
    bool result;

    n = input[0];
    //@ assert 1 <= n && n <= 9;
    result = (n == 7 || n == 5 || n == 3);
    return result;
}

/* ===== func3: checks if product of x,y is within 10000 ===== */
/*@ predicate in_bounds(integer x, integer y) =
      0 <= x && x <= 100 &&
      0 <= y && y <= 100;
*/

/*@ predicate product_within_limit(integer x, integer y) =
      x * y <= 10000;
*/

/*@ lemma nonlinear_bound:
      \forall integer x, y;
        in_bounds(x, y) ==> product_within_limit(x, y);
*/

bool func3(unsigned int x, unsigned int y)
{
    unsigned int product;
    bool result;

    //@ assert in_bounds(x, y);
    
    product = x * y;
    
    //@ assert product_within_limit(x, y);
    
    result = product <= 10000;
    return result;
}

/* ===== Synthesized function: Image size calculator for a digital frame =====
   Scenario: A digital photo frame supports images with dimensions (width, height)
   each between 1 and 10000 pixels. The frame has a "safe zone" check: if the 
   aspect ratio key (a/c) corresponds to one of the special values 3, 5, or 7,
   then the image passes an aesthetic filter. Additionally, the frame validates
   that the scaled dimensions (using the absolute difference + offsets) produce
   a total pixel count that fits within a memory limit of 10000 * 100 pixels.
   
   The synthesized function orchestrates:
   1. func1: compute a composite size metric from four parameters
   2. func2: check if an aspect-ratio-related value is "special"
   3. func3: validate that two unsigned coordinates are within bounds
   
   The high-level property ensures that if all checks pass, the final result 
   is a non-negative integer representing a valid size in pixels.
*/
int64_t image_size_processor(int64_t a, int64_t b, int64_t c, int64_t d, 
                              unsigned int x, unsigned int y, 
                              int input[1])
{
    int64_t size_metric;
    bool is_special;
    bool bounds_ok;
    
    size_metric = func1(a, b, c, d);
    
    is_special = func2(input);
    
    bounds_ok = func3(x, y);
    
    //@ assert size_metric >= 0 && size_metric == abs_diff(a, c) + b + d;
    
    return size_metric;
}
