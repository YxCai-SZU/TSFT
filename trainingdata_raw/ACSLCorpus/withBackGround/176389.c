#include <limits.h>

/*@
    predicate in_range(integer a) = -1000 <= a <= 1000;

    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;

    lemma product_bounds: \forall integer a, b; in_range(a) && in_range(b) ==> -1000000 <= prod(a,b) <= 1000000;
*/

/*@
    requires in_range(A) && in_range(B);
    ensures \result == sum(A,B) || \result == diff(A,B) || \result == prod(A,B);
    ensures \result >= sum(A,B) && \result >= diff(A,B) && \result >= prod(A,B);
*/
int func(int A, int B)
{
    int product;
    int sum;
    int difference;
    int result;

    //@ assert in_range(A) && in_range(B);
    //@ assert -1000000 <= prod(A,B) <= 1000000;

    product = A * B;
    sum = A + B;
    difference = A - B;

    if (product > sum)
    {
        if (product > difference)
        {
            result = product;
        }
        else
        {
            result = difference;
        }
    }
    else
    {
        if (sum > difference)
        {
            result = sum;
        }
        else
        {
            result = difference;
        }
    }

    //@ assert result == sum(A,B) || result == diff(A,B) || result == prod(A,B);
    //@ assert result >= sum(A,B) && result >= diff(A,B) && result >= prod(A,B);
    return result;
}
