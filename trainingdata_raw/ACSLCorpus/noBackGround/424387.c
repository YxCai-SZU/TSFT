#include <stdint.h>

/*@
    requires (0 <= (a) <= 10000) && (0 <= (b) <= 10000) && (0 <= (c) <= 10000) && (0 <= (d) <= 10000);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max1;
    uint32_t max2;
    uint32_t ans;

    //@ assert a * c <= 10000 * 10000;
    //@ assert a * d <= 10000 * 10000;
    //@ assert b * c <= 10000 * 10000;
    //@ assert b * d <= 10000 * 10000;
    //@ assert a * c <= b * d || a * d <= b * d || b * c <= b * d || a * c <= a * d || b * c <= a * d || a * c <= b * c;

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

    if (max1 > max2) {
        ans = max1;
    } else {
        ans = max2;
    }

    //@ assert ans == b * d || ans == b * c || ans == a * d || ans == a * c;
    return ans;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
