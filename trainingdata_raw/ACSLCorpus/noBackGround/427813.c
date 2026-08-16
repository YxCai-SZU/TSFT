#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures 1 <= \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
*/
uint32_t count_unique_colors(int32_t a, int32_t b, int32_t c)
{
    int32_t min;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a < b) {
        if (a < c) {
            min = a;
        } else {
            min = c;
        }
    } else {
        if (b < c) {
            min = b;
        } else {
            min = c;
        }
    }

    //@ assert 0 <= min <= 100;

    uint32_t num_colors;
    if (a == b && b == c) {
        num_colors = 1;
    } else if (a == b || b == c || c == a) {
        num_colors = 2;
    } else {
        num_colors = 3;
    }

    //@ assert 1 <= num_colors <= 3;
    return num_colors;
}
