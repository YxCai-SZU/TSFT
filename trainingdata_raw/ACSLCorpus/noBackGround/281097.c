#include <stdint.h>

/*@
    requires 0 <= length <= 2147483647;
    requires 0 <= width <= 2147483647;
    assigns \nothing;
    ensures \result == ((length) > (width) ? 2 * ((length) + (width)) : 2 * ((width) + (length)));
*/
int32_t compute_rectangle_perimeter(int32_t length, int32_t width)
{
    int32_t result;
    
    //@ assert ((length) >= 0);
    //@ assert ((width) >= 0);
    //@ assert ((length) <= 2147483647);
    //@ assert ((width) <= 2147483647);
    
    if (length > width) {
        //@ assert length > width;
        result = 2 * (length + width);
    } else {
        //@ assert length <= width;
        result = 2 * (width + length);
    }
    
    //@ assert result == ((length) > (width) ? 2 * ((length) + (width)) : 2 * ((width) + (length)));
    return result;
}

int main()
{
    return 0;
}
