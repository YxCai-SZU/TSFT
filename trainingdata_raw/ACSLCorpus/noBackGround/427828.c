#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures ((n) % 2 == 1) ==> \result == 1;
    ensures ((n) % 2 == 0) ==> \result == n;
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 1) {
        result = 1;
        //@ assert ((n) % 2 == 1) ==> result == 1;
        return result;
    } else {
        uint32_t i = 0;
        
        /*@
            loop invariant 0 <= i <= n;
            loop invariant ((n) % 2 == 0);
            loop invariant 1 <= n <= 100;
            loop assigns i;
            loop variant n - i;
        */
        while (i < n) {
            //@ assert 0 <= i < n;
            
            if (i % 2 == 0) {
                //@ assert ((i) % 2 == 0);
            } else {
                //@ assert ((i) % 2 == 1);
            }
            
            i = i + 1;
            //@ assert i <= n;
        }
        
        //@ assert i == n;
        result = (int32_t)n;
        //@ assert ((n) % 2 == 0) ==> result == n;
        return result;
    }
}

