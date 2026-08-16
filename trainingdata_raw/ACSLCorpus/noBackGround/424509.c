#include <limits.h>

/*@
    requires ((l) > 0 && (w) > 0 && (h) > 0 &&
        (l) <= 0x7FFFFFFF && (w) <= 0x7FFFFFFF && (h) <= 0x7FFFFFFF &&
        (long long)(l) * (long long)(w) * (long long)(h) <= INT_MAX);
    ensures \result == ((l) * (w) * (h));
    assigns \nothing;
*/
int volume_rectangular_prism(int l, int w, int h)
{
    // Declare all variables at the top
    int result;

    //@ assert l > 0 && w > 0 && h > 0;
    //@ assert l <= 0x7FFFFFFF && w <= 0x7FFFFFFF && h <= 0x7FFFFFFF;
    //@ assert (long long)l * (long long)w * (long long)h <= INT_MAX;
    //@ assert (long long)l * (long long)w <= INT_MAX;
    //@ assert (long long)l * (long long)w * (long long)h <= INT_MAX;

    result = l * w * h;
    return result;
}
