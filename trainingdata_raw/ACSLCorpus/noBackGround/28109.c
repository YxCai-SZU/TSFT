#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3);
    requires (1 <= (b) <= 3);
    requires ((a) != (b));
    ensures ((\result) == 6 - (a) - (b));
    ensures ((\result) == 1 || (\result) == 2 || (\result) == 3);
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert ((a) != (b));
    result = 6 - a - b;
    //@ assert ((result) == 6 - (a) - (b));
    //@ assert ((result) == 1 || (result) == 2 || (result) == 3);
    return result;
}
