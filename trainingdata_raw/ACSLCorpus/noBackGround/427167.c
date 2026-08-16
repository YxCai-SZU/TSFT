#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;

    sum = a + b;
    result = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= result;
        loop invariant result <= sum / 2;
        loop invariant temp_sum == sum - 2 * result;
        loop invariant sum == a + b;
        loop assigns result, temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        result += 1;
        temp_sum -= 2;
    }

    if (temp_sum == 1) {
        //@ assert temp_sum == 1;
        result += 1;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
