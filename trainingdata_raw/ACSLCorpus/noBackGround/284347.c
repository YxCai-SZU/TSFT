#include <limits.h>

/*@
    requires (400 <= (x) <= 1999);
    ensures \result == ((x) < 600 ? 8 :
        (x) < 800 ? 7 :
        (x) < 1000 ? 6 :
        (x) < 1200 ? 5 :
        (x) < 1400 ? 4 :
        (x) < 1600 ? 3 :
        (x) < 1800 ? 2 :
        (x) < 2000 ? 1 : 0);
    assigns \nothing;
*/
int func(int x)
{
    unsigned int x_unsigned;
    int result;
    
    //@ assert (400 <= (x) <= 1999);
    
    if (x < 0) {
        //@ assert x >= 400;
        x_unsigned = (unsigned int)(-x);
    } else {
        x_unsigned = (unsigned int)x;
    }
    
    result = -1;
    
    if (x_unsigned < 600) {
        result = 8;
    } else if (x_unsigned < 800) {
        result = 7;
    } else if (x_unsigned < 1000) {
        result = 6;
    } else if (x_unsigned < 1200) {
        result = 5;
    } else if (x_unsigned < 1400) {
        result = 4;
    } else if (x_unsigned < 1600) {
        result = 3;
    } else if (x_unsigned < 1800) {
        result = 2;
    } else if (x_unsigned < 2000) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == ((x) < 600 ? 8 :         (x) < 800 ? 7 :         (x) < 1000 ? 6 :         (x) < 1200 ? 5 :         (x) < 1400 ? 4 :         (x) < 1600 ? 3 :         (x) < 1800 ? 2 :         (x) < 2000 ? 1 : 0);
    return result;
}
