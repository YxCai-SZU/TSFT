#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - (b) * 2) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t result;
    result = a - b * 2;
    
    if (result > 0) {
        //@ assert result == ((a) - (b) * 2);
        return result;
    } else {
        //@ assert result == ((a) - (b) * 2);
        return 0;
    }
}
