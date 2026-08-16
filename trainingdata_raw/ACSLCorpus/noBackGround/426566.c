#include <limits.h>

/*@
    requires ((length) > 0 && (width) > 0 && (height) > 0);
    requires ((length) * (width) * (height) <= INT_MAX);
    ensures \result == length * width * height;
    assigns \nothing;
*/
int volume_rect_prism(int length, int width, int height) {
    //@ assert ((length) > 0 && (width) > 0 && (height) > 0);
    //@ assert ((length) * (width) * (height) <= INT_MAX);
    //@ assert length * width <= INT_MAX / height;
    //@ assert length * width * height <= INT_MAX;
    return length * width * height;
}
