#include <limits.h>

/*@
    requires ((length) > 0) && ((width) > 0) && ((height) > 0);
    requires ((long long)(length) * (long long)(width) * (long long)(height) <= INT_MAX);
    ensures \result == length * width * height;
    assigns \nothing;
*/
int volume_rectangular_prism(int length, int width, int height) {
    int result;
    
    //@ assert ((length) > 0);
    //@ assert ((width) > 0);
    //@ assert ((height) > 0);
    //@ assert ((long long)(length) * (long long)(width) * (long long)(height) <= INT_MAX);
    
    result = length * width * height;
    
    //@ assert result == length * width * height;
    return result;
}
