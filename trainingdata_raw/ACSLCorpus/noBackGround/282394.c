#include <stdbool.h>

/*@ requires ((n) >= 0);
    ensures \result == true <==> n >= 100;
    assigns \nothing;
 */
bool func(unsigned int n) {
    unsigned int k = 0;
    
    /*@ loop invariant 0 <= k <= 100;
        loop invariant true;
        loop assigns k;
        loop variant 100 - k;
     */
    while (k < 100) {
        k = k + 1;
    }
    
    if (n >= 100) {
        //@ assert n >= 100;
        return true;
    } else {
        //@ assert n < 100;
        return false;
    }
}
