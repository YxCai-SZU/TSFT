#include <stdbool.h>

/*@
    predicate sum_ge_22(integer a, integer b, integer c, integer k) =
        a + b + c + k >= 22;
*/

/*@
    requires 1 <= a <= 7;
    requires 1 <= b <= 7;
    requires 1 <= c <= 7;
    requires 1 <= k <= 7;
    ensures \result == true <==> sum_ge_22(a, b, c, k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int k)
{
    unsigned int sum;
    bool is_enough;

    sum = a + b + c + k;
    is_enough = false;

    if (sum >= 22)
    {
        is_enough = true;
    }
    else
    {
        is_enough = false;
    }

    //@ assert is_enough == true <==> sum_ge_22(a, b, c, k);

    return is_enough;
}
