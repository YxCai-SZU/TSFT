#include <limits.h>

/*@
    requires ((l) > 0 && (b) > 0 && (h) > 0);
    requires ((l) * (b) * (h) < INT_MAX);
    ensures \result == ((l) * (b) * (h));
    assigns \nothing;
*/
int rectangular_prism_volume(int l, int b, int h) {
    //@ assert ((l) > 0 && (b) > 0 && (h) > 0);
    //@ assert ((l) * (b) * (h) < INT_MAX);
    //@ assert l * b < INT_MAX;
    //@ assert l * b * h < INT_MAX;
    return l * b * h;
}
