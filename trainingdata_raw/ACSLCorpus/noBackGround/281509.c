#include <stdint.h>

/*@
requires (-100 <= (a) <= 100);
ensures \result == ((a) * (a) * (a)) || \result == a;
assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert -10000 <= a * a <= 10000;
    //@ assert -1000000 <= ((a) * (a) * (a)) <= 1000000;
    
    if (a * a * a < 0 || a * a * a > 0) {
        result = a * a * a;
    } else {
        result = a;
    }
    
    //@ assert result == ((a) * (a) * (a)) || result == a;
    return result;
}
