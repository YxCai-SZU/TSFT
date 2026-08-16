#include <limits.h>

/*@
    requires ((length) > 0 && (width) > 0 && (height) > 0 &&
        (long long)(length) * (long long)(width) <= (long long)(INT_MAX / (height)));
    ensures \result == ((length) * (width) * (height));
    assigns \nothing;
*/
int volume_rectangular_prism(int length, int width, int height)
{
    // Declare before use
    int result;
    long long intermediate;

    //@ assert length > 0 && width > 0 && height > 0;
    intermediate = (long long)length * (long long)width;
    //@ assert intermediate <= (long long)(INT_MAX / height);
    result = (int)intermediate * height;
    //@ assert result == ((length) * (width) * (height));
    return result;
}
