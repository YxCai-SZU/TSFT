#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (x) <= 100);
    ensures \result == (a <= x && x <= a + b);
*/
bool func(unsigned int a, unsigned int b, unsigned int x) {
    // Variable declarations at top of scope
    bool result;

    // Proof assertions
    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= x <= 100;

    result = (a <= x) && (x <= a + b);
    return result;
}
