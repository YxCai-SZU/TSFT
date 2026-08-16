#include <limits.h>

/*@
    predicate width_positive(integer w) = w > 0;
    predicate height_positive(integer h) = h > 0;
    predicate depth_positive(integer d) = d > 0;
    predicate width_safe(integer w, integer h) = w <= (INT_MAX / h);
    predicate product_safe(integer w, integer h, integer d) = (w * h) <= (INT_MAX / d);
*/

/*@
    logic integer volume(integer w, integer h, integer d) = w * h * d;
*/

/*@
    lemma product_bound: \forall integer w, h, d;
        width_positive(w) && height_positive(h) && depth_positive(d) &&
        width_safe(w, h) && product_safe(w, h, d) ==> 
        (w * h) <= (INT_MAX / d);
    
    lemma volume_bound: \forall integer w, h, d;
        width_positive(w) && height_positive(h) && depth_positive(d) &&
        width_safe(w, h) && product_safe(w, h, d) ==> 
        (w * h * d) <= INT_MAX;
*/

/*@
    requires width_positive(width) && height_positive(height) && depth_positive(depth);
    requires width_safe(width, height) && product_safe(width, height, depth);
    ensures \result == volume(width, height, depth);
    ensures \result <= INT_MAX;
*/
int volume_rect_prism(int width, int height, int depth) {
    int ret;
    
    //@ assert width * height <= INT_MAX / depth;
    //@ assert width * height * depth <= INT_MAX;
    
    ret = width * height * depth;
    return ret;
}
