#include <limits.h>

/*@
    requires ((s) >= 3 &&
        (l) > 0 &&
        (s) <= (INT_MAX / (l)));
    ensures \result == ((s) * (l));
    assigns \nothing;
*/
int perimeter_polygon(int s, int l) {
    //@ assert s >= 3 && l > 0 && s <= (INT_MAX / l);
    //@ assert s * l <= INT_MAX;
    return s * l;
}
