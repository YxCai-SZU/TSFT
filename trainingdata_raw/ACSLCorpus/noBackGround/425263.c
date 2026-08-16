#include <stdint.h>

/*@
    requires ((u) >= 0 && (u) <= 1000);
    ensures \result == ((u) * (u) * (u));
    assigns \nothing;
*/
int32_t test_complex_program(int32_t u) {
    // Variable declarations at scope top
    int32_t result;

    //@ assert u >= 0 && u <= 1000;
    //@ assert u * u <= 1000000;
    //@ assert u * u * u <= 1000000000;
    //@ assert u * u * u >= 0;

    result = u * u * u;
    return result;
}
