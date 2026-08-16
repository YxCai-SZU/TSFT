#include <stdbool.h>

/*@ predicate bounds(integer a, integer b, integer c, integer d) =
    a >= -100 && a <= 100 &&
    b >= -100 && b <= 100 &&
    c >= -100 && c <= 100 &&
    d >= -100 && d <= 100;
*/

/*@ predicate condition_a(integer a, integer c) = a == c; */

/*@ predicate condition_b(integer a, integer c) = a != c; */

/*@ lemma condition_split: \forall integer a, c;
    bounds(a, 0, c, 0) ==> (condition_a(a, c) || condition_b(a, c));
*/

/*@ logic integer result_a(integer b, integer d) = b - d; */

/*@ logic integer result_b(integer b, integer c) = c - b; */

/*@ requires \valid(v + (0..3));
    requires bounds(v[0], v[1], v[2], v[3]);
    ensures (v[0] == v[2] && \result == result_a(v[1], v[3])) ||
            (v[0] != v[2] && \result == result_b(v[1], v[2]));
*/
long func(long v[4]) {
    long a;
    long b;
    long c;
    long d;
    long res;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    if (a == c) {
        //@ assert condition_a(a, c);
        res = b - d;
        //@ assert res == result_a(b, d);
        return res;
    } else {
        //@ assert condition_b(a, c);
        res = c - b;
        //@ assert res == result_b(b, c);
        return res;
    }
}
