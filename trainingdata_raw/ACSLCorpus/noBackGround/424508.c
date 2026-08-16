#include <stdbool.h>

/*@
    requires n <= 100;
    ensures \result ==> ((n) % 2 != 0);
    ensures !\result ==> ((n) % 2 == 0);
*/
bool is_odd(unsigned int n) {
    //@ assert n % 2 != 0 || n % 2 == 0;
    return n % 2 != 0;
}
