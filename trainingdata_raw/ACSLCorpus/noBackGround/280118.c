#include <limits.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + (((y)) / 2));
    assigns \nothing;
*/
int func(int x, int y)
{
    unsigned int y_unsigned;
    unsigned int half_y_unsigned;
    int half_y;
    int result;

    //@ assert (1 <= (x) <= 100 &&         1 <= (y) <= 100 &&         (y) % 2 == 0);
    
    if (y < 0) {
        y_unsigned = (unsigned int)(-y);
    } else {
        y_unsigned = (unsigned int)y;
    }

    half_y_unsigned = y_unsigned / 2;

    if (y < 0) {
        half_y = -(int)half_y_unsigned;
    } else {
        half_y = (int)half_y_unsigned;
    }

    //@ assert half_y == y / 2;
    
    result = x + half_y;
    
    //@ assert result == x + y / 2;
    
    return result;
}
