#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    ensures \result >= 0;
    ensures \result <= 3;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t counter = 0;
    uint32_t min_val;

    //@ assert (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    
    if (a < b) {
        if (a < c) {
            min_val = a;
        } else {
            min_val = c;
        }
    } else {
        if (b < c) {
            min_val = b;
        } else {
            min_val = c;
        }
    }

    //@ assert min_val == ((a) < (b) ?             ((a) < (c) ? (a) : (c)) :             ((b) < (c) ? (b) : (c)));

    if (a == b && b == c) {
        counter += 1;
        //@ assert counter == 1;
    } else if (a == b || b == c || a == c) {
        counter += 2;
        //@ assert counter == 2;
    } else {
        counter += 3;
        //@ assert counter == 3;
    }

    //@ assert counter >= 0 && counter <= 3;
    return (int32_t)counter;
}
