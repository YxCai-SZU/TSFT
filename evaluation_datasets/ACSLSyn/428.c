#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* ACSL predicates and lemmas from the first snippet */
/*@
    predicate is_valid_input(integer x) = 1 <= x <= 32;
*/

int32_t func_parity(uint64_t input)
{
    int32_t result;
    
    //@ assert is_valid_input(input);
    
    if ((input & 0x1) == 1)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    
    return result;
}

/* ACSL predicates and lemmas from the second snippet */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer mod_100(integer n) = n % 100;
    logic integer mul_21(integer a) = a * 21;

    lemma mod_bound: \forall integer n; is_valid_n(n) ==> 0 <= mod_100(n) && mod_100(n) <= 99;
    lemma mul_bound: \forall integer a; 0 <= a && a <= 99 ==> 0 <= mul_21(a) && mul_21(a) <= 2079;
*/

int func_compare(int n)
{
    int a;
    int b;
    int c;
    int res;

    //@ assert is_valid_n(n);
    //@ assert 0 <= n % 100 && n % 100 <= 99;
    //@ assert 0 <= (n % 100) * 21 && (n % 100) * 21 <= 2079;

    a = n % 100;
    b = n / 100;
    c = a * 21;

    if (c >= n)
    {
        //@ assert a * 21 >= n;
        res = 1;
    }
    else
    {
        //@ assert a * 21 < n;
        res = 0;
    }

    return res;
}

/* ACSL predicates from the third snippet */
/*@
    predicate in_i32_range(integer v) = INT_MIN <= v <= INT_MAX;
 */

bool func_order(int a, int b, int c)
{
    //@ assert in_i32_range(a);
    //@ assert in_i32_range(b);
    //@ assert in_i32_range(c);
    return a < b && b < c;
}

/* ACSL predicates and lemmas from the fourth snippet */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer max_val(integer a, integer b) =
        a > b + 1 ? a - b - 1 : 0;

    logic integer min_val(integer a, integer b) =
        a > b ? 0 : b - a;

    logic integer diff(integer a, integer b) =
        max_val(a, b) < min_val(a, b) ?
        min_val(a, b) - max_val(a, b) :
        max_val(a, b) - min_val(a, b);

    lemma diff_nonnegative:
        \forall integer a, b; valid_range(a, b) ==> diff(a, b) >= 0;

    lemma diff_bound:
        \forall integer a, b; valid_range(a, b) ==> diff(a, b) <= a + b + 1;

    lemma sum_bound:
        \forall integer a, b; valid_range(a, b) ==> 0 <= a + b + 1 <= 201;
*/

int func_diff(int a, int b)
{
    int max_val;
    int min_val;
    int diff;
    int ans;

    //@ assert valid_range(a, b);
    
    if (a > b + 1) {
        max_val = a - b - 1;
    } else {
        max_val = 0;
    }
    //@ assert max_val == max_val(a, b);

    if (a > b) {
        min_val = 0;
    } else {
        min_val = b - a;
    }
    //@ assert min_val == min_val(a, b);

    if (max_val < min_val) {
        diff = min_val - max_val;
    } else {
        diff = max_val - min_val;
    }
    //@ assert diff == diff(a, b);

    //@ assert diff >= 0;
    //@ assert diff <= a + b + 1;
    //@ assert a + b + 1 >= 0;
    //@ assert a + b + 1 <= 201;

    ans = diff;
    return ans;
}

/* 
 * Scenario: Configuration validation for a network packet processor.
 * The synthesized function validates a configuration packet with:
 * - a version field (1-32)
 * - a sequence number (1-100000)
 * - three ordered parameters (a, b, c) that must be strictly increasing
 * - two range parameters (x, y) in [1,100] used for buffer size calculation
 * 
 * The function checks that:
 * 1. The version field is valid (odd/even check via func_parity)
 * 2. The sequence number meets a threshold relative to its modulo-100 value (func_compare)
 * 3. The three ordered parameters are strictly increasing (func_order)
 * 4. The difference between the two range parameters is within a bound (func_diff)
 * 
 * The high-level property: the configuration is valid only if all checks pass,
 * and the final result indicates whether the packet can be accepted.
 */

int validate_config_packet(uint64_t version, int seq_num, int a, int b, int c, int x, int y)
{
    int32_t parity_result;
    int compare_result;
    bool order_result;
    int diff_result;
    int final_result;

    parity_result = func_parity(version);
    //@ assert parity_result == 0 || parity_result == 1;

    compare_result = func_compare(seq_num);
    //@ assert compare_result == 1 || compare_result == 0;

    order_result = func_order(a, b, c);
    //@ assert order_result == (a < b && b < c);

    diff_result = func_diff(x, y);
    //@ assert diff_result >= 0;
    //@ assert diff_result <= x + y + 1;

    if (parity_result == 1 && compare_result == 1 && order_result == true && diff_result <= (x + y + 1) / 2)
    {
        final_result = 1;
    }
    else
    {
        final_result = 0;
    }

    //@ assert (final_result == 1) ==> (parity_result == 1 && compare_result == 1 && order_result == true && diff_result <= (x + y + 1) / 2);

    return final_result;
}
