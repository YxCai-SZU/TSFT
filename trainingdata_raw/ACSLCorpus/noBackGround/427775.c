#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (500 * k >= x);
*/
bool func(int k, int x) {
    //@ assert 500 * k >= x ==> (500 * k >= x);
    return 500 * k >= x;
}

