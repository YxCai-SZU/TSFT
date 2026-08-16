#include <stdbool.h>
#include <stddef.h>

/*@
    requires x < 2;
    ensures (x == 1 ==> \result == 0) && (x == 0 ==> \result == 1);
    assigns \nothing;
*/
int func(size_t x) {
    int result;
    
    //@ assert ((x) == 0 || (x) == 1);
    
    if (x == 1) {
        //@ assert x == 1;
        result = 0;
    } else {
        //@ assert x == 0;
        result = 1;
    }
    
    return result;
}
