#include <stdbool.h>

/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20);
    ensures (A <= 9 && B <= 9 ==> \result == A * B) && 
            (A > 9 || B > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(int A, int B) {
    int result;
    int i;

    //@ assert 1 <= A && A <= 20;
    //@ assert 1 <= B && B <= 20;
    //@ assert A * B <= 400;

    if (A <= 9 && B <= 9) {
        result = A * B;
    } else {
        result = -1;
    }

    //@ assert (A <= 9 && B <= 9) ==> result == A * B;
    //@ assert (A > 9 || B > 9) ==> result == -1;

    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant 1 <= A <= 20 && 1 <= B <= 20;
        loop invariant A * B <= 400;
        loop invariant (A <= 9 && B <= 9) ==> result == A * B;
        loop invariant (A > 9 || B > 9) ==> result == -1;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10) {
        i = i + 1;
    }

    return result;
}
