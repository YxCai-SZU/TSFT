#include <stdbool.h>

/*@
    predicate is_sum_eq(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires a > 0 && b > 0 && c > 0;
    requires a + b + c <= 0x100000000;
    ensures \result == true <==> is_sum_eq(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum1;
    unsigned int sum2;
    unsigned int sum3;
    bool result;

    sum1 = a + b;
    sum2 = a + c;
    sum3 = b + c;

    //@ assert sum1 == a + b;
    //@ assert sum2 == a + c;
    //@ assert sum3 == b + c;

    result = (sum1 == c) || (sum2 == b) || (sum3 == a);
    return result;
}
