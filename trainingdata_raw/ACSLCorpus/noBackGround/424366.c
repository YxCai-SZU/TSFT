#include <stdbool.h>

/*@
    requires \true;
    ensures \result == true;
*/
bool main(void) {
    bool result;

    //@ assert (0 <= (1) && (1) <= (2) && (2) < (5));
    //@ assert !(0 <= (3) && (3) <= (2) && (2) < (5));
    //@ assert ((1) <= (2) && (2) < (5));
    //@ assert !((3) <= (2) && (2) < (5));
    //@ assert ((0) % 2 == 0 && (2) % 2 == 0 && (4) % 2 == 0 && (6) % 2 == 0 && (8) % 2 == 0);
    //@ assert !((0) % 2 == 0 && (2) % 2 == 0 && (4) % 2 == 0 && (6) % 2 == 0 && (9) % 2 == 0);

    result = true;
    return result;
}
