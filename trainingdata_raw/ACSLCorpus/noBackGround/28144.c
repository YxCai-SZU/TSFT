#include <stdint.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max1;
    int64_t max2;
    int64_t max;

    //@ assert -100000000 <= a * c <= 100000000;
    //@ assert -100000000 <= a * d <= 100000000;
    //@ assert -100000000 <= b * c <= 100000000;
    //@ assert -100000000 <= b * d <= 100000000;

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }

    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }

    //@ assert -100000000 <= max1 <= 100000000;
    //@ assert -100000000 <= max2 <= 100000000;

    if (max1 > max2) {
        max = max1;
    } else {
        max = max2;
    }

    return max;
}
