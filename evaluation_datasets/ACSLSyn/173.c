#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n && n <= 1000000000000000000 &&
        1 <= a && a < b && b <= n;

    logic integer func_result(integer n, integer a, integer b) =
        (a + b) % 2 == 0 ?
            (b - a) / 2 :
            (a - 1 < n - b ? a - 1 : n - b) + 1 + (b - a - 1) / 2;

    lemma result_bounds:
        \forall integer n, a, b;
        valid_params(n, a, b) ==>
        1 <= func_result(n, a, b) && func_result(n, a, b) <= n;
*/

uint64_t func(uint64_t n, uint64_t a, uint64_t b)
{
    uint64_t left_val;
    uint64_t right_val;
    uint64_t min_val;
    uint64_t ans;

    if ((a + b) % 2 == 0)
    {
        return (b - a) / 2;
    }
    else
    {
        left_val = a - 1;
        right_val = n - b;
        min_val = (left_val < right_val) ? left_val : right_val;
        ans = min_val + 1 + (b - a - 1) / 2;

        return ans;
    }
}

/*@
    predicate nonnegative(integer v) = v >= 0;
    predicate bounded(integer v) = v >= 0 && v <= 10;

    lemma distributive_property:
        \forall integer x, y, z;
            bounded(x) && bounded(y) && bounded(z) ==>
            x * (y + z) == x * y + x * z;
*/

int verify_nonlinear_arith(int x, int y, int z)
{
    int result;
    
    result = x * (y + z);
    
    return result;
}

/*@
    predicate valid_resource_config(integer n, integer a, integer b, integer x, integer y, integer z) =
        valid_params(n, a, b) &&
        bounded(x) && bounded(y) && bounded(z) &&
        func_result(n, a, b) >= 1 && func_result(n, a, b) <= n;
*/

int validate_segment_resource_allocation(uint64_t n, uint64_t a, uint64_t b, int x, int y, int z)
{
    uint64_t segment_distance;
    int resource_combined;
    int resource_separate;
    
    segment_distance = func(n, a, b);
    
    resource_combined = verify_nonlinear_arith(x, y, z);
    
    resource_separate = x * y + x * z;
    
    return 1;
}
