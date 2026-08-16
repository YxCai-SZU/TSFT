#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(xs + (0 .. 2));
    requires ((3) >= 3 &&
        1 <= (xs)[0] && (xs)[0] <= 100 &&
        1 <= (xs)[1] && (xs)[1] <= 20 &&
        1 <= (xs)[2] && (xs)[2] <= 2000);
    ensures \result <= xs[2];
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t* xs) {
    int32_t water;
    int32_t result;

    //@ assert 1 <= xs[0] && xs[0] <= 100;
    //@ assert 1 <= xs[1] && xs[1] <= 20;
    //@ assert ((xs[0]) * (xs[1])) <= 2000;

    water = xs[0] * xs[1];
    
    if (water < xs[2]) {
        result = water;
    } else {
        result = xs[2];
    }

    //@ assert result <= xs[2];
    //@ assert result >= 0;
    return result;
}
