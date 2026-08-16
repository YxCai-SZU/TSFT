#include <stdint.h>

/*@
    predicate non_negative(integer x) = 0 <= x;
    predicate within_billion(integer x) = x <= 1000000000;
    predicate within_product_limit(integer p) = p <= 1000000000000000000;
*/

/*@
    requires non_negative(x) && non_negative(y);
    requires within_billion(x) && within_billion(y);
    ensures \result == x * y;
    assigns \nothing;
*/
int64_t non_linear_arith_example(int64_t x, int64_t y)
{
    int64_t result;

    //@ assert x * y <= 1000000000000000000;
    //@ assert x * y >= 0;

    result = x * y;
    return result;
}

int main()
{
    return 0;
}
