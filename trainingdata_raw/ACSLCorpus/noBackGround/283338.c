#include <limits.h>
#include <stdint.h>

/*@
    requires ((a) >= INT_MIN / 2 && (a) <= INT_MAX / 2) && ((b) >= INT_MIN / 2 && (b) <= INT_MAX / 2);
    requires ((long long)(a) * (long long)(b) <= (long long)INT_MAX &&
        (long long)(a) * (long long)(b) >= (long long)INT_MIN);
    ensures \result == a * b;
*/
int multiply(int a, int b) {
    //@ assert ((a) >= INT_MIN / 2 && (a) <= INT_MAX / 2);
    //@ assert ((b) >= INT_MIN / 2 && (b) <= INT_MAX / 2);
    //@ assert ((long long)(a) * (long long)(b) <= (long long)INT_MAX &&         (long long)(a) * (long long)(b) >= (long long)INT_MIN);
    return a * b;
}
