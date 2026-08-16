#include <stdint.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures \result >= 1 && \result <= 8;
    ensures (400 <= x && x < 600) ==> \result == 8;
    ensures (600 <= x && x < 800) ==> \result == 7;
    ensures (800 <= x && x < 1000) ==> \result == 6;
    ensures (1000 <= x && x < 1200) ==> \result == 5;
    ensures (1200 <= x && x < 1400) ==> \result == 4;
    ensures (1400 <= x && x < 1600) ==> \result == 3;
    ensures (1600 <= x && x < 1800) ==> \result == 2;
    ensures (1800 <= x && x < 2000) ==> \result == 1;
*/
int64_t func(int64_t x)
{
    int64_t result;

    //@ assert (400 <= (x) && (x) < 2000);

    if (x >= 400 && x < 600) {
        result = 8;
        //@ assert result == 8;
        return result;
    } else if (x >= 600 && x < 800) {
        result = 7;
        //@ assert result == 7;
        return result;
    } else if (x >= 800 && x < 1000) {
        result = 6;
        //@ assert result == 6;
        return result;
    } else if (x >= 1000 && x < 1200) {
        result = 5;
        //@ assert result == 5;
        return result;
    } else if (x >= 1200 && x < 1400) {
        result = 4;
        //@ assert result == 4;
        return result;
    } else if (x >= 1400 && x < 1600) {
        result = 3;
        //@ assert result == 3;
        return result;
    } else if (x >= 1600 && x < 1800) {
        result = 2;
        //@ assert result == 2;
        return result;
    } else {
        result = 1;
        //@ assert result == 1;
        return result;
    }
}
