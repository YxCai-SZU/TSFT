#include <stdbool.h>

/*@
    predicate exactly_one_equal(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && a != b);
 */

bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int count = 0;

    if (a == b) {
        count += 1;
    }
    if (a == c) {
        count += 1;
    }
    if (b == c) {
        count += 1;
    }

    return count == 1;
}

/*@
    predicate is_valid_params(integer k, integer a, integer b) =
        1 <= k <= 1000 &&
        1 <= a <= b <= 1000;

    logic integer compute_limit(integer k, integer b) = b - b % k;

    lemma mod_bound:
        \forall integer k, b; 1 <= k <= 1000 && 1 <= b <= 1000 ==> b % k <= b;

    lemma limit_bound:
        \forall integer k, b; 1 <= k <= 1000 && 1 <= b <= 1000 ==> b - b % k <= 1000;
*/

bool func2(unsigned int k, unsigned int a, unsigned int b)
{
    unsigned int a_limit;

    a_limit = b - b % k;
    
    if (a <= a_limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool resource_allocation_validator(unsigned int k, unsigned int a, unsigned int b, unsigned int c)
{
    bool exactly_one_equal_result;
    bool fits_limit_result;
    
    exactly_one_equal_result = func1(a, b, c);
    fits_limit_result = func2(k, a, b);
    
    return exactly_one_equal_result && fits_limit_result;
}
