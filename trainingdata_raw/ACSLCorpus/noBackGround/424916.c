#include <stdint.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == (((x) + (y)) / 2);
*/
int64_t func(int64_t x, int64_t y) {
    int64_t sum;
    int64_t avg;
    int64_t temp_sum;
    int64_t count;

    sum = x + y;
    avg = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        count += 1;
    }

    avg = count;

    //@ assert avg >= 0;
    //@ assert avg == (((x) + (y)) / 2);
    return avg;
}
