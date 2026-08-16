#include <stdbool.h>

/*@
    predicate is_triangle(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;

    lemma sum_bounds:
        \forall integer a, b, c;
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 ==>
        a + b <= 200 && a + c <= 200 && b + c <= 200;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == true <==> is_triangle(a, b, c);
*/
bool func(int a, int b, int c) {
    int x, y, z;
    
    // Sort variables: x >= y >= z
    if (a > b) {
        if (b > c) {
            x = a; y = b; z = c;
        } else if (a > c) {
            x = a; y = c; z = b;
        } else {
            x = c; y = a; z = b;
        }
    } else {
        if (a > c) {
            x = b; y = a; z = c;
        } else if (b > c) {
            x = b; y = c; z = a;
        } else {
            x = c; y = b; z = a;
        }
    }
    
    //@ assert x >= y && y >= z;
    //@ assert 0 <= x <= 100 && 0 <= y <= 100 && 0 <= z <= 100;
    
    if (x == y + z) {
        return true;
    } else {
        //@ assert y + z <= 200;
        //@ assert x + y <= 200;
        //@ assert x + z <= 200;
        return false;
    }
}
