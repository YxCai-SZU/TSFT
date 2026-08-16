#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (d) && (d) <= 100);
    ensures \result >= -1 && \result <= 4;
    ensures \result == -1 ==> (((a) + (b) + (c) + (d)) % 2 != 0) || (((a) + (b) + (c) + (d)) / 2 < 3);
    ensures \result == 0 ==> ((a) + (b) + (c) + (d)) / 2 == 0;
    ensures \result == 1 ==> ((a) + (b) + (c) + (d)) / 2 == 1;
    ensures \result == 2 ==> ((a) + (b) + (c) + (d)) / 2 == 2;
    ensures \result == 3 ==> ((a) + (b) + (c) + (d)) / 2 == 3;
    ensures \result == 4 ==> ((a) + (b) + (c) + (d)) / 2 >= 4;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t sum;
    int32_t res;
    uint32_t half_sum;
    uint32_t temp_sum;

    sum = a + b + c + d;
    res = -1;
    half_sum = 0;
    temp_sum = sum;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100 &&         1 <= (d) && (d) <= 100);
    //@ assert sum == ((a) + (b) + (c) + (d));

    /*@
        loop invariant 0 <= half_sum;
        loop invariant half_sum <= sum / 2;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum + 2 * half_sum == sum;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (d) && (d) <= 100);
        loop invariant sum == ((a) + (b) + (c) + (d));
        loop assigns temp_sum, half_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        half_sum += 1;
        //@ assert temp_sum + 2 * half_sum == sum;
    }

    //@ assert temp_sum < 2;
    //@ assert half_sum == sum / 2;

    if (half_sum == 0) {
        res = 0;
        //@ assert half_sum == 0;
    } else if (half_sum == 1) {
        res = 1;
        //@ assert half_sum == 1;
    } else if (half_sum == 2) {
        res = 2;
        //@ assert half_sum == 2;
    } else if (half_sum == 3) {
        res = 3;
        //@ assert half_sum == 3;
    } else if (half_sum >= 4) {
        res = 4;
        //@ assert half_sum >= 4;
    }

    //@ assert res >= -1 && res <= 4;
    return res;
}
