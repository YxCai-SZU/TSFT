#include <stdbool.h>

/*@
    predicate valid_vector(int *v) =
        \valid(v) &&
        v[0] >= 1 && v[0] <= 10000 &&
        v[1] >= 1 && v[1] <= 10000 &&
        v[2] >= 1 && v[2] <= 10000 &&
        v[3] >= 1 && v[3] <= 10000;

    logic integer product1(integer a, integer b) = a * b;
    logic integer product2(integer c, integer d) = c * d;

    lemma product_bounds:
        \forall integer a, b;
        a >= 1 && a <= 10000 && b >= 1 && b <= 10000 ==>
        product1(a, b) >= 1 && product1(a, b) <= 100000000;

    lemma max_property:
        \forall integer a, b, c, d, max_val;
        (max_val == product1(a, b) || max_val == product2(c, d)) &&
        a >= 1 && a <= 10000 && b >= 1 && b <= 10000 &&
        c >= 1 && c <= 10000 && d >= 1 && d <= 10000 ==>
        max_val >= 1;
*/

/*@
    requires valid_vector(v);
    ensures \result >= 1;
    ensures \result == v[0] * v[1] || \result == v[2] * v[3];
    assigns \nothing;
*/
int func(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int product1_val;
    int product2_val;
    int max_val;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    //@ assert product1(a, b) >= 1 && product1(a, b) <= 100000000;
    //@ assert product2(c, d) >= 1 && product2(c, d) <= 100000000;

    product1_val = a * b;
    product2_val = c * d;

    if (product1_val > product2_val) {
        max_val = product1_val;
    } else {
        max_val = product2_val;
    }

    //@ assert max_val == product1(a, b) || max_val == product2(c, d);
    //@ assert max_val >= 1;

    return max_val;
}
