#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B)) && \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D) {
    int S1;
    int S2;
    int result;

    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    //@ assert ((A) * (B)) >= 1 && ((A) * (B)) <= 100000000;
    //@ assert ((C) * (D)) >= 1 && ((C) * (D)) <= 100000000;

    S1 = A * B;
    S2 = C * D;

    //@ assert S1 == ((A) * (B));
    //@ assert S2 == ((C) * (D));

    if (S1 > S2) {
        result = S1;
    } else {
        result = S2;
    }

    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    //@ assert result >= ((A) * (B)) && result >= ((C) * (D));

    return result;
}
