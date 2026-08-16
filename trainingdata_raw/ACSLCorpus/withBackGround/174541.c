#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    
    predicate condition_holds(integer a, integer e, integer k) =
        e - a <= k;
*/

/*@
    requires in_range(a, b, c, d, e);
    requires k <= 123;
    ensures \result == true <==> condition_holds(a, e, k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    bool res;
    
    //@ assert in_range(a, b, c, d, e);
    //@ assert k <= 123;
    
    if (e - a <= k) {
        res = true;
    } else {
        res = false;
    }
    
    //@ assert res == true <==> (e - a <= k);
    
    return res;
}
