#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 50 &&
        0 <= (b) && (b) <= 50 &&
        0 <= (c) && (c) <= 50);
    ensures \result >= 0 && \result <= 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t m;
    uint32_t l;
    uint32_t ans;

    //@ assert (0 <= (a) && (a) <= 50 &&         0 <= (b) && (b) <= 50 &&         0 <= (c) && (c) <= 50);

    if (a > b) {
        if (a > c) {
            m = a;
        } else {
            m = c;
        }
    } else {
        if (b > c) {
            m = b;
        } else {
            m = c;
        }
    }

    //@ assert m == (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c)));

    l = 3 * m - (a + b + c);

    //@ assert l == (3 * ((((a)) > ((b))) ? ((((a)) > ((c))) ? ((a)) : ((c))) : ((((b)) > ((c))) ? ((b)) : ((c)))) - ((a) + (b) + (c)));

    if (l < 0) {
        ans = 0;
    } else if (l == 0) {
        ans = 1;
    } else {
        ans = 2;
    }

    //@ assert ans == (((3 * ((((a)) > ((b))) ? ((((a)) > ((c))) ? ((a)) : ((c))) : ((((b)) > ((c))) ? ((b)) : ((c)))) - ((a) + (b) + (c))) < 0) ? 0 : (((3 * ((((a)) > ((b))) ? ((((a)) > ((c))) ? ((a)) : ((c))) : ((((b)) > ((c))) ? ((b)) : ((c)))) - ((a) + (b) + (c))) == 0) ? 1 : 2));
    //@ assert ans >= 0;
    //@ assert ans <= 2;

    return ans;
}
