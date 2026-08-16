#include <stddef.h>

/*@ requires (1 <= (k) && (k) <= 23);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result < 24; */
int func(size_t k)
{
    int result;
    int x;
    
    //@ assert (1 <= (k) && (k) <= 23);
    x = 24 - (int)k;
    
    if (x > 0) {
        result = x;
        //@ assert result >= 0;
        //@ assert result < 24;
        return result;
    } else {
        //@ assert x <= 0;
        result = -1;
        //@ assert result == -1;
        return result;
    }
}
