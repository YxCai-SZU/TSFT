#include <stdbool.h>

/*@ predicate sorted_nonnegative(integer a, integer b, integer c, integer d, integer e) =
    a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
    a < 124 && b < 124 && c < 124 && d < 124 && e < 124 &&
    a <= b && b <= c && c <= d && d <= e;
*/

/*@ logic integer absolute_diff(integer a, integer e) =
    (a > e) ? (a - e) : (e - a);
*/

/*@ lemma diff_definition:
    \forall integer a, e; absolute_diff(a, e) == ((a > e) ? (a - e) : (e - a));
*/

/*@
    requires sorted_nonnegative(a, b, c, d, e);
    requires k >= 0 && k <= 123;
    ensures \result == true <==> (e - a) <= k;
    ensures \result == false <==> (e - a) > k;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int diff;
    
    //@ assert absolute_diff(a, e) == ((a > e) ? (a - e) : (e - a));
    diff = (a > e) ? (a - e) : (e - a);
    
    //@ assert diff == absolute_diff(a, e);
    
    if (diff <= k)
    {
        //@ assert (e - a) <= k;
        return true;
    }
    else
    {
        //@ assert (e - a) > k;
        return false;
    }
}
