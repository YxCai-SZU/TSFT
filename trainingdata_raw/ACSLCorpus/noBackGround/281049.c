#include <stdint.h>

/*@
    requires 1 <= A <= 20;
    requires 1 <= B <= 20;
    ensures (A <= 9 && B <= 9) ==> \result == (long long)(A * B);
    ensures !(A <= 9 && B <= 9) ==> \result == -1;
*/
long long func(unsigned int A, unsigned int B) {
    long long result;
    
    //@ assert 1 <= A <= 20;
    //@ assert 1 <= B <= 20;
    
    if (A <= 9 && B <= 9) {
        //@ assert ((1 <= (A) <= 9) && (1 <= (B) <= 9));
        //@ assert ((A) * (B)) <= 81;
        result = (long long)(A * B);
    } else {
        //@ assert !(A <= 9 && B <= 9);
        result = -1;
    }
    
    return result;
}
