#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (H) && (H) <= 100 &&
        (H) % 2 == 0);
    ensures \result == (((A) + (B)) * (H) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t H) {
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;

    //@ assert A + B <= 200;
    sum = (A + B) * H;
    //@ assert sum <= 20000;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant temp_sum + 2 * count == sum;
        loop invariant count <= sum / 2;
        loop invariant temp_sum <= sum;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum + 2 * count == sum;
    }

    result = count;
    //@ assert result == (((A) + (B)) * (H) / 2);
    return result;
}
