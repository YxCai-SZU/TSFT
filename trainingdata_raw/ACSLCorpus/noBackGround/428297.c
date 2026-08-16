#include <limits.h>

/*@
    requires (400 <= (x) && (x) <= 1999);
    ensures \result == ((400 <= (x) && (x) <= 599) ? 8 :
        (600 <= (x) && (x) <= 799) ? 7 :
        (800 <= (x) && (x) <= 999) ? 6 :
        (1000 <= (x) && (x) <= 1199) ? 5 :
        (1200 <= (x) && (x) <= 1399) ? 4 :
        (1400 <= (x) && (x) <= 1599) ? 3 :
        (1600 <= (x) && (x) <= 1799) ? 2 :
        (1800 <= (x) && (x) <= 1999) ? 1 : 0);
    assigns \nothing;
*/
int func(int x)
{
    unsigned int x_unsigned;
    unsigned int result_unsigned;
    int result;
    
    //@ assert (400 <= (x) && (x) <= 1999);
    
    if (x < 0) {
        //@ assert x >= 400 && x < 0 ==> \false;
        x_unsigned = (unsigned int)(-x);
    } else {
        x_unsigned = (unsigned int)x;
    }
    
    //@ assert 400 <= x_unsigned && x_unsigned <= 1999;
    result_unsigned = 10 - (x_unsigned / 200);
    
    if (x < 0) {
        result = -(int)result_unsigned;
    } else {
        result = (int)result_unsigned;
    }
    
    //@ assert result == ((400 <= (x) && (x) <= 599) ? 8 :         (600 <= (x) && (x) <= 799) ? 7 :         (800 <= (x) && (x) <= 999) ? 6 :         (1000 <= (x) && (x) <= 1199) ? 5 :         (1200 <= (x) && (x) <= 1399) ? 4 :         (1400 <= (x) && (x) <= 1599) ? 3 :         (1600 <= (x) && (x) <= 1799) ? 2 :         (1800 <= (x) && (x) <= 1999) ? 1 : 0);
    return result;
}
