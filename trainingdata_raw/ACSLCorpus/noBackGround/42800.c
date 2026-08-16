#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(size_t n) {
    size_t i = 0;
    int32_t a = 1;
    
    /*@
        loop invariant 0 <= i <= 100000;
        loop invariant (1 <= (n) && (n) <= 100);
        loop invariant a == (1 + (i));
        loop assigns i, a;
        loop variant 100000 - i;
    */
    while (i < 100000) {
        a = a + 1;
        //@ assert a == (1 + (i)) + 1;
        
        if (a == 0) {
            //@ assert a == 0;
            return 1;
        }
        
        i += 1;
        //@ assert a == (1 + (i));
    }
    
    //@ assert i == 100000;
    //@ assert a == (1 + (100000));
    return 0;
}
