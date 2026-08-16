#include <limits.h>

/*@
    predicate all_equal(integer a, integer b, integer c) = a == b && b == c;
    predicate all_different(integer a, integer b, integer c) = a != b && b != c && a != c;
    predicate two_equal(integer a, integer b, integer c) = (a == b || b == c || a == c) && !(a == b && b == c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures (\result == 1) ==> all_equal(a, b, c);
    ensures (\result == 2) ==> all_different(a, b, c);
    ensures (\result == 3) ==> two_equal(a, b, c);
*/
int func(int a, int b, int c)
{
    int r = -1;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    
    if (a == b && b == c) {
        r = 1;
        //@ assert all_equal(a, b, c);
    } else if (a != b && b != c && a != c) {
        r = 2;
        //@ assert all_different(a, b, c);
    } else {
        r = 3;
        //@ assert two_equal(a, b, c);
    }
    
    //@ assert r >= 1 && r <= 3;
    return r;
}
