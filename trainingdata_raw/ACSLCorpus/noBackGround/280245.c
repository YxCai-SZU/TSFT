#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= (y) && (y) <= 100);
    ensures \result == (((((x)) + ((y))) * 10) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t sum;
    uint32_t avg = 0;
    uint32_t temp_sum;
    uint32_t count = 0;

    //@ assert (1 <= (x) && (x) <= (y) && (y) <= 100);
    sum = (x + y) * 10;
    temp_sum = sum;

    /*@
        loop invariant 1 <= x && x <= y && y <= 100;
        loop invariant sum == (x + y) * 10;
        loop invariant avg == (sum - temp_sum) / 2;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant count <= sum / 2;
        loop invariant 0 <= temp_sum;
        loop assigns temp_sum, avg, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        avg += 1;
        count += 1;
        //@ assert avg == (sum - temp_sum) / 2;
    }

    //@ assert avg == (((((x)) + ((y))) * 10) / 2);
    return avg;
}
