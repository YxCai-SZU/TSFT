#include <stdint.h>

/*@ requires (1 <= (a) <= 10000 &&
      1 <= (b) <= 10000 &&
      1 <= (c) <= 10000 &&
      1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a * b + c * d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t product1;
    int64_t product2;
    int64_t max_value;
    int64_t x;

    //@ assert 1 <= a * b <= 10000 * 10000;
    product1 = a * b;

    //@ assert 1 <= c * d <= 10000 * 10000;
    product2 = c * d;

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    x = max_value;

    //@ assert x >= 0;
    //@ assert x <= a * b + c * d;
    return x;
}
