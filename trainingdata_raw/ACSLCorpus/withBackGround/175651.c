#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    lemma ans_value: \forall integer a, e; 0 <= a <= 123 && 0 <= e <= 123 && a < e ==> e - a == e - a;
*/

/*@
    requires 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123;
    requires 0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    requires is_ordered(a, b, c, d, e);
    ensures \result == (e - a <= k);
*/
bool func(long long a, long long b, long long c, long long d, long long e, long long k) {
    long long ans;
    long long max_val;
    long long min_val;
    long long i;

    ans = e - a;
    //@ assert ans == e - a;

    max_val = a;
    min_val = a;

    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    if (d > max_val) {
        max_val = d;
    }
    if (e > max_val) {
        max_val = e;
    }

    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    if (d < min_val) {
        min_val = d;
    }
    if (e < min_val) {
        min_val = e;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123;
        loop invariant 0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
        loop invariant is_ordered(a, b, c, d, e);
        loop invariant max_val == e;
        loop invariant min_val == a;
        loop invariant ans == e - a;
        loop assigns i;
    */
    while (i < 5) {
        i = i + 1;
    }

    //@ assert ans == e - a;

    return ans <= k;
}
