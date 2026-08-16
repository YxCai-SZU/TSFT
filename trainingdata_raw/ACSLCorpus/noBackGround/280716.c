#include <limits.h>

/*@
    requires (0 <= (edge) <= 1290);
    ensures \result == ((edge) * (edge) * (edge));
    assigns \nothing;
*/
int volume_cube(int edge) {
    // Variable declarations at top of scope
    int ret;

    //@ assert edge >= 0;
    //@ assert edge <= 1290;
    //@ assert edge * edge <= 1290 * 1290;
    //@ assert edge * edge * edge <= 1290 * 1290 * 1290;

    ret = edge * edge * edge;
    return ret;
}
