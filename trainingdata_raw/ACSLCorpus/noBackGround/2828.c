#include <limits.h>

/*@
    requires ((length) > 0) && ((width) > 0) && ((height) > 0);
    requires ((length) > 0 && (width) > 0 && (height) > 0 &&
        (long long)(length) * (long long)(width) <= INT_MAX &&
        (long long)(length) * (long long)(width) * (long long)(height) <= INT_MAX);
    ensures \result == ((length) * (width) * (height));
    assigns \nothing;
*/
int volume_rectangular_prism(int length, int width, int height) {
    //@ assert ((length) > 0) && ((width) > 0) && ((height) > 0);
    //@ assert ((length) > 0 && (width) > 0 && (height) > 0 &&         (long long)(length) * (long long)(width) <= INT_MAX &&         (long long)(length) * (long long)(width) * (long long)(height) <= INT_MAX);
    //@ assert (long long)length * (long long)width <= INT_MAX;
    int intermediate;
    int result;
    
    intermediate = length * width;
    //@ assert intermediate == length * width;
    //@ assert (long long)intermediate * (long long)height <= INT_MAX;
    
    result = intermediate * height;
    //@ assert result == ((length) * (width) * (height));
    
    return result;
}
