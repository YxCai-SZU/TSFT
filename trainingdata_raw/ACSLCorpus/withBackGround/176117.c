#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires is_ordered(a, b, c, d, e);
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    bool result;

    //@ assert is_ordered(a, b, c, d, e);
    dist = e - a;
    //@ assert dist == e - a;
    result = dist <= k;
    //@ assert dist <= k ==> result;
    //@ assert dist > k ==> !result;
    return result;
}
