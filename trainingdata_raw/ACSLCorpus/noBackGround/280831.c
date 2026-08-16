#include <limits.h>

/*@
    requires ((edge) >= 0 && (edge) * (edge) * (edge) <= INT_MAX);
    ensures \result == ((edge) * (edge) * (edge));
    assigns \nothing;
*/
int volume_cube(int edge)
{
    // Declarations at top of scope
    int ret;

    //@ assert edge >= 0;
    //@ assert edge * edge * edge <= INT_MAX;
    //@ assert edge >= 0 && edge <= 1290;
    //@ assert edge * edge <= 1290 * 1290;
    //@ assert edge * edge * edge <= 1290 * 1290 * 1290;

    ret = edge * edge * edge;
    return ret;
}
