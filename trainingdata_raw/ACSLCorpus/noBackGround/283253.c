#include <stdbool.h>

/*@
    requires ((x) > 0 && (x) <= 1);
    ensures \result == (x == 1);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= x;
        loop invariant count <= i;
        loop invariant i == count;
        loop invariant ((x) > 0 && (x) <= 1);
        loop assigns i, count;
        loop variant x - i;
    */
    while (i < x) {
        unsigned int next_bit = 1;
        
        if (next_bit == 1) {
            count += 1;
        }
        
        i += 1;
        //@ assert i == count;
    }
    
    if (count == 1) {
        return true;
    } else {
        return false;
    }
}
