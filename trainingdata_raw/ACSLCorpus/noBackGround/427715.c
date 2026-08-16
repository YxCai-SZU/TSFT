#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result == (c >= a + b && a + b + 1 >= c - a - b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;
    unsigned int sum_ab;
    unsigned int expr_val;

    sum_ab = a + b;

    if (c < sum_ab)
    {
        result = false;
        //@ assert c < sum_ab;
        return result;
    }

    //@ assert c >= sum_ab;
    expr_val = c - sum_ab;
    result = (sum_ab + 1 >= expr_val);
    return result;
}
