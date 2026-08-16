#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures ((\result) == -1 || (\result) >= 0);
    ensures ((\result) >= 0 ==> ((\result) <= (a) - 1 || (\result) >= (b)));
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a - 1 < b) {
        result = a - 1;
    } else {
        result = b;
    }
    
    if (result < 0) {
        //@ assert result < 0;
        return -1;
    } else {
        //@ assert result >= 0;
        //@ assert result <= a - 1 || result >= b;
        return result;
    }
}
