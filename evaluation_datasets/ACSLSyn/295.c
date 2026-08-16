#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_params_div(integer n, integer k) =
        0 <= n <= 1000000000000000000 &&
        1 <= k <= 1000000000000000000;
*/

int64_t func_div(int64_t n, int64_t k)
{
    int64_t quotient;
    int64_t remainder;
    int64_t abs_k;

    quotient = n;
    remainder = 0;
    abs_k = k < 0 ? -k : k;

    while (quotient >= abs_k)
    {
        quotient -= abs_k;
    }

    remainder = quotient;

    //@ assert remainder >= 0;
    //@ assert remainder < abs_k;

    if (remainder == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*@
    predicate valid_params_clamp(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer func_result(integer n, integer k) =
        n + k >= 0 ?
            (n >= 0 ? n : 0)
        : n + k;
*/

int64_t func_clamp(int64_t n, int64_t k)
{
    int64_t result;

    if (n + k >= 0) {
        if (n >= 0) {
            result = n;
        } else {
            result = 0;
        }
    } else {
        result = n + k;
    }

    return result;
}

/*@ predicate a_in_range(integer a) = 1 <= a && a <= 100; */
/*@ predicate b_in_range(integer b) = 1 <= b && b <= 100; */
/*@ predicate result_condition(integer a, integer b, bool result) = result == (b >= a); */

bool func_compare(int a, int b)
{
    bool result;
    
    result = (b >= a);
    return result;
}

int64_t resource_allocation_check(int64_t n, int64_t k, int64_t d, int64_t L)
{
    int64_t clamped;
    int64_t divisible;
    bool threshold_ok;
    int64_t result;
    
    clamped = func_clamp(n, k);
    
    divisible = func_div(clamped, d);
    
    if (clamped >= 1 && clamped <= 100) {
        threshold_ok = func_compare((int)L, (int)clamped);
    } else {
        threshold_ok = (clamped >= L);
    }
    
    if (divisible == 1 && threshold_ok) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
