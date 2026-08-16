#include <stdbool.h>

/*@ predicate is_sorted(integer a, integer b, integer c, integer d, integer e) =
    a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
    a < b && b < c && c < d && d < e;
*/

/*@ logic integer abs_diff(integer first, integer last) =
    last > first ? last - first : first - last;
*/

/*@ lemma diff_non_negative:
    \forall integer first, last; abs_diff(first, last) >= 0;
*/

/*@
    requires is_sorted(a, b, c, d, e) && k >= 0;
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k) {
    int x[5];
    int first;
    int last;
    int diff;
    
    x[0] = a;
    x[1] = b;
    x[2] = c;
    x[3] = d;
    x[4] = e;
    
    first = x[0];
    last = x[4];
    
    //@ assert first == a;
    //@ assert last == e;
    
    if (last > first) {
        diff = last - first;
    } else {
        diff = first - last;
    }
    
    //@ assert diff == abs_diff(first, last);
    
    if (diff <= k) {
        //@ assert diff <= k;
        return true;
    } else {
        //@ assert diff > k;
        return false;
    }
}
