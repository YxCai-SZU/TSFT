#include <stdbool.h>

/*@
    predicate valid_vec(int *v, integer len) =
        len == 3 &&
        \valid(v + (0 .. 2)) &&
        1 <= v[0] <= 500 &&
        1 <= v[1] <= 500 &&
        1 <= v[2] <= 1000;

    logic integer vector_sum(integer a, integer b) = a + b;

    lemma bounds_preserved:
        \forall integer a, b, c;
        (1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000) ==>
        (c <= vector_sum(a, b)) == (c <= a + b);
*/

/*@
    requires valid_vec(v, 3);
    ensures \result == (v[2] <= v[0] + v[1]);
    assigns \nothing;
*/
bool func(int *v)
{
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;

    result = (c <= a + b);
    return result;
}
