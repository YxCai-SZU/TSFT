#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;

    predicate is_sorted(int *v) =
        v[0] < v[1] && v[1] < v[2];
*/

/*@
    requires valid_vector(v, 3);
    ensures \result <==> is_sorted(v);
    assigns \nothing;
*/
bool func(int *v)
{
    int a;
    int b;
    int c;

    //@ assert 0 <= 0 && 0 < 3;
    a = v[0];
    //@ assert 0 <= 1 && 1 < 3;
    b = v[1];
    //@ assert 0 <= 2 && 2 < 3;
    c = v[2];

    //@ assert a == v[0] && b == v[1] && c == v[2];
    //@ assert valid_vector(v, 3) ==> (1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100);
    return a < b && b < c;
}
