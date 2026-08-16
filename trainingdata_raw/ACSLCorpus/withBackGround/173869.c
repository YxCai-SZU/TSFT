#include <stdbool.h>

/*@
    predicate within_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a < b < c < d < e < 123 &&
        0 <= k <= 123;

    logic integer absolute_distance(integer a, integer e) =
        a > e ? a - e : e - a;

    lemma dist_correctness:
        \forall integer a, e;
            absolute_distance(a, e) == (a > e ? a - e : e - a);
*/

/*@
    requires within_range(a, b, c, d, e, k);
    ensures \result == true <==> (e - a) <= k;
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;

    //@ assert within_range(a, b, c, d, e, k);
    
    if (a > e) {
        dist = a - e;
    } else {
        dist = e - a;
    }
    
    //@ assert dist == absolute_distance(a, e);
    
    if (dist <= k) {
        //@ assert (e - a) <= k;
        return true;
    } else {
        //@ assert (e - a) > k;
        return false;
    }
}
