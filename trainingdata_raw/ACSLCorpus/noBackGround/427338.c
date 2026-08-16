#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    requires a != b;
    ensures \result == ((a < c && c < b) || (a > c && c > b));
*/
bool func(int a, int b, int c) {
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert a != b;
    //@ assert a != c || b != c;

    result = (a < c && c < b) || (a > c && c > b);
    return result;
}
