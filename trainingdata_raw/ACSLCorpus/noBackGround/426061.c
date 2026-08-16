#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
int64_t func(int64_t a, int64_t p) {
    int64_t sum;
    int64_t pies;
    int64_t temp_sum;

    sum = a * 3 + p;
    pies = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= ((a) * 3 + (p));
        loop invariant 0 <= pies;
        loop invariant pies <= (((a) * 3 + (p)) - temp_sum) / 2;
        loop invariant temp_sum == ((a) * 3 + (p)) - 2 * pies;
        loop assigns temp_sum, pies;
    */
    while (temp_sum >= 2) {
        //@ assert pies <= (((a) * 3 + (p))) / 2;
        temp_sum -= 2;
        pies += 1;
    }

    //@ assert pies <= ((a) * 3 + (p));
    return pies;
}
