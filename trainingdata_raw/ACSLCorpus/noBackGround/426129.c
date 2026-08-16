#include <stdbool.h>
#include <stdint.h>

/*@ requires n <= 0xFFFF;
    ensures \result == n * n;
    assigns \nothing;
 */
uint32_t find_square_num(uint32_t n) {
    //@ assert n <= 0xFFFF;
    //@ assert n * n <= 0xFFFF * 0xFFFF;
    return n * n;
}

/*@ ensures \result == (n % 2 != 0);
    assigns \nothing;
 */
bool is_odd(uint32_t n) {
    return n % 2 != 0;
}

int main() {
    return 0;
}
