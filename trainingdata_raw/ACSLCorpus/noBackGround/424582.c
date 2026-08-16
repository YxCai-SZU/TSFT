#include <stdint.h>

/*@ requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result >= 0;
    ensures \result <= 30;
    assigns \nothing;
 */
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t result;
    int32_t cnt;

    if (a == b && b == c && a % 2 == 0) {
        result = 2;
        //@ assert result >= 0;
        return result;
    } else if (a == b && b == c) {
        result = 1;
        //@ assert result >= 0;
        return result;
    } else if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        result = 0;
        //@ assert result >= 0;
        return result;
    } else {
        cnt = 0;
        if (a % 2 != 0) {
            cnt += 1;
        }
        if (b % 2 != 0) {
            cnt += 1;
        }
        if (c % 2 != 0) {
            cnt += 1;
        }
        //@ assert cnt >= 0;
        result = cnt;
        //@ assert result >= 0;
        return result;
    }
}
