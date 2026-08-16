#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>

/* Original function 1: checks if exactly one pair matches among three digits */
/*@
    predicate is_valid_param(integer x) = 1 <= x <= 9;

    logic integer count_matches(integer a, integer b, integer c) =
        (a == b ? 1 : 0) + (b == c ? 1 : 0) + (c == a ? 1 : 0);

    lemma matches_range:
        \forall integer a, b, c;
            is_valid_param(a) && is_valid_param(b) && is_valid_param(c) ==>
                0 <= count_matches(a, b, c) <= 3;
*/

bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int aa;
    //@ assert is_valid_param(a) && is_valid_param(b) && is_valid_param(c);
    
    aa = (a == b ? 1 : 0) + (b == c ? 1 : 0) + (c == a ? 1 : 0);
    
    //@ assert aa == count_matches(a, b, c);
    //@ assert 0 <= aa <= 3;
    
    return aa == 1;
}

/* Original function 2: finds minimum absolute value in array of 5 elements */
/*@
    predicate valid_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate valid_array(int64_t* a, integer len) =
        len == 5 &&
        \valid(a+(0..len-1)) &&
        valid_range(a[0]) &&
        valid_range(a[1]) &&
        valid_range(a[2]) &&
        valid_range(a[3]) &&
        valid_range(a[4]);
*/

/*@
    logic integer abs_val(integer v) = v < 0 ? -v : v;
*/

int64_t func2(int64_t* a)
{
    int64_t ans;
    int i;
    ans = INT64_MAX;
    i = 0;

    while (i < 5)
    {
        int64_t ai;
        int64_t ans_abs;
        int64_t ai_abs;
        int64_t min_val;
        ai = a[i];
        
        //@ assert valid_range(ai);
        
        if (ans < 0) {
            ans_abs = -ans;
        } else {
            ans_abs = ans;
        }
        
        if (ai < 0) {
            ai_abs = -ai;
        } else {
            ai_abs = ai;
        }
        
        if (ans_abs < ai_abs) {
            min_val = ans_abs;
        } else {
            min_val = ai_abs;
        }
        
        ans = min_val;
        i = i + 1;
        
        //@ assert ans >= 0;
    }
    
    //@ assert ans >= 0;
    return ans;
}

/* Original function 3: counts increasing maxima in sequence of 100 values */
/*@ predicate valid_hs(unsigned long long* hs, integer len) =
    len == 100 &&
    \forall integer i; 0 <= i < len ==> 1 <= hs[i] <= 100;
*/

/*@ lemma hs_property_preserved:
    \forall unsigned long long* hs, integer len, integer index;
    valid_hs(hs, len) && 0 <= index <= len ==>
    \forall integer i; 0 <= i < len ==> 1 <= hs[i] <= 100;
*/

unsigned long long func3(unsigned long long* hs) {
    unsigned long long res = 0;
    unsigned long long max = 0;
    size_t index = 0;
    
    while (index < 100) {
        unsigned long long h = hs[index];
        if (max <= h) {
            res += 1;
            max = h;
        }
        index += 1;
    }
    return res;
}

/* 
 * Synthesized function: validate a 3-digit lock code against a pattern database
 * 
 * Scenario: A security system validates a 3-digit lock code (each digit 1-9) 
 * against stored patterns. It first checks if the code has exactly one matching 
 * pair (func1). If so, it retrieves the minimum absolute value from a 5-element 
 * sensor calibration array (func2), and uses this as a threshold to filter 
 * historical access patterns (func3). The final result indicates how many 
 * historical patterns exceed the threshold.
 * 
 * Data flow:
 * 1. func1 validates digit pattern (exactly one pair matches)
 * 2. If valid, func2 computes min absolute calibration value
 * 3. func3 counts patterns above threshold derived from calibration
 * 
 * High-level property: The count of patterns above threshold is consistent 
 * with the calibration data and lock code validity.
 */

unsigned long long synthesize_func(unsigned int a, unsigned int b, unsigned int c,
                                    int64_t* calib, unsigned long long* patterns)
{
    bool pair_match;
    int64_t min_abs;
    unsigned long long pattern_count;
    unsigned long long threshold;

    pair_match = func1(a, b, c);
    
    if (pair_match) {
        min_abs = func2(calib);
        
        threshold = (min_abs >= 0) ? (unsigned long long)min_abs : 0;
        
        pattern_count = func3(patterns);
    } else {
        pattern_count = 0;
    }
    
    //@ assert pattern_count <= 100;
    
    return pattern_count;
}

int main() {
    return 0;
}
