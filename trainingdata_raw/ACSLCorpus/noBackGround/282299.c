#include <stdint.h>

/*@ requires n < 1000;
    ensures \result == n * n;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t find_square_num(uint32_t n) {
    //@ assert n * n <= 999 * 999;
    return n * n;
}
