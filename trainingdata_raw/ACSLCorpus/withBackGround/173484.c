#include <limits.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;
    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma min_ab_def: \forall integer a, b; in_range(a) && in_range(b) ==> 
        (min(a,b) == a || min(a,b) == b);
    lemma max_ab_def: \forall integer a, b; in_range(a) && in_range(b) ==> 
        (max(a,b) == a || max(a,b) == b);
    lemma sum_bound: \forall integer a, b, c, d, m1, m2; 
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        (m1 == a || m1 == b) && (m2 == c || m2 == d) ==> 
        m1 + m2 <= a + b + c + d;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
    ensures \result <= a + b + c + d;
*/
long func(long a, long b, long c, long d) {
    long min_ab;
    long min_cd;
    long max_ab;
    long max_cd;
    long ans;

    // Calculate min(a,b)
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == a || min_ab == b;

    // Calculate min(c,d)
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == c || min_cd == d;

    // Calculate max(a,b)
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    //@ assert max_ab == a || max_ab == b;

    // Calculate max(c,d)
    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    //@ assert max_cd == c || max_cd == d;

    ans = LONG_MAX;

    //@ assert min_ab + max_cd <= a + b + c + d;
    if (ans < min_ab + max_cd) {
        ans = ans;
    } else {
        ans = min_ab + max_cd;
    }

    //@ assert max_ab + min_cd <= a + b + c + d;
    if (ans < max_ab + min_cd) {
        ans = ans;
    } else {
        ans = max_ab + min_cd;
    }

    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    return ans;
}
