/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;

    predicate k_in_range(integer k) = 0 <= k && k <= 123;

    lemma ordered_implies_positive:
        \forall integer a, b, c, d, e;
        is_ordered(a, b, c, d, e) ==> 0 <= a && 0 <= b && 0 <= c && 0 <= d && 0 <= e;
*/

#include <stdbool.h>

/*@
    requires is_ordered(a, b, c, d, e) && k_in_range(k);
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int state = 0;
    //@ assert is_ordered(a, b, c, d, e);
    //@ assert k_in_range(k);
    
    if (a + 1 >= e) {
        state = 1;
    } else if (b + 1 >= e) {
        state = 2;
    } else if (c + 1 >= e) {
        state = 3;
    } else if (d + 1 >= e) {
        state = 4;
    }
    
    //@ assert e - a <= k ==> \true;
    return e - a <= k;
}
