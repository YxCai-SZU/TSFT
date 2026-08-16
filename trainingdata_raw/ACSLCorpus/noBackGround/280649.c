#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    requires a <= b;
    ensures (a <= c && c <= b) ==> \result == 1;
    ensures (c < a || c > b) ==> \result == 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert a <= b;
    
    if (c >= a && c <= b) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
