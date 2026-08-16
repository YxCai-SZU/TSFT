#include <stdbool.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(unsigned int n, unsigned int *a) {
    int count = 0;
    unsigned int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= index;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        unsigned int value = a[index];
        
        //@ assert index < n;
        
        if ((index + 1) % 2 == 0 && value % 2 != 0) {
            count += 1;
        }
        
        index += 1;
        
        //@ assert index <= n;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
