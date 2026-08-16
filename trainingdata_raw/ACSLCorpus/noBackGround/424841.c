#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 2 && (n) <= 200000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000);
    assigns \nothing;
    ensures \result == (n > 2 || (n == 2 && a[0] == a[1]));
*/
bool func(size_t n, int *a) {
    // Variable declarations at top of scope
    bool result;

    if (n > 2) {
        result = true;
    } else {
        //@ assert n == 2;
        //@ assert a[0] > 0 && a[0] <= 1000000;
        //@ assert a[1] > 0 && a[1] <= 1000000;
        result = (a[0] == a[1]);
    }

    return result;
}
