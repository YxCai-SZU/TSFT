#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    requires 1 <= d <= 9;
    requires 1 <= e <= 9;
    ensures \result == ((((a) == (c) && (a) == (e)) ? 1 : (((a) == (c) && (a) != (e)) ? 1 : (((a) != (c) && (a) == (e)) ? 1 : 0))) + (((b) == (d) && (b) == (e)) ? 1 : (((b) == (d) && (b) != (e)) ? 1 : (((b) != (d) && (b) == (e)) ? 1 : 0))) > 0);
*/
bool func(int a, int b, int c, int d, int e)
{
    int z = 0;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    //@ assert (1 <= (d) <= 9);
    //@ assert (1 <= (e) <= 9);

    if (a == c && a == e) {
        z += 1;
    }
    if (b == d && b == e) {
        z += 1;
    }
    if (a == c && a != e) {
        z += 1;
    }
    if (b == d && b != e) {
        z += 1;
    }
    if (a != c && a == e) {
        z += 1;
    }
    if (b != d && b == e) {
        z += 1;
    }

    //@ assert 0 <= z <= 6;
    return z > 0;
}
