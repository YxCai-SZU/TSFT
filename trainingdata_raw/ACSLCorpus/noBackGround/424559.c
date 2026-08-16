#include <limits.h>
#include <stdbool.h>

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;
    return a < b && b < c;
}
