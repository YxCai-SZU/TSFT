#include <stdbool.h>

/*@ predicate sorted(integer x, integer y, integer z) = x <= y && y <= z; */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int x;
    int y;
    int z;
    int temp;

    x = a;
    y = b;
    z = c;

    //@ assert 1 <= x <= 100 && 1 <= y <= 100 && 1 <= z <= 100;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert x <= y;

    if (y > z) {
        temp = y;
        y = z;
        z = temp;
    }

    //@ assert y <= z;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert sorted(x, y, z);

    if (x + y == z) {
        return true;
    } else {
        return false;
    }
}
