#include <stdbool.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 9;

    predicate condition_holds(integer a, integer b, integer c) =
        b == a + c || a == b + c || c == a + b;
*/

/*@
    requires \valid(v + (0..2));
    requires valid_range(v, 3);
    ensures \result <==> condition_holds(v[0], v[1], v[2]);
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;

    return b == a + c || a == b + c || c == a + b;
}
