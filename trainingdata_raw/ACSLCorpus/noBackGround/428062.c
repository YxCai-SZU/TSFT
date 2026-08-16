#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    requires a != b;
    ensures \result == (a < b && b < c);
*/
bool func(long long a, long long b, long long c) {
    //@ assert 1 <= a <= 1000000000 && 1 <= b <= 1000000000 && 1 <= c <= 1000000000;
    //@ assert ((a) != (b) && (b) != (c) && (a) != (c)) || a == b || b == c || a == c;
    return a < b && b < c;
}
