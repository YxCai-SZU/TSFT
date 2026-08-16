#include <stdbool.h>

/*@
    requires 0 <= i < n;
    requires ((i) % 2 == 0 && (n) % 2 == 0);
    ensures \result == true;
*/
bool verify_even_pair(int i, int n) {
    //@ assert ((i) % 2 == 0);
    //@ assert ((n) % 2 == 0);
    return true;
}
