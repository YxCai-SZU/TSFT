#include <limits.h>

/*@
    requires ((width) > 0 && (height) > 0 && (depth) > 0 &&
        (width) <= INT_MAX && (height) <= INT_MAX && (depth) <= INT_MAX &&
        (long long)(width) * (long long)(height) <= INT_MAX &&
        (long long)(width) * (long long)(height) * (long long)(depth) <= INT_MAX);
    ensures \result == width * height * depth;
    assigns \nothing;
*/
int volume_rect_prism(int width, int height, int depth) {
    //@ assert (long long)width * (long long)height <= INT_MAX;
    return width * height * depth;
}
