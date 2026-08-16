#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t n) {
    int32_t result;
    
    if (n >= 1 && n <= 3) {
        result = 1;
    } else if (n >= 4 && n <= 6) {
        result = 2;
    } else if (n >= 7 && n <= 9) {
        result = 3;
    } else if (n >= 10 && n <= 12) {
        result = 4;
    } else {
        result = 5;
    }
    
    //@ assert result >= 0;
    return result;
}
