#include <stdbool.h>

/*@
    requires ((x) >= 0) && ((x) <= 3);
    ensures ((x) <= 4);
*/
void proof_two_trivial_inequalities(int x) {
    //@ assert x <= 4;
}
