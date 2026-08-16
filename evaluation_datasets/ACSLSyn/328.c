/* ========== Scenario: Video Stream Quality Assessment ==========
 * In a video processing pipeline, we need to determine if a segment
 * of video frames meets a certain quality threshold. The quality
 * depends on the difference between two parameters (a, b), the
 * frame offset (n), and the product of frame dimensions (a,b,c,d).
 * 
 * Data Flow:
 * 1. func1: Compute quality difference based on parameters a, b.
 * 2. func2: Compute frame alignment offset based on n.
 * 3. func3: Check if quality threshold is exceeded based on dimensions.
 * 
 * The composite function checks if the overall quality metric is valid.
 */

#include <stdbool.h>

/* ========== Original Function 1 (adapted from snippet 1) ========== */
/*@
    predicate is_valid_params(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b;

    lemma result_nonnegative:
        \forall integer a, b;
        is_valid_params(a, b) && compute_result(a, b) > 0 ==>
        compute_result(a, b) >= 0;

    lemma result_zero_or_diff:
        \forall integer a, b;
        is_valid_params(a, b) ==>
        (compute_result(a, b) > 0 ==> compute_result(a, b) == a - 2 * b) &&
        (compute_result(a, b) <= 0 ==> 0 == 0);
*/

void func1(long long a, long long b, long long *result)
{
    long long tmp;
    //@ assert is_valid_params(a, b);
    tmp = a - 2 * b;
    if (tmp > 0) {
        //@ assert tmp == a - 2 * b;
        *result = tmp;
    } else {
        //@ assert 0 == 0;
        *result = 0;
    }
    //@ assert *result >= 0;
}

/* ========== Original Function 2 (adapted from snippet 2) ========== */
/*@
    predicate valid_range(integer n) = 1 <= n && n <= 10000;

    logic integer compute_result2(integer n) =
        (1000 - n % 1000) % 1000;

    lemma result_property:
        \forall integer n;
        valid_range(n) ==>
        (compute_result2(n) == 0 || compute_result2(n) == 1000 - n % 1000);
*/

int func2(int n)
{
    unsigned long long n_unsigned;
    unsigned long long result_unsigned;
    int result;

    //@ assert valid_range(n);
    if (n < 0)
    {
        n_unsigned = (unsigned long long)(-(long long)n);
    }
    else
    {
        n_unsigned = (unsigned long long)n;
    }

    result_unsigned = (1000 - n_unsigned % 1000) % 1000;

    if (n < 0)
    {
        result = -(int)result_unsigned;
    }
    else
    {
        result = (int)result_unsigned;
    }

    //@ assert result == 0 || result == 1000 - n % 1000;
    return result;
}

/* ========== Original Function 3 (adapted from snippet 3) ========== */
/*@
    predicate bounds(integer v) = 1 <= v <= 10000;

    lemma mul_bounds:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> 1 <= x * y <= 10000 * 10000;
*/

bool func3(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert bounds(a) && bounds(b) && bounds(c) && bounds(d);
    //@ assert 1 <= a * b <= 10000 * 10000;
    //@ assert 1 <= c * d <= 10000 * 10000;
    //@ assert (a * b) - 1 < c * d || (a * b) - 1 >= c * d;
    
    return (a * b) - 1 < c * d;
}

/* ========== Synthesized Composite Function ========== */
bool composite_quality_check(long long a, long long b, int n,
                             unsigned int ua, unsigned int ub,
                             unsigned int uc, unsigned int ud)
{
    long long diff_result;
    int offset_result;
    bool threshold_result;
    
    diff_result = 0;
    func1(a, b, &diff_result);
    //@ assert diff_result >= 0;
    //@ assert diff_result == a - 2 * b || diff_result == 0;
    
    offset_result = func2(n);
    //@ assert offset_result == 0 || offset_result == 1000 - n % 1000;
    
    threshold_result = func3(ua, ub, uc, ud);
    //@ assert threshold_result == ((ua * ub) - 1 < uc * ud);
    
    
    return (diff_result == 0) || (diff_result > 0 && threshold_result == true);
}
