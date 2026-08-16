#include <limits.h>

/*@
    requires ((length) >= 0 && (width) >= 0 && (height) >= 0);
    requires (((length) == 0 && (width) * (height) <= INT_MAX) ||
        ((width) == 0 && (length) * (height) <= INT_MAX) ||
        ((height) == 0 && (length) * (width) <= INT_MAX));
    ensures \result == length * width * height;
    assigns \nothing;
*/
int volume_rect_prism(int length, int width, int height) {
    // Variable declarations at scope top
    int result;
    
    //@ assert ((length) >= 0 && (width) >= 0 && (height) >= 0);
    //@ assert (((length) == 0 && (width) * (height) <= INT_MAX) ||         ((width) == 0 && (length) * (height) <= INT_MAX) ||         ((height) == 0 && (length) * (width) <= INT_MAX));
    //@ assert length * width <= INT_MAX;
    //@ assert length * width * height <= INT_MAX;
    
    result = length * width * height;
    return result;
}
