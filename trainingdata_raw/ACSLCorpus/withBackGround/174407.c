#include <stdbool.h>

/*@ predicate is_equal(integer n, integer m) = n == m; */

/*@ lemma trivial_lemma: \forall integer n, m; is_equal(n, m) ==> is_equal(n, m); */

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func2(int n, int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

/*@ predicate is_sorted(integer x, integer y, integer z) = x <= y && y <= z; */

/*@ lemma sorted_lemma: \forall integer x, y, z; is_sorted(x, y, z) ==> is_sorted(x, y, z); */

/*@ requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    ensures \result == (x <= y && y <= z);
    assigns \nothing;
*/
bool func3(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x <= y && y <= z ==> x <= y && y <= z;
    return x <= y && y <= z;
}

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func4(unsigned int n, unsigned int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

/*@ requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func5(int n, int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}
