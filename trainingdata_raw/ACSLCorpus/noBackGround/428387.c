#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    ensures \result == (((A) * (B)) % 2 == 0);
*/
int func(int A, int B) {
    int C;
    int is_even;
    int abs_C;
    
    //@ assert 1 <= A <= 10000;
    //@ assert 1 <= B <= 10000;
    
    //@ assert 1 <= ((A) * (B)) <= 10000 * 10000;
    C = A * B;
    
    is_even = 1;
    abs_C = C;
    
    if (C < 0) {
        abs_C = -C;
    }
    
    /*@
        loop invariant 0 <= abs_C <= 10000 * 10000;
        loop invariant abs_C <= ((A) * (B));
        loop invariant (abs_C % 2 == 0) ==> is_even == 1;
        loop invariant (C % 2 == 0) ==> is_even == 1;
        loop invariant abs_C % 2 == C % 2;
        loop assigns abs_C, is_even;
    */
    while (abs_C > 0) {
        if (abs_C == 1) {
            is_even = 0;
            break;
        }
        abs_C -= 2;
    }
    
    //@ assert is_even == (((A) * (B)) % 2 == 0);
    return is_even;
}
