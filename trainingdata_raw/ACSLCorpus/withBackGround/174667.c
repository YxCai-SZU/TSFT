#include <limits.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;

    logic integer max_of_three(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x : ((y >= x && y >= z) ? y : z);

    lemma max_ge_all:
        \forall integer x, y, z;
        max_of_three(x, y, z) >= x &&
        max_of_three(x, y, z) >= y &&
        max_of_three(x, y, z) >= z;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
*/
long func(long a, long b)
{
    long add;
    long sub;
    long mul;
    long result;

    add = a + b;
    sub = a - b;
    //@ assert -10000 <= a * b <= 10000;
    mul = a * b;

    if (add >= sub && add >= mul)
    {
        result = add;
    }
    else if (sub >= add && sub >= mul)
    {
        result = sub;
    }
    else
    {
        result = mul;
    }

    //@ assert result == max_of_three(add, sub, mul);
    return result;
}
