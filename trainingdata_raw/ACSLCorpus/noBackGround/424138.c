#include <stdint.h>

/*@
    requires ((length) >= 0) && ((width) >= 0);
    requires ((length) <= 2147483647 && (width) <= 2147483647 && (length) * (width) <= 2147483647);
    ensures \result == length * width;
    ensures ((\result) >= 0);
*/
int rectangle_area(int length, int width) {
    int ret;
    //@ assert ((length) <= 2147483647 && (width) <= 2147483647 && (length) * (width) <= 2147483647);
    ret = length * width;
    return ret;
}
