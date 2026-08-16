#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ========== Original Function 1: Check arithmetic progression ========== */

/*@ predicate valid_range(integer a, integer b, integer c) =
    a >= 1 && a <= 100 &&
    b >= 1 && b <= 100 &&
    c >= 1 && c <= 100;
*/

/*@ logic integer diff1(integer a, integer b) = b - a;
    logic integer diff2(integer b, integer c) = c - b;
    logic integer diff3(integer a, integer b) = a - b;
*/

/*@ lemma diff_bounds1: \forall integer a,b; 
    a >= 1 && a <= 100 && b >= 1 && b <= 100 ==> 
    diff1(a,b) >= -99 && diff1(a,b) <= 99;
*/
/*@ lemma diff_bounds2: \forall integer b,c; 
    b >= 1 && b <= 100 && c >= 1 && c <= 100 ==> 
    diff2(b,c) >= -99 && diff2(b,c) <= 99;
*/
/*@ lemma diff_bounds3: \forall integer a,b; 
    a >= 1 && a <= 100 && b >= 1 && b <= 100 ==> 
    diff3(a,b) >= -99 && diff3(a,b) <= 99;
*/

bool arithmetic_check(long v[3]) {
    long a;
    long b;
    long c;
    bool is_arithmetic;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert valid_range(a, b, c);
    //@ assert diff1(a,b) >= -99 && diff1(a,b) <= 99;
    //@ assert diff2(b,c) >= -99 && diff2(b,c) <= 99;
    //@ assert diff3(a,b) >= -99 && diff3(a,b) <= 99;
    
    is_arithmetic = (b - a == c - b);
    
    return is_arithmetic;
}

/* ========== Original Function 2: Count distinct peaks (adapted from original func) ========== */

/*@ predicate is_valid_array(size_t n, int64_t *p) =
    n >= 1 && n <= 200000 &&
    \valid(p + (0 .. n-1)) &&
    (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
    (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/

int64_t count_monotonic_segments(size_t n, const int64_t *p) {
    int64_t count = 0;
    int64_t m = p[0];
    size_t i = 0;
    
    while (i < n) {
        //@ assert 0 <= i < n;
        if (m >= p[i]) {
            count += 1;
        } else {
            m = p[i];
            count += 1;
        }
        i += 1;
    }
    //@ assert count >= 0;
    return count;
}

/* ========== Original Function 3: Check triangle condition (adapted from original func) ========== */

/*@ predicate valid_index(integer i, integer len) = 0 <= i < len;
    predicate valid_value(integer val) = 1 <= val <= 1000;
    predicate valid_array(int *arr, integer len) = 
        len >= 1 &&
        \forall integer i; 0 <= i < len ==> valid_index(i, len) && valid_value(arr[i]);
*/

/*@ predicate triangle_condition(int *arr, integer len) =
        len >= 3 &&
        (arr[0] + arr[1] == arr[2] ||
         arr[1] + arr[2] == arr[0] ||
         arr[2] + arr[0] == arr[1]);
*/

bool check_triangle(int *v, int len) {
    bool res;
    
    //@ assert len >= 1;
    
    res = (len >= 3 && 
           (v[0] + v[1] == v[2] || 
            v[1] + v[2] == v[0] || 
            v[2] + v[0] == v[1]));
    
    return res;
}

/* ========== Original Function 4: Compute sum of differences from minimum ========== */

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;

    logic integer min_of_three(integer a, integer b, integer c) =
        (a < b ? (a < c ? a : c) : (b < c ? b : c));

    lemma min_le_all:
        \forall integer a, b, c, m;
            m == min_of_three(a, b, c) ==> m <= a && m <= b && m <= c;

    lemma diff_nonnegative:
        \forall integer a, b, c, m;
            m == min_of_three(a, b, c) ==> a + b + c - 3 * m >= 0;

    lemma typed_diff_bounded:
        \forall integer a, b, c, m;
            (1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && m == min_of_three(a, b, c)) ==>
            a + b + c - 3 * m <= a + b + c;
*/

int sum_diff_from_min(int a, int b, int c)
{
    int min_ab;
    int min_bc;
    int min_ac;
    int min;
    int diff;

    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);

    min_ab = a < b ? a : b;
    min_bc = b < c ? b : c;
    min_ac = a < c ? a : c;
    min = min_ab < min_bc ? min_ab : min_bc;
    min = min < min_ac ? min : min_ac;

    //@ assert min == min_of_three(a, b, c);
    //@ assert min <= a && min <= b && min <= c;

    diff = a + b + c - 3 * min;

    //@ assert diff >= 0;
    //@ assert diff <= a + b + c;

    return diff;
}

/* ========== Synthesized Complex Function: Geometric Sequence Analyzer ========== */

int analyze_geometric_sequence(long v[3]) {
    int a, b, c;
    bool is_arith;
    int diff_sum;
    
    a = (int)v[0];
    b = (int)v[1];
    c = (int)v[2];
    
    is_arith = arithmetic_check(v);
    
    diff_sum = sum_diff_from_min(a, b, c);
    
    int triangle_array[3] = {a, b, c};
    bool is_triangle = check_triangle(triangle_array, 3);
    
    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);
    //@ assert diff_sum >= 0 && diff_sum <= a + b + c;
    
    return diff_sum;
}
