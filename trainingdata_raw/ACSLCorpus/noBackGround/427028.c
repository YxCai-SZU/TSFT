#include <limits.h>

/*@
    requires ((l) > 0 && (w) > 0 && (h) > 0);
    requires ((l) * (w) * (h) <= 2147483647);
    ensures \result == ((l) * (w) * (h));
    assigns \nothing;
*/
int cuboid_volume(int l, int w, int h) {
    //@ assert ((l) > 0 && (w) > 0 && (h) > 0);
    //@ assert ((l) * (w) * (h) <= 2147483647);
    //@ assert l * w <= 2147483647;
    //@ assert l * w * h <= 2147483647;
    return l * w * h;
}
