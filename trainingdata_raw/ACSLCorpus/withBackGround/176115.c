#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer sum_plus_one(integer a, integer b) = a + b + 1;
    logic integer product_sum(integer a, integer b, integer c) = a * c + b * c;
    logic integer result_formula1(integer a, integer b, integer c) = sum_plus_one(a, b) * c;
    logic integer result_formula2(integer a, integer b, integer c) = product_sum(a, b, c);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == result_formula1(a, b, c) || \result == result_formula2(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum;
    int product;
    int result;

    //@ assert 1 <= a * c + b * c <= 162;
    sum = a + b + 1;
    product = a * c + b * c;

    if (sum > product)
    {
        //@ assert 1 <= sum * c <= 900;
        result = sum * c;
    }
    else
    {
        result = product;
    }

    //@ assert result == result_formula1(a, b, c) || result == result_formula2(a, b, c);
    return result;
}
