#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t sum;
    size_t avg;

    sum = a + b;
    
    if (sum % 2 == 0) {
        avg = sum / 2;
        //@ assert avg == sum / 2;
    } else {
        avg = sum / 2 + 1;
        //@ assert avg == sum / 2 + 1;
    }
    
    //@ assert avg == (((a) + (b) + 1) / 2);
    return avg;
}
