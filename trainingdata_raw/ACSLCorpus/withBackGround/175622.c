#include <stdbool.h>

/*@ predicate is_sorted_strictly_increasing(integer a, integer b, integer c) =
    a < b && b < c;
*/
/*@ predicate is_sorted_strictly_decreasing(integer a, integer b, integer c) =
    a > b && b > c;
*/
/*@ predicate is_monotonic(integer a, integer b, integer c) =
    is_sorted_strictly_increasing(a, b, c) || is_sorted_strictly_decreasing(a, b, c);
*/

/*@ lemma distinct_implies_not_equal:
    \forall integer a, b, c;
    a != b && a != c && b != c ==> a != b && a != c && b != c;
*/

/*@
    requires \valid_read(v + (0..2));
    requires v[0] >= -100 && v[0] <= 100;
    requires v[1] >= -100 && v[1] <= 100;
    requires v[2] >= -100 && v[2] <= 100;
    requires v[0] != v[1] && v[0] != v[2] && v[1] != v[2];
    ensures \result == (v[0] < v[1] && v[1] < v[2] || v[0] > v[1] && v[1] > v[2]);
    assigns \nothing;
*/
bool func(const long long v[3]) {
    //@ assert v[0] >= -100 && v[0] <= 100;
    //@ assert v[1] >= -100 && v[1] <= 100;
    //@ assert v[2] >= -100 && v[2] <= 100;
    //@ assert v[0] != v[1] && v[0] != v[2] && v[1] != v[2];
    
    if ((v[0] < v[1] && v[1] < v[2]) || (v[0] > v[1] && v[1] > v[2])) {
        return true;
    } else {
        return false;
    }
}
