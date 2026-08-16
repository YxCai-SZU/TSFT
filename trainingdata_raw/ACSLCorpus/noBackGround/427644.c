#include <stdint.h>

/*@ requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
      1 <= (c) && (c) <= 20);
    ensures \result >= 0 && \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t remain;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&       1 <= (c) && (c) <= 20);
    remain = c - (a - b);
    
    if (remain > 0) {
        //@ assert remain == ((c) - ((a) - (b)));
        return remain;
    } else {
        //@ assert remain <= 0;
        return 0;
    }
}
