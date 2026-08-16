#include <stdbool.h>

/*@
    predicate valid_vec(int *v, integer len) =
        len == 4 &&
        \valid(v + (0 .. 3)) &&
        1 <= v[0] <= 10000 &&
        1 <= v[1] <= 10000 &&
        1 <= v[2] <= 10000 &&
        1 <= v[3] <= 10000;

    logic integer product1(integer a, integer b) = a * b;
    logic integer product2(integer c, integer d) = c * d;

    lemma product_bounds:
        \forall integer a, b, c, d;
        1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000 ==>
        product1(a, b) >= 1 && product2(c, d) >= 1 &&
        product1(a, b) <= 100000000 && product2(c, d) <= 100000000;
*/

/*@
    requires valid_vec(v, 4);
    ensures \result == product1(v[0], v[1]) || \result == product2(v[2], v[3]);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int product1;
    int product2;
    int max_value;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;

    //@ assert a * b <= 100000000;
    //@ assert c * d <= 100000000;

    product1 = a * b;
    product2 = c * d;

    //@ assert product1 >= 1;
    //@ assert product2 >= 1;

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    //@ assert max_value == product1 || max_value == product2;
    //@ assert max_value >= 1;

    return max_value;
}
