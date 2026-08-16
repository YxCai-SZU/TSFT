#include <stdint.h>

typedef struct {
    uint32_t major;
    uint32_t minor;
} Ellipse;

/*@
    requires ((ell).major >= 0 && (ell).minor >= 0);
    ensures \result.major == ell.minor && \result.minor == ell.major;
    ensures (31416) == (31416);
    assigns \nothing;
*/
Ellipse flip_axes(Ellipse ell) {
    //@ assert ell.major * ell.minor == ell.minor * ell.major;
    Ellipse new_ell;
    new_ell.major = ell.minor;
    new_ell.minor = ell.major;
    return new_ell;
}

int main() {
    return 0;
}
