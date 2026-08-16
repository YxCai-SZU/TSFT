#include <limits.h>

/*@ predicate is_min(integer val, integer a, integer b, integer c) =
    (val == a || val == b || val == c) &&
    (val <= a && val <= b && val <= c);
*/

/*@ lemma min_property:
    \forall integer a, b, c, m;
    is_min(m, a, b, c) ==> (m == a || m == b || m == c) && (m <= a && m <= b && m <= c);
*/

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result == a || \result == b || \result == c;
    ensures \result <= a && \result <= b && \result <= c;
    ensures is_min(\result, a, b, c);
*/
int min_of_three(int a, int b, int c) {
    int min_val = a;
    
    if (b < min_val) {
        min_val = b;
    }
    
    if (c < min_val) {
        min_val = c;
    }
    
    //@ assert min_val == a || min_val == b || min_val == c;
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    //@ assert is_min(min_val, a, b, c);
    
    return min_val;
}
