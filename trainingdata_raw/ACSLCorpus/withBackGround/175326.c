#include <limits.h>

/*@
    predicate positive(integer x) = x > 0;
    predicate no_overflow(integer l, integer w, integer h) = 
        l * w * h <= INT_MAX;
*/

/*@
    requires positive(l) && positive(w) && positive(h);
    requires no_overflow(l, w, h);
    ensures \result == l * w * h;
    assigns \nothing;
*/
int cuboid_volume(int l, int w, int h) {
    // Variable declarations at top of scope
    int ret;
    
    //@ assert positive(l) && positive(w) && positive(h);
    //@ assert no_overflow(l, w, h);
    
    ret = l * w * h;
    
    //@ assert ret == l * w * h;
    return ret;
}
