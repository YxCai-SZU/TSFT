#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a == b && b != c) || (a != b && a == c) || (a != b && b == c));
*/
bool func(long a, long b, long c) {
    long diff1;
    long diff2;
    long diff3;
    bool result;

    diff1 = (a > b) ? (a - b) : (b - a);
    diff2 = (b > c) ? (b - c) : (c - b);
    diff3 = (a > c) ? (a - c) : (c - a);

    if ((a == b && b != c) || (a != b && a == c) || (a != b && b == c)) {
        result = true;
    } else {
        //@ assert 0 <= diff1 <= 9;
        //@ assert 0 <= diff2 <= 9;
        //@ assert 0 <= diff3 <= 9;
        result = false;
    }
    return result;
}
