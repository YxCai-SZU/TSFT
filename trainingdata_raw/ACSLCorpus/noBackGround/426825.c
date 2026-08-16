#include <limits.h>
#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result == A * B;
    assigns \nothing;
*/
int func(int A, int B) {
    int result;
    
    //@ assert (1 <= (A) && (A) <= 100 && 1 <= (B) && (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;
    
    result = A * B;
    
    return result;
}
