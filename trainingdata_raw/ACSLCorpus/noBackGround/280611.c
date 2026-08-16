#include <stdbool.h>

/*@
    requires x != 0;
    ensures \result == ((x) * 2);
    ensures \result != 0;
*/
int example_double_nonzero(int x) {
    //@ assert x != 0;
    int result = x * 2;
    //@ assert result == ((x) * 2);
    //@ assert result != 0;
    return result;
}
