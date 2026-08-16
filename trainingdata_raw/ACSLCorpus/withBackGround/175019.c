#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 200;

    logic integer sum_compare(integer a, integer b, integer c) = a + b >= c ? 1 : 0;
*/

/*@
    requires \valid(v + (0..2));
    requires 1 <= v[0] <= 100;
    requires 1 <= v[1] <= 100;
    requires 1 <= v[2] <= 200;
    ensures \result == (v[0] + v[1] >= v[2]);
*/
bool func(int v[3]) {
    bool result = false;
    int a = 0;
    int b = 0;
    int c = 0;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert valid_range(a, b, c);
    
    if (a + b >= c) {
        result = true;
    }

    //@ assert result == (a + b >= c);
    return result;
}
