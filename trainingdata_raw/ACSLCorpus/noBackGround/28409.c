#include <limits.h>

/*@
    requires ((length) > 0) && ((width) > 0) && ((height) > 0);
    requires ((length) > 0 && (width) > 0 && (height) > 0 &&
        (length) * (width) * (height) <= INT_MAX);
    ensures \result == length * width * height;
    assigns \nothing;
*/
int volume_rectangular_prism(int length, int width, int height) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert ((length) > 0);
    //@ assert ((width) > 0);
    //@ assert ((height) > 0);
    //@ assert ((length) > 0 && (width) > 0 && (height) > 0 &&         (length) * (width) * (height) <= INT_MAX);
    
    result = length * width * height;
    
    //@ assert result == length * width * height;
    return result;
}
