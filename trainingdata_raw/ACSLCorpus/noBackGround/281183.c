#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t min1;
    uint64_t max1;
    uint64_t min2;
    uint64_t max2;
    uint64_t min_val;
    uint64_t max_val;
    uint64_t diff1;
    uint64_t diff2;
    uint64_t result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a < b) {
        min1 = a;
        max1 = b;
    } else {
        min1 = b;
        max1 = a;
    }

    //@ assert min1 == ((a) < (b) ? (a) : (b)) && max1 == ((a) < (b) ? (b) : (a));

    if (min1 < c) {
        min2 = min1;
        max2 = c;
    } else {
        min2 = c;
        max2 = min1;
    }

    //@ assert min2 == ((min1) < (c) ? (min1) : (c)) && max2 == ((min1) < (c) ? (c) : (min1));

    min_val = min2;
    max_val = max2;

    diff1 = max1 - min1;
    diff2 = max2 - min2;

    //@ assert diff1 >= 0 && diff2 >= 0;

    if (max_val == min_val || (diff1 == 0 && diff2 == 0)) {
        //@ assert max_val == min_val || (diff1 == 0 && diff2 == 0);
        result = 1;
    } else if (diff1 == 0 || diff2 == 0) {
        //@ assert diff1 == 0 || diff2 == 0;
        result = 2;
    } else {
        //@ assert diff1 != 0 && diff2 != 0;
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}
