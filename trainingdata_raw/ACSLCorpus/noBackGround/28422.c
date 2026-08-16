#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (N) <= 100);
    requires \valid_read(X_N + (0..N-1));
    requires (\forall integer i; 0 <= i < (N) ==> (1 <= ((X_N)[i]) <= 100));
    assigns \nothing;
    ensures 0 <= \result <= N;
 */
unsigned int func(unsigned int N, unsigned int* X_N) {
    unsigned int m = 0;
    unsigned int index = 0;
    unsigned int result = 0;
    
    // First loop
    /*@ loop invariant 0 <= index <= N;
        loop invariant (0 <= (m) <= 3);
        loop assigns m, index;
        loop variant N - index;
     */
    while (index < N) {
        unsigned int x = X_N[index];
        unsigned int d;
        
        if (x < 10) {
            d = 1;
        } else if (x < 100) {
            d = 2;
        } else {
            d = 3;
        }
        
        unsigned int new_m = (m < d) ? m : d;
        m = new_m;
        index++;
        
        //@ assert (0 <= (m) <= 3);
    }
    
    // Reset for second loop
    index = 0;
    
    // Second loop
    /*@ loop invariant 0 <= index <= N;
        loop invariant (0 <= (result) <= (index));
        loop assigns result, index;
        loop variant N - index;
     */
    while (index < N) {
        unsigned int x = X_N[index];
        unsigned int d;
        
        if (x < 10) {
            d = 1;
        } else if (x < 100) {
            d = 2;
        } else {
            d = 3;
        }
        
        if (d <= m) {
            result++;
        }
        index++;
        
        //@ assert (0 <= (result) <= (index));
    }
    
    // Final verification
    //@ assert 0 <= result <= N;
    return result;
}
