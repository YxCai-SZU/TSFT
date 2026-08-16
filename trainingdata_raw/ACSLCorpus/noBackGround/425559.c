#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) % 100 == 0 ? 0 : 100 - ((n) % 100));
    ensures \result >= 0;
    ensures \result < 1000;
    assigns \nothing;
 */
size_t func(size_t n)
{
    size_t r;
    size_t change;

    r = n % 100;
    
    if (r == 0) {
        change = 0;
        //@ assert change == 0;
    } else {
        change = 100 - r;
        //@ assert change == 100 - r;
    }
    
    //@ assert change == ((n) % 100 == 0 ? 0 : 100 - ((n) % 100));
    return change;
}
