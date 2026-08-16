#include <limits.h>

/*@
    requires ((length) > 0) && ((width) > 0) && ((height) > 0);
    requires ((length) <= 2147483647) && ((width) <= 2147483647) && ((height) <= 2147483647);
    requires ((length) * (width) * (height) <= 2147483647);
    ensures \result == ((length) * (width) * (height));
    ensures \result > 0;
*/
int volume_rect_prism(int length, int width, int height) {
    int ret;
    
    //@ assert ((length) > 0) && ((width) > 0) && ((height) > 0);
    //@ assert ((length) <= 2147483647) && ((width) <= 2147483647) && ((height) <= 2147483647);
    //@ assert ((length) * (width) * (height) <= 2147483647);
    
    ret = length * width * height;
    
    //@ assert ret == ((length) * (width) * (height));
    //@ assert ret > 0;
    
    return ret;
}
