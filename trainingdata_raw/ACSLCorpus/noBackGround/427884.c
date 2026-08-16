#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B)) && \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D) {
    // Variable declarations at scope top
    int result;
    
    //@ assert A <= 10000;
    //@ assert B <= 10000;
    //@ assert C <= 10000;
    //@ assert D <= 10000;
    
    //@ assert ((A) * (B)) <= 10000 * 10000;
    //@ assert ((C) * (D)) <= 10000 * 10000;
    
    if (A * B > C * D) {
        result = A * B;
    } else {
        result = C * D;
    }
    
    return result;
}
