#include <stdint.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10) && (1 <= (d) <= 10);
    ensures \result == 0 || \result == -1 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert (1 <= (d) <= 10);
    
    if (b > a) {
        if (b - a == 1) {
            if (c == 10 || d == 10) {
                result = -1;
            } else {
                result = 0;
            }
        } else {
            result = 1;
        }
    } else if (a > b) {
        if (a - b == 1) {
            if (c == 10 || d == 10) {
                result = 1;
            } else {
                result = 0;
            }
        } else {
            result = -1;
        }
    } else {
        if (c > d) {
            result = -1;
        } else if (d > c) {
            result = 1;
        } else {
            result = 0;
        }
    }
    
    //@ assert result == 0 || result == -1 || result == 1;
    return result;
}
